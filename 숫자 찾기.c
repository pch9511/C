#include <stdio.h>
#include <stdlib.h>

//int �� ������  (*ap) 7~15 �����Ҵ� ����  ex) 10 -> 10�� �迭 2�ڸ� �ڿ��� �ߺ� X ���� �������� ���� ==> ex ap int�� �Լ�(�迭,ã�°�,������ġ(0),����(10��)) 
//==> ���߾� ������ �� ã�°��� �� ã�°��� ũ�� ������ ��� ������ ���� ��� �ٽ� �߾� ã�Ƽ� ��� �ݺ��ؼ� ã�°��� ������ �� �ڸ��� �����ؼ� ���� ���� 

int find(int *,int,int,int);

int main(int argc, char *argv[]) {
	
	int *ap,a,i=0,j,temp,k;
		
	srand((unsigned int)time(NULL)); 
	
	a=rand()%9+7;
	ap=(int *)malloc(a*sizeof(int));
	
	for(i=0; i<a; i++){
		ap[i]=rand()%90+10;
		for(j=0; j<i; j++){
			if(ap[i]==ap[j]){
				i--;
				break;
			}
		}
	}
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){
			if(ap[i]<ap[j]){
				temp=ap[i];
				ap[i]=ap[j];
				ap[j]=temp;
			}
		}
	}
	for(i=0; i<a; i++){
		printf("%d\t",ap[i]);
	}
	printf("\n");
	printf("ã�� ���� �Է��ϼ��� : ");
	scanf("%d",&k);
	i=0;
	temp=find(ap,k,i,a);
	if(temp!=-1){
	printf("%d��° �����Դϴ�.",temp);
	}
	else{
	printf("ã�� ���� �����ϴ�.");
	}
	
	return 0;
}
int find(int *ap,int k,int f,int a){
	
	int ans=(a+f)/2;

	if(a<f){
		return -1;
	}
	if(ap[ans]>k){								
		return find(ap,k,f,ans-1); 	
	}	
	if(ap[ans]<k){
		return find(ap,k,ans+1,a); 
	}
	return ans+1;
}
