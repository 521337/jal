#include "syscalls/syscalls.h"
#include "printf.h"

#ifndef MMAPFILE_H_
#define MMAPFILE_H_
// fsfddsf
char *mmapfile(char *file, int mode, uint64_t *file_size){
    int fd;
    struct stat st;
    char *addr;
    
    fd = open(file, mode, 0);
    if(fd < 0){
        printf("mmapfile(): open failed\n");
        exit(1);
    }

    fstat(fd, &st);

    addr = (char *)mmap(NULL, st.st_size, PROT_READ, MAP_SHARED_VALIDATE, fd, 0);
    if(addr < 0){
        printf("mmapfile(): mmap failed\n");
        exit(1);
    }
    close(fd);

    *file_size = st.st_size;
    return addr;
}

#endif // MMAPFILE_H_

