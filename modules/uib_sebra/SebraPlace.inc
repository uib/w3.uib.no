<?php
/**
 * @file
 * Information about a UiB organisation unit obtained from Sebra.
 */
class SebraPlace extends stdClass {

  /**
   * Construct a new SebraPlace object.
   *
   * The object will have the attributes 'name', 'address', 'postbox',
   * 'postcode', 'postarea', 'phone', 'fax', 'alias', 'maildomain'.
   *
   * @param $id
   *    The place code.  It's a 6-digit number.  For instance '221000'
   *    represent the IT-department.
   */
  public function __construct($id) {
    if (strlen($id) != 6) {
      throw new Exception("Place id $id is invalid (needs to be 6 digits)");
    }
    if ($id == '000000') {
      $this->id = $id;
      $this->name = "Universitetet i Bergen";
      $this->address = '';
      $this->postbox = '7800';
      $this->postcode = '5020';
      $this->phone = '+47 55580000';
      $this->fax = NULL;
      $this->alias = 'UiB';
      $this->maildomain = 'uib.no';
      return;
    }
    $place = uib_sebra__sws_get('place?code=' . $id);
    if (empty($place)) {
      throw new Exception("Place $id not found");
    }
    $this->id = $id;
    $this->name = (string)$place->name;
    $this->address = (string)$place->address;
    $this->postbox = (string)$place->postboks;
    $this->postcode = (string)$place->postnr;
    $this->postarea = (string)$place->postcode;
    $this->phone = (string)$place->tlf;
    $this->fax = (string)$place->fax;
    $this->alias = (string)$place->alias;
    $this->maildomain = (string)$place->maildomain;

    // Instead of empty strings we get the string "None" leaked
    // for the NULL attributes.  Sometimes we also get "na".
    foreach ($this as $key => $value) {
      if ($value == "None" || $value == "na") {
        $this->$key = NULL;
      }
      elseif ($value == 0 && ($key == 'phone' || $key == 'fax')) {
        $this->$key = NULL;
      }
    }

    if ($this->phone)
      $this->phone = '+47 ' . $this->phone;
    if ($this->fax)
      $this->fax = '+47 ' . $this->fax;
  }
}
