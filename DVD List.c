#include <stdio.h>
#include <stdlib.h>
//1. 등록(add/insert -> dvd명 기준 오름차순 5건이하 -> countnode) 2. 조회 (1. DVD명 2. 주연배우 3. 제작사 ==> 기준으로 오름차순) 3. 수정(DVD 명 검색후 수정 ) 4. 삭제 (검색후 삭제 ) 5. 종료
//DVD 구조체 -> dvd명 장르 시간 주연 감독 제작사 DVD 등록번호(중복X)   전부 파일로 기록 
typedef struct REGI{
	char name[20];
	char genre[20];
	char time[20];
	char actor[20];
	char direc[20];
	char company[20];
	int num;
}REG;
typedef struct DVDLIST{
    REG data;
	struct DVDLIST *link;
}DVD;



int main_select();
void fileload(DVD *,REG,FILE **);
DVD *create();
void regist(DVD *,REG *);
void add(DVD *,REG );
void insert(DVD *,REG );
int check(int,DVD *);
int sort(DVD *,REG );
void sortview(DVD *);
void view(DVD *);
void search_menu(DVD *);
int searchmenu_select();
void dvdname(DVD *);
void dvdview(DVD *,char *);
void actor(DVD *);
void acotorview(DVD *,char *);
void company(DVD *);
void companyview(DVD *,char *);
void modiflist(DVD *);
void modif(DVD *,int);
void dellist(DVD *);
void del(DVD *,int);

int main(int argc, char *argv[]) {
	
	DVD *h;
	FILE *ifp;
	REG n;
	int i,c;
	 
	h=create();	
	ifp=fopen("DVDLIST.txt","r");
	if(ifp!=NULL){
		fileload(h,n,&ifp);
	}
	fclose(ifp);
	while((i=main_select())!=5){
		switch(i){
			case 1 :
			regist(h,&n);		
			c=sort(h,n);
			if(c==0){
				insert(h,n);
			}
			else{
				add(h,n);
			}
			break;
			
			case 2 :
			sortview(h);
			search_menu(h);
			break;
			
			case 3 :
			modiflist(h);
			break;
			
			case 4 :
			dellist(h);
			break;
			
			default : 
			break;
		}
	}
	free(h);
	return 0;
}


int main_select(){
	
	int i;
	
	printf("1. 등록 2. 조회 3. 수정 4. 삭제 5. 종료\n->");
	scanf("%d",&i); 
	
	return i;	
}
void fileload(DVD *h,REG n,FILE **ifp){
	
	int res;	
	
	while(1){
		res=fscanf(*ifp,"%s %s %s %s %s %s %d\n",n.name,n.genre,n.time,n.actor,n.direc,n.company,&n.num);	
		if(res==EOF) break;
		add(h,n);
	
	}
}
DVD *create(){
	
	DVD *a;
	
	a=(DVD *)malloc(sizeof(DVD));
	strcpy(a->data.name," ");
	strcpy(a->data.genre," ");
	strcpy(a->data.time," ");
	strcpy(a->data.actor," ");
	strcpy(a->data.direc," ");
	strcpy(a->data.company," ");
	a->data.num=0;
	a->link=NULL;
	
	return a;	
}
void regist(DVD *h,REG *n){
	
	printf("DVD 명 : ");
	scanf("%s",n->name);
	printf("장르 : ");
	scanf("%s",n->genre);
	printf("시간 : ");
	scanf("%s",n->time);
	printf("주연 : ");
	scanf("%s",n->actor);
	printf("감독 : ");
	scanf("%s",n->direc);
	printf("제작사  : ");
	scanf("%s",n->company);
	while(1){
		printf("등록번호 : ");
		scanf("%d",&n->num);
		if(check(n->num,h)==-1){
			printf("이미 존재하는 등록번호입니다.\n");
		}
		else{
			break;
		}
	}

}
void add(DVD *h,REG n){
	
	DVD *p,*o;
	
	o=create(n);
	o->data=n;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;
	}
	p->link=o;
	file(h);
}
void insert(DVD *h,REG n){
	
	DVD *p,*o,*t;
	
	o=create(n);
	o->data=n;
	
	p=h;
	while(p->link!=NULL){
		t=p;
		p=p->link;
		if(strcmp(p->data.name,n.name)>0){
			o->link=t->link;
			t->link=o;
			break;
		}
	}
	file(h);
}
int check(int num,DVD *h){
	
	DVD *p;
	int c=0;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;
		if(p->data.num==num){
			c=-1;
		}
	}
	
	return c;	
}

int sort(DVD *h,REG n){
	
	DVD *p;
	int check=1;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;	
		if(strcmp(p->data.name,n.name)>0){
			check=0;
			break;
		}
		else{
		}
	}					
	return check;
}

