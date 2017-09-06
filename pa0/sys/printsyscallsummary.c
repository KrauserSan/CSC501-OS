#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include "lab0.h"

void init();
void syscallsummary_start();
void syscallsummary_stop();

char sysname[27][30] = {"freemem","chprio","getpid","getprio","gettime","kill",
        "receive","recvclr","recvtim","resume","scount","sdelete","send","setdev",
        "setnok","screate","signal","signaln","sleep","sleep10","sleep100","sleep1000",
        "sreset","stacktrace","suspend","unsleep","wait"};
	

void syscallsummary_start(){
	init();
	flag = 1;

}

void syscallsummary_stop(){
	flag = 0;
}

void init(){
	int i;
	int j;
	for(i = 0; i<numproc;i++){
		for(j = 0;j<27;j++){
			sysFreq[i][j] = 0;
		}
	}
	
}

void printsyscallsummary(){
	int i;
	int j;
	for(i = 0; i<NPROC; i++){
		kprintf("Process [pid:%s]\n",proctab[i].pname);
		for(j = 0;j<27;j++){
			kprintf("Syscall: %s, count: %d, average execution time:(ms)\n",
				sysname[j],sysFreq[i][j]);
		}
		
	}
}


