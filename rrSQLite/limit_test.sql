-- 分页查询示例
-- zhengrr
-- 2019-08-02 – 2019-11-27
-- Unlicense

--
-- 表 rrsqltest_toolong
--

DROP TABLE IF EXISTS rrsqltest_toolong;
CREATE TABLE rrsqltest_toolong (
    id   INTEGER PRIMARY KEY,
    name TEXT    NOT NULL
);

DO
$plpgsql$
    BEGIN
        FOR i IN 1..10000 LOOP
            INSERT INTO rrsqltest_toolong (id, name)
            VALUES (i, concat('value-', i::text));
        END LOOP;
    END
$plpgsql$;

--
-- 分页查询
--

SELECT *
  FROM rrsqltest_toolong
 LIMIT 1000
OFFSET 5000;
