# Adding an UiB article type

Articles (uib\_article) have a field (field\_uib\_article\_type) that distinguish article types. It is a list (text) field with an allowed values list, one value pair for each article type.

To add a new article type:

## 1. Edit the field\_uib\_article\_type

~/en/admin/structure/types/manage/uib-article/fields/field\_uib\_article\_type

Add the new article type at the end of the "Allowed values list", and save settings.

## 2. Manage node edit form fields

The node edit form for articles has been fixed to show a partially different set of fields depending on article type. This is done in code in an implementation of hook\_form\_alter in the uib\_article.module (uib\_article\_form\_alter).

The form api for managing the field states (visible, required etc) can be tricky to handle. But when adding a new article type, there is a good chance that existing structures may be changed rather than new added. Most of the current code relates to the "event" article type.

For a field "fieldname", look for $form[fieldname]['#states'].

The following example will make the "field\_uib\_contacts" field visible if the article type is "event" or "phd\_press\_release":

<code>
<pre>
    $form['field_uib_contacts']['#states'] = array(
      'visible' => array(
        ':input[name="field_uib_article_type[und]"]' => array(
          array('value' => 'event'),
          array('value' => 'phd_press_release'),
        ),
      ),
    );
</pre>
</code>

For more information on state handing in the Drupal form api, see:

https://api.drupal.org/api/drupal/developer!topics!forms\_api\_reference.html/7#states

https://api.drupal.org/api/drupal/includes!common.inc/function/drupal\_process\_states/7

## 3. Update the uib\_area feature

<code>
  bin/site-drush features-update -y uib\_area
</code>

## 4. Commit the changes

Note that the feature change is in the uib\_area module, while the code change is in the uib\_article.module.
