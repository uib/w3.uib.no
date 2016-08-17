# Search engine based on Elasticsearch

We use the [Elasticsearch service](https://tk.app.uib.no/node/247)
for instant search for persons on uib.no.
[Elasticsearch](https://en.wikipedia.org/wiki/Elasticsearch) is a search
interface built on top of [Apache Lucene](https://lucene.apache.org) that
provide fast and precise search results from large amounts of semi-structured
data.

## Disable frontend search
You can disable the instant search in the uib.no frontend by deleting
variable `uib_elasticsearch_index`; for instance with the command `bin/site-drush vdel uib_elasticsearch_index`.

## Setup


The following variables need to be set to allow the search to work.

* `uib_elasticsearch_index` - The index used as a base for all searches
* `uib_elasticsearch_url` - Base url for the search index.
* `uib_elasticsearch_user` - Read only user to the search index
* `uib_elasticsearch_password` - Password for read only user

The following variables need to be setup to allow indexing of documents, and
drush commands to work

* `uib_elasticsearch_admin_index` - Index used as a base for indexing documents
* `uib_elasticsearch_admin_url` - Base url used when indexing documents
* `uib_elasticsearch_admin_user` - User with administration rights for index
* `uib_elasticsearch_admin_password` - Password for admin user

If you don't have a database available visit
[token.search.uib.no](https://token.search.uib.no)
and fill in the variables from the values it provide you after you
create a new index.

On the production system, the index and url will usually be the same for both
admin and read only, while this can differ on development systems.

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

    bin/site-drush vget elastic           # list all current variables for
                                          # elasticsearch.
    bin/site-drush help | grep uib-search # list drush commands on uib_search
                                          # module

## User document structure in elastic

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
        title_en,
        link_en,
        excerpt_en,
        title_nb,
        link_nb,
        excerpt_nb,
        image,
      },
    }


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
