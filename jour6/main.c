#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
#include <string.h>

#include "utils.h"

void prem_partie(FILE *ptr)
{
  int total = 0, find = 0;
  char act_line[30], find_char[26], empty[26];
  char tmp;
  fscanf(ptr, "%s", act_line);

  while (!feof(ptr))
  {
    for (int i = 0; i < strlen(act_line); i++)
    {
      tmp = act_line[i];
      if (strchr(find_char, act_line[i]) == NULL)
      {
        find++;
        strncat(find_char, &tmp, 1);
      }
    }

    if (check_void_line(ptr))
    {
      total += find;
      find = 0;
      strcpy(find_char, empty);
    }
    fscanf(ptr, "%s", act_line);
  }

  printf("La somme de toutes les réponses est : %d.\n", total);
}

void deux_partie(FILE *ptr)
{
  int total = 0, find = 0, first = 1;
  char act_line[30], find_char[26], empty[26];
  char tmp;
  fscanf(ptr, "%s", act_line);

  while (!feof(ptr))
  {
    if (first) 
    {
      strcpy(find_char, act_line);
      find = strlen(find_char);
      first = 0;
    }
    else
    {
      int i = 0;
      tmp = find_char[i];

      while (tmp != '\0')
      {
        if (strchr(act_line, tmp) == NULL && tmp != '!')
        {
          find--;
          find_char[i] = '!';
        }
        i++;
        tmp = find_char[i];
      }
    }

    if (check_void_line(ptr))
    {
      total += find;
      find = 0;
      first = 1;
      strcpy(find_char, empty);
    }
    fscanf(ptr, "%s", act_line);
  }

  printf("La somme de toutes les réponses est : %d.\n", total);
}
