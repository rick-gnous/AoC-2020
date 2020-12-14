#include <stdio.h>

#define FILENAME "input"
//#define FILENAME "test"

void prem_partie(FILE *ptr);
void deux_partie(FILE *ptr);

int main()
{
  FILE *ptr = fopen(FILENAME, "r");
  if (ptr == NULL)
  {
    printf("Le fichier %s n’existe pas.\n", FILENAME);
    return 1;
  }

  printf("Traitement de la première partie…\n");
  prem_partie(ptr);
  fseek(ptr, 0, SEEK_SET);
  printf("\nTraitement de la deuxième partie…\n");
  deux_partie(ptr);

  fclose(ptr);
  return 0;
}
