# In-Memory Database

The project was created for study purposes

A small relational database engine written in C from scratch.
The project focuses on understanding memory management, dynamic data structures, pointers, unions, and how a database works internally.

## Architecture

```text
Database
└── Tables
    ├── Schema
    │   └── Columns
    └── Rows
        └── Cells
            └── Values
```

## TODO

### 1. Storage Layer

- [x] Database
- [x] Multiple tables
- [x] Table schema / columns
- [x] Rows
- [x] Cells with multiple data types
- [x] Dynamic arrays
- [x] Deep copying
- [x] Memory cleanup
- [x] Row validation against table schema

### 2. CRUD

- [ ] INSERT
- [ ] SELECT
- [ ] UPDATE
- [ ] DELETE
- [ ] Find rows by condition
- [ ] Column selection

### 3. Query Engine

- [ ] `WHERE`
- [ ] Comparison operators (`=`, `!=`, `<`, `>`, `<=`, `>=`)
- [ ] `AND` / `OR`
- [ ] `ORDER BY`
- [ ] `LIMIT`

### 4. SQL-like CLI

- [ ] Command parser
- [ ] `CREATE TABLE`
- [ ] `INSERT INTO`
- [ ] `SELECT`
- [ ] `UPDATE`
- [ ] `DELETE`
- [ ] Error handling

### 5. Performance

- [ ] Hash index
- [ ] Index lookup
- [ ] Benchmark linear search vs indexed search

### 6. Persistence

- [ ] Save database to file
- [ ] Load database from file
- [ ] Define a binary file format

## Goal

Build a functional mini database engine while learning how memory management, dynamic data structures, data representation, and query processing work at a low level in C.
