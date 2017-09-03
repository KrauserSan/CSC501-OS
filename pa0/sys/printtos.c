#include <stdio.h>

/*
unsigned long *stackPointer;
unsigned long *basePointer;

void printtos(){
    asm("movl %esp, stackPointer");
    asm("movl %ebp, basePointer");
    kprintf("Before[0x%x]: 0x%x\n", basePointer+2, *(basePointer+2));
    kprintf("After[0x%x]: 0x%x\n", stackPointer, *stackPointer);
    
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    kprintf("    element[0x%x]: 0x%x, var:0x%x\n", stackPointer, *stackPointer,a);
    kprintf("    element[0x%x]: 0x%x, var:0x%x\n", stackPointer, *(stackPointer+5),b);
    kprintf("    element[0x%x]: 0x%x, var:0x%x\n", stackPointer, *(stackPointer+4),c);
    kprintf("    element[0x%x]: 0x%x, var:0x%x\n", stackPointer, *(stackPointer+3),d);
*/

unsigned long *x1, *x2;

void printtos(){
	asm("movl %esp, x1");
	asm("movl %ebp, x2");
	kprintf("ebp:\t 0x%x \nesp_before_entry:\t 0x%x \n",x2,x2+2);
	kprintf("esp:\t 0x%x \n",x1);
	int i;
	for(i=0; i<6;i++)
		kprintf("esp+%d:\t 0x%x [esp+%d]:\t 0x%x\n",i,x1+i,i,*(x1+i));
	kprintf("--------------------------------\n");  
}
