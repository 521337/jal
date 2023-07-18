#include "printf.h"

void print_bytes(char *buffer_to_read, int len){
    for (int i = 0; i < len; i++){
        if (i%16 == 0){
            printf("\n");
            printf("%02x", buffer_to_read[i] & 0xff);
            continue;
        }
        //if (i != 0) printf(":");
        printf(" %02x", buffer_to_read[i] & 0xff);
    }
    printf("\n");
}
