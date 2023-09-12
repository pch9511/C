#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct a{
	int row;
	int col;
}a;
typedef struct stack{
	a data;
	struct stack *link;
}ST;
//int **ap -> 7~10 ���� => ex.7*7 60%=1->���� Ÿ�� 40%=0->�� Ÿ��  0->2(��)��ŸƮ�� 0->3(��Ʈ)����  
//���� (��,��)�� ���  �� ��ŸƮ�� �������̶��(push) ����-> ��Ʈ�� ����� �������� (push) �������� ��� ǥ�� (�ٽ� ����) 4���� �ٸ����� pop�ϰ� pop ��ҷ� �ٽ� ����


void map(int **,int);
ST *create();
void push(ST *,int,int);
a *pop(ST *); 
int move(int **,ST *,int,a *);
void print(int **,int);
int isempty(ST *);
int move2(int **,ST *,int);
int main(int argc, char *argv[]){
	
	int **ap,rnd,i,rnd2,j,row,col;
	ST *h;
	a *h2;
	
	srand((unsigned int)time(NULL));
 	
 	//rnd=rand()%4+7;
 	rnd=6;
 	ap=(int **)malloc(rnd*sizeof(int *));
 	for(i=0; i<rnd; i++){
		ap[i]=(int *)malloc(rnd*sizeof(int));		
	}
 	map(ap,rnd);
	h=create();
	for(i=0; i<rnd; i++){
		for(j=0; j<rnd; j++){
			if(ap[i][j]==2){
				col=i;
				row=j;
			}
		}
	}
	/*while(1){  �̷�ã�� 
		sleep(1);
		system("cls");	
		i=move(ap,h,rnd);
		print(ap,rnd);
		printf("\n"); 
		if(i==2){
			printf("����");	
			h2=pop(h);	
			ap[h2->row][h2->col]=2;
		}
		else if(i==-1){
			break;
		}
	}*/
	while(1){  //�ִܰŸ� ã��   -> ���������� �����Ҷ������� Ƚ���� üũ(�̵������� ��� ����?) -> Ƚ�� ���� ���� ���� Ƚ���� ��Ʈ�� print��Ŵ(��Ʈ���� ��� ����?)  
		sleep(1);
		system("cls");	
		i=move2(ap,h,rnd);
		print(ap,rnd);
		printf("\n"); 
		if(i==2){
			printf("����");		
			while(isempty(h)!=0){	
				h2=pop(h);
			}
			ap[col][row]=2;
			for(i=0; i<rnd; i++){
				for(j=0; j<rnd; j++){
					if(ap[i][j]==4){
						ap[i][j]=0;
					}
				}
			}
		}
		else if(i==-1){
			break;
		}
	}
	while(isempty(h)!=0){
		h2=pop(h);
		ap[h2->col][h2->row]=2;
	}
	printf("\n");
	print(ap,rnd);
	return 0;
}

