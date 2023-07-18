#include <stdint.h>
#include <stddef.h>
#include "include/socket_constants.h"
#include "include/netlink_constants.h"
#include "include/mmap_constants.h"
#include "include/pid.h"
#include "include/time.h"
#include "include/in.h"
#include "include/open.h"
#include "include/ssize.h"
#include "include/resource.h" // getrlimit
#include "include/lseek.h"    // LSEEK_* defines
#include "include/dirent.h"
#include "include/bpf.h"
#include "include/stat.h"

#ifndef SYSCALLS_H
#define SYSCALLS_H

#define READ_SYSCALL_NUMBER        0
#define WRITE_SYSCALL_NUMBER       1
#define OPEN_SYSCALL_NUMBER        2
#define CLOSE_SYSCALL_NUMBER       3
#define FSTAT_SYSCALL_NUMBER       5
#define LSEEK_SYSCALL_NUMBER       8
#define MMAP_SYSCALL_NUMBER        9
#define MUNMAP_SYSCALL_NUMBER     11
#define BRK_SYSCALL_NUMBER        12
#define IOCTL_SYSCALL_NUMBER      16
#define NANOSLEEP_SYSCALL_NUMBER  35
#define GETPID_SYSCALL_NUMBER     39
#define SOCKET_SYSCALL_NUMBER     41
#define CONNECT_SYSCALL_NUMBER    42
#define RECVMSG_SYSCALL_NUMBER    47 // Sin implementar, me he enterado de que se puede 
                                     // usar read
#define BIND_SYSCALL_NUMBER       49
#define FORK_SYSCALL_NUMBER       57
#define EXIT_SYSCALL_NUMBER       60
#define FCHDIR_SYSCALL_NUMBER     81
#define GETRLIMIT_SYSCALL_NUMBER  97
#define SETRLIMIT_SYSCALL_NUMBER 160
#define TIME_SYSCALL_NUMBER      201
#define GETDENTS64_NUMBER        217
#define BPF_SYSCALL_NUMBER       321
#define CLONE3_SYSCALL_NUMBER    435 // Sin implementar.

// The calling convention:
//
//       ~~~~
// User->User:
//   Args:      rdi, rsi, rdx, rcx, r8, r9 0x8(rsp)...
//   Preserved: rbx, rsp, r12, r13, r14, r15
//   Return:    rax
//
// ~~~~
// User->Kernel:
//
//   Args:          rax, rdi, rsi, rdx, r10, r8
//   Not preserved: rcx, r11
//   Return:        rax

int64_t __attribute__ ((naked)) syscall6(int64_t number, int64_t a1, int64_t a2, int64_t a3, int64_t a4, int64_t a5, int64_t a6){
    __asm__ volatile (
        "movq %rdi, %rax     ;"
        "movq %rsi, %rdi     ;"
        "movq %rdx, %rsi     ;"
        "movq %rcx, %rdx     ;"
        "movq %r8,  %r10     ;"
        "movq %r9,  %r8      ;"
        "movq 0x8(%rsp), %r9 ;"
        "syscall             ;"
        "ret                 ;"
    );
}

int64_t __attribute__ ((naked)) syscall5(int64_t number, int64_t a1, int64_t a2, int64_t a3, int64_t a4, int64_t a5){
    __asm__ volatile (
        "movq %rdi, %rax ;"
        "movq %rsi, %rdi ;"
        "movq %rdx, %rsi ;"
        "movq %rcx, %rdx ;"
        "movq %r8,  %r10 ;"
        "movq %r9,  %r8  ;"
        "syscall         ;"
        "ret             ;"
    );
}

int64_t __attribute__ ((naked)) syscall4(int64_t number, int64_t a1, int64_t a2, int64_t a3, int64_t a4){
    __asm__ volatile (
        "movq %rdi, %rax ;"
        "movq %rsi, %rdi ;"
        "movq %rdx, %rsi ;"
        "movq %rcx, %rdx ;"
        "movq %r8,  %r10 ;"
        "syscall         ;"
        "ret             ;"
    );
}

int64_t __attribute__ ((naked)) syscall3(int64_t number, int64_t a1, int64_t a2, int64_t a3){
    __asm__ volatile (
        "movq %rdi, %rax ;"
        "movq %rsi, %rdi ;"
        "movq %rdx, %rsi ;"
        "movq %rcx, %rdx ;"
        "syscall         ;"
        "ret             ;"
    );
}

