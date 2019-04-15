#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int i;
    int wtime;
    int totwtime;
    int rtime;
    int totrtime;
    int iotime;
    int totiotime;
    int status;
    int p[20];

    for (i = 0; i < 20; i++)
    {
        p[i] = fork();
        if (p[i] > 0)
        {
            continue;
        }
        int j;
        for (j = 0; j < 10000000; j++)
        {
        }
        exit();
    }

    while (wait_stat(&wtime, &rtime, &iotime, &status) != -1)
    {

        for (i = 0; i < 20; i++)
        {
            if (status == p[i])
            {
                printf(1, "Child pid: %d, wait time: %d, running time: %d, turnaround time: %d\n", status, wtime, rtime, wtime + rtime + iotime);

                totwtime += wtime;
                totrtime += rtime;
                totiotime += iotime;
            }
        }
    }

    printf(1, "average wait time: %d, average run time: %d, average turnaround time: %d", totwtime / 20, totrtime / 20, (totiotime + totwtime + totrtime) / 20);
    exit();
}