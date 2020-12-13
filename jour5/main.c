#include <stdio.h>
#include <string.h>

void premPartie(FILE *ptr)
{
  int bornSupR, bornInfR, bornSupC, bornInfC, column, row, newId;
  int idMax = 0;
  char str[10];

  fscanf(ptr, "%s", str);

  while (!feof(ptr))
  {
    bornSupR = 127, bornSupC = 7;
    bornInfR = 0; bornInfC = 0;

    for (int i = 0; i < strlen(str); i++)
    {
      switch(str[i])
      {
        case 'F': bornSupR = (bornSupR + bornInfR)/2; break;
        case 'B': bornInfR = (bornSupR + bornInfR + 1)/2; break;
        case 'R': bornInfC = (bornSupC + bornInfC + 1)/2; break;
        case 'L': bornSupC = (bornSupC + bornInfC)/2; break;
        default: break;
      }

      if (i == 6)
        row = str[i] == 'F' ? bornInfR : bornSupR;
      else if (i == 9)
        column = str[i] == 'L' ? bornInfC : bornSupC;
    }

    newId = row * 8 + column;
    if (newId > idMax)
      idMax = newId;

    fscanf(ptr, "%s", str);
  }

  printf("L’id max est %d.\n", idMax);
}

void deuxPartie(FILE *ptr)
{
  int i;
}
