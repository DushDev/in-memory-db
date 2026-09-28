#include "../schema/schema.h"

#ifndef VALUE_H
#define VALUE_H
typedef union {
  int int_val;
  char *str_val;
  float float_val;
} Value;

typedef struct {
  DataType type;
  Value value;
} Cell;

void cell_init_int(Cell *cell, int value);
void cell_init_float(Cell *cell, float value);
void cell_init_string(Cell *cell, const char *value);

void cell_free(Cell *cell);

void cell_print(const Cell *cell);

#endif
