# Search engine based on Elastic search

uib.no uses [Elasticsearch](https://www.elastic.co/products/elasticsearch)
backend for instant search for persons on uib.no. Elasticsearch is a search
interface built on top of [Apache Lucene](https://lucene.apache.org)
provide fast and precise search results from large amounts of semi-structured
data.

# Disable frontend search
You can disable the instant search in the uib.no frontend by deleting
variable uib\_elasticsearch\_index (./bin/site-drush vdel uib\_elasticsearch\_index)

# Setup
The following variables need to be set to allow the search to work.

* uib\_elasticsearch\_index - The index used as a base for all searches
* uib\_elasticsearch\_url - Base url for the search index.
* uib\_elasticsearch\_user - Read only user to the search index
* uib\_elasticsearch\_password - Password for read only user

The following variables need to be setup to allow indexing of documents, and
drush commands to work

* uib\_elasticsearch\_admin\_index - Index used as a base for indexing documents
* uib\_elasticsearch\_admin\_url - Base url used when indexing documents
* uib\_elasticsearch\_admin\_user - User with administration rights for index
* uib\_elasticsearch\_admin\_password - Password for admin user

Test index can be created on https
should be created on https

On the production system, the index and url will usually be the same for both
admin and read only, while this can differ on development systems.

The admin-variables are defined in settings.php on the production system, to
prevent these values from leaking to development systems when running
bin/site-prod-reset.

You can list the currently set variable with
bin/site-drush vget elastic

You can change readonly variables with
bin/site-drush vset variablename variablevalue

# Drush functionality
There is functionality available in the site-drush - interface to manage
indexing. The functionality depends on some variable settings in drupal. The
following commands are useful when working with the search index

bin/site-drush vget elastic           \# list all current variables for
                                      \# elasticsearch.
bin/site-drush help | grep uib-search \# list drush commands on uib\_search
                                      \# module

# User document structure in elastic

The current document structure, as json, of indexed users
<pre>
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
</pre>
