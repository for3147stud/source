#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int returnInt(char *str);
void printMat(int *mat,int line, int col);
int main(int argc,char **argv){
	if(argc!=3){
		printf("Syntax: %s <line> <col>\n",argv[0]);
		exit(1);
	}
	unsigned int line=-1, col=-1;
	line=returnInt(argv[1]);
	col=returnInt(argv[2]);
	int mat[line][col];
	for(int i=0;i<line;++i){
		for(int t=0;t<col;++t){
			mat[i][t]=3+2*i+3*t;
		}
	}
	printMat(*mat, line,col);
	printf("\n");
	for(int i=0;i<line;++i)
		for(int t=0; t<col;++t)
			if(i==t)
				mat[i][i]=666;
	printMat(*mat,line,col);
	return 1;
}

void printMat(int *mat,int line, int col){
	for(int i=0;i<line;++i){
		for(int t=0;t<col;++t){
			printf("%d\t",*(mat+i*col+t));
		}
		printf("\n");
	}
}

int returnInt(char *str){
	int count=0,retInt=0;
	char Ares[80];
	memset(Ares, 0, sizeof(Ares));
	for(register int t=0;t<strlen(str);++t){
			if(isdigit(str[t])){
				Ares[count]=str[t];
				count++;
			}
			else continue;
	}	
	retInt=atoi(Ares);
	return retInt;
}