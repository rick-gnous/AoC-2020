#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "utils.h"

void deux_partie(FILE *ptr)
{
  int find = 0, tmp;
  int nb_data = 0; /* est incrémenté si arg bon */
  /* ne pas changer l’ordre des deux tableaux sinon ça casse (jsp pk) */
  char value[11];
  char key[3];
  char *tmp_char = NULL;
  fscanf(ptr, "%s:%s", key, value);

  while (!feof(ptr))
  {
    if (!strncmp(key, "byr", 3)) 
    {
      tmp = sub_digit(value);
      if (tmp >= 1920 && tmp <= 2002)
        nb_data++;
    }
    else if (!strncmp(key, "iyr", 3)) 
    {
      tmp = sub_digit(value);
      if (tmp >= 2010 && tmp <= 2020)
        nb_data++;
    }
    else if (!strncmp(key, "eyr", 3)) 
    {
      tmp = sub_digit(value);
      if (tmp >= 2020 && tmp <= 2030)
        nb_data++;
    }
    else if (!strncmp(key, "hgt", 3)) 
    {
      int checkH = sub_digit(value);

      if (strstr(value, "cm") != NULL && checkH >= 150 && checkH <= 193)
        nb_data++;
      else if (strstr(value, "in") != NULL && checkH >= 59 && checkH <= 76)
        nb_data++;
    }
    else if (!strncmp(key, "ecl", 3)) 
    {
      if (check_ecl(value))
        nb_data++;
    } 
    else if (!strncmp(key, "pid", 3)) 
    {
      tmp_char = strpbrk(value, "0123456789");
      if (strspn(tmp_char, "0123456789") == 9)
        nb_data++;
    }
    else if (!strncmp(key, "hcl", 3))
    {
      /* comme le 1er char est :, on doit tout décaler de 1 */
      if (value[1] == '#' && strlen(value) == 8)
      {
        int i = 2;
        while (isalnum(value[i]) && value[i] != '\0')
          i++;

        if (i == (int) strlen(value))
          nb_data++;
      }
    }

    if (check_void_line(ptr))
    {
      if (nb_data == 7)
        find++;
      nb_data = 0;
    }

    fscanf(ptr, "%s:%s", key, value);
  }
  
  printf("%d bons passeports trouvés.\n", find);
}

void prem_partie(FILE *ptr)
{
  int find = 0;
  int nb_data = 0, cid = 0;
  char word[256];
  fscanf(ptr, "%s", word);

  while (!feof(ptr))
  {
    nb_data++;

    if (!strncmp(word, "cid", 3))
      cid = 1;

    if (check_void_line(ptr))
    {
      if ((nb_data == 7 && !cid) || nb_data == 8)
        find++;
      nb_data = 0;
      cid = 0;
    }

    fscanf(ptr, "%s", word);
  }
  
  printf("%d bons passeports trouvés.\n", find);
}
