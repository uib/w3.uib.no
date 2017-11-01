# Search engine based on Elasticsearch

We use the [Elasticsearch service](https://tk.app.uib.no/node/247)
for instant search for persons on uib.no.
[Elasticsearch](https://en.wikipedia.org/wiki/Elasticsearch) is a search
interface built on top of [Apache Lucene](https://lucene.apache.org) that
provide fast and precise search results from large amounts of semi-structured
data.

## Setup (TAKE CARE: There are currently two competing setups):

#### Using the elasticsearch prod - server: ####

The production server is at https://api.search.uib.no. This setup only allows
for a single index to be used at the same time. Indices can be  created at
https://token.search.uib.no.

The config structure is as follows:

*Admin setup*

    $conf['uib_elasticsearch_admin'] = array(
      'index1' => array(
        'url' => 'https://api.search.uib.no',
        'user' => 'my_first_index_admin',
        'password' => 'abcdefgh',
        'index' => 'my_first_index',
      ),
      'index2' => array(
        'url' => 'https://api.test.search.uib.no',
        'user' => 'my_second_index_admin',
        'password' => 'ijklmnop',
        'index' => 'my_second_index',
      ),
    );

*Read only setup*

    $conf['uib_elasticsearch'] = array(
      'index1' => array(
        'url' => 'https://api.search.uib.no',
        'user' => 'my_first_index_user',
        'password' => 'abcdefgh',
        'index' => 'my_first_index',
      ),
      'index2' => array(
        'url' => 'https://api.test.search.uib.no',
        'user' => 'my_second_index_user',
        'password' => 'ijklmnop',
        'index' => 'my_second_index',
      ),
    );

The read only setup is used for the actual searching, while the admin setup is
used for indexing, and updating the elastic data when changes are made.

To specify which index is used, use:

bin/site-drush vset uib_elasticsearch_useindex index1
bin/site-drush vset uib_elasticsearch_useindex_admin index1

#### Using the elasticsearch test - server: ####

This setup should take over for and become the new production environment
shortly. The test server is at https://api.test.search.uib.no. Indices for this
are created at https://token.search.uib.no.

Variables in site/settings.php:

    $conf['uib_elasticsearch_admin_url'] = 'https://api.test.search.uib.no';
    $conf['uib_elasticsearch_admin_index'] = 'anyindex';
    $conf['uib_elasticsearch_admin_token'] = 'thisisa1078characterslongtoken';

...while the read only setup can be set in the database using variable_set
(For a development-setup, using settings.php for both settings will be fine)

    bin/site-drush vset uib_elasticsearch_url https://api.test.search.uib.no
    bin/site-drush vset uib_elasticsearch_index anyindex
    bin/site-drush vset uib_elasticsearch_token thisisalso1078characterslongtoken

It is important that the admin-variables are defined in settings.php on the
production system, to prevent these values from leaking to development systems
when running `bin/site-prod-reset`.

In the old authentication scheme, the variables `uib_elasticsearch_useindex` and
`uib_elasticsearch_useindex_admin` would determine which index to use. If these
variables are set, old auth-scheme is still used. To use the new scheme, change
these variables to capital letters FALSE:

    bin/site-drush vset uib_elasticsearch_useindex FALSE
    bin/site-drush vset uib_elasticsearch_useindex_admin FALSE

To to create and / or review your available indices, visit
[shield.testapp.uib.no](https://shield.testapp.uib.no).

## Drush functionality

There is functionality available from drush to manage
indexing. The following commands are useful when working with the search index

    bin/site-drush vget elastic           # list all current variables
                                          # for elasticsearch.
    bin/site-drush help | grep uib-search # list drush commands on
                                          # uib_search module

### Functions for any setup:

bin/site-drush uib-search            # Do a search in the elasticsearch database and prettyprint the results.bin/site-drush uib-search
bin/site-drush uib-search-drop-inde  # Drop the current elastic index. The index will be recreated when new content is added. If thebin/site-drush uib-search
bin/site-drush uib-search-index      # Index entities in the database to the elastic search database. Currently supports users and nodes.bin/site-drush uib-search
bin/site-drush uib-search-node       # Retrieve a node as it will be inserted into the elastic search index. Options --index and --drop are
bin/site-drush uib-search-setup      # Setup elastic search. By default setup mapping found in the file uib_search/elastic/mapping.json.bin/site-drush uib-search
bin/site-drush uib-search-study      # Retrieve a study object as it will be inserted into the elastic search index. Options --index andbin/site-drush uib-search
bin/site-drush uib-search-user       # Retrieve a user object as it will be inserted into the elastic search index. Options --index andbin/site-drush uib-search


### Functions only for the old setup:

bin/site-drush uib-search-url        # Print URL that can be used to access the elastic server.bin/site-drush uib-search

### Functions only for the new setup:

bin/site-drush uib-search-curl       # Print curl-string for easy access to the elastic server.bin/site-drush uib-search
bin/site-drush uib-search-createix   # Create a new elasticsearch index and print the index name. Return an empty string on failure.bin/site-drush uib-search


## User document structure in Elastic

The current document structure, as json, of indexed users

    {
      name,
      mail,
      uid,
      first_name,
      last_name,
      phone,
      social_media,
      slug,
      ou_en,
      ou_nb,
      position_en,
      position_nb,
      alt_position_en,
      alt_position_nb,
      competence_en,
      competence_nb,
      link_en,
      link_nb,
      generic : {
        title,
        link,
        excerpt,
        title_en,
        title_nb,
        link_en,
        link_nb,
        excerpt_en,
        excerpt_nb,
        image,
        _searcable_text,
      },
      search_manual_boost,
    }

## Node document structure in Elastic

Nodes can contain the fields defined below. `field_uib_` is stripped from the
field names, so a field called `field_uib_somefield` will simply show in the
structure as `somefield`.


    {
      w3 : {
        title,
        lead,
        teaser,
        text,
        text2,
        primary_text,
        secondary_text,
        article_type,
        promote,
        url,
        url_string,
        search_description,
        date: {
          value,
          value2,
        },
        published_timestamp,
        changed,
        location,
        search_keywords,
        language,
        type,
        study_code,
        study_title,
      },
      generic : {
        title,
        link,
        excerpt,
        title_en,
        title_nb,
        link_en,
        link_nb,
        excerpt_en,
        excerpt_nb,
        _searchable_text,
      },
      search_manual_boost,
    }


Generic fields are populated by combining relevant fields for the entity.

The generic field `_searchable_text` should be a field containing all relevant
searchable text from a node.

## Study document stucture in Elastic

{
  w3 : {
    title,
    lead,
    teaser,
    text,
    text2,
    primary_text,
    secondary_text,
    article_type,
    promote,
    url,
    url_string,
    search_description,
    date: {
      value,
      value2,
    },
    published_timestamp,
    changed,
    location,
    search_keywords,
    language,
    type,
    study_code,
    study_title,
  },
  generic : {
    title,
    link,
    excerpt,
    title_en,
    title_nb,
    link_en,
    link_nb,
    excerpt_en,
    excerpt_nb,
    _searchable_text,
  },
  search_manual_boost,
  fs: {
    study_type,
    study_code,
    text_en,
    text_nb.
    credits,
    dicipline_en,
    dicipline_nb,
    excerpt_en,
    excerpt_nb,
    url_en,
    url_nb,
  },
}

## Update document schema in Elasticsearch

The section below is instructive on how to modify your index mappings in
elasticsearch. However, this is most important when setting up a new index from
scratch and during development. It might not be what you need ...

When adding data to Elasticsearch, a mapping schema for the data is created
automatically. This is often nice and correct, but sometimes not what you want.
How to change this mapping is described below.

If you change the mapping for a field in an index, all documents in this
index needs to be reindexed.

Save the current mapping and setting to a files:

    curl -XGET `bin/site-drush uib-search-url --admin`_settings?pretty >settings.txt
    curl -XGET `bin/site-drush uib-search-url --admin`_mapping?pretty >mapping.txt

For the new auth scheme:

    echo "$(bin/site-drush uib-search-curl --admin GET _settings)" |sh > settings.txt
    echo "$(bin/site-drush uib-search-curl --admin GET _mapping)" |sh > mapping.txt


Open `mapping.txt` and `settings.txt` in a text editor and change  to your liking. First
remove the reference to the actual index name (here called `w3myindex`), so:

    {
      "w3myindex" : {
        "mappings" : {
          "node" : {
            "properties" : {
              ...
            }
          }
        }
      }
    }

will be:

    {
      "mappings" : {
        "node" : {
          "properties" : {
            ...
          }
        }
      }
    }

Now edit the mapping and settings to how you need it. Fields that should not be
analyzed can be set to `{ “index”: “not_analyzed” }`, f.ex. url fields.

Now, to make a new index with your new mapping:

Drop the current index:

    bin/site-drush uib-search-drop-index

You need to merge your mapping and your settings file. It should look something like:

{
  "settings": {
    ... settings here ...
  },
  "mappings" : {
    ... mappings here ...
  }
}

Call the file mapping.txt

Create a new index which includes your modified mapping.txt file:

    curl -XPUT `bin/site-drush uib-search-url --admin` --data-binary @mapping.txt

With new auth scheme:

    echo "$(bin/site-drush uib-search-curl --admin PUT /) --data-binary @mapping.txt" |sh

Check your new mapping with

    curl -XGET `bin/site-drush uib-search-url --admin`_mapping?pretty

With new auth scheme:

    echo "$(bin/site-drush uib-search-curl --admin GET _mapping)" |sh

Restore the index. To reindex everything:

    bin/index-all-users
    bin/index-all-studies
    bin/index-all-nodes
