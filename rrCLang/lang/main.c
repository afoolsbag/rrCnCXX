/**
 * \file
 * \brief 主函数
 * \sa \ref p_main
 * \author zhengrr
 * \date 2016-10-9 – 2018-1-22
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \page p_main
 * \section sec_motherboard 主板
 * \sa ["电脑主板主要由那些部分组成，它们的作用是什么？"](https://zhihu.com/question/59272639). *知乎*.
 */

/**
 * \page p_main
 * \section sec_cpu_vs_gpu 中央处理器与图形处理器的异同
 * \sa ["CPU 和 GPU 的区别是什么？"](https://zhihu.com/question/19903344). *知乎*.
 */

/**
 * \page p_main
 * \section sec_endianness 字节序
 * \sa ["大小端字节序存在的意义，为什么不用一个标准呢？"](https://zhihu.com/question/25311159). *知乎*.
 */

/**
 * \brief 主函数
 * \param argc 参数计数（argument count）
 * \param argv 参数矢量（argument vector）
 * \return 退出状态（exit status）
 * \sa ["Main function"](http://en.cppreference.com/w/c/language/main_function). *cppreference.com*.
 */
int main(int argc, char *argv[])
{
	printf("hello, world\n");
	return EXIT_SUCCESS;
}
