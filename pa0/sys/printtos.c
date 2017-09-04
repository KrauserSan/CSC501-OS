#include <stdio.h>


unsigned long *esp;
unsigned long *ebp;

void printtos(){
    asm("movl %esp, esp");
    asm("movl %ebp, ebp");
    kprintf("Before[0x%08X]: 0x%08X\n", ebp+2, *(ebp+2));
    kprintf("After[0x%08X]: 0x%08X\n", esp, *esp);
  
    kprintf("    element[0x%08X]: 0x%08X\n", 
		esp, *esp);
    kprintf("    element[0x%08X]: 0x%08X\n", 
		esp, *esp);
    kprintf("    element[0x%08X]: 0x%08X\n", 
		esp+1, *(esp+1));
    kprintf("    element[0x%08X]: 0x%08X\n", 
		esp+2, *(esp+2));
    kprintf("    element[0x%08X]: 0x%08X\n", 
		esp+3, *(esp+3));

}
