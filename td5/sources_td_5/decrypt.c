#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  char str[256];
  FILE *fic = fopen(argv[1],"r");
  unsigned char res[256];
  int r,g,b,i;

  /*retire les headers */
  fgets(str, 256, fic);
  fgets(str, 256, fic);
  fgets(str, 256, fic);
  
  for(i=0; i<255; i++){
    fgets(str, 256, fic);
    r = atoi(str);
    fgets(str, 256, fic);
    g = atoi(str);
    fgets(str, 256, fic);
    b = atoi(str);
    res[i]= (r % 8)*64 + (g % 8)*8 + (b % 8);
  }
  res[i] = '\0';
  printf("Le message est : \n%s\n",res);

  fclose(fic);
  return 0;
}
