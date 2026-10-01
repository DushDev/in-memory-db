#include <stdio.h>

#include "database/database.h"
#include "row/row.h"
#include "table/table.h"
#include "value/value.h"

int main(void) {
  Database db;
  database_init(&db);

  // Create users table
  database_create_table(&db, "users");

  Table *users = database_get_table(&db, "users");

  table_add_column(users, "id", TYPE_INT);
  table_add_column(users, "name", TYPE_STR);
  table_add_column(users, "age", TYPE_INT);

  // --------------------------------
  // Test 1: valid row
  // --------------------------------

  Row row1;
  row_init(&row1, 3);

  Cell id1;
  Cell name1;
  Cell age1;

  cell_init_int(&id1, 1);
  cell_init_string(&name1, "Peter");
  cell_init_int(&age1, 20);

  row_set(&row1, 0, &id1);
  row_set(&row1, 1, &name1);
  row_set(&row1, 2, &age1);

  printf("Test 1 - valid row: ");

  if (table_validate_row(users, &row1)) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }

  table_add_row(users, &row1);

  cell_free(&id1);
  cell_free(&name1);
  cell_free(&age1);
  row_free(&row1);

  // --------------------------------
  // Test 2: wrong type
  // --------------------------------

  Row row2;
  row_init(&row2, 3);

  Cell id2;
  Cell name2;
  Cell age2;

  cell_init_int(&id2, 2);
  cell_init_int(&name2, 123); // WRONG: should be STRING
  cell_init_int(&age2, 25);

  row_set(&row2, 0, &id2);
  row_set(&row2, 1, &name2);
  row_set(&row2, 2, &age2);

  printf("Test 2 - wrong type: ");

  if (!table_validate_row(users, &row2)) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }

  table_add_row(users, &row2);

  cell_free(&id2);
  cell_free(&name2);
  cell_free(&age2);
  row_free(&row2);

  // --------------------------------
  // Test 3: wrong number of cells
  // --------------------------------

  Row row3;
  row_init(&row3, 2);

  Cell id3;
  Cell name3;

  cell_init_int(&id3, 3);
  cell_init_string(&name3, "Anna");

  row_set(&row3, 0, &id3);
  row_set(&row3, 1, &name3);

  printf("Test 3 - wrong number of cells: ");

  if (!table_validate_row(users, &row3)) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }

  table_add_row(users, &row3);

  cell_free(&id3);
  cell_free(&name3);
  row_free(&row3);

  // --------------------------------
  // Print database
  // --------------------------------

  printf("\nDatabase:\n");
  database_print(&db);

  database_free(&db);

  return 0;
}
