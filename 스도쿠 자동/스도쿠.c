#include <stdio.h>
#include <stdlib.h>

 



int main(int argc, char *argv[]) {

int score[3][3]={0};
int i=0,j=1,num,a,b;
int	row=sizeof(score)/sizeof(score[0]), col=sizeof(score[0])/sizeof(score[0][0]);									
											
	srand((unsigned int)time(NULL));
	
	a=rand()%4+1;
	b=rand()%4+5; 
	printf("a : %d b : %d \n",a,b); 
	
	if(a%2==1){
		if(a==1){
			i=0; j=1;
			if(b%2==1){
				printf("(0,1) 왼쪽\n");				
				for(num=1; num<=9; num++){
					score[i][j]=num;
					if(i-1<0&&j-1<0){
						if(score[i+1][j]==0){
							i++;
						}
					}
					else if(i-1<0||j-1<0){
						if(j-1<0){
							j+=2;
							i--;
						}
						else{
							j--;
							i+=2;
						}
					}
					else if(score[i-1][j-1]!=0){
						if(score[i+1][j]==0){
							i++;
						}
					}
					else{
						i--;
						j--;
					}
				}
				for(i=0; i<row; i++){
					
					for(j=0; j<col; j++){
						printf("%d\t",score[i][j]);
					}
					printf("\n");
				}
			}
			else{
				printf("(0,1) 오른쪽\n"); 
				for(num=1; num<=9; num++){
					
					score[i][j]=num;
												
					if(i-1<0&&j+1>2){		
						if(score[i+1][j]==0){
							i++;
						}
			
					}	
					else if(i-1<0||j+1>2){
						if(i-1<0){
							i+=2;
							j++;
						}
						else{
							i--;
							j-=2;
						}
					}
					else if(score[i-1][j+1]!=0){
						if(score[i+1][j]==0){ 
							i++;
						}
					
					}
					else{
						i--;
						j++;
					}
				}
				for(i=0; i<row; i++){					
					for(j=0; j<col; j++){
						printf("%d\t",score[i][j]);
					}
					printf("\n");
				}
			}
		}	
		else{
			i=2; j=1;
			if(b%2==0){
				printf("(2,1) 오른쪽\n"); 
				for(num=1; num<=9; num++){
					score[i][j]=num;
					if(i+1>2&&j+1>2){
						if(score[i-2][j]!=0){
							i--;
						}
					}	
					else if(i+1>2||j+1>2){
						if(i+1>2){
							i-=2;
							j++;
						}
						else{
							i++;
							j-=2;
						}
					}
					else if(score[i+1][j+1]!=0){
						if(score[i-1][j]==0){
							i--;
						}
					}
					else{
						i++;
						j++;
					}
				}
				for(i=0; i<row; i++){					
					for(j=0; j<col; j++){
						printf("%d\t",score[i][j]);
					}
					printf("\n");
				}
			}
			else{
			printf("(2,1) 왼쪽\n"); 
				for(num=1; num<=9; num++){	
					score[i][j]=num;						
					if(i+1>2&&j-1<0){
						if(score[i-2][j]!=0){
							i--;
						}
					}
					else if(i+1>2||j-1<0){
						if(j-1<0){
							j+=2;
							i++;
						}
						else{
							i-=2;
							j--;
						}
					}
					else if(score[i+1][j-1]!=0){
						if(score[i-1][j]==0){
							i--;
						}
					}
					else{
						i++;
						j--;
					}
				}	
				for(i=0; i<row; i++){
					for(j=0; j<col; j++){
						printf("%d\t",score[i][j]);
					}
					printf("\n");
				}
			}
		}
	}
	else{
		if(a==2){
			i=1; j=0;
			if(b%2==1){	
				printf("(1,0) 위\n");			
				for(num=1; num<=9; num++){
					score[i][j]=num;
					if(i-1<0&&j-1<0){
						if(score[i+1][j]!=0){
							j++;
						}
					}
					else if(i-1<0||j-1<0){
						if(j-1<0){
							j+=2;
							i--;
						}
						else{
							j--;
							i+=2;
						}
					}
					else if(score[i-1][j-1]!=0){
						if(score[i+1][j]!=0){
							j++;
						}
					}
					else{
						i--;
						j--;
					}
				}
				for(i=0; i<row; i++){
					for(j=0; j<col; j++){
						printf("%d\t",score[i][j]);
					}
					printf("\n");
				}
			}
			else{
				printf("(1,0) 아래\n"); 
				for(num=1; num<=9; num++){	
					score[i][j]=num;						
					if(i+1>2&&j-1<0){
						if(score[i][j+2]!=0){
							j++;
						}
					}
					else if(i+1>2||j-1<0){
						if(j-1<0){
							j+=2;
							i++;
						}
						else{
							i-=2;
							j--;
						}
					}
					else if(score[i+1][j-1]!=0){
						if(score[i][j+1]==0){
							j++;
						}
					}
					else{
						i++;
						j--;
					}
				}	
				for(i=0; i<row; i++){
					for(j=0; j<col; j++){
						printf("%d\t",score[i][j]);
					}
					printf("\n");
				}
			}
		}
		else{
			i=1; j=2;
			if(b%2==1){	
				printf("(1,2) 위\n");
				for(num=1; num<=9; num++){
				
					score[i][j]=num;
											
					if(i-1<0&&j+1>2){			
						if(score[i][j-1]==0){
							j--;
						}
			
					}	
					else if(i-1<0||j+1>2){
						if(i-1<0){
							i+=2;
							j++;
						}
						else{
							i--;
							j-=2;
						}
					}
					else if(score[i-1][j+1]!=0){
						if(score[i][j-1]==0){ 
							j--;
						}
					
					}
					else{
						i--;
						j++;
					}
				}
				for(i=0; i<row; i++){
					for(j=0; j<col; j++){
						printf("%d\t",score[i][j]);
					}
					printf("\n");
				}
			}
			else{
				printf("(1,2) 아래\n"); 
				for(num=1; num<=9; num++){
					score[i][j]=num;
					if(i+1>2&&j+1>2){
						if(score[i][j-2]!=0){
							j--;
						}
					}	
					else if(i+1>2||j+1>2){
						if(i+1>2){
							i-=2;
							j++;
						}
						else{
							i++;
							j-=2;
						}
					}
					else if(score[i+1][j+1]!=0){
						if(score[i][j-1]==0){
							j--;
						}
					}
					else{
						i++;
						j++;
					}
					}
				for(i=0; i<row; i++){
					for(j=0; j<col; j++){
						printf("%d\t",score[i][j]);
					}
					printf("\n");
				}
			}
		}
	}
	
	return 0;
}
