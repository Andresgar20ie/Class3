/*
Henry Santiago Mora Mancera
Andrés Felipe García Rodríguez
ALSE - 1
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int contCol(char* buffer);
int contFil(char* buffer);
void sumMatrix(char* buffer,char* buffer2);//Declaración de funciones a usar.
void RestMatrix(char* buffer,char* buffer2);
void Save(char* buffer, char* buffer2, FILE *fd_arch3,	FILE *fd_arch2, int* bufferT, int op1);


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


//Función de conteo de columnas.
int contCol(char* buffer)
{
	int rep = 0;
	int colContador = 0;
	while(buffer[rep] != '\n')
	{
		if(',' == buffer[rep])
		{
			colContador++;
		}
		rep++;
	}
	return colContador+1;
}


//Función de conteo de filas.
int contFil(char* buffer)
{
	int rep = 0;
	int filContador = 0;
	while(buffer[rep] != '\0')
	{
		if('\n' == buffer[rep])
		{
			filContador++;
		}
		rep++;
	}
	return filContador;
}


//Función de suma.
void sumMatrix(char* buffer, char* buffer2)
{
	int v1;
	char *val;
	char *val2;
	int cont = 0;
	int rep = 0;
	int repFil = 0;
	int repColumn = 0;
	int columnStart = 0;
	if((contFil(buffer) != contFil(buffer2)) || (contCol(buffer) != contCol(buffer2))) //Para poder hacer una suma o resta entre matrices es necesario que sean del mismo tamaño tanto de filas como de columnas.
	{
		printf("No se puede realizar la suma.");
	}
	else
	{
		while(repFil != contFil(buffer))
		{
			while(repColumn != contCol(buffer))
			{
				if((buffer[rep] != ',') && (buffer[rep] != '\n')) // Conteo de filas mediante el numero de \n y de colomnas mediante el numero de ("," + 1).
				{
					val = &buffer[rep];
					val2 = &buffer2[rep];
					printf("%d",atoi(val)+atoi(val2)); //Pasar de el documento csv a números para poder operarlos.
					printf("%s", ", ");
					repColumn++;
					cont++;
 				}
				rep++;
			}
			printf("\n");
			repColumn = 0;
			repFil++;
			rep++;
		}
	}
}


//Funcipon de resta.
void RestMatrix(char *buffer, char* buffer2)
{
	char *val;
	char *val2;
	int rep=0;
	int repFil=0;
	int repCol=0;
	int PCol=0;
	if((contFil(buffer) != contFil(buffer2)) || (contCol(buffer) != contCol(buffer2))) //Para poder hacer una suma o resta entre matrices es necesario que sean del mismo tamaño tanto de filas como de columnas.
	{
		printf("No es posible realizar la resta.");
	}
	else
	{
		while(repFil != contFil(buffer))
		{
			while(repCol != contCol(buffer))
			{
				if((buffer[rep] != ',') && (buffer[rep] != '\n'))  //Conteo de filas mediante el numero de \n y de colomnas mediante el numero de ("," + 1)
				{
					val = &buffer[rep];
					val2 = &buffer2[rep];
					printf("%d",atoi(val)-atoi(val2)); //Pasar de el documento csv a números para poder operarlos 
					printf("%s", ", ");
					repCol++;
				}
			rep++;
			}

		printf("\n");
		repCol = 0;
		repFil++;
		rep++;

		}
	}
}


//Funcion de guardado.
void Save(char* buffer, char* buffer2, FILE *fd_arch3,	FILE *fd_arch2, int* bufferT, int op1)
{
	char *val;
	char *val2;
	char v1 = 0;
	int rep = 0;
	int repFil = 0;
	int repColumn = 0;
	int columnStart = 0;
	long tam_arch2=0;

	while(repFil != contFil(buffer))
	{
		while(repColumn != contCol(buffer))
		{
			if((buffer[rep] != ',') && (buffer[rep] != '\n'))
			{
				val = &buffer[rep];
				val2 = &buffer2[rep];
				if(op1 = 0)
				{
					v1 = atoi(val) + atoi(val2);
				}
				else
				{
					v1 = atoi(val) - atoi(val2);
				}
				bufferT[rep] = v1;
				//printf("%d ", bufferT[rep]);
				repColumn++;
 			}
			rep++;
		}
		//printf("\n");
		repColumn = 0;
		repFil++;
		rep++;
	}

	fseek(fd_arch2, 0, SEEK_END);
	tam_arch2 = ftell(fd_arch2);//Se calcula el tamaño del archivo 2 para darle tamaño a la matriz.
	rewind (fd_arch2);

	fwrite(&bufferT, 1, tam_arch2, fd_arch3);//Se escribe la matriz resultante en el archivo dado por el usuario.
	fclose(fd_arch3);
}

