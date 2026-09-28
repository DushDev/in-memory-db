#include "row.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void row_init(Row *row, size_t capacity) {
  row->cells = (Cell *)malloc(capacity * sizeof(Cell));
  row->size = 0;
  row->capacity = capacity;
}

void row_set(Row *row, size_t index, const Cell *cell) {
  if (index >= row->capacity) {
    size_t new_capacity = row->capacity == 0 ? 2 : row->capacity * 2;

    while (index >= new_capacity) {
      new_capacity *= 2;
    }

    Cell *new_cells = realloc(row->cells, new_capacity * sizeof(Cell));

    if (new_cells == NULL) {
      return;
    }

    row->cells = new_cells;
    row->capacity = new_capacity;
  }

  cell_copy(&row->cells[index], cell);

  if (index >= row->size) {
    row->size = index + 1;
  }
}

void row_print(const Row *row) {
  for (size_t i = 0; i < row->size; i++) {
    cell_print(&row->cells[i]);
    if (i < row->size - 1) {
      printf(" | ");
    }
  }
  printf("\n");
}

void row_free(Row *row) {
  for (size_t i = 0; i < row->size; i++) {
    cell_free(&row->cells[i]);
  }

  free(row->cells);

  row->cells = NULL;
  row->size = 0;
  row->capacity = 0;
}

void cell_copy(Cell *dest, const Cell *src) {
  dest->type = src->type;

  switch (src->type) {
  case TYPE_INT:
    dest->value.int_val = src->value.int_val;
    break;

  case TYPE_FLOAT:
    dest->value.float_val = src->value.float_val;
    break;

  case TYPE_STR:
    dest->value.str_val = malloc(strlen(src->value.str_val) + 1);

    if (dest->value.str_val != NULL) {
      strcpy(dest->value.str_val, src->value.str_val);
    }
    break;
  }
}
