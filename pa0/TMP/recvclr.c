/* recvclr.c - recvclr */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include "lab0.h"

/*------------------------------------------------------------------------
 *  recvclr  --  clear messages, returning waiting message (if any)
 *------------------------------------------------------------------------
 */
extern unsigned long ctr1000;
SYSCALL	recvclr()
{
	unsigned long start = ctr1000;
	if(flag==2){
		sysFreq[currpid][7]++;
	}
	STATWORD ps;    
	WORD	msg;

	disable(ps);
	if (proctab[currpid].phasmsg) {
		proctab[currpid].phasmsg = 0;
		msg = proctab[currpid].pmsg;
	} else
		msg = OK;
	restore(ps);
	unsigned long stop = ctr1000 - start;
	if(flag==2){
		sysTime[currpid][7] = sysTime[currpid][7] + stop;
	}
	return(msg);
}
