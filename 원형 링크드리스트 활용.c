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

//33건 -> countNODE ,addNODE, 중복체크(checkNODE) , struct -> int 1~33 자동증가 ,char 대소문자 포함 33건 -> ex)h->[1,c]->[2,k]->[3,u] printNode 
//deletenode h가 가르키는 얘를 지우고 h는 두칸씩 옮기기 꼬리는 다음으로 몇번을 지우든 똑같은 번호가 2개 남아야함   

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
		printf("값이 없습니다.\n"); 
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
