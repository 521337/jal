#include <stdint.h>

#ifndef SYSCALLS_G_H
#define SYSCALLS_G_H

inline int64_t syscall6(int64_t number, int64_t a1, int64_t a2, int64_t a3, int64_t a4, int64_t a5, int64_t a6){
    int64_t a;
    __asm__ volatile (
        "movq %1, %%rax ;"   // system call number
        "movq %2, %%rdi ;"
        "movq %3, %%rsi ;"
        "movq %4, %%rdx ;"
        "movq %5, %%r10 ;"
        "movq %6, %%r8  ;"
        "movq %7, %%r9  ;"
        "syscall ;"
        "movq %%rax, %0 ;"
        : "=r" (a)
        : "rax" (number), "r" (a1), "r" (a2), "r" (a3), "r" (a4), "r" (a5), "r" (a6)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10", "%r8", "%r9", "%rcx", "%r11"
    );
    return a;
}

inline int64_t syscall5(int64_t number, int64_t a1, int64_t a2, int64_t a3, int64_t a4, int64_t a5){
    int64_t a;
    __asm__ volatile (
        "movq %1, %%rax ;"   // system call number
        "movq %2, %%rdi ;"
        "movq %3, %%rsi ;"
        "movq %4, %%rdx ;"
        "movq %5, %%r10 ;"
        "movq %6, %%r8  ;"
        "syscall ;"
        "movq %%rax, %0 ;"
        : "=r" (a)
        : "r" (number), "r" (a1), "r" (a2), "r" (a3), "r" (a4), "r" (a5)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10", "%r8", "%rcx", "%r11"
    );
    return a;
}

inline int64_t syscall4(int64_t number, int64_t a1, int64_t a2, int64_t a3, int64_t a4){
    int64_t a;
    __asm__ volatile (
        "movq %1, %%rax ;"   // system call number
        "movq %2, %%rdi ;"
        "movq %3, %%rsi ;"
        "movq %4, %%rdx ;"
        "movq %5, %%r10 ;"
        "syscall ;"
        "movq %%rax, %0 ;"
        : "=r" (a)
        : "r" (number), "r" (a1), "r" (a2), "r" (a3), "r" (a4)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10", "%rcx", "%r11"
    );
    return a;
}

inline int64_t syscall3(int64_t number, int64_t a1, int64_t a2, int64_t a3){
    int64_t a;
    __asm__ volatile (
        "movq %1, %%rax ;"   // system call number
        "movq %2, %%rdi ;"
        "movq %3, %%rsi ;"
        "movq %4, %%rdx ;"
        "syscall        ;"
        "movq %%rax, %0 ;"
        : "=r" (a)
        : "r" (number), "r" (a1), "r" (a2), "r" (a3)
        : "%rax", "%rdi", "%rsi", "%rdx", "%rcx", "%r11"
    );
    return a;
}

inline int64_t __attribute__ ((visibility ("internal"))) syscall2(int64_t number, int64_t a1, int64_t a2){
    int64_t a;
    __asm__ volatile (
        "movq %1, %%rax ;"   // system call number
        "movq %2, %%rdi ;"
        "movq %3, %%rsi ;"
        "syscall ;"
        "movq %%rax, %0 ;"
        : "=r" (a)
        : "r" (number), "r" (a1), "r" (a2)
        : "%rax", "%rdi", "%rsi", "%rcx", "%r11"
    );
    return a;
}

inline int64_t __attribute__ ((visibility ("internal"))) syscall1(int64_t number, int64_t a1){
    int64_t a;
    __asm__ volatile (
        "movq %1, %%rax ;"   // system call number
        "movq %2, %%rdi ;"
        "syscall ;"
        "movq %%rax, %0 ;"
        : "=r" (a)
        : "r" (number), "r" (a1)
        : "%rax", "%rdi", "%rcx", "%r11"
    );
    return a;
}

inline int64_t __attribute__ ((visibility ("internal"))) syscall0(int64_t number){
    int64_t a;
    register long *syscall_num __asm__( "rax" );
    __asm__ volatile (
        "movq %1, %%rax ;" // system call number
        "syscall        ;"
        "movq %%rax, %0 ;"
        : "=r" (a)
        : "r" (number)
        : "%rax", "%rcx", "%r11"
    );
    return a;
}

#endif // SYSCALLS_G_H
