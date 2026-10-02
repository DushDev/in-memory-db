#ifndef DATABASE_H
#define DATABASE_H

#include "../table/table.h"

typedef struct {
  Table *tables;
  size_t table_count;
  size_t table_capacity;
} Database;

void database_init(Database *db);

void database_create_table(Database *db, const char *name);

Table *database_get_table(Database *db, const char *name);

void database_print(const Database *db);

void database_free(Database *db);

void database_insert(Database *db, const char *table_name, const Row *row);

#endif
