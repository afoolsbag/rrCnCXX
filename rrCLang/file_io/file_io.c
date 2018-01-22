/**
 * \file
 * \brief 输入输出
 * \sa ["File input/output"](http://en.cppreference.com/w/c/io). *cppreference.com*.
 * \author zhengrr
 * \date 2016-11-14 – 2018-1-17
 * \copyright The MIT License
 */

#include <stdbool.h>
#include <stdio.h>

/**
 * \brief 打开文件
 * \sa ["fopen"](http://cplusplus.com/reference/cstdio/fopen/). *C++ Reference*.
 * \sa ["fclose"](http://cplusplus.com/reference/cstdio/fclose/). *C++ Reference*.
 * \sa ["fopen, fopen_s"](http://en.cppreference.com/w/c/io/fopen). *cppreference.com*.
 * \sa ["fclose"](http://en.cppreference.com/w/c/io/fclose). *cppreference.com*.
 */
void file_open(void)
{
	FILE *fp = fopen("hello.txt", "a+");
	if (NULL == fp) {
		fprintf(stderr, "file open failed.\n");
		return;
	}

	fclose(fp);
}

/**
 * \brief 文件重打开
 * \sa ["freopen"](http://cplusplus.com/reference/cstdio/freopen/). *C++ Reference*.
 * \sa ["freopen, freopen_s"](http://en.cppreference.com/w/c/io/freopen). *cppreference.com*.
 */
void file_reopen(void)
{
#if false
	freopen("hello.txt", "a+", stdout);
	printf("sweet lovely.\n");
	fclose(stdout);
#endif
}

/**
 * \brief 缓冲
 * \sa ["fflush"](http://cplusplus.com/reference/cstdio/fflush/). *C++ Reference*.
 * \sa ["setbuf"](http://cplusplus.com/reference/cstdio/setbuf/). *C++ Reference*.
 * \sa ["setvbuf"](http://cplusplus.com/reference/cstdio/setvbuf/). *C++ Reference*.
 * \sa ["fflush"](http://en.cppreference.com/w/c/io/fflush). *cppreference.com*.
 * \sa ["setbuf"](http://en.cppreference.com/w/c/io/setbuf). *cppreference.com*.
 * \sa ["setvbuf"](http://en.cppreference.com/w/c/io/setvbuf). *cppreference.com*.
 */
void file_buffer(void) {}

/**
 * \brief 取、放字符
 * \sa ["getchar"](http://cplusplus.com/reference/cstdio/getchar/). *C++ Reference*.
 * \sa ["getc"](http://cplusplus.com/reference/cstdio/getc/). *C++ Reference*.
 * \sa ["putchar"](http://cplusplus.com/reference/cstdio/putchar/). *C++ Reference*.
 * \sa ["putc"](http://cplusplus.com/reference/cstdio/putc/). *C++ Reference*.
 * \sa ["getchar"](http://en.cppreference.com/w/c/io/getchar). *cppreference.com*.
 * \sa ["fgetc, getc"](http://en.cppreference.com/w/c/io/fgetc). *cppreference.com*.
 * \sa ["putchar"](http://en.cppreference.com/w/c/io/putchar). *cppreference.com*.
 * \sa ["fputc, putc"](http://en.cppreference.com/w/c/io/fputc). *cppreference.com*.
 */
void get_put_character(void)
{
#if false
	char ch;
	while (EOF != (ch = (char) getchar()))
		if (EOF == putchar(ch)) {
			fprintf(stderr, "putchar()\n");
			return;
		};

	if (feof(stdin)) {
		if (EOF == puts("End of file reached.")) {
			fprintf(stderr, "puts()\n");
			return;
		}
	} else if (ferror(stdin)) {
		fprintf(stderr, "getchar()\n");
		return;
	}
#endif
}

/**
 * \brief 取、放字符串
 * \sa ["gets"](http://cplusplus.com/reference/cstdio/gets/). *C++ Reference*.
 * \sa ["fgets"](http://cplusplus.com/reference/cstdio/fgets/). *C++ Reference*.
 * \sa ["puts"](http://cplusplus.com/reference/cstdio/puts/). *C++ Reference*.
 * \sa ["fputs"](http://cplusplus.com/reference/cstdio/fputs/). *C++ Reference*.
 * \sa ["gets, gets_s"](http://en.cppreference.com/w/c/io/gets). *cppreference.com*.
 * \sa ["fgets"](http://en.cppreference.com/w/c/io/fgets). *cppreference.com*.
 * \sa ["puts"](http://en.cppreference.com/w/c/io/puts). *cppreference.com*.
 * \sa ["fputs"](http://en.cppreference.com/w/c/io/fputs). *cppreference.com*.
 */
