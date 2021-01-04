#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "utils.h"

#define NBVAL 25 /* Le nb de val à prendre, mit sur 5 pour les test */
int prem; /* la réponse à la partie 1 */

void prem_partie(FILE *ptr)
{
  int val, find = 0;
  int i = 0, j, k;
  int first = 0; /* permet de check si on a bien fait les n premiers */
  int prev_val[NBVAL]; /* tableau contenant les n valeurs précédentes */
  fscanf(ptr, "%d", &val);

  while (!feof(ptr) && !find)
  {
    if (first < NBVAL)
      first++;
    else
    {
      j = 0;
      while (j < NBVAL && !find)
      {
        k = 0;
        while (k < NBVAL && !find)
        {
          if (k != j && !find)
            find = prev_val[j] + prev_val[k] == val ? 1 : 0;
          k++;
        }
        j++;
      }
      find = find ? 0 : 1;
    }

    i = (i+1) % NBVAL;
    if (!find)
    {
      prev_val[i] = val;
      fscanf(ptr, "%d", &val);
    }
  }

  prem = val;
  printf("La première valeur ne correspondant pas est %d.\n", val);
}

void deux_partie(FILE *ptr)
{
  int *tab = NULL;
  int size = 2, born_inf = 0;
  int find = 0;
  while (!feof(ptr) && !find)
  {
    tab = (int *) malloc(sizeof(int) * size);

    while (!find && !feof(ptr))
    {
      go_line(ptr, born_inf);
      for (int i = 0; i < size; i++)
        fscanf(ptr, "%d", (tab + i));

      if (sum_ptr(tab, size) == prem)
        find = 1;

      born_inf++;
    }   

    if (!find)
    {
      born_inf = 0;
      size++;
      free(tab);
      fseek(ptr, 0, SEEK_SET);
    }
  }

  int inf = *tab, sup = *tab;
  for (int i = 0; i < size; i++)
  {
    if (inf > *(tab+i))
      inf = *(tab+i);
    if (sup < *(tab+i))
      sup = *(tab+i);
  }
  
  free(tab);
  int last = sup + inf;

  printf("La somme des nombres faisant %d est %d.\n", prem, last); 
}
