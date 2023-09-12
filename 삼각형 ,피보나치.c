#include <stdio.h>
#include <stdlib.h>


void star(int,int);
int star2(int,char);
//star(int) star2(int) -> if star(5) -> star star2 활용해서 삼각형 * 
int add(int,int );
int add2(int,int );
void p(int);
int p2(int );

int main(int argc, char *argv[]) {

	int i,a=0,j;

	printf("숫자를 입력하세요 : ");
	scanf("%d",&i);
	/*j=i;
	star(i,j);
	j=add(i,a);
	printf("합계 : %d",j);*/	
	int pb[i];
	pb[0]=1;
	pb[1]=1;
	p(i);
	return 0;
}
void star(int i,int j){
	
	if(i==0) return;
	star2(i-1,' ');	
	star2(j-i+1,'*');
	printf("\n");		
	star(i-1,j);
}
int star2(int i,char str){  
									
	if(i==0) return;
	printf("%c",str);
  	star2(i-1,str);
}

int add(int i,int a){
	
	int res=0,j;
	
	if(i==0) return a;
	else j=add2(i,res); a+=j; add(i-1,a);
}

int add2(int i,int res){
	
	if(i==0) return res;
	else res+=i; add2(i-1,res);
}

void p(int i){ 
	
	int res=0;
	
	if(i==0) return;	
	p(i-1); res=p2(i); printf("%d ",res);
}

int p2(int i){
	
	if(i==1||i==2) return i;
	else return p2(i-1)+p2(i-2);
}


 