void get_put_string(void)
{
#if false
	char buf[256];

	if (!gets(buf)) {
		if (feof(stdin)) {
			if (EOF == puts("End of file reached.")) {
				fprintf(stderr, "puts()\n");
				return;
			}
		} else {
			fprintf(stderr, "getchar()\n");
			return;
		}

	}

	if (EOF == puts(buf)) {
		fprintf(stderr, "puts()\n");
		return;
	}
#endif
}

/**
 * \brief 格式化扫描（输入）打印（输出）
 * \sa ["scanf"](http://cplusplus.com/reference/cstdio/scanf/). *C++ Reference*.
 * \sa ["printf"](http://cplusplus.com/reference/cstdio/printf/). *C++ Reference*.
 * \sa ["scanf, fscanf, sscanf, scanf_s, fscanf_s, sscanf_s"](http://en.cppreference.com/w/c/io/fscanf). *cppreference.com*.
 * \sa ["printf, fprintf, sprintf, snprintf, printf_s, fprintf_s"](http://en.cppreference.com/w/c/io/fprintf). *cppreference.com*.
 */
void scan_print_formatted(void)
{
#if false
	printf("d: %d, i: %i;\n", 123, 456);
	printf("td: %td;\n", stdout - stderr);
	printf("o: %o, u: %u, x: %x, X: %X;\n", 077u, 99u, 0xffu, 0xFFu);
	printf("zu: %zu;\n", sizeof(int));
	printf("f: %f;\n", 0.7);
	printf("e: %e, E: %E;\n", 0.977, 0.1314569);
	printf("g: %g, G: %G;\n", 0.977, 0.1314569);
	printf("c: %c;\n", 'c');
	printf("s: %s;\n", "string.");
	printf("p: %p;\n", stdout);
#endif
}

/**
 * \brief 移除（文件）
 * \sa ["remove"](http://cplusplus.com/reference/cstdio/remove/). *C++ Reference*.
 * \sa ["remove"](http://en.cppreference.com/w/c/io/remove). *cppreference.com*.
 */
void remove_file(void) {}

/**
 * \brief 重命名（文件）
 * \sa ["rename"](http://cplusplus.com/reference/cstdio/rename/). *C++ Reference*.
 * \sa ["rename"](http://en.cppreference.com/w/c/io/rename). *cppreference.com*.
 */
void rename_file(void) {}

/**
 * \brief 临时文件
 * \sa ["tmpfile"](http://cplusplus.com/reference/cstdio/tmpfile/). *C++ Reference*.
 * \sa ["tmpfile, tmpfile_s"](http://en.cppreference.com/w/c/io/tmpfile). *cppreference.com*.
 */
void temporary_file(void)
{
	FILE *fp = tmpfile();
	if (NULL == fp) {
		fprintf(stderr, "temporary file get failed.\n");
		return;
	}

	fclose(fp);
}

/**
 * \brief 临时文件名
 * \sa ["tmpnam"](http://cplusplus.com/reference/cstdio/tmpnam/). *C++ Reference*.
 * \sa ["tmpnam, tmpnam_s"](http://en.cppreference.com/w/c/io/tmpnam). *cppreference.com*.
 */
void temporary_filename(void)
{
	char name[L_tmpnam] = {'\0'};
	if (!tmpnam(name)) {  /* TMP_MAX */
		fprintf(stderr, "temporary filename get failed.\n");
		return;;
	}
}

int main(void)
{
	/* File access */
	file_open();
	file_reopen();
	file_buffer();

	/* Direct input/output */

	/* Unformatted input/output */
	get_put_character();
	get_put_string();

	/* Formatted input/output */
	scan_print_formatted();

	/* File positioning */

	/* Error handling */

	/* Operations on files */
	remove_file();
	rename_file();
	temporary_file();
	temporary_filename();
}
