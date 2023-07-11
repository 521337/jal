#include "bool.h"

bool memcmp(const void *s1, const void *s2, size_t n){
    // XXX ugly

    for(size_t i = 0; i < n; ++i){
        if(((unsigned char*)s1)[i] != ((unsigned char *)s2)[i])
            return false;
    }
    return true;
}
