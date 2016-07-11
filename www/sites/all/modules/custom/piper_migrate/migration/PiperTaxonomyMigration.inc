<?php
/**
 * @file
 * TRPDC Taxonomy Migration.
 */

/**
 * Piper Taxonomy Migration.
 */
class PiperTaxonomyMigration extends PiperMigration {

  /**
   * Constructs the Taxonomy Migration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    // Defaults to mapping to 'tags' vocabulary if the source vocabulary can't
    // be found.
    $this->destination = new MigrateDestinationTerm($arguments['destination']);

    // Define Migration mapping.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // Import terms to their declared vocabulary.
    $this->addFieldMapping('vocabulary_machine_name', 'vocabulary');
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('parent_name', 'parent');
    $this->addFieldMapping('weight', 'weight');
  }
}