void map(int **ap,int rnd){
	
	int rnd2,i,j,res,res2,cnt=0,cnt2=0,rnd3,rnd4;
	double a,b;

	a=rnd*rnd*0.2; //�� 
	b=rnd*rnd*0.8; //��� 
	if(a-(int)a>=0.5){
		res=(int)a+1;
	}
	else{
		res=(int)a;
	}
	if(b-(int)b>=0.5){
		res2=(int)b+1;
	}
	else{
		res2=(int)b;
	}
	for(i=0; i<rnd; i++){
		for(j=0; j<rnd; j++){
			ap[i][j]=4;
		}
	}
	while(cnt+cnt2!=rnd*rnd){
		rnd3=rand()%rnd+0;
		rnd4=rand()%rnd+0;
		rnd2=rand()%2+0;
		if(rnd2==1){
			if(res>cnt&&ap[rnd3][rnd4]==4){
				ap[rnd3][rnd4]=rnd2;
				cnt++;	
				}
		}
		else{
			if(res2>cnt2&&ap[rnd3][rnd4]==4){
				ap[rnd3][rnd4]=rnd2;
				cnt2++;
			}
		}
	}
	while(1){
		rnd3=rand()%rnd+0;
		rnd4=rand()%rnd+0;
		if(ap[rnd3][rnd4]==0){
			ap[rnd3][rnd4]=2;
			break;
		}
	}
	while(1){
		rnd3=rand()%rnd+0;
		rnd4=rand()%rnd+0;
		if(ap[rnd3][rnd4]==0){
			ap[rnd3][rnd4]=3;
			break;
		}
	}
	for(i=0; i<rnd; i++){
 		for(j=0; j<rnd; j++){
 			if(ap[i][j]==1){
 				printf("��");
 			}
 			else if(ap[i][j]==0){
 				printf("��");
			}
			else if(ap[i][j]==2){
				printf("��");
			}
			else if(ap[i][j]==3){
				printf("��");
			}  
			else if(ap[i][j]==4){
				printf("��");
			}
 		}
 		printf("\n");
 	}
}
ST *create(){
	
	ST *a;
	
	a=(ST *)malloc(sizeof(ST));
	a->data.col=0;
	a->data.row=0;
	a->link=NULL;
	
	return a;
}
void push(ST *h,int i,int j){
	
	ST *p,*n;
	
	n=create();
	n->data.col=i;
	n->data.row=j;
	p=h;
	
	n->link=p->link;	
	p->link=n;
}
a *pop(ST *h){

	ST *p;
	a *h2;
	h2=(int *)malloc(sizeof(int));
	
	p=h;
	p=h->link;
	h2->col=p->data.col;
	h2->row=p->data.row;
	h->link=p->link;
	free(p);
	
	return h2;
}	
int move(int **ap,ST *h,int rnd,a *h2){
	
	int i,j,a,b,c,d,cnt=0;
	
	for(i=0; i<rnd; i++){
		for(j=0; j<rnd; j++){
			if(ap[i][j]==2){
				a=i;
				b=j;
			}
			else if(ap[i][j]==3){
				c=i;
				d=j;
			}
		}
	}
	printf("�� : (%d,%d)\n",a,b); 
		if(a<rnd-1&&ap[a+1][b]==3){
			ap[a][b]=4;
			ap[a+1][b]=2;
			printf("����\n"); 
			return -1;
		}
		else if(b>0&&ap[a][b-1]==3){
			ap[a][b]=4;
			ap[a][b-1]=2;
			printf("����\n");
			return -1;
		}
		else if(b<rnd-1&&ap[a][b+1]==3){
			ap[a][b]=4;
			ap[a][b+1]=2;
			printf("����\n");
			return -1;
		}
		else if(a>0&&ap[a-1][b]==3){
			ap[a][b]=4;
			ap[a-1][b]=2;
			printf("����\n");
			return -1;
		}
		/*if(b>0&&ap[a][b-1]==0){
			cnt++;
		}
		if(b<rnd-1&&ap[a][b+1]==0){
			cnt++;
		}
		if(a>0&&ap[a-1][b]==0){
			cnt++;
		}
		if(a<rnd-1&&ap[a+1][b]==0){
			cnt++;
		}	
		if(cnt>=2){
			push(h,a,b);
		} */
		if(a>c&&b>d){
			if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}	
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}
			else{
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{	
					ap[a][b]=4;
					return 2; 
				}
			}	
		}
		else if(a>c&&b<d){
			if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}				
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}				
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}	
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=4;
					return 2; 
				}
			}	
		}
		else if(a<c&&b>d){	
			if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=4;
					return 2; 
				}
			}			
		}
		else if(a<c&&b<d){			
			if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}	
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}		
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=4;
					return 2; 
				}
			}
		}
		else if(a==c&&b>d){
			if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}	
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}			
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}			
			else{ 
				if(isempty(h)==0){
				printf("�� ���� ����\n");
				return -1;
				}
				else {
					ap[a][b]=4;
					return 2; 
				}	
			}
		}
		else if(a==c&&b<d){			
			if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}	
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}			
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}	
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=4;
					return 2; 
				}
			}				
		}
		else if(a>c&&b==d){			
			if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}	
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}			
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}		
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=4;
					return 2; 
				}
			}				
		}
		else if(a<c&&b==d){			
			if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}	
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}				
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}			
			else{ 
				if(isempty(h)==0){
				printf("�� ���� ����\n");
				return -1;
				}
				else{
					ap[a][b]=4;
					return 2; 
				}
			}				
		}
	return 0;
}
void print(int **ap,int rnd){
	
	int i,j;
	for(i=0; i<rnd; i++){
 		for(j=0; j<rnd; j++){
 			if(ap[i][j]==1){
 				printf("��");
 			}
 			else if(ap[i][j]==0){
 				printf("��");
			}
			else if(ap[i][j]==2){
				printf("��");
			}
			else if(ap[i][j]==3){
				printf("��");
			}  
			else if(ap[i][j]==4){
				printf("��");
			}
			else if(ap[i][j]==5){
				printf("��"); 
			}
 		}
 		printf("\n");
 	}
 	
}	
int isempty(ST *h){
	return h->link!=NULL;
}
int move2(int **ap,ST *h,int rnd){
	
	int i,j,a,b,c,d,cnt=0;
	
	for(i=0; i<rnd; i++){
		for(j=0; j<rnd; j++){
			if(ap[i][j]==2){
				a=i;
				b=j;
			}
			else if(ap[i][j]==3){
				c=i;
				d=j;
			}
		}
	}
	push(h,a,b);
	printf("�� : (%d,%d)\n",a,b); 
		if(a<rnd-1&&ap[a+1][b]==3){
			ap[a][b]=4;
			ap[a+1][b]=2;
			printf("����\n"); 
			return -1;
		}
		else if(b>0&&ap[a][b-1]==3){
			ap[a][b]=4;
			ap[a][b-1]=2;
			printf("����\n");
			return -1;
		}
		else if(b<rnd-1&&ap[a][b+1]==3){
			ap[a][b]=4;
			ap[a][b+1]=2;
			printf("����\n");
			return -1;
		}
		else if(a>0&&ap[a-1][b]==3){
			ap[a][b]=4;
			ap[a-1][b]=2;
			printf("����\n");
			return -1;
		}
		/*if(b>0&&ap[a][b-1]==0){
			cnt++;
		}
		if(b<rnd-1&&ap[a][b+1]==0){
			cnt++;
		}
		if(a>0&&ap[a-1][b]==0){
			cnt++;
		}
		if(a<rnd-1&&ap[a+1][b]==0){
			cnt++;
		}	
		if(cnt>=2){
			push(h,a,b);
		} */
		if(a>c&&b>d){
			if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}	
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}			
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}
			else{
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{	
					ap[a][b]=5;
					return 2; 
				}
			}	
		}
		else if(a>c&&b<d){
			if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}	
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}			
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}				
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}	
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=5;
					return 2; 
				}
			}	
		}
		else if(a<c&&b>d){	
			if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=5;
					return 2; 
				}
			}			
		}
		else if(a<c&&b<d){
			if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}		

			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}		
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=5;
					return 2; 
				}
			}
		}
		else if(a==c&&b>d){
			if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}	
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}			
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}			
			else{ 
				if(isempty(h)==0){
				printf("�� ���� ����\n");
				return -1;
				}
				else {
					ap[a][b]=5;
					return 2; 
				}	
			}
		}
		else if(a==c&&b<d){			
			if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}	
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}			
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}	
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=5;
					return 2; 
				}
			}				
		}
		else if(a>c&&b==d){			
			if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}	
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}			
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}		
			else if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}			
			else{ 
				if(isempty(h)==0){
					printf("�� ���� ����\n");
					return -1;
				}
				else{
					ap[a][b]=5;
					return 2; 
				}
			}				
		}
		else if(a<c&&b==d){			
			if(a<rnd-1&&ap[a+1][b]==0){
				ap[a][b]=4;
				ap[a+1][b]=2;
			}
			else if(b>0&&ap[a][b-1]==0){
				ap[a][b]=4;
				ap[a][b-1]=2;
			}	
			else if(b<rnd-1&&ap[a][b+1]==0){
				ap[a][b]=4;
				ap[a][b+1]=2;
			}				
			else if(a>0&&ap[a-1][b]==0){
				ap[a][b]=4;
				ap[a-1][b]=2;
			}			
			else{ 
				if(isempty(h)==0){
				printf("�� ���� ����\n");
				return -1;
				}
				else{
					ap[a][b]=5;
					return 2; 
				}
			}				
		}
}
