#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
#include <string.h>

#include "utils.h"

void prem_partie(FILE *ptr)
{
  int total = 0, find = 0;
  char actLine[30], findChar[26], empty[26];
  char tmp;
  fscanf(ptr, "%s", actLine);

  while (!feof(ptr))
  {
    for (int i = 0; i < strlen(actLine); i++)
    {
      tmp = actLine[i];
      if (strchr(findChar, actLine[i]) == NULL)
      {
        find++;
        strncat(findChar, &tmp, 1);
      }
    }

    if (check_void_line(ptr))
    {
      total += find;
      find = 0;
      strcpy(findChar, empty);
    }
    fscanf(ptr, "%s", actLine);
  }

  printf("La somme de toutes les réponses est : %d.\n", total);
}

void deux_partie(FILE *ptr)
{
  int i;
}
