#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "utils.h"

/**
 * sub_digit(): return the longest sub string with digit
 * @str: a string with digit
 *
 * Extract the longest sub string with digit in a big string.
 *
 * Return: a int which is the digit
 */
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

/**
 * check_ecl(): check only the ecl (jour4)
 * @str: the string to test
 *
 * Just check if ecl is good
 *
 * Return: 0 if not good, 1 else
 */
int check_ecl(char *str)
{
  str = str + 1;

  if (!strcmp(str, "amb") || !strcmp(str, "blu") || !strcmp(str, "brn")
      || !strcmp(str, "gry") || !strcmp(str, "grn") || !strcmp(str, "hzl")
      || !strcmp(str, "oth"))
    return 1;

  return 0;
}

/**
 * check_void_line(): check if one line is blank
 * @ptr: a pointer to the file
 *
 * Check if, in one file, we have an empty line between two line with text
 *
 * Return: 0 if the line isn’t empty, 1 else
 */
int check_void_line(FILE *ptr)
{
  int ret = 0;
  char check_line[2];
  check_line[0] = getc(ptr);
  check_line[1] = getc(ptr);
  if (check_line[0] == '\n' && (check_line[1] == '\n' || check_line[1] == EOF))
    ret = 1;

  /* reviens un caractère en arrière pour éviter de perdre des infos
   quand on check la présence d’une ligne vide */
  fseek(ptr, -1, SEEK_CUR);

  return ret;
}

/**
 * sum_ptr(): make the sum of int in pointer
 * @ptr: the pointer with int
 * @size: the size of pointer
 *
 * 
 *
 * Return: the sum
 */
int sum_ptr(int *ptr, int size)
{
  int ret = 0;
  for (int i = 0; i < size; i++)
  {
    ret += *(ptr + i);
  }
  return ret;
}

/**
 * go_line(): positionne le curseur à la ligne donnée
 * @ptr: le pointeur vers le fichier
 * @line: le numéro de la ligne où mettre le curseur
 *
 * met le curseur à la ligne passée en paramètre
 *
 * Return: -1 quand pointeur null ou line négative
 *          1 quand le curseur est à la fin du fichier
 *          0 quand tout est ok
 */
int go_line(FILE *ptr, int line)
{
  int ret = -1;

  if (ptr != NULL && line >= 0)
  {
    fseek(ptr, 0, SEEK_SET);
    char *tmp = NULL;
    size_t t = 0;
    int i = 0;
    while (i < line - 1 && !feof(ptr))
    {
      getline(&tmp, &t, ptr);
      i++;
    }

    if (feof(ptr))
      ret = 1;

    free(tmp);
  }

  return ret;
}
