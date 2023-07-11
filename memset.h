#ifndef JAL_MEMSET_H
#define JAL_MEMSET_H

void *memset(void *s, int c, size_t n){
    for(size_t i = 0; i < n; ++i){
        ((char *)s)[i] = (char)c;
    }
    return s;
}

#endif /* JAL_MEMSET_H */