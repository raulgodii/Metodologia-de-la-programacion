  #include <stdlib.h>
  #include <stdio.h>
  #include <ctype.h>
  #include <string.h>

  
  void crear_fichero_mayus(char* fichero_mayus, char* cad){
        FILE* fm;

        char cad4[]="mayusculas";

        if ((fm=fopen(fichero_mayus, "w"))==NULL) {
            printf("\nError, el fichero no pudo abrirse\n");
            exit(-1);        
        }

        for(int i=0; i<strlen(cad); i++){
            cad[i]=toupper(cad[i]);
        }
        fprintf(fm, "%s", cad);

        fclose(fm);

  }