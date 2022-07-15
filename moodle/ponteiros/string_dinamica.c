#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void clearbuff(){
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
}

int sortstring( const void *str1, const void *str2 )
{
    const char *rec1 = *(char**)str1;
    const char *rec2 = *(char**)str2;
    int val = strcmp(rec1, rec2);

    return val;
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  char buffer[255];
  int n = atoi(fgets(buffer,255,stdin));
  char* nomes[n];

  for(int i = 0; i < n; i++){

    printf("==============================\n");

    for(int nome = 0; nome < i; nome++){
      printf("%d : %s\n", nome, nomes[nome]);
    }

    fgets(buffer, 255, stdin);
    int s = atoi(buffer);
    nomes[i] = malloc(s*sizeof(char));

    fgets(nomes[i], s, stdin);
    setbuf(stdin, NULL);
  }

  qsort(nomes, n, n*sizeof(char*), &sortstring);

  for(int i = 0; i < n; i++){
    printf("%s\n", nomes[i]);
  }
  
  return 0;
}
