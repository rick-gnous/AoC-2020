#include <stdio.h>
#include <stdlib.h>

void deux_partie(FILE *ptr)
{
  int born_inf, born_sup;
  int find = 0;
  char spe_char;
  char word[256];

  fscanf(ptr, "%d-%d %c: %s", &born_inf, &born_sup, &spe_char, word);

  while (!feof(ptr)) 
  {
    if ((word[born_inf - 1] == spe_char && word[born_sup - 1] != spe_char)
      || (word[born_inf - 1] != spe_char && word[born_sup - 1] == spe_char))
    {
      find++;
    }
    
    fscanf(ptr, "%d-%d %c: %s", &born_inf, &born_sup, &spe_char, word);
  }

  printf("%d bons mdp trouvés.\n", find);
}

void prem_partie(FILE *ptr)
{
  int born_inf, born_sup, i, nbOcc;
  int find = 0;
  char spe_char, read_char;
  char word[256];

  fscanf(ptr, "%d-%d %c: %s", &born_inf, &born_sup, &spe_char, word);
  while (!feof(ptr)) 
  {
    i = 0;
    nbOcc = 0;
    read_char = word[i];
    while (read_char != '\0')
    {
      if (read_char == spe_char)
      {
        nbOcc++;
      }

      i++;
      read_char = word[i];
    }

    if (nbOcc >= born_inf && nbOcc <= born_sup)
    {
      find++;
    }
    
    fscanf(ptr, "%d-%d %c: %s", &born_inf, &born_sup, &spe_char, word);
  }

  printf("%d bons mdp trouvés.\n", find);
}
