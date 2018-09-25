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
	int c_line,c_col;
	int p,max;
	line=returnInt(argv[1]);
	col=returnInt(argv[2]);
	int mat[line][col];
	for(int i=0;i<line;++i){
		for(int t=0;t<col;++t){
			mat[i][t]=3+2*i-3*t;
		}
	}
	printMat(*mat, line,col);
	printf("\n");

 	max=mat[0][0];
	for(int i=0;i<line;++i)
		for(int t=0;t<col;++t)
			if(mat[i][t]>max){
				max=mat[i][t];
				c_line=i;
				c_col=t;
			}
	if(!(c_line==0)){
		for(int i=0;i<col;++i){
		p=mat[0][i];
		mat[0][i]=mat[c_line][i];
		mat[c_line][i]=p;
		}
	}
	if(!(c_col==(col-1))){
		for(int i=0;i<line;++i){
			p=mat[i][col-1];
			mat[i][col-1]=mat[i][c_col];
			mat[i][c_col]=p;
		}
	}
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