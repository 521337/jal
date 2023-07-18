#ifndef STRLEN_H_
#define STRLEN_H_

size_t strlen(const char* str){
    const char* s;
    for (s = str; *s; ++s);
    return (size_t)(s - str);
}

#endif // STRLEN_H_