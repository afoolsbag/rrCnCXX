/**
 * \file
 * \brief 整数
 * \sa \ref page_integer
 * \sa ["Integer types"](http://en.cppreference.com/w/c/language/arithmetic_types#Integer_types). *cppreference.com*.
 * \sa ["integer constant"](http://en.cppreference.com/w/c/language/integer_constant). *cppreference.com*.
 * \sa ["Limits of integer types"](http://en.cppreference.com/w/c/types/limits#Limits_of_integer_types). *cppreference.com*.
 * \sa ["Expressions"](http://en.cppreference.com/w/c/language/expressions). *cppreference.com*.
 * \sa ["C Operator Precedence"](http://en.cppreference.com/w/c/language/operator_precedence). *cppreference.com*.
 * \author zhengrr
 * \date 2016-10-9 – 2018-1-15
 * \copyright The MIT License
 */

/**
 * \page page_integer
 * \section sec_declaration_in_c99 C99 中的声明
 *
 * \sa ["Declarations"](http://en.cppreference.com/w/c/language/declarations). *cppreference.com*.
 * \sa ["for loop"](http://en.cppreference.com/w/c/language/for). *cppreference.com*.
 */

/**
 * \page page_integer
 * \section sec_integer_division 整数除法
 *
 * C89 中，
 * 两数同号，值向下截断取整，如 `8/5 === 1`；
 * 两数异号，结果由实现定义，如 `-9/7` 可能为 `-1` 也可能为 `-2`。
 *
 * C99 中，
 * 值向 `0` 截断取整。
 *
 * 如何向上取整？
 * 例如以 `8+(5-1)/5` 替代 `8/5` 即向上取整。
 *
 * \sa ["Division"](http://en.cppreference.com/w/c/language/operator_arithmetic#Division). *cppreference.com*.
 */

/**
 * \page page_integer
 * \section sec_integer_remainder 整数取余
 *
 * C89 中，
 * 两数异号，结果由实现定义，如 `-9%7` 可能为 `-2` 也可能为 `5`。
 *
 * C99 中，
 * 取被除数符号。
 *
 * \sa ["Remainder"](http://en.cppreference.com/w/c/language/operator_arithmetic#Remainder). *cppreference.com*.
 */

// TODO:
// signal
// error
// wchar
// time
