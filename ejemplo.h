#ifndef EJEMPLO_H

	#define EJEMPLO_H

	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>

	int contCol(char* buffer);
	int contFil(char* buffer);
	void sumMatrix(char* buffer,char* buffer2);//Declaración de funciones a usar.
	void RestMatrix(char* buffer,char* buffer2);
	void Save(char* buffer, char* buffer2, FILE *fd_arch3,	FILE *fd_arch2, int* bufferT, int op1);
	
#endif
