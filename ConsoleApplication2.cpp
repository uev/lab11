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
void exchange(char ** SArray, int lseek,int rseek);

void exchange(char ** SArray, int lseek,int rseek) { // обмен значений
	char * tmp;
	tmp = SArray[lseek];
    SArray[lseek] = SArray[rseek];
    SArray[rseek] = tmp;
}

void mysort(char **Array, int Size,int flag)
{
	/*
	 * flag - exersize variable
	 */
        int i=0,j,seek=0;
		for(i = 0; i<Size; i++){
                for(j = i+1; j<Size; j++){
                 //       printf("%s %s\n",Array[i],Array[j]);
						while (Array[i][seek] == Array[j][seek]) {
								seek+=1;
							}
						if (flag == 2) {
							if(Array[i][seek]<Array[j][seek]){
								exchange(Array,i,j);
							 }
                        } else {
                        	if(Array[i][seek]> Array[j][seek]){
								exchange(Array,i,j);
                        	}
                        }
                seek=0;
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
    // 2 - сортировка по убыванию кодов символов, 1 - сортировка по возрастанию кодов символов
    fscanf(fp,"%s",g);
    if (g[0] == '1' && strlen(g) == 1){
		flag+=1;
    } else if (g[0] =='2' && strlen(g) == 1){
		flag=2;
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