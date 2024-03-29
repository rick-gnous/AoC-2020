#include <stdio.h>
#include <stdlib.h>

#define FILETEST "test"
#define FILEINPUT "input"

void prem_partie(FILE *ptr);
void deux_partie(FILE *ptr);

int main(int argc, char *argv[])
{
  char *filename = argc > 1 ? FILETEST : FILEINPUT;

  FILE *ptr = fopen(filename, "r");
  if (ptr == NULL)
  {
    printf("Le fichier %s n’existe pas.\n", filename);
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
