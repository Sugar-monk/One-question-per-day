/*************************************************************************
*文件名: sig.c
*作者: bean
*邮箱: 17331372728@163.com
* 创建时间: 2019年08月11日 星期日 11时38分52秒
* 备注:
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    //int kill(pid_t pid, int sig);
    //向pid进程发送sig信号
    kill(getpid(), SIGKILL);

    while(1)
    {
        sleep(1);
        printf("我饿了\n");
    }
	return 0;
}

