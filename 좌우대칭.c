#include <stdio.h>
#include <stdlib.h>

void a(int);



// 3 -> 1 2 1 3 1 2 1       4-> 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1  �¿��Ī 


int main(int argc, char *argv[]) {
	
	int i,j;
	
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d",&i);
	a(i);	
	return 0;
}

void a(int i){
	if(i==0) return ;

	a(i-1);
	printf("%d",i);
	a(i-1);
	
}
 
