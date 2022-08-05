

/*****************************
          espacios.c
*******************************
Programa en ANSI C, en donde 
se introduce una frase con espacios,
y luego se vuelca en memoria, indicando
la dirección de inicio del buffer de
almacenamiento.
Realizado:
LINUX Ubuntu 20.04.4 LTS.
Bajo el standard ANSI C.-C-11
Consola de Linux.
Compilación:
gcc espacios.c -o espacios
***************************
*/

#include <stdio.h>
#include <string.h> 
char Codigo_ascii[17];
int i;
int main()
{
    char palabras[301]  ;
    printf("Ingresa unas frases: ");
/*
La función de biblioteca C
char *fgets(char *str, int n, FILE *stream)
lee una línea de la secuencia especificada
y la almacena en la cadena a la que apunta 
str. Se detiene cuando se leen (n-1) 
caracteres, se lee el carácter de nueva 
línea o se alcanza el final del archivo,
lo que suceda primero.
*/
    
    fgets(palabras, 300, stdin);
    printf("*********************************************************\n");
/*
La función strlen() calcula la longitud de una cadena dada.
La strlen()función toma una cadena como argumento
y devuelve su longitud. El valor devuelto
es de tipo size_t(un tipo entero sin signo).
Se define en el archivo de encabezado <string.h> .
*/

    // Remover salto de línea
    if ((strlen(palabras) > 0) && (palabras[strlen(palabras) - 1] == '\n'))
    {
        palabras[strlen(palabras) - 1] = '\0';
    }
    printf("Direccion de inicio buffer de palabras: %p\n", &palabras);
    printf("------------------------------------------------------------------------\n");
//Volcamos la salida de memoria.
for (i = 0; i < 300; ++i) {
        printf("%02X ", ((unsigned char*)&palabras)[i]);
        if (((unsigned char*)palabras)[i] >= ' ' && ((unsigned char*)&palabras)[i] <= '~')
         {
            Codigo_ascii[i % 16] = ((unsigned char*)&palabras)[i];
        } else {
            Codigo_ascii[i % 16] = '.';
        }
        if ((i+1) % 8 == 0 || i+1==300) {
            printf(" ");
            if ((i+1) % 16 == 0) {
                printf(" |  %s \n", Codigo_ascii);
                
            }
            }
                        }
   
printf("\n");//Incluimos un salto.

    return 0;
}
