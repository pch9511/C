#include <stdio.h>
#include <stdlib.h>
typedef struct temp{
	int num;
	char apb;
}temp;

typedef struct node{
	temp data;
	struct node *link;
}NODE;

NODE *create();
void add(NODE *,int,char);
int count(NODE *);
int check(NODE *,char);
void print(NODE *);
void del(NODE *);

//33�� -> countNODE ,addNODE, �ߺ�üũ(checkNODE) , struct -> int 1~33 �ڵ����� ,char ��ҹ��� ���� 33�� -> ex)h->[1,c]->[2,k]->[3,u] printNode 
//deletenode h�� ����Ű�� �긦 ����� h�� ��ĭ�� �ű�� ������ �������� ����� ����� �Ȱ��� ��ȣ�� 2�� ���ƾ���   

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
	NODE *h;
	int i,chk,cnt=1;
	char res;
	
	h=create();
	while((i=count(h))!=33){
		while(1){
			while(1){
				res=rand()%58+'A';
				if(res>'Z'&&res<'a'){
					res=rand()%58+'A';
				}
				else break;
			}
			chk=check(h,res);
			if(chk!=1){
				break;
			}	
		}
		add(h,i+1,res);
	}
	while((i=count(h))!=2){
		del(h);
		print(h);
		printf("\n");
	}
	return 0;
}

NODE *create(){
	
	NODE *a;
	
	a=(NODE *)malloc(sizeof(NODE));
	a->data.num=0;
	a->data.apb=' ';
	a->link=NULL;
	
	return a;
}
void add(NODE *h,int i,char j){
	
	NODE *p,*n;
	
	n=create();
	n->data.num=i;
	n->data.apb=j;
	
	p=h;
	if(p->link==NULL){
		p->link=n;
		n->link=h->link;
	}
	else{
		do{
			p=p->link;
		}
		while(p->link!=h->link);
		n->link=p->link;
		p->link=n;
	}
}
int count(NODE *h){
	
	NODE *p;
	int cnt=0;
	
	p=h;
	if(p->link==NULL){
		return;
	}
	else{
		do{
			p=p->link;
			cnt++;
		}
		while(p->link!=h->link);
	}
	return cnt;
}
int check(NODE *h,char j){
	
	NODE *p;
	int ch=0;
	
	p=h;
	if(p->link==NULL){
		return;
	}
	else{
		do{
			p=p->link;
			if(p->data.apb==j){
				ch=1;
			}
		}
		while(p->link!=h->link);
	}
	return ch;
}
void print(NODE *h){
	
	NODE *p;
	
	p=h;
	if(p->link==NULL){
		printf("���� �����ϴ�.\n"); 
		return;	
	}
	else{
		do{
			p=p->link;
			printf("%d,%c\n",p->data.num,p->data.apb);
		}
		while(p->link!=h->link);
	}
}
void del(NODE *h){
	
	NODE *p,*o,*t,*k;
	
	p=h;
	p=p->link;
	k=p;	
	t=p;
	t->link=p->link;
	p=p->link;
	o=p;
	o->link=p->link;
	if(p->link==NULL){
		return;
	}
	else{
		do{
			p=p->link;
		}
		while(p->link!=h->link);		
		h->link=o->link;
		p->link=t->link;
		free(k);			
	} 
}
