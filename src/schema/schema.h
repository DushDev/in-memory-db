#ifndef SCHEMA_H
#define SCHEMA_H

typedef enum {
  TYPE_INT,
  TYPE_STR,
  TYPE_FLOAT,
} DataType;

typedef struct {
  DataType type;
  char *name;
} Column;

void column_init(Column *col, DataType type, const char *name);
void column_free(Column *col);
#endif
