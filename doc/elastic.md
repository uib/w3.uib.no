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
