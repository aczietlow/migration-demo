<?php
/**
 * @file
 * Piper Base Migration.
 */

/**
 * Base class to use with all migrations.
 */
class PiperNodeMigration extends DrupalNode6Migration {

  /**
   * The source and destination content types (bundles) we're dealing with.
   */
  protected $destinationType;

  /**
   * Default language to apply to the node and its body field.
   *
   * @var string
   */
  protected $defaultLanguage = LANGUAGE_NONE;

  /**
   * Default format to apply to the node and its body field.
   *
   * @var string
   */
  protected $defaultFormat = 'filtered_html';

  /**
   * Shared migration setup.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);


    $this->team = array(
      new MigrateTeamMember(
        'Chris Zietlow', 'chris.zietlow@zietlow.ninja',
        t('Developer')
      ),
    );

    $this->description = $arguments['description'];

    // Set destination content type.
    $this->destinationType = $arguments['destination'];

    // Define Migration mapping.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Set the node bundle for the destination object.
    $this->nodeOptions = MigrateDestinationNode::options($this->defaultLanguage, $this->defaultFormat);
    $this->destination = new MigrateDestinationNode($this->destinationType);

    // Set the default author to user 1.
    $this->addFieldMapping('uid')
      ->defaultValue(1);
    // Set the title.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('status')
      ->defaultValue(TRUE);
    $this->addFieldMapping('body:language')
      ->defaultValue($this->defaultLanguage);

    $this->addUnmigratedSources(array('uid'), 'DNM');
  }
}
