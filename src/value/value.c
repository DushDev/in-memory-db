#include "value.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cell_init_int(Cell *cell, int value) {
  cell->type = TYPE_INT;
  cell->value.int_val = value;
}

void cell_init_string(Cell *cell, const char *value) {
  cell->type = TYPE_STR;

  cell->value.str_val = malloc(strlen(value) + 1);

  if (cell->value.str_val != NULL) {
    strcpy(cell->value.str_val, value);
  }
}

void cell_init_float(Cell *cell, float value) {
  cell->type = TYPE_FLOAT;
  cell->value.float_val = value;
}

void cell_free(Cell *cell) {
  if (cell->type == TYPE_STR) {
    free(cell->value.str_val);
  }
}

void cell_print(const Cell *cell) {
  switch (cell->type) {
  case TYPE_INT:
    printf("%d", cell->value.int_val);
    break;
  case TYPE_FLOAT:
    printf("%f", cell->value.float_val);
    break;
  case TYPE_STR:
    printf("%s", cell->value.str_val);
    break;
  }
}
