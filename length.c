#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	int len;
	int check;
	struct node *left;
	struct node *right;
}NODE;
typedef struct stack{
	char data;
	struct STACK *link;
}STACK;

NODE *create2();
STACK *create();
void push(STACK *,char);
char pop(STACK *);
int isempty(STACK *);
int main(int argc, char *argv[]) {
	
	NODE *H[8],*temp,*p;
	STACK *top;
	int i,j,length,passlen,check,k;
	char t,start,end,pass;
	
	srand((unsigned)time(NULL));
	top=create(); 
	for(i=0; i<8; i++){
		H[i]=create2();
		H[i]->data='A'+i;
		H[i]->len=rand()%9+1;
	}
	for(i=0; i<8; i++){
		while(1){
			j=rand()%2+0;
			k=rand()%8+0;
			if(j==0){
				if(H[i]->left==NULL&&i!=k&&H[k]->left!=H[i]&&H[k]->right!=H[i]&&H[i]->right!=H[k]){
					H[i]->left=H[k];
				}
			}
			else{
				if(H[i]->right==NULL&&i!=k&&H[k]->right!=H[i]&&H[k]->left!=H[i]&&H[i]->left!=H[k]){
					H[i]->right=H[k];
				}
			}	
			if(H[i]->left!=NULL&&H[i]->right!=NULL){
				break;
			}
		}
	}
	p=H[0];
	while(1){
		if(p->check==0&&p->left!=NULL&&p->right!=NULL){  
			push(top,p->data);
		}	
		if(p->check==1){
			if(isempty(top)==1){
				t=pop(top);
			}
			else{
				break;
			}
			for(i=0; i<8; i++){
				if(t==H[i]->data){
					p=H[i];
					break;
				}
			}
			p=p->right;	
		}
		else if(p->left!=NULL){
			p->check=1;
			p=p->left;
		}
		else if(p->right!=NULL){
			p->check=1;
			p=p->right;
		}
	}
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if(H[i]->len<H[j]->len){
				temp=H[i];
				H[i]=H[j];
				H[j]=temp;
			}
		}
	}
	for(i=0; i<8; i++){
		while(i==k){
			k=rand()%8+0;
		}
		printf("%c 의 길이 : %d\n",H[i]->data,H[i]->len);
		if(i<7){
			H[i]->left=H[i+1];	
		}
		else{
			H[i]->left=H[0];
		}
		H[i]->right=H[k];
	}
	printf("경로를 입력하세요 : ");
	scanf("%c %c",&start,&end);
	printf("%c -> %c\n",start,end);
	for(i=0; i<8; i++){
		if(H[i]->data==start) break;
	}	
	printf("경유지를 입력하세요 : ");
	fflush(stdin);
	scanf("%c",&pass);
	p=H[i];
	int min=0,num=0,cnt=0,pcheck=0;
	printf("최단 루트: ");
	p=H[i];
	min=0;
	num=0;
	cnt=0;
	t=' ';
	for(j=0; j<8; j++){
		min+=p->len;
		p=p->left;
	} 
	p=H[i];
	for(j=0; j<2; j++){	
		cnt=0;
		for(k=0; k<8; k++){
			p->check=0;
			p=p->left;
		}
		p=H[i];
		while(1){ 
			if(p->check==0&&p->left!=NULL&&p->right!=NULL){ 
				push(top,p->data);
				p->check=1;
			}
			if(p->data==end){
				if(j==1&&num==cnt){
					printf("%c",p->data);
				}				

				if(length<min){
					min=length;
					num=cnt;			
					if(isempty(top)==0){
						t=' ';
						break;
					} 
					t=pop(top);
					length=0;
					p=H[i];
				}
				else{
					if(isempty(top)==0){
						t=' ';
						break;
					} 					
					t=pop(top);
					length=0;
					p=H[i];
				}
				cnt++;
			}
			else if(p->data==t){
				length+=p->len;
				if(j==1&&num==cnt){
					printf("%c",p->data);
				}
				p=p->right;	
				t=' ';
			}			
			else if(p->left!=NULL){
				if(j==1&&num==cnt){ 
					printf("%c",p->data);
				}  
				length+=p->len;
				p=p->left;
			}
			else if(p->right!=NULL){
				if(j==1&&num==cnt){
					printf("%c",p->data);
				}
				length+=p->len;
				p=p->right;
			}			
		}
	}
	printf("\n");
	printf("최단 거리 : %d\n",min);
	printf("경유 루트: ");
	p=H[i];
	min=0;
	num=0;
	cnt=0;
	length=0;
	t=' ';
	char t2;
	for(j=0; j<8; j++){
		min+=p->len;
		p=p->left;
	} 
	p=H[i]; 
	for(j=0; j<2; j++){	
		cnt=0;
		pcheck=0;
		for(k=0; k<8; k++){
			p->check=0;
			p=p->left;
		}
		p=H[i];
		while(1){ 
			if(p->check==0&&p->left!=NULL&&p->right!=NULL){ 
				push(top,p->data);
				p->check=1;
			}
			if(p->data==pass){
				pcheck=1;
			}
			if(p->data==end){
				if(j==1&&num==cnt){
					printf("%c",p->data);
				}				

				if(length<min){
					if(pcheck==1){ 
						min=length;
						num=cnt;			
					}
					if(isempty(top)==0){
						t=' ';
						break;
					} 
					if(t2==pass){ 
						pcheck=0;
					}
					t=pop(top);
					length=0;
					p=H[i];
				}
				else{
					if(isempty(top)==0){
						t=' ';
						break;
					} 	
					if(t2==pass){
						pcheck=0;
					}				
					t=pop(top);
					length=0;
					p=H[i];
				}
				cnt++;
			}
			else if(p->data==t){
				length+=p->len;
				if(j==1&&num==cnt){
					printf("%c",p->data);
				}
				p=p->right;	
				t2=t;
				t=' ';
			}			
			else if(p->left!=NULL){
				length+=p->len;				
				if(j==1&&num==cnt){ 
					printf("%c",p->data);
				}  
				p=p->left;
			}
			else if(p->right!=NULL){
				if(j==1&&num==cnt){
					printf("%c",p->data);
				}
				length+=p->len;
				p=p->right;
			}			
		}
	}
	printf("\n경유 거리 : %d",min); 
	return 0;
}
STACK *create(){
	
	STACK *a;
	
	a=(STACK *)malloc(sizeof(STACK));
	a->data=' ';
	a->link=NULL;
	
	return a;
}
void push(STACK *top,char i){
	
	STACK *p,*n;
	
	n=create();
	n->data=i;
	p=top;
	
	n->link=p->link;
	p->link=n;
}
char pop(STACK *top){
	
	char i;
	
	STACK *p;
	p=top->link;
	top->link=p->link;
	i=p->data;
	free(p);
	
	return i;
}
int isempty(STACK *top){
	return top->link!=NULL;
}
NODE *create2(){
	
	NODE *a;
	
	a=(NODE *)malloc(sizeof(NODE));
	
	a->data=' ';
	a->len=0;
	a->check=0;
	a->left=NULL;
	a->right=NULL;
	
	return a;
}
