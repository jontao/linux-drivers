/*************************************************************************
	> File Name: timer.c
	> Author: jonta
	> Mail: jonta@foxmail.com 
	> Created Time: Thu 27 Apr 2017 06:53:09 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
int fd;
int i;
int counter=0;
int old_counter=0;
fd=open("/dev/timer_dev",O_RDWR);
if(fd<0)
{
printf("open file error\n");
exit(1);
}
for(i=0;i<30;)//运行30s
  {
  read(fd,&counter,sizeof(int));
 if(counter!=old_counter)
    {
     printf("second=%d\n",counter);
     old_counter=counter;
    i++;
    }

  }
close(fd);
exit (0);

}
