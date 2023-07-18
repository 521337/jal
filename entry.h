#include "syscalls/syscalls.h"

#ifdef ARGC_ARGV
void __attribute__((naked)) _start(void){
    __asm__ volatile (
        "movq (%rsp),  %rdi ;" // ARGC
        "leaq 8(%rsp), %rsi ;" // ARGV
        "call main          ;" // main(argc, argv)
        "movq %rax, %rdi    ;" // exit()
        "movq $60,  %rax    ;"
        "syscall            ;"
    );
}
#else
int _start(void){
    __asm__ volatile (
        "call main          ;" // main(argc, argv)
        "movq %rax, %rdi    ;" // exit()
        "movq $60,  %rax    ;"
        "syscall            ;"
    );
}
#endif
