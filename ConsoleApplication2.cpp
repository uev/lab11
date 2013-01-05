/*
 ============================================================================
 Name        : lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : 17. Дан символьный файл. Упорядочить его элементы по (1) возрастанию,
  	  	  	  	   (2) убыванию их кодов (код действия содержится в первой строке входного файла).
  	  	  	  	   Известно, что в файле не более 20 строк.
 ============================================================================
 */
#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIZE 255

void mysort(char **Array, int Size,int flag);

void mysort(char **Array, int Size,int flag)
{
	/*
	 * flag - exersize variable
	 */
        int i,j;
        char *tmp;
        for(i = 0; i<Size; i++){
                for(j = i+1; j<Size; j++){
                 //       printf("%s %s\n",Array[i],Array[j]);
						if (flag == 0) {
							if(strlen(Array[i])>strlen(Array[j])){
								tmp = Array[i];
                                Array[i] = Array[j];
                                Array[j] = tmp;
							 }
                        } else {
                        	if(Array[i][0]> Array[j][0]){
                        	     tmp = Array[i];
                        	     Array[i] = Array[j];
                        	     Array[j] = tmp;
                        	}
                        }
                }
        }
}


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
    int chk=0; // words counter
    int getch; // read char
    char **words; //words array
	char g[SIZE];
    int i;
    int flag=0; // маркер задачи
	fp = fopen("input.txt","r");
	if (fp == NULL) {
		puts("Error reading file!");
        return 255;
    }
    //counting words
    getch = fgetc(fp);
    while(getch != EOF){
		if ( getch == ' ' || getch == '\n') {
			chk+=1;
        }
        getch = fgetc(fp);
	}
    rewind(fp); // reset
    words = (char**)calloc(chk-1, sizeof(char*));
    // 0 - сортировка по длине строк, 1 - сортировка по кодам символов
    fscanf(fp,"%s",g);
    if (g[0] == '1' && strlen(g) == 1){
		flag+=1;
    } else if (g[0] =='0' && strlen(g) == 1){
		flag=0;
    } else{
		puts("Error. Expected 0 or 1 on first line.");
        return -1;
    }		
	for(i=0; i<=chk-1;i++){
		fscanf(fp,"     %s",g);
		words[i] = (char*)calloc(strlen(g),sizeof(char));
        strcpy(words[i],g); // took string
        //printf("%s\n",words[i]); //test
    }
    mysort(words,chk,flag);
    for (i=0; i <= chk-1; i++) {
		printf("%s\n",words[i]);
    }
	fclose(fp);
	return 0;
}