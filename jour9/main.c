#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NBVAL 25

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

  printf("La première valeur ne correspondant pas est %d.", val);
}

void deux_partie(FILE *ptr)
{

}
