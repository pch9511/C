#include <stdio.h>
#include <stdlib.h>

//int 형 포인터  (*ap) 7~15 동적할당 랜덤  ex) 10 -> 10개 배열 2자리 자연수 중복 X 랜덤 오름차순 정렬 ==> ex ap int형 함수(배열,찾는값,시작위치(0),갯수(10개)) 
//==> 정중앙 데이터 를 찾는값과 비교 찾는값이 크면 오른쪽 재귀 작으면 왼쪽 재귀 다시 중앙 찾아서 재귀 반복해서 찾는값이 나오면 그 자리를 리턴해서 값을 구함 

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
	printf("찾는 값을 입력하세요 : ");
	scanf("%d",&k);
	i=0;
	temp=find(ap,k,i,a);
	if(temp!=-1){
	printf("%d번째 숫자입니다.",temp);
	}
	else{
	printf("찾는 값이 없습니다.");
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
