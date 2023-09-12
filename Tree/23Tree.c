#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data[2];
	struct tree *left;
	struct tree *right;
}TREE;

TREE *create();
void insert(TREE *,int);
int check(TREE *,int);
void del(TREE *,int);
void levelorder(T);



int main(int argc, char *argv[]) {
	TREE *T;
	int i,temp[]={10,60,40,35,50,55,45,20,5,8,9,11,7,4,6,1,65,58,56,49,47,53,52,67,70,62,61,68,69,37,27,17,36,34,33};
	
	T=create();
	for(i=0; i<sizeof(temp)/sizeof(temp[0]); i++){
		insert(T,temp[i]);
	}
	levelorder(T);
	while(1){
	/*	printf("숫자를 입력하세요 : ");
		scanf("%d",&i);
		if(i==-1) break;
		if(check(T,i)!=-1){
			insert(T,i);
			levelorder(T);
		}
		else{
			printf("중복입니다\n");
		}*/
		while(1){ 
			printf("지울 숫자를 입력하세요 : ");
			scanf("%d",&i);
			if(i==-1) break;
			if(check(T,i)==-1){			
				del(T,i);
				levelorder(T);
				break;
			}	
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
	a->left=NULL;
	a->right=NULL;
	
	return a;
}
void insert(TREE *T,int i){
	TREE *p,*o,*n,*m;
	int temp,j,check=0;
	
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
						if(p->right==NULL){
							m=create();
							p->right=m;
							m->data[0]=p->data[1];
							p->data[1]=0;
						}	
						n=create();
						p->left=n;
						n->data[0]=i;
						break;
					}
				}
				else{
					if(p->left->data[0]<i){
						n=p->left;
						while(n!=NULL){
							if(n->data[0]<i&&n->data[1]<i){
								j=-1;
							}
							else{
								j=0;
								break;
							}	
							n=n->right;
						}	
						if(j==-1&&p->data[1]==0){
							p->data[1]=p->data[0];
							p->data[0]=i;
							break;
						}
						else{
							p=p->left;
						}
					}
					else{
						p=p->left;
					}
				}
			}
			else if(p->data[1]<i){	
				if(p->right!=NULL){
					if(p->right->data[0]>i){
						if(p->data[1]==0){
							p->data[1]=i;
							break;
						}
						else{
							p=p->right;
						}
					}
					else{
						p=p->right;
					}
				}
				else{
					if(p->data[1]==0){
						p->data[1]=i;
						break;
					}
					else{
						if(p->left==NULL){
							n=create();
							p->left=n;
							n->data[0]=p->data[0];						
							p->data[0]=p->data[1];
							p->data[1]=0;
						}
						m=create();
						p->right=m;
						m->data[0]=i;
						break;
					}
				}
			}
			else{
				if(p->right!=NULL){
					check=-1;
					o=p;
					temp=p->data[0];
					p->data[0]=i;
					i=temp;
					j=p->data[1];
					p->data[1]=0;
					p=p->left;
				}
				else{
					n=create();
					m=create();
					p->left=n;
					p->right=m;
					n->data[0]=p->data[0];
					p->data[0]=i;
					m->data[0]=p->data[1];
					p->data[1]=0;
					break;
				}
				
			}
		}
		if(check==-1){
			insert(o->right,j);
		}
	}
}
int check(TREE *T,int c){
	TREE *q[1000],*w[1000];
	int i,j,child=1,n,level=0;
	
	q[0]=T;
	do{
		n=0;
		for(i=0; i<child; i++){
			if(q[i]->data[0]==c||q[i]->data[1]==c){
				return -1;
			}
			if(q[i]->left!=NULL){
				w[n++]=q[i]->left;
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
}
void del(TREE *T,int i){
	TREE *p,*o,*n;
	o=T;
	if(T->data[0]==i){
		if(T->left!=NULL){
			p=T->left;
			while(p->right!=NULL){
				o=p;
				p=p->right;
			}
			if(p->data[1]!=0){
				T->data[0]=p->data[1];
				p->data[1]=0;
			}
			else{
				T->data[0]=p->data[0];
				p->data[0]=0;
				if(o==T){
					o->left=T->left->left;
					free(p);
				}
				else{
					o->right=NULL;
					free(p);
				}
			}
			return;
		}
		else{
			if(T->right==NULL){
				T->data[0]=T->data[1];	
				T->data[1]=0; 
				return;
			}
			else{
				T->data[0]=T->data[1];
				T->data[1]=i;
			}
		}
	}
	if(T->data[1]==i){
		if(T->right!=NULL){
			p=T->right;
			while(p->left!=NULL){
				o=p;
				p=p->left;
			}
			T->data[1]=p->data[0];
			p->data[0]=p->data[1];
			p->data[1]=0;
			if(p->data[0]==0){
				if(o==T){
					o->right=T->right->right;
					free(p);
				}
				else{
					if(p->right==NULL){
						o->left=NULL;
					}
					else{
						o->left=p->right;
					}
					free(p);
				}
			}
		}
		else{
			T->data[1]=0;
		}
		return;
	} 
	p=T;
	while(1){
		if(p->data[0]>i){ 
			o=p;
			p=p->left; 
		}
		else if((p->data[1]==0&&p->data[0]<i)||(p->data[1]!=0&&p->data[1]<i)){
			o=p;
			p=p->right;
		}
		else if(p->data[0]==i||p->data[1]==i){
			if(p->left==NULL&&p->right==NULL){		
				if(p->data[1]==i){
					p->data[1]=0;
				}
				else{
					if(o->left==p){
						if(p->data[1]!=0){
							p->data[0]=p->data[1];
							p->data[1]=0;
						}
						else{ 
							o->left=NULL;
							free(p);
						}
					}
					else if(o->right==p){
						if(p->data[1]!=0){
							p->data[0]=p->data[1];
							p->data[1]=0;
						}
						else{
							o->right=NULL;
							free(p);
						}
					}
				}
			}
			else if(p->data[0]==i&&p->left!=NULL){ 
				n=p->left;
				o=p;
				while(n->right!=NULL){
					o=n;
					n=n->right;
				}
				if(n->data[1]!=0){
					p->data[0]=n->data[1];
					n->data[1]=0;
				}
				else{
					p->data[0]=n->data[0];
					if(o==p){
						o->left=p->left->left;
					}
					else{
						if(n->left==NULL){
							o->right=NULL;
						}
						else{
							o->right=n->left;
						}
					}
					free(n);
				}
			}
			else if(p->data[1]==i&&p->right!=NULL){
				n=p->right;
				o=p;
				while(n->left!=NULL){
					o=n;
					n=n->left;
				}
				if(n->data[1]!=0){
					p->data[1]=n->data[0];
					n->data[0]=n->data[1];
					n->data[1]=0;
				}
				else{
					if(p->data[0]==i){
						p->data[0]=n->data[0];
					}
					else{
						p->data[1]=n->data[0];
					}
					if(o==p){
						o->right=p->right->right;
					}
					else{
						if(n->right==NULL){
							o->left=NULL;	
						}
						else{
							o->left=n->right;
						}
					}
					free(n);
				}
			}
			else{ 
				if(p->data[1]==i){
					p->data[1]=0;
				}
				else if(p->data[0]==i&&p->data[1]==0){
					if(o->left==p){
						o->left=p->right;
					}
					else{
						o->right=p->right;
					}
				}
				else{
					p->data[0]=p->data[1];
					p->data[1]=0;
				}
			}
			return;
		}
	}
}
void levelorder(TREE *T){
	TREE *q[1000],*w[1000];
	int i,j,child=1,n,level=0;
	
	q[0]=T;
	do{
		n=0;
		printf("level : %d",level);
		for(i=0; i<child; i++){
			printf("\t(%d,%d)",q[i]->data[0],q[i]->data[1]);
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
