drush si standard --site-name=pied-piper --account-name=admin --account-pass=admin -y;drush en piper_migrate -y

## Module Breakdown

import/ - data sampling used in testing.
migration/ - Directory containing all the Piper Migrations.
piper_migrate.info - Loads all class files, tells drupal about the module
piper_migrate.migrate.inc - Handles all the migration class registrations and arguments.
piper_migrate.module - literally does nothing other than satisfy the condition that it must exist.
PiperMigration - Base migration class. Sets state that all other migration classes will use
PiperNodeMigration - Base migration class for all Node migrations.