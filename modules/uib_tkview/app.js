Ember.$.getJSON('https://tk.app.uib.no/api/v1/service/all', function(data) {
  var tkdata = data;

  // configuration
  var extended_view = false;

  var m;
  if (m = document.URL.match(/\?([^#]+)/)) {
    var q = m[1];
    q = q.split('&');
    for (var i=0; i < q.length; i++) {
      if (q[i] == 'ex')
        extended_view = true;
    }
  }

  var pretty_values = {
    criticality: {
      1: 'kritisk',
      2: 'viktig',
      3: 'normal',
      4: 'liten'
    },
    availability: {
      247: 'alltid',
      'arbeidstid': '08:00–15:45 man–fre',
      'vakt': '07:00-22:00 man-fre (10:00-18:00 lør–søn)'
    },
    service_supplier: {
      'ita': 'IT-avdelingen',
      'intern': 'annen intern enhet',
      'ekstern': 'ekstern',
    },
    service_type: {
      'cfs': 'tilbudt',
      'ss': 'understøttende',
    },
  };

  var pretty = function(obj, attr) {
    v = obj[attr];
    if (pretty_values[attr]) {
      return pretty_values[attr][v] || v;
    }
    return v;
  }

  // filter and prepare the service records for display
  filtered_service = {};
  for (var k in tkdata.service) {
    var s = tkdata.service[k]

    if (!extended_view) {
      if (s.info.service_type != 'cfs')
        continue;
      if (s.info.service_state != 'prod')
        continue;
      if (!extended_view && s.info.edit_state != 'accepted')
        continue;
    }

    s.id = k;
    filtered_service[k] = s;

    s.infolinks = [];
    if (s.link.doc) {
      s.infolinks.push({'title': 'Dokumentasjon av tjenesten', 'icon': 'fa-info-circle', 'link': s.link.doc});
    }
    if (extended_view && s.info.cmdb_id) {
      s.infolinks.push({'title': 'CMDB #' + s.info.cmdb_id, 'icon': 'fa-database', 'link': 'https://bs.uib.no/?module=cmdb&action=viewt&tjeneste=' + s.info.cmdb_id});
    }
    if (extended_view && s.link.href_tk) {
      s.infolinks.push({'title': 'tk.app.uib.no', 'icon': 'fa-file-text-o', 'link': s.link.href_tk});
    }
    if (extended_view && s.link.href_tk) {
      s.infolinks.push({'title': 'Rediger tjenenesten på tk.app.uib.no', 'icon': 'fa-cog', 'link': s.link.href_tk + "/edit"});
    }

    s.facts = []
    if (extended_view && s.info.criticality) {
      s.facts.push({'title': 'Kritikalitet', 'value': pretty(s.info, 'criticality')});
    }
    if (s.info.availability) {
      s.facts.push({'title': 'Tilgjengelighet', 'value': pretty(s.info, 'availability')});
    }
    if (s.info.cost) {
      s.facts.push({'title': 'Kostnad', 'value': s.info.cost});
    }
    if (s.info.service_status) {
      s.facts.push({'title': 'Driftsstatus', 'value': s.info.service_status});
    }
    if (extended_view && s.info.service_type) {
      s.facts.push({'title': 'Tjenestetype', 'value': pretty(s.info, 'service_type')});
    }
    if (extended_view && s.info.service_state) {
      s.facts.push({'title': 'Livssyklus', 'value': pretty(s.info, 'service_state')});
    }
    if (s.info.service_supplier) {
      s.facts.push({'title': 'Driftsleverandør', 'value': pretty(s.info, 'service_supplier')});
    }
    if (s.meta.changed) {
      s.facts.push({'title': 'Oppdatert', 'value': s.meta.changed.substr(0,10)});
    }
    if (extended_view && s.info.cmdb_id) {
      s.facts.push({'title': 'CMDB#', 'value': s.info.cmdb_id});
    }
    if (s.related && s.related.support_contact) {
      s.facts.push({'title': 'Brukerstøtte', 'value': s.related.support_contact.title});
    }

    if (s.role && s.role.owner) {
      s.role.owner_name = tkdata['user'][s.role.owner];
      s.role.owner_link = 'http://www.uib.no/user/uib/' + s.role.owner;
    }
  }
  tkdata.service = filtered_service

  var categories = [];
  for (var k in tkdata['class']) {
    c = tkdata['class'][k];
    if (c.icon) {
      c.icon = 'fa-' + c.icon;
    }
    else {
      c.icon = 'fa-star';
    }
    c.services = [];
    c.promoted_services = [];

    categories.push(c);
  }
  categories.sort(function(a, b) {
    return a.weight - b.weight;
  });

  for (var k in tkdata.service) {
    s = tkdata.service[k]
    s.categories = [];
    promoted = s.flag && s.flag.search(/promote/ >= 0);
    if ('classification' in s) {
      classification = s['classification'].split(' ');
      for (var i=0; i < classification.length; i++) {
        tkdata['class'][classification[i]].services.push(s);
        s.categories.push(tkdata['class'][classification[i]]);
        if (promoted && tkdata['class'][classification[i]].promoted_services.length < 5) {
          tkdata['class'][classification[i]].promoted_services.push(s);
        }
      }
    }
  }

  var App = Ember.Application.create({
    rootElement: '#ember-app',
  });
  App.Router.map(function() {
    this.resource('about');
    this.resource('services', function() {
      this.resource('service', { path: ':service_id' });
    });
    this.resource('categories', function() {
      this.resource('category', { path: ':category_id' });
    });
    // put your routes here
  });

  App.IndexRoute = Ember.Route.extend({
    model: function() {
      cat = tkdata['class']
      cat_list = []
      for (var i = 0; i < categories.length; i++) {
        if (categories[i].promoted_services.length && categories[i].type != 'service_roles')
          cat_list.push(categories[i]);
      }
      return cat_list
    },
  });

  App.ServicesRoute = Ember.Route.extend({
    model: function() {
      lst = [];
      for (var k in tkdata.service) {
        var s = tkdata.service[k];
        lst.push(s);
      }
      lst.sort(function(a, b) {
        a = a.title;
        b = b.title;
        return a < b ? -1 : a > b ? 1 : 0;
      });
      return lst;
    }
  });

  App.ServicesController = Ember.Controller.extend({
    filteredServices: function() {
      try {
        needle = new RegExp(this.get('searchFor'), 'i');
        return this.get('model').filter(function (o) {
          return o.title.match(needle);
        });
      }
      catch(err) {
        // regexp construction might fail
        return this.get('model');
      }
    }.property('model', 'searchFor'),
  });

  App.ServiceRoute = Ember.Route.extend({
    model: function(params) {
      return tkdata.service[params.service_id];
    }
  });

  App.CategoriesRoute = Ember.Route.extend({
    model: function() {
      return categories;
    }
  });

  App.CategoryRoute = Ember.Route.extend({
    model: function(params) {
      return tkdata['class'][params.category_id];
    }
  });

});
