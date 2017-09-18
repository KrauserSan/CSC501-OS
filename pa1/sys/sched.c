#include <stdio.h>
#include <sched.h>

int scheduler; 

void setschedclass(int sched_class){
	scheduler = sched_class;
}

int getschedclass(){
	return scheduler;
}