void file(DVD *h){
	
	FILE *ifp;
	DVD *p;
	
	ifp=fopen("DVDLIST.txt","w");
		if(ifp==NULL){
			printf("파일 개방 실패\n");
		}
	p=h;
	while(p->link!=NULL){
		p=p->link;
		fprintf(ifp,"%s %s %s %s %s %s %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
	}
	fclose(ifp);
}
void sortview(DVD *h){
	
	DVD *p,*o,*temp;
	p=h;
	while(p->link!=NULL){
		o=p;
		p=p->link;
		while(o->link!=NULL){
			o=o->link;
			if(strcmp(p->data.name,o->data.name)>0){
				temp->data=p->data;
				p->data=o->data;
				o->data=temp->data;
			}
		}
	}
	view(h);	
}	
void view(DVD *h){

	DVD *p;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;
		printf("DVD 명 : %s 장르 : %s 시간 : %s 주연 : %s 감독 : %s 제작사 : %s 등록번호 : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
	}
}

void search_menu(DVD *h){
	
	int i;
	
	while((i=searchmenu_select())!=4){
		switch(i){
			
			case 1:
			dvdname(h);
			break;
			
			case 2:
			actor(h);
			break;
			
			case 3:
			company(h);
			break;
			
			default:
			break;
		}
	}
}
int searchmenu_select(){
	
	int i;
	
	printf("1. DVD 2. 주연배우 3. 제작사 4.나가기\n->");
	scanf("%d",&i); 
	
	return i;
}

void dvdname(DVD *h){
	
	DVD *p,*o,*temp;
	char name[20];	

	printf("찾을 DVD명을 입력하세요 : ");
	scanf("%s",name); 
	
	p=h;
	while(p->link!=NULL){
		o=p;
		p=p->link;
		while(o->link!=NULL){
			o=o->link;
			if(p->data.num>o->data.num){
				temp->data=p->data;
				p->data=o->data;
				o->data=temp->data;
			}
		}
	}
	dvdview(h,name);	
	
}

void dvdview(DVD *h,char *name){

	DVD *p;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.name,name)==0){
			printf("DVD 명 : %s 장르 : %s 시간 : %s 주연 : %s 감독 : %s 제작사 : %s 등록번호 : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
		}
	}
}
void actor(DVD *h){
	
	DVD *p,*o,*temp;
	char name[20];
	
	printf("찾을 주연배우명을 입력하세요 : ");
	scanf("%s",name); 
	p=h;
	while(p->link!=NULL){
		o=p;
		p=p->link;
		while(o->link!=NULL){
			o=o->link;
			if(p->data.num>o->data.num){
				temp->data=p->data;
				p->data=o->data;
				o->data=temp->data;
			}
		}
	}
	actorview(h,name);				
}

void actorview(DVD *h,char *name){

	DVD *p;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.actor,name)==0){
			printf("DVD 명 : %s 장르 : %s 시간 : %s 주연 : %s 감독 : %s 제작사 : %s 등록번호 : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
		}
	}
}

void company(DVD *h){

	DVD *p,*o,*temp;
	char name[20];
	
	printf("찾을 제작사명을 입력하세요 : ");
	scanf("%s",name);
	 
	p=h;
	while(p->link!=NULL){
		o=p;
		p=p->link;
		while(o->link!=NULL){
			o=o->link;
			if(p->data.num>o->data.num){
				temp->data=p->data;
				p->data=o->data;
				o->data=temp->data;
			}
		}
	}
	companyview(h,name);					
}

void companyview(DVD *h,char *name){

	DVD *p;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.company,name)==0){
			printf("DVD 명 : %s 장르 : %s 시간 : %s 주연 : %s 감독 : %s 제작사 : %s 등록번호 : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
		}
	}
}
void modiflist(DVD *h){
	
	DVD *p;
	char name[20];
	int i;
	
	p=h;
	printf("찾을 DVD명을 입력하세요 : ");
	scanf("%s",name); 
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.name,name)==0){
			printf("DVD 명 : %s 장르 : %s 시간 : %s 주연 : %s 감독 : %s 제작사 : %s 등록번호 : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
		}
	}
	printf("수정할 DVD의 등록번호를 입력하세요 : ");
	scanf("%d",&i); 
	
	modif(h,i);
}
void modif(DVD *h,int i){
	
	DVD *p;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;
		if(i==p->data.num){
			printf("DVD 명 : ");
			scanf("%s",p->data.name);
			printf("장르 : ");
			scanf("%s",p->data.genre);
			printf("시간 : ");
			scanf("%s",p->data.time);
			printf("주연 : ");
			scanf("%s",p->data.actor);
			printf("감독 : ");
			scanf("%s",p->data.direc);
			printf("제작사  : ");
			scanf("%s",p->data.company);
		}
	}
	file(h);
}
void dellist(DVD *h){
	DVD *p;
	char name[20];
	int i,check=1;
	
	p=h;
	printf("삭제할 DVD명을 입력하세요 : ");
	scanf("%s",name); 
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.name,name)==0){
			printf("DVD 명 : %s 장르 : %s 시간 : %s 주연 : %s 감독 : %s 제작사 : %s 등록번호 : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
			check=0;
		}
	}
	if(check==0){
		printf("삭제할 DVD의 등록번호를 입력하세요 : ");
		scanf("%d",&i); 
		del(h,i);
	}
	else{
		printf("입력하신 DVD명이 없습니다.\n");
	}
	
}
void del(DVD *h,int i){
	
	DVD *p,*n;

	p=h;
	while(p->link!=NULL){
		n=p;
		p=p->link;
		if(p->data.num==i){	
			n->link=p->link;
			free(p);
			break;
		}
	}
	file(h);
}

