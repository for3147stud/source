#include <stdio.h>
#include <stdlib.h>
_Bool m_exp(int num);
int main(void){
	char str[80];
	int A;
	printf("Num: ");
	fgets(str,79,stdin);
	A=atoi(str);
	if(m_exp(A))
		printf("NO");
	else
		printf("YES");
}

_Bool m_exp(int num){
	if(num&(num-1))
		return 1;
	else
		return 0;
}