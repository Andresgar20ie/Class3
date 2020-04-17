#include "ejemplo.h"

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
