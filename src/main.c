#include <stdio.h>

#include "database/database.h"
#include "row/row.h"
#include "schema/schema.h"
#include "table/table.h"
#include "value/value.h"

int main(void) {
  Database db;

  // =========================
  // DATABASE
  // =========================

  database_init(&db);

  // =========================
  // CREATE TABLES
  // =========================

  database_create_table(&db, "users");
  database_create_table(&db, "products");

  // =========================
  // USERS TABLE
  // =========================

  Table *users = database_get_table(&db, "users");

  table_add_column(users, "id", TYPE_INT);
  table_add_column(users, "name", TYPE_STR);
  table_add_column(users, "age", TYPE_INT);

  // ---- Row 1 ----

  Row row1;
  row_init(&row1, 3);

  Cell id1;
  Cell name1;
  Cell age1;

  cell_init_int(&id1, 1);
  cell_init_string(&name1, "Oleg");
  cell_init_int(&age1, 20);

  row_set(&row1, 0, &id1);
  row_set(&row1, 1, &name1);
  row_set(&row1, 2, &age1);

  table_add_row(users, &row1);

  // ---- Row 2 ----

  Row row2;
  row_init(&row2, 3);

  Cell id2;
  Cell name2;
  Cell age2;

  cell_init_int(&id2, 2);
  cell_init_string(&name2, "Anna");
  cell_init_int(&age2, 21);

  row_set(&row2, 0, &id2);
  row_set(&row2, 1, &name2);
  row_set(&row2, 2, &age2);

  table_add_row(users, &row2);

  // ---- Row 3 ----

  Row row3;
  row_init(&row3, 3);

  Cell id3;
  Cell name3;
  Cell age3;

  cell_init_int(&id3, 3);
  cell_init_string(&name3, "John");
  cell_init_int(&age3, 25);

  row_set(&row3, 0, &id3);
  row_set(&row3, 1, &name3);
  row_set(&row3, 2, &age3);

  table_add_row(users, &row3);

  // =========================
  // PRODUCTS TABLE
  // =========================

  Table *products = database_get_table(&db, "products");

  table_add_column(products, "id", TYPE_INT);
  table_add_column(products, "title", TYPE_STR);
  table_add_column(products, "price", TYPE_FLOAT);

  // ---- Product 1 ----

  Row product1;
  row_init(&product1, 3);

  Cell product_id1;
  Cell product_title1;
  Cell product_price1;

  cell_init_int(&product_id1, 1);
  cell_init_string(&product_title1, "Keyboard");
  cell_init_float(&product_price1, 99.99f);

  row_set(&product1, 0, &product_id1);
  row_set(&product1, 1, &product_title1);
  row_set(&product1, 2, &product_price1);

  table_add_row(products, &product1);

  // ---- Product 2 ----

  Row product2;
  row_init(&product2, 3);

  Cell product_id2;
  Cell product_title2;
  Cell product_price2;

  cell_init_int(&product_id2, 2);
  cell_init_string(&product_title2, "Mouse");
  cell_init_float(&product_price2, 49.99f);

  row_set(&product2, 0, &product_id2);
  row_set(&product2, 1, &product_title2);
  row_set(&product2, 2, &product_price2);

  table_add_row(products, &product2);

  // =========================
  // PRINT DATABASE
  // =========================

  printf("========== DATABASE ==========\n\n");

  database_print(&db);

  // =========================
  // CLEANUP TEMPORARY ROWS
  // =========================

  row_free(&row1);
  row_free(&row2);
  row_free(&row3);

  row_free(&product1);
  row_free(&product2);

  // Cells have their own allocated strings,
  // so free them too.
  cell_free(&id1);
  cell_free(&name1);
  cell_free(&age1);

  cell_free(&id2);
  cell_free(&name2);
  cell_free(&age2);

  cell_free(&id3);
  cell_free(&name3);
  cell_free(&age3);

  cell_free(&product_id1);
  cell_free(&product_title1);
  cell_free(&product_price1);

  cell_free(&product_id2);
  cell_free(&product_title2);
  cell_free(&product_price2);

  // =========================
  // FREE DATABASE
  // =========================

  database_free(&db);

  return 0;
}
