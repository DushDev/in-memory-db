#include "schema.h"
#include <stdlib.h>
#include <string.h>

void column_init(Column *col, DataType type, const char *name) {
  col->type = type;
  col->name = malloc(strlen(name) + 1);

  if (col->name == NULL) {
    return;
  }

  strcpy(col->name, name);
}

void column_free(Column *col) { free(col->name); }
