<?php
/**
 * @file
 * Piper Series Item Migration.
 *
 * @copyright (C) Copyright 2015 New Valley Media.
 */

/**
 * Piper %Page% Node Migration.
 */
class PiperNewsMigration extends PiperNodeMigration {

  /**
   * Constructs the Node Migration.
   *
   * @param array $arguments
   *   Options passed in when the migration is defined. See hook_migrate_api().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);


    $this->addSoftDependencies($arguments['soft_dependencies']);
    $this->addFieldMapping('field_description', 'description');
    $this->addFieldMapping('field_description:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_listing_position', 'position');
    $this->addFieldMapping('field_summary', 'summary');
    $this->addFieldMapping('changed', 'last_updated');
    $this->addFieldMapping('promote')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_landing_page', 'landing_page')
      ->callbacks(array($this, 'termNameToID'));

    $this->addFieldMapping(NULL, 'url')
      ->issueGroup(t('wip'));
  }

  /**
   * Overrides Migration::prepareRow().
   *
   * This method is called from the source
   * plugin upon first pulling the raw data from the source.
   *
   * @param object $row
   *   Object containing raw source data.
   *
   * @return bool
   *   TRUE to process this row, FALSE to have the source skip it.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    return TRUE;
  }
}
