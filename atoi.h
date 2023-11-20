#ifndef JAL_ATOI_H
#define JAL_ATOI_H

// test if char is a digit (0-9)
// \return true if char is a digit
static _Bool is_digit(char ch){
  return (ch >= '0') && (ch <= '9');
}


// ASCII string to unsigned int conversion
// it stops if the char is not a digit.
unsigned int atoi(const char *str){
  unsigned int i = 0;
  unsigned int i2 = 0;
  while(is_digit(str[i2])){
    i = i * 10 + (unsigned int)((str[i2]) - '0');
    i2++;
  }
  return i;
}

// ASCII string to unsigned int conversion
// it stops if the char is not a digit.
//
// In n returns the number of chars readed.
unsigned int atoi_n(const char *str, int *n){
  unsigned int i = 0;
  *n = 0;
  //unsigned int i2 = 0;
  while(is_digit(str[*n])){
    i = i * 10 + (unsigned int)((str[*n]) - '0');
    (*n)++;
  }
  return i;
}
#endif /* JAL_ATOI_H */