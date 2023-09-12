#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char alp;
	struct Node *link;
}NODE;

NODE *create();
int count(NODE *);
int check(NODE *,char);
void add(NODE *,char);
void print(NODE *);
void sort(NODE *,char *);
int check2(NODE *,char *);
void sort2(NODE *,char *,int);
void del(NODE *,char *);
int main(int argc, char *argv[]) {
	
	NODE *h;
	srand((unsigned)time(NULL));
	int chk,i=0;
	char str[7],res;
	
	h=create();
	while((i=count(h))!=26){
		while(1){
			res=rand()%26+'A';
			if((chk=check(h,res))!=1){
				break;
			}	 
		}
		add(h,res);
	}	 
	print(h);
	while(1){
		printf("알파벳 입력 : ");
		scanf("%s",str); 
		if(strlen(str)>7){
			printf("정렬 불가\n");
		}
		else{
			break;
		}
	}
	sort(h,str);
	print(h);
	while(1){
		if((chk=check2(h,str))!=strlen(str)){ 
			sort2(h,str,chk);	
		}
		else{
			break;
		}
	}
	del(h,str);
	print(h);
	return 0;
}

NODE *create(){
	
	NODE *a;
	
	a=(NODE *)malloc(sizeof(NODE));
	a->alp=' ';
	a->link=NULL;
	
	return a;
}
void add(NODE *h,char j){
	
	NODE *p,*n;
	
	n=create();
	n->alp=j;
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
			if(p->alp==j){
				ch=1;
				return ch;
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
			printf("%c ",p->alp);
		}
		while(p->link!=h->link);
	}printf("\n");
}
void sort(NODE *h,char *str){
	
	NODE *p,*o,*t;
	int i,cnt=0,ch=0;
	p=h;
	for(i=0; i<strlen(str); i++){
		do{
			o=p;
			p=p->link;
			if(p->alp==str[i]-32){
				if(o->link!=h->link){
					o->link=p->link;
					t=p;
				}
				else{
					ch=1;
				}
			}
		}while(p->link!=h->link);
		if(i==0){
			if(ch==0){
				t->link=h->link;
				h->link=t;
				p->link=t;	
			}
		}
		else{
			do{
				o=p;
				p=p->link;
				cnt++;
				if(cnt==i*(26/strlen(str))+1){
					t->link=o->link;
					o->link=t;
				}
			}while(p->link!=h->link);
				cnt=0;
		}
	}
}

int check2(NODE *h,char *str){

	NODE *p,*o,*t;
	int i,cnt=0,chk=0;
	
	p=h;
	
	for(i=1; i<strlen(str); i++){
		do{
			o=p;
			p=p->link;
			cnt++;
			if(cnt==i*(26/strlen(str))+1&&p->alp!=str[i]-32){
				return i;
			}
		}while(p->link!=h->link);
		cnt=0;	
	}
	return i;
}		
void sort2(NODE *h,char *str,int a){
	
	NODE *p,*o,*t;
	int cnt=0; 
	p=h;
	do{
		o=p;
		p=p->link;
		if(p->alp==str[a]-32){
			o->link=p->link;
			t=p;
		}
	}while(p->link!=h->link);
	do{
		o=p;
		p=p->link;
		cnt++;
		if(cnt==a*(26/strlen(str))+1){
			t->link=o->link;
			o->link=t;
		}			
	}while(p->link!=h->link);
		cnt=0;
}
void del(NODE *h,char *str){

	NODE *p,*o;
	int cnt=0;
	
	p=h;
	do{
		p=p->link;
		cnt++;
		if(cnt==(26/strlen(str))*strlen(str)){ 
			o=p;
		}
	}while(p->link!=h->link);
		o->link=p->link;
		free(p);
}

			
			
			
