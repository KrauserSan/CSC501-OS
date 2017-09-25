
/* resched.c  -  resched */


#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sched.h>
#include <math.h>


unsigned long currSP;	/* REAL sp of current process */
extern int ctxsw(int, int, int, int);

/*-----------------------------------------------------------------------
 * resched  --  reschedule processor to highest priority ready process
 *
 * Notes:	Upon entry, currpid gives current process id.
 *		Proctab[currpid].pstate gives correct NEXT state for
 *			current process if other than PRREADY.
 *------------------------------------------------------------------------
 */

int resched()
{
	register struct	pentry	*optr;	/* pointer to old process entry */
	register struct	pentry	*nptr;	/* pointer to new process entry */

	optr = &proctab[currpid];


	if(getschedclass() == EXPDISTSCHED){

		int randprio = (int) expdev(0.1);

		if (optr->pstate == PRCURR) {

			optr->pstate = PRREADY;

			insert(currpid,rdyhead,optr->pprio);

		}		

		int head = q[rdyhead].qnext;
		if(firstkey(rdyhead)!=lastkey(rdytail)){
			head = q[head].qnext;
		}

		if(randprio<q[head].qkey){

			nptr = &proctab[ (currpid = dequeue(head)) ];

			nptr->pstate = PRCURR;		/* mark it currently running	*/

		}else if(randprio>lastkey(rdytail)){

			nptr = &proctab[ (currpid = getlast(rdytail))];

			nptr->pstate = PRCURR;		/* mark it currently running	*/

		}else{

			while(q[head].qkey<randprio){

				head = q[head].qnext;

			}
			nptr = &proctab[ (currpid = dequeue(head))];

			nptr->pstate = PRCURR;		/* mark it currently running	*/

		}
	}else if(getschedclass()==LINUXSCHED){
		int i;

		Bool epochflag = TRUE;
		optr->prevsched = TRUE;
		optr->quantum = preempt;
		
		//kprintf("\nProcName:%s\t preempt: %d\n",optr->pname,optr->quantum);

		if (optr->pstate == PRCURR) {
			optr->pstate = PRREADY;
			insert(currpid,rdyhead,optr->pprio);
			
		}
		
		int head = q[rdyhead].qnext;
		if(firstkey(rdyhead)!=lastkey(rdytail)){
			head = q[head].qnext;
		}
		int n = head;

		//while(q[n].qkey<=lastkey(rdytail)){
		//	kprintf("ready queue: %s\t",proctab[n].pname);
		//	n = q[n].qnext;
		//}
		//kprintf("\n");

		for(i=0;i<NPROC;i++){
			if((proctab[i].pstate==PRREADY||proctab[i].pstate==PRCURR)&&proctab[i].peflag==TRUE&&proctab[i].quantum>0){
				epochflag = FALSE;
				break;
			}
		}
		if(epochflag==TRUE){
			int maximumgoodness = 0;
			int pgoodness;
			int next = head;
			int maxproc = next;
			while(q[next].qkey<=lastkey(rdytail)){
				proctab[next].peflag=TRUE;
				if(proctab[next].prevsched){
					proctab[next].counter = proctab[next].quantum;
				}
				proctab[next].quantum = proctab[next].pprio + (int)(proctab[next].counter)/2;
				pgoodness = proctab[next].counter + proctab[next].pprio;
				if(pgoodness>maximumgoodness){
					maximumgoodness = pgoodness;
					maxproc = next;
				}
				next = q[next].qnext;
			}
			nptr = &proctab[ (currpid = dequeue(maxproc))];
			//kprintf("Proc name: %s, Proc goodness: %d, Epoch Flag = True\n",nptr->pname, maximumgoodness);
			nptr->pstate = PRCURR;		/* mark it currently running	*/
			
		}else{

			int next = head;
			int maxproc = next;
			int maxgoodness = 0;
			int pgoodness;
			while(q[next].qkey<=lastkey(rdytail)){
				if(proctab[next].quantum>0){
					pgoodness = proctab[next].counter + proctab[next].pprio;
					if(pgoodness>maxgoodness){
						maxgoodness = pgoodness;
						maxproc = next;
					}
				}
				next = q[next].qnext;
			}
			nptr = &proctab[ (currpid = dequeue(maxproc))];
			//kprintf("Proc name: %s, Proc goodness: %d, Epoch Flag = False\n",nptr->pname, maxgoodness);

			nptr->pstate = PRCURR;		/* mark it currently running	*/
			
		}

		#ifdef	RTCLOCK

		preempt = nptr->quantum;		/* reset preemption counter	*/

		#endif
		ctxsw((int)&optr->pesp, (int)optr->pirmask, (int)&nptr->pesp, (int)nptr->pirmask);

		/* The OLD process returns here when resumed. */

		return OK;
		

	}else{


                /* no switch needed if current process priority higher than next*/

                if ( ( (optr= &proctab[currpid])->pstate == PRCURR) &&

                   (lastkey(rdytail)<optr->pprio)) {

                        return(OK);

                }

                /* force context switch */


                if (optr->pstate == PRCURR) {

                        optr->pstate = PRREADY;

                        insert(currpid,rdyhead,optr->pprio);

                }

                /* remove highest priority process at end of ready list */

                nptr = &proctab[ (currpid = getlast(rdytail)) ];

                nptr->pstate = PRCURR;          /* mark it currently running    */

        }


#ifdef	RTCLOCK

	preempt = QUANTUM;		/* reset preemption counter	*/

#endif
	ctxsw((int)&optr->pesp, (int)optr->pirmask, (int)&nptr->pesp, (int)nptr->pirmask);

	/* The OLD process returns here when resumed. */

	return OK;

}
