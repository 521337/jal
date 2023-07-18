#include "syscalls/syscalls.h"

#ifdef ARGC_ARGV

void __attribute__((naked)) _start(void){
    __asm__ volatile (
        "movq (%rsp),  %rax ;"
        "movq 8(%rsp), %rsi ;"
        "call main         ;"
    );
  //      "movq %rsi, %rdi ;"
  //      "syscall         ;"
  //      "ret             ;"
}

//int _start(int argc, char **argv){
//    main(argc, argv);
//    exit(0);
//}
#else
int _start(void){
    main();
    exit(0); 
}
#endif
