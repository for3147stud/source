#include <stdio.h>
int counter(char *mas);
int main(void){
	char mas[80];
	printf("str: ");
	fgets(mas,79,stdin);
	int cont=counter(mas);
	for(int i=0,j=cont-1;i<cont/2;i++,j--){
		char tmp=mas[i];
		mas[i]=mas[j];
		mas[j]=tmp;
	}
	printf("mas: %s",mas);
}

int counter(char *mas){
	int c=0;
	for(int i=0;mas[i];++i){
		c++;
	}
	return c-1;
}