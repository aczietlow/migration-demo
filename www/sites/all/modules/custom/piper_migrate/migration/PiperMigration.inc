<?php
/**
 * @file
 * Piper Base Migration.
 *
 */

/**
 * Base class to use with all migrations.
 */
class PiperMigration extends Migration {

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

    // Define Migration description from arguments set in migrate.inc.
    $this->description = $arguments['description'];

    // Define Migration source from arguments set in migrate.inc.
    $this->dataSource = $arguments['source'];

    // Define Migration source.
    $this->source = new MigrateSourceCSV(
      $this->getImportPath($this->dataSource),
      array(),
      array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE)
    );

    // Set the default author to user 1.
    $this->addFieldMapping('uid')
      ->defaultValue(1);

    // Deal with issues with csv line endings.
    ini_set('auto_detect_line_endings', TRUE);
  }

  /**
   * Gets the full file path for the CSVs to be imported.
   *
   * @return string
   *   The full file path for the directory containing the CSVs to be imported.
   *
   * @throws \MigrateException if can not locate import file.
   */
  protected function getImportPath($data_source) {
    $path = DRUPAL_ROOT . '/' . drupal_get_path('module', 'piper_migrate') . '/import/' . $data_source;
    if (file_exists($path)) {
      return $path;
    }

    throw new MigrateException(
      t("The data source %source doesn't exist or has not been set properly.",
        array('%source' => $data_source)));
  }
}
