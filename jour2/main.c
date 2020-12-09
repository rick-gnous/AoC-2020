#include <stdio.h>
#include <stdlib.h>

#define FILENAME "input"

void premPartie(FILE *ptr);
void deuxPartie(FILE *ptr);


int main()
{
  FILE *ptr = fopen(FILENAME, "r");
  if (ptr == NULL)
  {
    return 1;
  }

  // commentez la première partie quand vout voulez exécuter la deuxième
  // le curseur de lecture du fichier reste à la fin
  //premPartie(ptr);
  deuxPartie(ptr);

  fclose(ptr);
  return 0;
}

void deuxPartie(FILE *ptr)
{
  int bornInf, bornSup;
  int find = 0;
  char speChar;
  char word[256];

  fscanf(ptr, "%d-%d %c: %s", &bornInf, &bornSup, &speChar, word);

  while (!feof(ptr)) 
  {
    if ((word[bornInf - 1] == speChar && word[bornSup - 1] != speChar)
      || (word[bornInf - 1] != speChar && word[bornSup - 1] == speChar))
    {
      find++;
    }
    
    fscanf(ptr, "%d-%d %c: %s", &bornInf, &bornSup, &speChar, word);
  }

  printf("%d bons mdp trouvés.\n", find);
}

void premPartie(FILE *ptr)
{
  int bornInf, bornSup, i, nbOcc;
  int find = 0;
  char speChar, readChar;
  char word[256];

  fscanf(ptr, "%d-%d %c: %s", &bornInf, &bornSup, &speChar, word);
  while (!feof(ptr)) 
  {
    i = 0;
    nbOcc = 0;
    readChar = word[i];
    while (readChar != '\0')
    {
      if (readChar == speChar)
      {
        nbOcc++;
      }

      i++;
      readChar = word[i];
    }

    if (nbOcc >= bornInf && nbOcc <= bornSup)
    {
      find++;
    }
    
    fscanf(ptr, "%d-%d %c: %s", &bornInf, &bornSup, &speChar, word);
  }

  printf("%d bons mdp trouvés.\n", find);
}
