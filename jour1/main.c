#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "input"
#define NUMBER_LINES 200

int main ()
{
    FILE *ptr = fopen(FILENAME, "r");

    if (ptr == NULL)
    {
      return 1;
    }

    int find = 0, i = 0, j, k, a, b, c, line;
    int array[NUMBER_LINES];

    // init du tableau
    while (i <= NUMBER_LINES)
    {
      fscanf(ptr, "%d", &line);
      array[i] = line;
      i++;
    }
    fclose(ptr);

    // recherche des nombres
    i = 0;
    while (!find && i < NUMBER_LINES)
    {
        j = 0;
        a = array[i];
        while (!find && j < NUMBER_LINES)
        {
            k = 0;
            b = array[j];

            // boucle pour la 2e partie
            while (!find && k < NUMBER_LINES)
            {  
              c = array[k];
              if (a + b + c == 2020)
              {
                  find = a * b * c;
              }
              k++;
            }
            j++;
        }
        i++;
    }
    printf("find : %d\n", find);
    return 0;
}
