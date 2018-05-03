#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	time1 = localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	printf("size compare\n");
	(int)stat1.st_size> (int)stat2.st_size) ? printf("text1 is bigger\n"); : printf("text2 is bigger\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	printf("block compare\n");
	(int)stat1.st_blocks> (int)stat2.st_blocks) ? printf("text1 is bigger\n"); : printf("text2 is bigger\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	printf("date compare\n");
	if (time1->tm_mon < time2->tm_min)
		printf("text2 is early\n\n");
	else if (time1->tm_mon > time2->tm_min)
		printf("text1 is early\n\n");
	else
	{
		if(time1->tm_mday < time2->tm_mday)
			printf("text2 is early\n\n");
		else if (time1->tm_mday > time2->tm_mday)
			printf("text1 is early\n\n");
		else
			printf("same date\n\n");
	}
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	printf("time compare\n");
	if (time1->tm_hour < time2->tm_hour)
		printf("text2 is early\n\n")
	else if (time1->tm_hour > time2->tm_hour)
		printf("text1 is early\n\n")
	else
	{
		if(time1->tm_min < time2->tm_min)
			printf("text2 is early\n\n")
		else if (time1->tm_min > time2->tm_min)
			printf("text1 is early\n\n")
		else
			printf("same time\n\n")
	}
}
