#include "ejemplo.h"

void main(int argc, char *argv[])
{
	//Se crean variables y se hace lectura del código de la operación o acción a desarrollar.
	int op1, op2, cod1, cod2;
	char comp1[]="-a";
	char comp2[]="-d";
	char comp3[]="-s";
	char comp4[]="-p";

	op1= strcmp(argv[1], comp1);
	op2= strcmp(argv[1], comp2);
	cod1= strcmp(argv[4], comp3);

	//Variables iniciales para la lectura de archivos.
	FILE *fd_arch1;
	FILE *fd_arch2;
	FILE *fd_arch3;

	long tam_arch=0;
	long tam_arch2=0;
	long tam_arch3=0;
	
	//Se le da un valor maximo al arreglo para guardar el contenido de los archivos csv.
	char buffer[100];
	char buffer2[100];
	int bufferT[100];
	
	//Se abre para poder leer o escribir en los argumento en nuestro caso las matrices.
	fd_arch1 = fopen(argv[2],"r");
	fd_arch2 = fopen(argv[3],"r");
	fd_arch3 = fopen(argv[5],"w");
	
	//Se encuentran y confirman la dimension de los archivos con una lectura de los documentos.
	fseek(fd_arch1, 0, SEEK_END);
	tam_arch = ftell(fd_arch1);//Se calcula el tamaño del archivo 1.
	rewind(fd_arch1);
	
	if(fread(buffer, 1, tam_arch, fd_arch1) != tam_arch)
	{
		printf("\nError");
	}
	
	
	fseek(fd_arch2, 0, SEEK_END);
	tam_arch2 = ftell(fd_arch2);//Se calcula el tamaño del archivo 2.
	rewind (fd_arch2);

	if(fread(buffer2, 1, tam_arch2, fd_arch2) != tam_arch2)
	{
		printf("\nError");
	}
	

//Comienzo de las operaciones. Verificación de codigo de la operación a ejecutar.

	if(op1 == 0)//Se comprueba si el operador dado es el operador de suma.
	{
		printf("\nSuma\n\n");

		printf("%s\n",buffer);
		printf("%s\n",buffer2);
		sumMatrix(buffer,buffer2);//Se llama a la función se suma de matrices.

		if(cod1 == 0)
		{
			printf("\nArchivo guardado.\n\n");
			Save(buffer, buffer2, fd_arch3, fd_arch2, bufferT, op1);//Se llama a la función save que guarda el archivo.
		}
		else
		{
			printf("\nArchivo sin guardar.\n\n");
		}
		//Se cierran los archivos abiertos anteriormante para liberar memoria.
		fclose(fd_arch1);
		fclose(fd_arch2);
	}
	else
	{
		if(op2 == 0)//Se comprueba si el operador dado es el operador de resta.
		{
			printf("\nResta\n");

			printf("%s\n", buffer);
			printf("%s\n", buffer2);
			RestMatrix(buffer, buffer2);//Se llama a la función de resta de matrices.

			if(cod1 == 0)
			{
				printf("\nArchivo guardado.\n\n");
				Save(buffer, buffer2, fd_arch3, fd_arch2, bufferT, op1);//Se llama a la función save para ejecutar el codigo de guardado del archivo.
			}
			else
			{
				printf("\nArchivo sin guardar.\n\n");
			}
			//Se cierran los archivos abiertos anteriormente para liberar memoria.
			fclose(fd_arch1);
			fclose(fd_arch2);
		}
		else
		{
			printf("\nEl comando de operación no es válido.\n\n");
		}
	}
}
