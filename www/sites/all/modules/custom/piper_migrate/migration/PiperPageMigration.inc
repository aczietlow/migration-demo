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
class PiperPageMigration extends PiperNodeMigration {

  /**
   * Constructs the Node Migration.
   *
   * @param array $arguments
   *   Options passed in when the migration is defined. See hook_migrate_api().
   */
  /**
   * Constructs the Basic Page Migration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    // Define Migration Destination.
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('path', 'uri');
  }
}
