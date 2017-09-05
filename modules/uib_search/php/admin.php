<?php

function uib_search__boosting_admin_form($form, &$form_state) {
  $boosting = uib_search__get_boosting();
  drupal_add_js(drupal_get_path('module', 'uib_search') . '/js/uib_search_admin.js');
  $form['fields'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('boost-fields')),
  );
  foreach ($boosting as $key => $object) {
    $form['fields'][$key] = array(
      '#type' => 'textfield',
      '#title' => t($object->title),
      '#required' => TRUE,
      '#description' => t($object->description),
      '#default_value' => $object->value,
    );
  }
  $form['test-search'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('test-area')),
    'uib_search_testing__keywords' => array(
      '#type' => 'textarea',
      '#title' => t('Test queries below'),
      '#description' => t('Test queries will be executed when clicking the test
        button. The result will be a summary difference in result from the
        saved setup vs your suggested setup. You can add test queries yourself,
        but please dont remove those that are already there, unless you know
        what you are doing.'),
      '#default_value' => variable_get('uib_search_testing__keywords',
        'mat, master, bio, psykologi, bachelor, psyk, geo, '
        . 'medisin, inf, kjem, timeplan'),
    ),
    'test-submit' => array(
      '#type' => 'button',
      '#value' => t('Evaluate your changes'),
      '#attributes' => array(
        'onclick' => 'jQuery.fn.uib_search__test_setup(event);',
        'id' => 'something'
      ),
    ),
  );

  $form = system_settings_form($form);
  $form['results'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('test-results')),
    '#weight' => 1000,
  );

  return $form;
}

class uib_search__boost_value {
  private $value = 1;
  private $name;
  private $title = '';
  private $description = '';
  private $prefix = 'uib_search_boosting__';
  function __construct($n, $t = '', $d = '', $v = 1) {
    $this->name = $n;
    $this->title = t($t);
    $this->description = t($d);
    $this->value = variable_get($this->prefix . $n, $v);
  }

  function __get($name) {
    if ($name == 'title' && !$this->title) {
      return ucfirst(str_replace(array('-', '_'), ' ', $this->name));
    }
    else if ($name == 'name') {
      return $this->prefix . $this->name;
    }
    else {
      return $this->$name;
    }
  }

  function __toString() {
    return $this->__get('title') . ': ' . $this->value;
  }

}

