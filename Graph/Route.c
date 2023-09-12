#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char data;
	int c[4];
	int cnt;
	struct Node *link[3];
}node;

node *create();

int main(int argc, char *argv[]) {
	
	node *H[4],*p,*o;
	int **ap,i,j,k=0,check=0;
	
	
	ap=(int **)malloc(4*sizeof(int *));
	for(i=0; i<4; i++){ 
		ap[i]=(int *)malloc(4*sizeof(int));
		H[i]=create();
		H[i]->data='A'+i;
	}
	
	srand((unsigned int)time(NULL));
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(i==j){
				ap[i][j]=0;
			}
			else{
				ap[i][j]=rand()%2+0;
				if(ap[i][j]==1){
					if(H[i]->link[0]==NULL){			
						H[i]->link[0]=H[j];
					}
					else if(H[i]->link[1]==NULL){ 
						H[i]->link[1]=H[j];
					}
					else{
						H[i]->link[2]=H[j];
					}
				}
			}
		}	
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d",ap[i][j]);
		}
		printf("\n");
	}					
	for(i=0; i<4; i++){	//A,B,C,D의 방향 개수를 체크   
		for(j=0; j<3; j++){			
			if(H[i]->link[j]!=NULL){
				H[i]->cnt++;
			}
		}
	}
//	for(i=0; i<4; i++){	     //A,B,C,D 순차적으로 대입 
		for(j=0; j<4; j++){	//체크 코드 초기화 
			H[j]->c[3]=0;
		}
		p=H[0];		
		k=0;
		printf("%c : ",p->data);
		p->c[3]=1;
		for(j=0; j<p->cnt; j++){
			o=p->link[j];
			while(1){
				if(o->c[k]==0&&o->link[k]->c[3]==0){
					printf("%c",o->data);
					o->c[3]=1;
					o->c[k]=1;
					o=o->link[k];
					k=0;
				}
				else{
					k++;
				}
			}
		printf("\n");
		}
//	}				
	return 0;
}
node *create(){
	int i;
	node *a; 
	
	a=(node *)malloc(sizeof(node));
	
	a->data=' ';
	for(i=0; i<4; i++){
		a->c[i]=0;
	}
	a->cnt=0;
	for(i=0; i<3; i++){	
		a->link[i]=NULL;
	}
	
	return a;
}
