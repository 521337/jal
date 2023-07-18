#include "syscalls/syscalls.h"
#include "printf.h"

#ifndef MMAPFILE_H_
#define MMAPFILE_H_

char *mmapfile(char *file, int mode){
    int fd;
    struct stat st;
    char *addr;
    
    fd = open(file, mode, 0);
    if(fd < 0){
        printf("LULY\n");
    }

    fstat(fd, &st);

    addr = (char *)mmap(NULL, st.st_size, PROT_READ, MAP_SHARED_VALIDATE, fd, 0);
    if(addr < 0){
        printf("mmap has failed\n");
    }

    close(fd);

    return addr;
}

#endif // MMAPFILE_H_

