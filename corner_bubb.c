#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int returnInt(char *str);
void printMat(int *mat,int line, int col);
void sortMat(int line, int col,int *mat);
int main(int argc,char **argv){
	if(argc!=3){
		printf("Syntax: %s <line> <col>\n",argv[0]);
		exit(1);
	}
	unsigned int line=-1, col=-1;
	int c_line,c_col;
	int p,max;
	int lil=9;
	line=returnInt(argv[1]);
	col=returnInt(argv[2]);
	int mat[line][col];
	for(int i=0;i<line;++i){
		for(int t=0;t<col;++t){
			mat[i][t]=lil-2*i-3*t;
		}
	}
	printMat(*mat, line,col);
	printf("\n");

	sortMat(line,col,&mat[0][0]);
	printf("\n");
	printMat(*mat,line,col);
	return 0;
}

void sortMat(int line, int col,int *mat){
	int p;
	for(int s=0;s<line*col;++s){
		for(int i=0;i<line;++i){
			for(int t=col-1;t>=0;--t){
				if(i+1==line && t==0)	continue;
				if(t==0 && (*(mat+i*col+t)<*(mat+((i+1)*col)+col-1))){
					p=*(mat+i*col+t);
					*(mat+i*col+t)=*(mat+((i+1)*col)+col-1);
					*(mat+((i+1)*col)+col-1)=p;
				}
				else if(*(mat+i*col+t)<*(mat+i*col+t-1) && t!=0){
					p=*(mat+i*col+t);
					*(mat+i*col+t)=*(mat+i*col+t-1);
					*(mat+i*col+t-1)=p;
				}
			}
		}
	}	
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