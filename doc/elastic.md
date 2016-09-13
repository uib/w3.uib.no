# Search engine based on Elasticsearch

We use the [Elasticsearch service](https://tk.app.uib.no/node/247)
for instant search for persons on uib.no.
[Elasticsearch](https://en.wikipedia.org/wiki/Elasticsearch) is a search
interface built on top of [Apache Lucene](https://lucene.apache.org) that
provide fast and precise search results from large amounts of semi-structured
data.

## Disable frontend search
You can disable the instant search in the uib.no frontend by deleting
variable `uib_elasticsearch_index`, for instance with the command

    bin/site-drush vdel uib_elasticsearch_index

## Setup

Variables for the administrative setup will generally be set up in drupals
settings.php - file:

    $conf['uib_elasticsearch_admin'] = array(
      'index1' => array(
        'url' => 'https://api.search.uib.no',
        'user' => 'w3_admin',
        'password' => '*********',
        'index' => 'w3',
      ),
      'index2' => array(
        'url' => 'https://api.test.search.uib.no',
        'user' => 'w3_2_admin',
        'password' => '*********',
        'index' => 'w3_2',
      ),
    );

...while the read only setup can be set in the database using variable_set

    bin/site-drush ev '
    $arr = array(
      "index1" => array(
        "url" => "https://api.search.uib.no",
        "user" => "w3",
        "password" => "*********",
        "index" => "w3",
      ),
      "index2" => array(
        "url" => "https://api.test.search.uib.no",
        "user" => "w3_2",
        "password" => "*********",
        "index" => "w3_2",
      ),
    );
    variable_set("uib_elasticsearch", $arr);
    '

The variables `uib_elasticsearch_useindex` and
`uib_elasticsearch_useindex_admin` determine which index to use. Default
for these are 'index1'. You can set these using drush

  `bin/site-drush vset uib_elasticsearch_useindex index2`
  `bin/site-drush vset uib_elasticsearch_useindex_admin index2`

If you don't have a database available visit
[token.test.search.uib.no](https://token.test.search.uib.no) (testing) or
[token.search.uib.no](https://token.search.uib.no) (production)
and fill in the variables from the values it provide you after you
create a new index.

The admin-variables are defined in settings.php on the production system, to
prevent these values from leaking to development systems when running
`bin/site-prod-reset`.

You can list the currently set variable with
`bin/site-drush vget elastic`.
You can change variable values with
`bin/site-drush vset <variablename> <variablevalue>`.

## Drush functionality

There is functionality available from drush to manage
indexing. The following commands are useful when working with the search index

    bin/site-drush vget elastic           # list all current variables
                                          # for elasticsearch.
    bin/site-drush help | grep uib-search # list drush commands on
                                          # uib_search module

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
      position_en,
      alt_position_en,
      competence_en,
      link_en,
      ou_nb,
      position_nb,
      competence_nb,
      link_nb
      generic : {
        title,
        link,
        excerpt,
        title_en,
        link_en,
        excerpt_en,
        title_nb,
        link_nb,
        excerpt_nb,
        image,
      },
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
      },
      generic : {
        title,
        link,
        excerpt,
        _searchable_text,
      }
    }

Generic fields are populated by combining relevant fields for the entity.

The generic field `_searchable_text` should be a field containing all relevant
searchable text from a node.

## Update document schema in Elasticsearch

When adding data to Elasticsearch, a mapping schema for the data is created
automatically. This is often nice and correct, but sometimes not what you want.
How to change this mapping is described below.

If you change the mapping for a field in an index, all documents in this
index needs to be reindexed.

Save the current mapping to a file (mapping.txt):

    curl -XGET `bin/site-drush uib-search-url --admin`_mapping?pretty >mapping.txt

Open `mapping.txt` in a text editor and change the mapping to your liking. First
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

Now edit the mapping to how you need it. Fields that should not be analyzed can
be set to `{ “index”: “not_analyzed” }`, f.ex. url fields.

Now, to make a new index with your current mapping:

Drop the current index:

    bin/site-drush uib-search-drop-index

Create a new index which includes your modified mapping.txt file:

    curl -XPUT `bin/site-drush uib-search-url --admin` --data-binary <mapping.txt

Check your new mapping with

    curl -XGET `bin/site-drush uib-search-url --admin`_mapping?pretty

Restore the index. This depends on what content was actually in the index. The
code below will index all users in w3, in batches of 1000.

    bin/site-drush vset uib_search_last_processed_user 0
    for i in {1..10}; do bin/site-drush uib-search-index user --stop=1000 -v; done
