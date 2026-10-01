#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void table_init(Table *table, const char *name) {
  table->name = malloc(strlen(name) + 1);

  if (table->name == NULL) {
    return;
  }

  strcpy(table->name, name);

  table->columns = NULL;
  table->column_count = 0;

  table->rows = malloc(10 * sizeof(Row));
  table->row_count = 0;
  table->row_capacity = 10;
}

void table_add_column(Table *table, const char *name, DataType type) {
  Column *new_columns =
      realloc(table->columns, (table->column_count + 1) * sizeof(Column));

  if (new_columns == NULL) {
    return;
  }

  table->columns = new_columns;

  column_init(&table->columns[table->column_count], type, name);

  table->column_count++;
}

void table_add_row(Table *table, const Row *row) {
  if (!table_validate_row(table, row)) {
    printf("Error: invalid row\n");
    return;
  }

  if (row->size != table->column_count) {
    printf("Error: row has %zu cells, but table expects %zu\n", row->size,
           table->column_count);
    return;
  }

  if (table->row_count == table->row_capacity) {
    size_t new_capacity =
        table->row_capacity == 0 ? 2 : table->row_capacity * 2;

    Row *new_rows = realloc(table->rows, new_capacity * sizeof(Row));

    if (new_rows == NULL) {
      return;
    }

    table->rows = new_rows;
    table->row_capacity = new_capacity;
  }

  Row *new_row = &table->rows[table->row_count];

  row_init(new_row, row->size);

  for (size_t i = 0; i < row->size; i++) {
    row_set(new_row, i, &row->cells[i]);
  }

  new_row->size = row->size;

  table->row_count++;
}

void table_print(const Table *table) {
  printf("Table: %s\n", table->name);

  if (table->column_count == 0) {
    printf("(no columns)\n");
    return;
  }

  // Print column names
  for (size_t i = 0; i < table->column_count; i++) {
    printf("%s", table->columns[i].name);

    if (i < table->column_count - 1) {
      printf(" | ");
    }
  }

  printf("\n");

  // Print rows
  for (size_t i = 0; i < table->row_count; i++) {
    const Row *row = &table->rows[i];

    for (size_t j = 0; j < row->size; j++) {
      cell_print(&row->cells[j]);

      if (j < row->size - 1) {
        printf(" | ");
      }
    }

    printf("\n");
  }
}

void table_free(Table *table) {
  for (size_t i = 0; i < table->column_count; i++) {
    column_free(&table->columns[i]);
  }

  free(table->columns);

  for (size_t i = 0; i < table->row_count; i++) {
    row_free(&table->rows[i]);
  }

  free(table->rows);

  free(table->name);

  table->name = NULL;
  table->columns = NULL;
  table->rows = NULL;

  table->column_count = 0;
  table->row_count = 0;
  table->row_capacity = 0;
}

int table_validate_row(const Table *table, const Row *row) {
  if (row->size != table->column_count) {
    return 0;
  }

  for (size_t i = 0; i < row->size; i++) {
    if (row->cells[i].type != table->columns[i].type) {
      return 0;
    }
  }

  return 1;
}
