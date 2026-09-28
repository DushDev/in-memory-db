#ifndef TABLE_H
#define TABLE_H

#include "../row/row.h"
#include "../schema/schema.h"
#include <stddef.h>

typedef struct {
  char *name;

  Column *columns;
  size_t column_count;

  Row *rows;
  size_t row_count;
  size_t row_capacity;
} Table;

void table_init(Table *table, const char *name);

void table_add_column(Table *table, const char *name, DataType type);

void table_add_row(Table *table, const Row *row);

void table_print(const Table *table);

void table_free(Table *table);

#endif
