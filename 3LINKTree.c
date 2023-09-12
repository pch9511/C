#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data[2];
	char dat;
	struct tree *left;
	struct tree *right;
	struct tree *mid;
}TREE;

TREE *create();
void insert(TREE *,int);
int check(TREE *,int);
void levelorder(TREE *);

int main(int argc, char *argv[]) {
	TREE *T;
	int i;
	
	T=create();
	while(1){
		printf("숫자를 입력하세요 : ");
		scanf("%d",&i);
		if(i==-1) break; 
		if(check(T,i)==-1){
			printf("중복입니다.\n");
		}
		else{
			insert(T,i);
			levelorder(T);
		}
	}
	return 0;
}
TREE *create(){
	TREE *a;
	int i;
	a=(TREE *)malloc(sizeof(TREE));
	
	for(i=0; i<2; i++){
		a->data[i]=0;
	}
	a->dat=' ';
	a->left=NULL;
	a->mid=NULL;
	a->right=NULL;
	
	return a;	
}
void insert(TREE *T,int i){
	TREE *n,*p;
	
	if(T->data[0]==0){
		T->data[0]=i;
	}
	else{
		p=T;
		while(1){
			if(p->data[0]>i){
				if(p->left==NULL){
					if(p->data[1]==0){
						p->data[1]=p->data[0];
						p->data[0]=i;
						break;
					}
					else{
						n=create();
						p->left=n;
						n->data[0]=i;
						n->dat='L';
						break;
					}
				}
				else{
					p=p->left;
				}
			}
			else if(p->data[1]<i){
				if(p->right==NULL){
					if(p->data[1]!=0){
						n=create();
						p->right=n;
						n->data[0]=i;
						n->dat='R';
						break;
					}
					else{
						p->data[1]=i;
						break;
					}
				}
				else{
					p=p->right;
				}
			}
			else{
				if(p->mid==NULL){
					n=create();
					p->mid=n;
					n->data[0]=i;
					n->dat='M';
					break;
				}
				else{
					p=p->mid;
				}
			}
		}
	}
}
int check(TREE *T,int a){
	TREE *q[1000],*w[1000];
	int i,j,child=1,n,level=0;
	
	q[0]=T;
	do{
		n=0;
		for(i=0; i<child; i++){
			if(q[i]->data[0]==a||q[i]->data[1]==a){
				return -1;
			}
			if(q[i]->left!=NULL){
				w[n++]=q[i]->left;
			}
			if(q[i]->mid!=NULL){
				w[n++]=q[i]->mid;
			}
			if(q[i]->right!=NULL){
				w[n++]=q[i]->right;
			}
		}
		child=n;
		for(i=0; i<child; i++){
			q[i]=w[i];
		}
		level++;
	}while(child!=0);	
	return 0;		
}
void levelorder(TREE *T){
	TREE *q[1000],*w[1000];
	int i,j,child=1,n,level=0;
	
	q[0]=T;
	do{
		n=0;
		printf("level : %d",level);
		for(i=0; i<child; i++){
			printf("\t%c(%d,%d)",q[i]->dat,q[i]->data[0],q[i]->data[1]);
			if(q[i]->left!=NULL){
				w[n++]=q[i]->left;
			}
			if(q[i]->mid!=NULL){
				w[n++]=q[i]->mid;
			}
			if(q[i]->right!=NULL){
				w[n++]=q[i]->right;
			}
		}
		printf("\n");
		child=n;
		for(i=0; i<child; i++){
			q[i]=w[i];
		}
		level++;
	}while(child!=0);	
	printf("\n");		
}
