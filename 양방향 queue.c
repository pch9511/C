#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue{
	int data;
	struct Queue *Rlink;
	struct Queue *Llink;
}que; 

que *front,*rear;
que *create();
void Lenque(int);
void Renque(int);
int Ldelque();
int Rdelque();
int isempty();
void RRprint();
void RLprint();
void LLprint();
void LRprint();
int main(int argc, char *argv[]) {
	
	int i;
	
	front=create();
	rear=create();
	Lenque(10);
	Renque(20);
	Renque(30);
	Lenque(40);
	Renque(50);
	Lenque(60);
	Ldelque();
	LLprint();
	/*RRprint();
	RLprint();
	LLprint();
	LRprint();
	printf("\n");
	while(isempty()!=0){
		i=Rdelque();
		printf("Rdel : %d\n",i);
		RRprint();
		RLprint();
		LLprint();
		LRprint();
		printf("\n");
		i=Ldelque();
		printf("Ldel : %d\n",i);
		RRprint();
		RLprint();
		LLprint();
		LRprint();
		printf("\n");
	}*/
	return 0;
}

que *create(){

	que *a;
	
	a=(int *)malloc(sizeof(int));
	
	a->data=0;
	a->Llink=NULL;
	a->Rlink=NULL;
		
	return a;
}
void Lenque(int i){
	
	que *n,*p;

	n=create();
	n->data=i;
		
	if(rear->Llink==NULL){
		front->Rlink=n;
		rear->Llink=n;
	}
	else{
		front->Rlink->Llink=n;
		n->Rlink=front->Rlink;
		front->Rlink=n;
	}
}

void Renque(int i){
	
	que *n,*p;

	n=create();
	n->data=i;
		
	if(front->Rlink==NULL){
		front->Rlink=n;
		rear->Llink=n;
	}
	else{
		rear->Llink->Rlink=n;
		n->Llink=rear->Llink;
		rear->Llink=n;
	}
}
int Ldelque(){
	
	int j;
	que *p;
	
	p=rear->Llink;
	if(rear->Llink==NULL){
		printf("삭제할 데이터 없음\n"); 
		return;
	}
	else if(front->Rlink==rear->Llink){
		j=p->data;
		front->Rlink=NULL;
		rear->Llink=NULL;
		free(p);
		
	}
	else{
		j=p->data;
		rear->Llink=p->Llink;
		p->Llink->Rlink=p->Rlink;
		free(p);
	}
	return j;	
}

int Rdelque(){
	
	int j;
	que *p;
	
	p=front->Rlink;
	if(front->Rlink==NULL){
		printf("삭제할 데이터 없음\n"); 
		return;
	}
	else if(front->Rlink==rear->Llink){
		j=p->data;
		front->Rlink=NULL;
		rear->Llink=NULL;
		free(p);
		
	}
	else{
		j=p->data;
		front->Rlink=p->Rlink;
		p->Rlink->Llink=p->Llink;
		free(p);
	}
	return j;	
}

int isempty(){
	return rear->Llink!=NULL;	
}
void RRprint(){
	
	que *p;
	
	p=front;
	printf("RR : ");
	while(p->Rlink!=NULL){
		p=p->Rlink;
		printf("%d ",p->data);
	}
	printf("\n");
}

void RLprint(){

	que *p;
	
	p=front->Rlink;
	printf("RL : ");
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->Llink;
	}
	printf("\n");
}

void LLprint(){
	
	que *p;
	
	p=rear;
	printf("LL : ");
	while(p->Llink!=NULL){
		p=p->Llink;
		printf("%d ",p->data);
	}	
	printf("\n");
}

void LRprint(){
	
	que *p;
	
	p=rear->Llink;
	printf("LR : ");
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->Rlink;
	}
	printf("\n");
}
