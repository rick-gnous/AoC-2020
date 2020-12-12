#include <stdlib.h>
#include <string.h> 

#include "utils.h"

int sub_digit(char *str)
{
  int ret = 0;
  char *beginning = strpbrk(str, "0123456789");
  int len = strspn(beginning, "0123456789");

  char *tmp = (char *) malloc(sizeof(char) * len);
  strncpy(tmp, beginning, len);
  ret = atoi(tmp);
  free(tmp);
  
  return ret;
}

int check_ecl(char *str)
{
  str = str + 1;

  if (!strcmp(str, "amb") || !strcmp(str, "blu") || !strcmp(str, "brn")
      || !strcmp(str, "gry") || !strcmp(str, "grn") || !strcmp(str, "hzl")
      || !strcmp(str, "oth"))
    return 1;

  return 0;
}
