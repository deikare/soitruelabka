#include <lib.h>
#include <stdio.h>
#include <stdlib.h>

int addtoprocnr(int);
int getprocnr(void);
int getprocgroup(void);
int set_scheduler(int);

int main(int argc, char* argv[]) {
    int i = 0;
    int j = 0;
    int pid = getprocnr();
    printf("PID = %d, grupa = %d \n", pid, pid % 2); 
    /* set_scheduler(atoi(argv[1])); */
    while(1);
}

int addtoprocnr(int arg) {
    message msg;
    msg.m2_l2 = arg;
    return(_syscall(MM, ADDTOPROCNR, &msg));
}

int getprocnr(void) {
    message msg;
    return(_syscall(MM, GETPROCNR, &msg));
}

int getprocgroup(void) {
    message msg;
    msg.m1_i1 = getprocnr();
    return(_syscall(MM, GETPROCGROUP, &msg));
}

int set_scheduler(int speed) {
    message msg;
    msg.m2_l2 = speed;
    return(_syscall(MM, SETSCHEDULER, &msg));
}
