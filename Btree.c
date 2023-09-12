#include <stdio.h>	
#include <stdlib.h>
typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}TREE;

TREE *create();
void insert(TREE *,int);
int Tcheck(TREE *);
void roundcheck(TREE *);
void leftround(TREE *);
void rightround(TREE *);
void Lround(TREE *,int);
void Rround(TREE *,int);
void levelorder(TREE *);
void del(TREE *,int);

int main(int argc, char *argv[]) {
	int i,j;
	TREE *T,*p;
	T=create();
	while(1){
		printf("숫자를 입력하세요 : ");
		scanf("%d",&i); 
		if(i==-1) break;	
		insert(T,i);	
		roundcheck(T);
		levelorder(T);		
		printf("삭제할 숫자를 입력하세요 : ");
		scanf("%d",&j);
		if(j!=-1){
			del(T,j);
			roundcheck(T);
			levelorder(T); 
		}
	}

	return 0;
}
TREE *create(){
	TREE *a;
	
	a=(TREE *)malloc(sizeof(TREE));
	a->data=0;
	a->left=NULL;
	a->right=NULL;
	
	return a;
}
void insert(TREE *T,int i){
	TREE *n;
	if(T->data==0){
		T->data=i;
	}
	else{
		if(T->data>i){
			if(T->left==NULL){
				n=create();
				n->data=i;
				T->left=n;
			}
			else{
				return insert(T->left,i);
			}
		}
		else if(T->data<i){
			if(T->right==NULL){
				n=create();
				n->data=i;
				T->right=n;
			}
			else{
				return insert(T->right,i);
			}
		}
	}
}
int Tcheck(TREE *T){
	TREE *q[1000],*w[1000];
	int i,child,n,level,check=0;
	
	child=1;
	q[0]=T;
	level=0;
	
	do{
		n=0;
		for(i=0; i<child; i++){
			if(q[i]->left!=NULL){
				if(check==-1) return q[i]->data;
				w[n++]=q[i]->left;
			}
			else{
				check=-1;
			}
			if(q[i]->right!=NULL){
				if(check==-1) return q[i]->data;
				w[n++]=q[i]->right;
			}
			else{ 
				check=-1;
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
void roundcheck(TREE *T){
	int c;
	while((c=Tcheck(T))!=0){              
		if(T->left!=NULL&&T->right!=NULL){  
			if(c>T->data){ 			
				if(Tcheck(T->right)!=0){
					//printf("1.");
					Rround(T->right,c);
				//	levelorder(T);
				}
				else{		 
					if(Tcheck(T->left)==0){
					//	printf("2.");
						rightround(T);
					//	levelorder(T);
						roundcheck(T->left);
					}
					else{
					//	printf("3.");
						roundcheck(T->left);
					//	levelorder(T);
					}
				}
			}
			else if(c<T->data){ 	 
				if(Tcheck(T->left)!=0){ 
				//	printf("4.");	
					Lround(T->left,c);
				//	levelorder(T);
				}
				else{			
					if(Tcheck(T->right)==0){
					//	printf("5.");
						leftround(T);
					//	levelorder(T);
						roundcheck(T->right);
					}
					else{
					//	printf("6.");
						roundcheck(T->right);
					//	levelorder(T);
					}
				}
			}
		}	
		else if(T->left!=NULL&&T->right==NULL){				
		//	printf("7.");
			leftround(T);
		//	levelorder(T);
			if(T->left!=NULL){

				roundcheck(T->left);
			}
		}
		else{
		//	printf("8.");
			rightround(T);
		//	levelorder(T);
			if(T->right!=NULL){
				roundcheck(T->right);
			}
		}
	}
	return;	
}
void leftround(TREE *T){
	TREE *p,*o;	
	int temp;
	p=T->left;
	o=p; 
	if(p->right==NULL){
		T->left=p->left;
	}
	else{
		while(p->right!=NULL){
			o=p;
			p=p->right;
		}	
		if(p->left==NULL){
			o->right=NULL;
		}
		else{
			o->right=p->left;
		}
	}
	p->right=T->right;
	T->right=p;
	temp=T->data;
	T->data=p->data;
	p->data=temp;
	p->left=NULL;
}	
void rightround(TREE *T){
	TREE *p,*o;
	int temp;
	p=T->right;
	o=p; 
	if(p->left==NULL){
		T->right=p->right;
	}
	else{
		while(p->left!=NULL){
			o=p;
			p=p->left;
		}	
		if(p->right==NULL){
			o->left=NULL;
		}
		else{
			o->left=p->right;
		}
	}
	p->left=T->left;
	T->left=p;
	temp=T->data;
	T->data=p->data;
	p->data=temp;
	p->right=NULL;
}
void Lround(TREE *T,int i){
	TREE *o,*p;
	int temp;
	p=T;
	o=p;
	//printf("%d",i); 
	while(1){
		if(p->data>i){ 
			o=p;
			p=p->left;
		}
		else if(p->data<i){
			o=p;
			p=p->right;
		}
		else{
		//	printf("오긴해? %d %d",o->data,p->data); 
			if(p->left==NULL){  	//정렬이 안되어있을때 
				p->left=p->right;
				temp=p->data;
				p->data=p->left->data;
				p->left->data=temp;
				p->right=NULL;
			}
			else if(Tcheck(o)!=0){ 						//나머지
			//	printf("in");
				if(Tcheck(o->left)!=0){
				//	printf("들어옴2"); 
					roundcheck(o);
				}
				else{
				//	printf("들어옴"); 
					roundcheck(o);
				//	levelorder(T);
				}
			}
			else{
			//	printf("들어옴3"); 
				if(Tcheck(T->left)==0){
					leftround(T);
					roundcheck(T->right);
				}
				else{
					roundcheck(T->left);
				}
			}
			return;
		}
		//printf("%d : %d \n",i,p->data);
	}
}
void Rround(TREE *T,int i){
	TREE *o,*p;
	int temp;
	p=T;
	o=p;
	while(1){
		if(p->data>i){ 
			o=p;
			p=p->left;
		}
		else if(p->data<i){
			o=p;
			p=p->right;
		}
		else{
			if(p->left==NULL){  	//정렬이 안되어있을때 
				p->left=p->right;
				temp=p->data;
				p->data=p->left->data;
				p->left->data=temp;
				p->right=NULL;
			}
			else if(Tcheck(o)!=0){ 	
				if(Tcheck(o->left)!=0){
					roundcheck(o);
				}
				else{
					roundcheck(o);
				}
			}
			else{
				if(Tcheck(T->right)==0){
					rightround(T);
					roundcheck(T->left);
				}
				else{
					roundcheck(T->right);
				}
			}
			return;
		}
	}		
}
void levelorder(TREE *T){
	TREE *q[1000],*w[1000];
	int i,child,n,level;
	
	child=1;
	q[0]=T;
	level=0;
	
	do{
		n=0;
		printf("level : %d",level);
		for(i=0; i<child; i++){
			printf("%8d",q[i]->data);
			if(q[i]->left!=NULL){
				w[n++]=q[i]->left;
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
void del(TREE *T,int i){
	TREE *o,*p,*n;
	if(T->data==i){
		p=T->left;
		o=T; 
		if(T->left==NULL&&T->right==NULL){ 
			T->data=0;
		}
		else{
			while(p->right!=NULL){
				o=p;
				p=p->right;
			}
			T->data=p->data;
			if(o==T){
				T->left=NULL;
			}
			else{
				o->right=NULL;
			}
			free(p);
		}	
		return;
	}
	p=T;
	while(1){	
		if(p->data>i){ 
			o=p;
			p=p->left;
		}
		else if(p->data<i){
			o=p;
			p=p->right;
		}
		else{
			if(p->left==NULL&&p->right==NULL){
				if(o->left==p){
					o->left=NULL;
				}
				else{
					o->right=NULL;
				}
				free(p);
			}
			else if(p->left!=NULL){
				n=p->left;
				o=p;
				while(n->right!=NULL){
					o=n;
					n=n->right;
				}
				p->data=n->data;
				if(o==p){
					o->left=NULL;
				}
				else{
					o->right=NULL;
				}
				free(n);
			}
			else{
				n=p->right;
				o=p;
				while(n->left!=NULL){
					o=n;
					n=n->left;
				}
				p->data=n->data;
				if(o==p){
					o->right=NULL;
				}
				else{
					o->left=NULL;
				}
				free(n);
			}
			return;
		}
	}
}
