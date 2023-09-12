#include <stdio.h>
#include <stdlib.h>

// 대<-h->소(26개 중복 X 랜덤) printf 대문자-> 오른쪽 print 소문자 ->왼쪽   대문자 순서에 맞춰서 소문자에 있는 알파벳을 찾아 자리에 맞춰서 넣기 
typedef struct NODE{
	char data;
	struct NODE *Llink;
	struct NODE *Rlink;
}dblist; 

dblist *create();
int countlower(dblist *);
int countupper(dblist *);
int checklower(dblist *,char);
int checkupper(dblist *,char);
void addlower(dblist *,char);
void addupper(dblist *,char);
void pright(dblist *);
void pleft(dblist *);
void sort(dblist *,int);

int main(int argc, char *argv[]) {
	
	dblist *h,*p;
	srand((unsigned)time(NULL));
	int cnt=0;
	char s;
	
	h=create();
	while(countlower(h)!=26){
		while(1){
			s=rand()%26+'a';
			if(checklower(h,s)!=1){
				break;
			}
		} 
		addlower(h,s);
	}
	pright(h);
	p=h;
	while(countupper(h)!=26){
		while(1){
			s=rand()%26+'A';
			if(checkupper(h,s)!=1){
				break;
			}
		}
		addupper(h,s);
	}
	pleft(h);
	while(cnt!=26){	
		sort(h,cnt);
		cnt++;
		printf("%d------------------\n", cnt-1);
		pright(h);
		pleft(h);
	}


	
	return 0;
}

dblist *create(){
	
	dblist *a;
	
	a=(dblist *)malloc(sizeof(dblist));
	a->data=' ';
	a->Llink=NULL;
	a->Rlink=NULL;
	
	return a;
}
int countlower(dblist *h){
	
	dblist *p;
	int cnt=0;
	
	p=h;
	if(p->Rlink==NULL){
		return ;
	}
	do{
		p=p->Rlink;
		cnt++;
	}while(p->Rlink!=h->Rlink);
	return cnt;
}
int countupper(dblist *h){
	
	dblist *p;
	int cnt=0;
	
	p=h;
	if(p->Llink==NULL){
		return;
	}
	do{	
		p=p->Llink;
		cnt++;
	}while(p->Llink!=h->Llink);
	return cnt;
}
int checklower(dblist *h,char s){
	
	dblist *p;
	
	p=h;
	if(p->Rlink==NULL){
		return;
	}
	do{
		p=p->Rlink;
		if(p->data==s){
			return 1;
		}
	}while(p->Rlink!=h->Rlink);
	return 0;
}
int checkupper(dblist *h,char s){
	
	dblist *p;

	p=h;
	if(p->Llink==NULL){
		return ;
	}
	do{
		p=p->Llink;		
		if(p->data==s){
			return 1;
		}
	}while(p->Llink!=h->Llink);
	return 0;
}
void addlower(dblist *h,char s){
	
	dblist *p,*n;
	
	n=create();
	n->data=s;
	
	p=h;
	if(p->Rlink==NULL){
		p->Rlink=n;
		n->Llink=p->Rlink;
		n->Rlink=p->Rlink;
	}
	else{
		do{
			p=p->Rlink;
			if(h->Rlink==p){
				p->Llink=n;
			}
		}while(p->Rlink!=h->Rlink);
			n->Rlink=p->Rlink;
			p->Rlink=n;
			n->Llink=p;
	}
}
void addupper(dblist *h,char s){
	dblist *p,*n;
	
	n=create();
	n->data=s;
	
	p=h;
	if(p->Llink==NULL){
		p->Llink=n;
		n->Rlink=p->Llink;
		n->Llink=p->Llink;
	}
	else{
		do{
			p=p->Llink;
			if(h->Llink==p){
				p->Rlink=n;
			}
		}while(p->Llink!=h->Llink);
			n->Llink=p->Llink;
			p->Llink=n;
			n->Rlink=p;
	}
}	
void pright(dblist *h){
	
	dblist *p;
	
	p=h->Rlink;
	do{
		printf("%c",p->data);
		p=p->Llink;
	}while(p!=h->Rlink);
	printf("\n");
}
void pleft(dblist *h){
	
	dblist *p;
	
	p=h->Llink;
	do{	
		printf("%c",p->data);
		p=p->Rlink;
	}while(p!=h->Llink);
	printf("\n");
}
void sort(dblist *h,int res){
	
	dblist *p,*o,*t,*k;
	char a,c=0;
	int i=0,cnt=0;
	
	p=h->Llink;
	a=p->data+32;
	h->Llink=p->Llink;
	p=h;
	do{	
		o=p;
		p=p->Rlink;
		if(a==p->data){
			if(h->Rlink==p){
				t=p;
				c=1;
			}
			else{	
				o->Rlink=p->Rlink;	
				p->Rlink->Llink=o;	
				p->Rlink=NULL;
				p->Llink=NULL;
				t=p;
				break;
			}
		}
	}while(p->Rlink!=h->Rlink);
		if(c==1){
			t->Rlink->Llink=t->Llink;
			h->Rlink=t->Rlink;
			p->Rlink=t->Rlink;				
			t->Rlink=NULL;
			t->Llink=NULL;
			c=0;	
		}
	p=h->Rlink;
	do{	
		if(res==25){
			t->Rlink=p->Rlink;
			p->Rlink->Llink=t;;
			p->Rlink=t;
			t->Llink=p;
			break;
		}
		if(cnt==res){	
			if(h->Rlink==p){				
				c=1;
			}
			else{
				o->Llink=t;
				p->Rlink=t;
				t->Rlink=o;
				t->Llink=p;
				break;				
			}
		}
		o=p;
		cnt++;
		p=p->Llink;	
	}while(p!=h->Rlink);
		if(c==1){
			t->Llink=p->Llink;
			p->Llink->Rlink=t;
			p->Llink=t;
			h->Rlink=t;
			t->Rlink=p;		
		}		
}
