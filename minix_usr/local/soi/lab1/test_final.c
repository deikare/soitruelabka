#include <lib.h>
#include <stdio.h>
#include <stdlib.h>

int addtoprocnr(int);
int getprocnr(void);

int main(int argc, char* argv[]) {
    int result, index, sumarg;
    sumarg = atoi(argv[1]);
    result = addtoprocnr(sumarg);
    index = getprocnr();
    printf("nrPID = %d, nrPID + sum_arg: %d + %d = %d\n", index, index, sumarg, result);
    printf("Feel free, to check, if result matches the process table, press ENTER to quit");
    getchar();
    return 0;
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
