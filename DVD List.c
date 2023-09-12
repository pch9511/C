#include <stdio.h>
#include <stdlib.h>
//1. ���(add/insert -> dvd�� ���� �������� 5������ -> countnode) 2. ��ȸ (1. DVD�� 2. �ֿ���� 3. ���ۻ� ==> �������� ��������) 3. ����(DVD �� �˻��� ���� ) 4. ���� (�˻��� ���� ) 5. ����
//DVD ����ü -> dvd�� �帣 �ð� �ֿ� ���� ���ۻ� DVD ��Ϲ�ȣ(�ߺ�X)   ���� ���Ϸ� ��� 
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
	
	printf("1. ��� 2. ��ȸ 3. ���� 4. ���� 5. ����\n->");
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
	
	printf("DVD �� : ");
	scanf("%s",n->name);
	printf("�帣 : ");
	scanf("%s",n->genre);
	printf("�ð� : ");
	scanf("%s",n->time);
	printf("�ֿ� : ");
	scanf("%s",n->actor);
	printf("���� : ");
	scanf("%s",n->direc);
	printf("���ۻ�  : ");
	scanf("%s",n->company);
	while(1){
		printf("��Ϲ�ȣ : ");
		scanf("%d",&n->num);
		if(check(n->num,h)==-1){
			printf("�̹� �����ϴ� ��Ϲ�ȣ�Դϴ�.\n");
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
			printf("���� ���� ����\n");
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
		printf("DVD �� : %s �帣 : %s �ð� : %s �ֿ� : %s ���� : %s ���ۻ� : %s ��Ϲ�ȣ : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
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
	
	printf("1. DVD 2. �ֿ���� 3. ���ۻ� 4.������\n->");
	scanf("%d",&i); 
	
	return i;
}

void dvdname(DVD *h){
	
	DVD *p,*o,*temp;
	char name[20];	

	printf("ã�� DVD���� �Է��ϼ��� : ");
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
			printf("DVD �� : %s �帣 : %s �ð� : %s �ֿ� : %s ���� : %s ���ۻ� : %s ��Ϲ�ȣ : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
		}
	}
}
void actor(DVD *h){
	
	DVD *p,*o,*temp;
	char name[20];
	
	printf("ã�� �ֿ������� �Է��ϼ��� : ");
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
			printf("DVD �� : %s �帣 : %s �ð� : %s �ֿ� : %s ���� : %s ���ۻ� : %s ��Ϲ�ȣ : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
		}
	}
}

void company(DVD *h){

	DVD *p,*o,*temp;
	char name[20];
	
	printf("ã�� ���ۻ���� �Է��ϼ��� : ");
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
			printf("DVD �� : %s �帣 : %s �ð� : %s �ֿ� : %s ���� : %s ���ۻ� : %s ��Ϲ�ȣ : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
		}
	}
}
void modiflist(DVD *h){
	
	DVD *p;
	char name[20];
	int i;
	
	p=h;
	printf("ã�� DVD���� �Է��ϼ��� : ");
	scanf("%s",name); 
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.name,name)==0){
			printf("DVD �� : %s �帣 : %s �ð� : %s �ֿ� : %s ���� : %s ���ۻ� : %s ��Ϲ�ȣ : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
		}
	}
	printf("������ DVD�� ��Ϲ�ȣ�� �Է��ϼ��� : ");
	scanf("%d",&i); 
	
	modif(h,i);
}
void modif(DVD *h,int i){
	
	DVD *p;
	
	p=h;
	while(p->link!=NULL){
		p=p->link;
		if(i==p->data.num){
			printf("DVD �� : ");
			scanf("%s",p->data.name);
			printf("�帣 : ");
			scanf("%s",p->data.genre);
			printf("�ð� : ");
			scanf("%s",p->data.time);
			printf("�ֿ� : ");
			scanf("%s",p->data.actor);
			printf("���� : ");
			scanf("%s",p->data.direc);
			printf("���ۻ�  : ");
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
	printf("������ DVD���� �Է��ϼ��� : ");
	scanf("%s",name); 
	while(p->link!=NULL){
		p=p->link;
		if(strcmp(p->data.name,name)==0){
			printf("DVD �� : %s �帣 : %s �ð� : %s �ֿ� : %s ���� : %s ���ۻ� : %s ��Ϲ�ȣ : %d\n",p->data.name,p->data.genre,p->data.time,p->data.actor,p->data.direc,p->data.company,p->data.num);
			check=0;
		}
	}
	if(check==0){
		printf("������ DVD�� ��Ϲ�ȣ�� �Է��ϼ��� : ");
		scanf("%d",&i); 
		del(h,i);
	}
	else{
		printf("�Է��Ͻ� DVD���� �����ϴ�.\n");
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

