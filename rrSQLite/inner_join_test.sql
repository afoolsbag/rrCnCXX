-- 内联查询示例
-- zhengrr
-- 2019-08-02 – 2019-08-02
-- Unlicense

--------------------------------------------------------------------------------
-- 表 rrsqltest_entity

-- [PostgreSQL `DROP TABLE`](https://postgresql.org/docs/current/sql-droptable.html)
-- [SQLite     `DROP TABLE`](https://sqlite.org/lang_droptable.html)
DROP TABLE IF EXISTS rrsqltest_entity;

-- [PostgreSQL `CREATE TABLE`](https://postgresql.org/docs/current/sql-createtable.html)
-- [SQLite     `CREATE TABLE`](https://sqlite.org/lang_createtable.html)
-- [PostgreSQL `Data Types`](https://postgresql.org/docs/current/datatype.html)
-- [SQLite     `Data Types`](https://sqlite.org/datatype3.html)
CREATE TABLE rrsqltest_entity (
    id   INTEGER PRIMARY KEY,
    name TEXT    NOT NULL
);

-- [PostgreSQL `INSERT`](https://postgresql.org/docs/current/sql-insert.html)
-- [SQLite     `INSERT`](https://sqlite.org/lang_insert.html)
INSERT INTO rrsqltest_entity (id, name)
VALUES (1, 'SMT'),
       (2, 'ZL'),
       (3, 'JT');

--------------------------------------------------------------------------------
-- 表 rrsqltest_property

DROP TABLE IF EXISTS rrsqltest_property;

CREATE TABLE rrsqltest_property (
    id        INTEGER PRIMARY KEY,
    entity_id INTEGER,
    name      TEXT,
    value     TEXT
);

INSERT INTO rrsqltest_property (id, entity_id, name, value)
VALUES (1, 1, 'nick', 'MT'),
       (2, 1, 'some', ''),
       (3, 2, 'nick', 'L'),
       (4, 2, 'some', ''),
       (5, 3, 'nick', 'T'),
       (6, 3, 'some', '');

--------------------------------------------------------------------------------
-- 内联查询

-- [PostgreSQL `SELECT`](https://postgresql.org/docs/current/sql-select.html)
-- [SQLite     `SELECT`](https://sqlite.org/lang_select.html)
SELECT e.name  AS name,
       p.name  AS property_name,
       p.value AS property_value
  FROM rrsqltest_entity AS e
       INNER JOIN rrsqltest_property AS p
       ON e.id = p.entity_id
