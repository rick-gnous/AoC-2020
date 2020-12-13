#include <stdio.h>

#define FILENAME "input"

void premPartie(FILE *ptr);
void deuxPartie(FILE *ptr);

int main()
{
  FILE *ptr = fopen(FILENAME, "r");
  if (ptr == NULL)
  {
    printf("Le fichier %s n’existe pas.\n", FILENAME);
    return 1;
  }

  printf("Traitement de la première partie…\n");
  premPartie(ptr);
  fseek(ptr, 0, SEEK_SET);
  printf("\nTraitement de la deuxième partie…\n");
  deuxPartie(ptr);

  fclose(ptr);
  return 0;
}
