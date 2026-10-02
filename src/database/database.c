#include "database.h"
#include "../table/table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void database_init(Database *db) {
  db->tables = NULL;
  db->table_count = 0;
  db->table_capacity = 0;
}

void database_create_table(Database *db, const char *name) {
  if (db->table_count == db->table_capacity) {
    size_t new_capacity = db->table_capacity == 0 ? 2 : db->table_capacity * 2;

    Table *new_tables = realloc(db->tables, new_capacity * sizeof(Table));

    if (new_tables == NULL) {
      return;
    }

    db->tables = new_tables;
    db->table_capacity = new_capacity;
  }

  Table *table = &db->tables[db->table_count];

  table_init(table, name);

  if (table->name == NULL) {
    return;
  }

  db->table_count++;
}

void database_free(Database *db) {
  for (size_t i = 0; i < db->table_count; i++) {
    table_free(&db->tables[i]);
  }

  free(db->tables);

  db->tables = NULL;
  db->table_count = 0;
  db->table_capacity = 0;
}

Table *database_get_table(Database *db, const char *name) {
  for (size_t i = 0; i < db->table_count; i++) {
    if (strcmp(db->tables[i].name, name) == 0) {
      return &db->tables[i];
    }
  }

  return NULL;
}

void database_print(const Database *db) {
  for (size_t i = 0; i < db->table_count; i++) {
    table_print(&db->tables[i]);
  }
}

void database_insert(Database *db, const char *table_name, const Row *row) {
  Table *table = database_get_table(db, table_name);

  if (table == NULL) {
    printf("Error: table '%s' not found\n", table_name);
    return;
  }

  table_add_row(table, row);
}
