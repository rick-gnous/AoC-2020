#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "utils.h"

void deuxPartie(FILE *ptr)
{
  int find = 0, tmp;
  int nbData = 0; // est incrémenté si arg bon
  char checkLigne[2]; // vérifie 2 lignes plus loin pour détecter ligne vide
  char value[10];
  char key[3];
  char *tmpChar = NULL;
  fscanf(ptr, "%s:%s", key, value);

  while (!feof(ptr))
  {
    if (!strncmp(key, "byr", 3)) 
    {
      tmp = sub_digit(value);
      if (tmp >= 1920 && tmp <= 2002)
        nbData++;
    }
    else if (!strncmp(key, "iyr", 3)) 
    {
      tmp = sub_digit(value);
      if (tmp >= 2010 && tmp <= 2020)
        nbData++;
    }
    else if (!strncmp(key, "eyr", 3)) 
    {
      tmp = sub_digit(value);
      if (tmp >= 2020 && tmp <= 2030)
        nbData++;
    }
    else if (!strncmp(key, "hgt", 3)) 
    {
      int checkH = sub_digit(value);

      if (strstr(value, "cm") != NULL && checkH >= 150 && checkH <= 193)
        nbData++;
      else if (strstr(value, "in") != NULL && checkH >= 59 && checkH <= 76)
        nbData++;
    }
    else if (!strncmp(key, "ecl", 3)) 
    {
      if (check_ecl(value))
        nbData++;
    } 
    else if (!strncmp(key, "pid", 3)) 
    {
      tmpChar = strpbrk(value, "0123456789");
      if (strspn(tmpChar, "0123456789") == 9)
        nbData++;
    }
    else if (!strncmp(key, "hcl", 3))
    {
      //comme le 1er char est :, on doit tout décaler de 1
      if (value[1] == '#' && strlen(value) == 8)
      {
        int i = 2;
        while (isalnum(value[i]) && value[i] != '\0')
          i++;

        if (i == strlen(value))
          nbData++;
      }
    }

    checkLigne[0] = getc(ptr);
    checkLigne[1] = getc(ptr);
    if (checkLigne[0] == '\n' && (checkLigne[1] == '\n' || checkLigne[1] == EOF))
    {
      if (nbData == 7)
        find++;
      nbData = 0;
    }

    // reviens un caractère en arrière pour éviter de perdre des infos
    // quand on check la présence d’une ligne vide
    fseek(ptr, -1, SEEK_CUR); 
    fscanf(ptr, "%s:%s", key, value);
  }
  
  printf("%d bons passeports trouvés.\n", find);
}

void premPartie(FILE *ptr)
{
  int find = 0;
  int nbData = 0, cid = 0;
  char checkLigne[2]; // vérifie 2 lignes plus loin pour détecter ligne vide
  char word[256];
  fscanf(ptr, "%s", word);

  while (!feof(ptr))
  {
    nbData++;

    if (!strncmp(word, "cid", 3))
      cid = 1;

    checkLigne[0] = getc(ptr);
    checkLigne[1] = getc(ptr);
    if (checkLigne[0] == '\n' && (checkLigne[1] == '\n' || checkLigne[1] == EOF))
    {
      if ((nbData == 7 && !cid) || nbData == 8)
        find++;
      nbData = 0;
      cid = 0;
    }

    // reviens un caractère en arrière pour éviter de perdre des infos
    // quand on check la présence d’une ligne vide
    fseek(ptr, -1, SEEK_CUR); 
    fscanf(ptr, "%s", word);
  }
  
  printf("%d bons passeports trouvés.\n", find);
}
