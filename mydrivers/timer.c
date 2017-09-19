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


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h> 
#include <sys/param.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
void init_deamon(void) 
{ 
    int pid; 
    int i;

    if(signal(SIGCHLD,SIG_IGN) == SIG_ERR){
        printf("Cant signal in init_daemon.");
        exit(1);
    }
    if(pid=fork()) 
        exit(0);//是父进程，结束父进程 
    else if(pid< 0){ 
        perror("fail to fork1");
        exit(1);//fork失败，退出
    }
    setsid();//第一子进程成为新的会话组长和进程组长 
    //并与控制终端分离 
    if(pid=fork()) 
        exit(0);//是第一子进程，结束第一子进程 
    else if(pid< 0) 
        exit(1);//fork失败，退出 
    //是第二子进程，继续 
    //第二子进程不再是会话组长 

    for(i=0;i< getdtablesize();++i)//关闭打开的文件描述符 
        close(i); 
    chdir("/tmp");//改变工作目录到/tmp 
    umask(0);//重设文件创建掩模 
    return; 
}


int main()
{
int fd;
int counter=0;
int last_count=0;
init_deamon();
fd=open("/dev/timer_dev",O_RDWR);
if(fd<0)
{
	printf("open file failed\n");
	exit(1);
}
while(1){ 
	read(fd,&counter,sizeof(int));
	if(counter!=last_count)
   	 {
     	printf("second=%d\n",counter);
     	last_count=counter;
   	 }

 	 }
return;
}
