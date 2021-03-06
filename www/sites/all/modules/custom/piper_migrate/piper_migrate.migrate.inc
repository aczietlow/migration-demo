<?php
/**
 * @file
 * Migrate module file.
 */

/**
 * Implements hook_migrate_api().
 */
function piper_migrate_migrate_api() {
  // Migrate_d2d arguments.
  $common_arguments = array(
    'source_connection' => 'piper_legacy',
    'source_version' => 6,
  );

  $api = array(
    'api' => 2,
    'groups' => array(
      'node' => array(
        'title' => t('Node Migrations'),
      ),
      'taxonomy' => array(
        'title' => t('Taxonomy Migrations'),
      ),
    ),
    'migrations' => array(
      'PiperTaxonomy' => array(
        'class_name' => 'PiperTaxonomyMigration',
        'group_name' => 'taxonomy',
        'source' => 'taxonomy_terms.csv',
        'destination' => 'tags',
        'description' => t('Migrate Taxonomy terms into vocabularies'),
      ),
      'PiperNews' => $common_arguments + array(
        'class_name' => 'PiperNewsMigration',
        'group_name' => 'node',
        'source' => 'news_content.csv',
        'destination' => 'news',
        'description' => t('Migrate News content'),
        'soft_dependencies' => array('PiperTaxonomy'),
      ),
      'PiperPage' => $common_arguments + array(
        'class_name' => 'PiperPageMigration',
        'group_name' => 'node',
        'source' => 'page_content.csv',
        'destination' => 'news',
        'description' => t('Migrate News content'),
      ),
      // D2D Migration.
      'PiperFile' => $common_arguments + array(
        'class_name' => 'DrupalFile6Migration',
        'group_name' => 'file',
        'default_uid' => 1,
        'source_dir' => 'http://piper-legacy.edu',
        'destination_dir' => 'public://legacy_files',
        'description' => t('Migrate Old Piper Managed files.'),
      ),
    ),
  );
  return $api;
}
