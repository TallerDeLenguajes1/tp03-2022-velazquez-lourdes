#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *buff;
    char *nombre[4];
    buff  =(char*)malloc(100*sizeof(char));
       for (int i = 0; i < 5; i++)
    {   
        printf("ingrese Nombres %d :", i+1);
        gets(buff);
        nombre[i]= (char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nombre[i],buff);
    }
        for (int i = 0; i < 5; i++)
    {
        printf("Nombre ingresador %d:" , i+1);
        printf("%s \n", nombre[i]);
    }
        for (int i=0; i<5; i++)
    {
        free(nombre[i]);
    }
    
    free(buff);
    
    
return 0;
}