// ConsoleApplication3.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*
��� ����, ���������� ����� �� ������� ����� (�� ����� 50 �����). � ���������� ������� ������� ��� ������� ���������,
������� ������ � ������ �������� ����� � �� ������ �� � ���� ������ �����.
*/

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <locale>
#define SIZE 255

void mysort(char *Array, int Size);

void mysort(char *Array, int Size)
{
	int i,j;
    char tmp;
	for(i = 0; i<Size; i++){
		for (j = 0;j < Size; j++){
         //       printf("%s %s\n",Array[i],Array[j]);
			if(Array[j] > Array[j+1] && Array[j+1] != '\0'){
				tmp = Array[j+1];
				Array[j+1] = Array[j];
				Array[j] = tmp;
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
	char g[SIZE]; // read buffer
    int i,j,k,l,m; // counters
	int flag=0; // ������������ ���������� ������� � ������ �����.
	char allowc[26] = "����������������������#"; // ���������� �������
	char buf[sizeof(allowc)]=""; //���������� ��������. �����-�� ��� ��� ������ ����������
	setlocale(LC_ALL, "Russian");
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
			for(i=0; i<=chk-1;i++){
        		fscanf(fp,"     %s",g);
				words[i] = (char*)calloc(strlen(g),sizeof(char));
        		strcpy(words[i],g); // took string
              //printf("%s\n",words[i]); //test
        	}
			//�����
			for (i=1; i < chk;i+=2){ // ����� �� �������
				for (j=0; j < strlen(words[i]);j++){ //������ �����
					//������ ����������� ������� � ������ ���������� ������
					k=0;
					while (words[i][j] != allowc[k] && allowc[k] != '#') { //������� ���������?
						k+=1;
					}
					//���� ������� �� ������� ��������� ���� �� ������ ������
					if (allowc[k] != '#') {
						l=0;
						while (l<chk){ //����� ������ ����
							//printf("%d", strlen(words[l]));
							for (m=0;m < strlen(words[l]); m++){ // ������ ������� �����
								if (words[l][m] == allowc[k]) { // ���� ����������?
									m=strlen(words[l])-1; //����� �� ��������� �����. �������
									flag+=1; // ����������� ������������ ������
								}
							}
							if (flag == 0) { //� ������ ������ ��� ������ �������?
								//������� ����������� �����?		
								m=0; // ������ ������ ������
								while (buf[m] != '\0'  && buf[m] != allowc[k] ) {
									m+=1;
								}
								if (buf[m] != allowc[k]){
									strncat(buf,&allowc[k],1);
								}
							}
							l+=2;
							flag=0;
						}
					}
				}
			}
			//���������
			i=0;
			mysort(buf, strlen(buf)); // ���������
			while (buf[i] != '\0'){
				printf("%c\n",buf[i]);
				i+=1;
			}
	return 0;
}

