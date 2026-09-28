#include "../value/value.h"
#include <stdlib.h>

#ifndef ROW_H
#define ROW_H
typedef struct {
  Cell *cells;
  size_t size;
  size_t capacity;
} Row;

void row_init(Row *row, size_t capacity);
void row_set(Row *row, size_t index, const Cell *cell);
void row_print(const Row *row);
void row_free(Row *row);

void cell_copy(Cell *dest, const Cell *src);
#endif
