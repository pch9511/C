#include <stdio.h>
#include <stdlib.h>

typedef struct TREE{
	int data;
	struct TREE *Llink;
	struct TREE *Rlink;
}tree;



tree *create();
void insert(tree *,int);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
int countnode(tree *);
//데이터 1 L R 하나씩 링크 create 제외 모두 재귀 
//insert(삽입) ,create(동적할당)->값이 =0 
//exinsert(T,10) h->data가 0이면 대입  
//inorder(T)왼루오 우선으로  preorder(T)루왼오  postorder(T)왼오루 

int main(int argc, char *argv[]) {
	
	tree *T;
	int i=1,cnt=0;
	
	T=create();
	insert(T,10);
	insert(T,5);
	insert(T,15);
	insert(T,3);
	insert(T,8);
	insert(T,23);
	inorder(T);
	printf("\n");
	preorder(T);
	printf("\n");
	postorder(T);
	printf("\n");
	cnt=countnode(T);
	printf("%d\n ",cnt);
	return 0;
}


tree *create(){
	
	tree *a;
	a=(int *)malloc(sizeof(int));
	
	a->data=0;
	a->Llink=NULL;
	a->Rlink=NULL;
	
	return a;
	
}
void insert(tree *T,int i){
	
	tree *n;
	n=create();
	n->data=i;
	
	if(T->data==0){
		T->data=n->data;
	}
	else if(T->data>i){			
			if(T->Llink==NULL){
				T->Llink=n;
				return ;
			}
			insert(T->Llink,i);
	}
	else if(T->data<i){	
			if(T->Rlink==NULL){
				T->Rlink=n;
				return ;
			}
			insert(T->Rlink,i);
	}
}
void inorder(tree *T){
	if(T!=NULL){ 
		inorder(T->Llink);
		printf(" %d ",T->data);
		inorder(T->Rlink);
	}
}
void preorder(tree *T){
	if(T!=NULL){
		printf(" %d ",T->data);
		inorder(T->Llink);
		inorder(T->Rlink);
	}
}
void postorder(tree *T){
	if(T!=NULL){
		inorder(T->Llink);
		inorder(T->Rlink);
		printf(" %d ",T->data);
	}
}
int countnode(tree *T){
	if(T!=NULL) return 1+countnode(T->Llink)+
}