int64_t __attribute__ ((naked)) syscall2(int64_t number, int64_t a1, int64_t a2){
    __asm__ volatile (
        "movq %rdi, %rax ;"
        "movq %rsi, %rdi ;"
        "movq %rdx, %rsi ;"
        "syscall         ;"
        "ret             ;"
    );
}

int64_t __attribute__ ((naked)) syscall1(int64_t number, int64_t a1){
    __asm__ volatile (
        "movq %rdi, %rax ;"
        "movq %rsi, %rdi ;"
        "syscall         ;"
        "ret             ;"
    );
}

int64_t __attribute__ ((naked)) syscall0(int64_t number){
    __asm__ volatile (
        "movq %rdi, %rax ;"
        "movq %rsi, %rdi ;"
        "syscall         ;"
        "ret             ;"
    );
}

ssize_t read(int fd, void *buf, size_t count){
    return syscall3(READ_SYSCALL_NUMBER, fd, (int64_t)buf, count);
}

ssize_t write(int fd, const void *buf, size_t count){
    return syscall3(WRITE_SYSCALL_NUMBER, fd, (int64_t)buf, count);
}

int open(const char *pathname, int flags, mode_t mode){
    return syscall3(OPEN_SYSCALL_NUMBER, (int64_t)pathname, flags, mode);
}

int close(int fd){
    return syscall1(CLOSE_SYSCALL_NUMBER, fd);
}

off_t lseek(unsigned int fd, off_t offset, unsigned int whence){
    return syscall3(LSEEK_SYSCALL_NUMBER, fd, offset, whence);
}

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset){
    return (void*)syscall6(MMAP_SYSCALL_NUMBER, (int64_t)addr, length, prot, flags, fd, offset);
}

int munmap(void *addr, size_t length){
    return syscall2(MUNMAP_SYSCALL_NUMBER, (int64_t)addr, length);
}

int ioctl(unsigned int fd, unsigned long cmd, unsigned long arg){
    return syscall3(IOCTL_SYSCALL_NUMBER, fd, cmd, arg);
}

int nanosleep(const struct timespec *req, struct timespec *rem){
    return syscall2(NANOSLEEP_SYSCALL_NUMBER, (int64_t)req, (int64_t)rem);
}

pid_t getpid(void){
    return syscall0(GETPID_SYSCALL_NUMBER);
}

int socket(int domain, int type, int protocol){
    return syscall3(SOCKET_SYSCALL_NUMBER, domain, type, protocol);
}

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    return syscall3(CONNECT_SYSCALL_NUMBER, sockfd, (int64_t)addr, (int64_t)addrlen);
}

int bind(int sockfd, const struct sockaddr *addr, unsigned int addrlen){
    return syscall3(BIND_SYSCALL_NUMBER, sockfd, (int64_t)addr, addrlen);
}

pid_t fork(void){
    return syscall0(FORK_SYSCALL_NUMBER);
}

_Noreturn void exit(int status){
    syscall1(EXIT_SYSCALL_NUMBER, status);
    __builtin_unreachable();
}

int fchdir(int fd){
    return syscall1(FCHDIR_SYSCALL_NUMBER, fd);
}
int getrlimit(int resource, struct rlimit *rlim){
    return syscall2(GETRLIMIT_SYSCALL_NUMBER, resource, (int64_t)rlim);
}

int setrlimit(int resource, const struct rlimit *rlim){
    return syscall2(SETRLIMIT_SYSCALL_NUMBER, resource, (int64_t)rlim);
}

time_t time(time_t *tloc){
    return syscall1(TIME_SYSCALL_NUMBER, (int64_t)tloc);
}

ssize_t getdents64(int fd, struct linux_dirent64 *dirent, unsigned int count){
    return syscall3(GETDENTS64_NUMBER, fd, (int64_t)dirent, count);
}

int bpf(int cmd, union bpf_attr *attr, unsigned int size){
    return syscall3(BPF_SYSCALL_NUMBER, cmd, (int64_t)attr, size);
}

int fstat(int fd, struct stat *statbuf){
    return syscall2(FSTAT_SYSCALL_NUMBER, fd, (int64_t)statbuf);
}

//int clone3(struct clone_args *cl_args, size_t size){
//    return syscall2(CLONE3_SYSCALL_NUMBER, cl_args, size);
//}
//

#endif // SYSCALLS_H