function uib_search__get_boosting() {
  $items = array();

  $item = new uib_search__boost_value (
    'match-title',
    t('Match title'),
    t('Boost when having a full word match in the title of nodes'),
    2
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'match-name-user',
    t('Match name of user'),
    t('Boost when having a full match of user first or last name'),
    3
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'match-keywords',
    t('Match a keyword'),
    t('Boost when matching a keyword. Matching is fuzzy with fuzziness=1 and
    prefix=4, meaning one letter can be wrong after first four letters.'),
    5
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'match-search-description',
    t('Fuzzy match of search description'),
    t('Boost when matching a search description added to this object. Search is
    fuzzy with fuzziness=auto'),
    2
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'match-url',
    t('Match end of url'),
    t('Boost when exactly matching (term query) the last element of the url, transformed to
    lowercase'),
    3
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'match-phone',
    t('Match user phone number'),
    t('Boost when query matches users first part of phone number,
    excluding +47'),
    10
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'match-study-code',
    t('Match a study code'),
    t('Boost when exactly matching a study code'),
    5
  );
  $items[$item->name] = $item;

  /*
  * Relevance boosting. These don't include the actual search term: boosting
  * is done as a filter on the returned results, depending on their properties.
  */
  $item = new uib_search__boost_value (
    'study-type-programme',
    t('Boost if study programme'),
    t('Boost if matching data is study programme'),
    6
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'study-type-course',
    t('Boost if study course'),
    t('Boost if matching data is a study course'),
    5
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'study-type-exchange',
    t('Boost if exchange agreement'),
    t('Boost if matching data is a exchange agreement'),
    5
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'study-whatever-study',
    t('Boost if in the study index'),
    t('Boost other items in the study index, that are not a course,
    a study programme, or an exchange agreement'),
    4
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'node-area',
    t('Boost node type area'),
    t('Boost if node type is area'),
    6
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'node-content-list',
    t('Boost node type uib_content_list'),
    t('Boost if node type is a content-list'),
    6
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'node-external-content',
    t('Boost external content'),
    t('Boost external content. This is normally used to point to internal
      content that is not indexed, like views etc.'),
    6
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'recent-content',
    t('Boost recent news'),
    t('Boost nodes with article type = news, changed in the last month.'),
    5
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'upcoming-events',
    t('Boost upcoming events'),
    t('Boost events that are happening today or forward in time'),
    5
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'relevance-vs-criteria-boosting',
    t('Boost relevance kriteria'),
    t('Boost relevance criteria in regard to search criteria. 1 means
      relevance and search criteria attribute equally to the score.'),
    1
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'manual-boost-factor',
    t('Manual boost factor'),
    t('Factor used with the manual boost function.'),
    1.5
  );
  $items[$item->name] = $item;

  $item = new uib_search__boost_value (
    'unboost-past-events',
    t('Unboost past events'),
    t('Negative boost for past events.'),
    0.03
  );
  $items[$item->name] = $item;

  return $items;
}

function uib_search__compare_page() {
  $url = rtrim(uib_search__get_setup('url'), '/');
  $url .= '/' .uib_search__get_setup('index');
  $url .= '/_search';

  // Query with old settings
  $query = uib_search__create_query();
  $old = uib_search__run_elastic_request($url, json_encode($query), 'GET', FALSE, 5, TRUE);
  $old = json_decode($old->data);
  $old = array_map('uib_search__simplify_result', $old->hits->hits);

  // Query with new settings
  $query = uib_search__create_query(TRUE);
  $new = uib_search__run_elastic_request($url, json_encode($query), 'GET', FALSE, 5, TRUE);
  $new = json_decode($new->data);
  $new = array_map('uib_search__simplify_result', $new->hits->hits);

  // Compare
  $same = TRUE;
  $result = array();
  for ($i = 0; $i<count($new); $i++){
    $index = array_search($new[$i], $old);
    if ($index === FALSE) {
      // New entry
      $result[] = array('new', $new[$i], $i + 1);

    }
    else if ($index == $i) {
      // in same position, no action
      continue;
    }
    else if($index > $i) {
      // Has gone up
      $result[] = array('up', $new[$i], $i + 1, $index + 1);
    }
    else if($index < $i) {
      // Has gone down
      $result[] = array('down', $new[$i], $i + 1, $index + 1);
    }
  }
  // Excluded entries
  $excluded = array_diff($old, $new);

  $retval = array();
  if (count($result)>0) {
    $retval[] = '<h2>' . t('Changes in search for ') . '<em>' . $_REQUEST['query'] . '</em></h2>';
    $retval[] = '<ul>';
    foreach ($result as $v) {
      $r = "<li class=\"{$v[0]}\">";
      $r .= ' <span class="rank">';
      $r .= t('Rank ') . $v[2] . ', ';
      if ($v[0] == 'up') {
        $r .= t('up from ') . $v[3];
      }
      else if ($v[0] == 'down') {
        $r .= t('down from ') . $v[3];
      }
      else if ($v[0] == 'new') {
        $r .= t('new entry');
      }
      $r .= '</span>';
      $r .= ' <a href="' . $v[1]->link . '">' . $v[1]->title . '</a>';
      $r .= "</li>";
      $retval[] = $r;
    }
    $retval[] = '</ul>';
    if (count($excluded)) {
      $retval[] = '<h3>' . t('Excluded entries ') . '</h3>';
      $retval[] = '<ul>';
      foreach ($excluded as $v) {
        $retval[] = '<li><a href="' . $v->link . '">' . $v->title . '</a></li>';
      }
      $retval[] = '</ul>';
    }
  }
  return $retval;
}

class uib_search__stdClass extends stdClass{
  function __toString() {
    return $this->_index .'##' . $this->_type . '##' . $this->_id;
  }
}
function uib_search__simplify_result($a) {
  $o = new uib_search__stdClass();
  $o->_id = $a->_id;
  $o->_type = $a->_type;
  $o->_index = $a->_index;
  $o->title = $a->_source->generic->title;
  $o->link = $a->_source->generic->link;
  return $o;
}

function uib_search__compare_all_pages() {
  drupal_add_http_header('Content-Type', 'text/plain');
  $keywords = explode(',', $_REQUEST['uib_search_testing__keywords']);
  $output = array();
  foreach ($keywords as $v) {
    $_REQUEST['query'] = trim($v);
    $output = array_merge($output, uib_search__compare_page());
  }

  if(count($output) == 0) {
    print '<h3>No changes found</h3>';
  }
  else {
    print implode('', $output);
  }
}
