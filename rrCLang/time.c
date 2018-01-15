/**
 * \file
 * \brief 时间
 * \sa ["Date and time utilities"](http://en.cppreference.com/w/c/chrono). *cppreference.com*.
 * \sa ["what is the difference between difftime and '-'?"](https://stackoverflow.com/questions/13855890/). *Stack Overflow*.
 * \author zhengrr
 * \date 2016-12-2 – 2018-1-15
 * \copyright The MIT License
 */

#include <stdio.h>
#include <time.h>

void ascii_time(void)
{
	time_t curtime;

	time(&curtime);

	printf("ascii_time: %s", ctime(&curtime));
}

int main(void)
{
	return (0);
}
