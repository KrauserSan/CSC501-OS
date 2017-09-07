#include <proc.h>

int flag; 
int sysFreq[NPROC][27];
int sysTime[NPROC][27];
char sysname[27][30];
void printsyscallsummary();
