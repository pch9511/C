#include <stdio.h>
#include <stdlib.h>
//A 0행 x B 0열  A(0,0)xB(0,0)+A(1,0)xB(0,1)+A(2,0)xB(0,2) => C (0,0) A 0행 x B 1열 -> C(0,1)   C-> 나타내는건 구조체로  

struct data{
	int row;
	int col;
	int data;
};

struct MAT{
	int rows;
	int cols;
	int datas;
	struct data ar[9];
};


int main(int argc, char *argv[]) {
	
	struct data D;
	struct MAT A={3,3,3,{{0,0,1},{1,2,2},{2,1,8}}}; 
	struct MAT B={3,3,4,{{0,1,2},{0,2,3},{1,0,4},{2,2,2}}};
	struct MAT C;
	
	int **ap,**bp,**cp,i,j,k,cnt=0;	

	ap=(int **)malloc((A.rows)*sizeof(int *));
	for(i=0; i<A.rows; i++){
		ap[i]=(int *)malloc((A.cols)*sizeof(int));
	}
	for(i=0; i<A.rows; i++){
		for(j=0; j<A.cols; j++){
			ap[i][j]=0;
		}
	}
	for(i=0; i<A.datas; i++){
		ap[A.ar[i].row][A.ar[i].col]=A.ar[i].data;
	}
	
	for(i=0; i<A.rows; i++){
		for(j=0; j<A.cols; j++){
			printf("%d ",ap[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	bp=(int **)malloc((B.rows)*sizeof(int *));
	for(i=0; i<B.rows; i++){
		bp[i]=(int *)malloc((B.cols)*sizeof(int));
	}
	
	for(i=0; i<B.rows; i++){
		for(j=0; j<B.cols; j++){
			bp[i][j]=0;
		}
	}
	for(i=0; i<B.datas; i++){
		bp[B.ar[i].row][B.ar[i].col]=B.ar[i].data;
	}
	for(i=0; i<B.rows; i++){
		for(j=0; j<B.cols; j++){
			printf("%d ",bp[i][j]);
		}
		printf("\n");
	}	
	
	printf("\n");
	cp=(int **)malloc(3*sizeof(int *));
	for(i=0; i<3; i++){
		cp[i]=(int *)malloc(3*sizeof(int));
	}
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			cp[i][j]=0;
		}
	}
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			for(k=0; k<3; k++){
				cp[i][j]+=ap[i][k]*bp[k][j];
			}
		}
	}
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d ",cp[i][j]);
		}
		printf("\n");
	}
	
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(cp[i][j]!=0){
				C.ar[cnt].row=i;
				C.ar[cnt].col=j;
				C.ar[cnt].data=cp[i][j];
				cnt++;
			}
		}
	}
	C.rows=3;
	C.cols=3;
	C.datas=cnt;
	
	printf("C의 행 : %d\nC의 열 :%d\nC의 데이터수 : %d\n",C.rows,C.cols,C.datas);
	for(i=0; i<C.datas; i++){
		printf("{%d,%d,%d}\n",C.ar[i].row,C.ar[i].col,C.ar[i].data);
	}
	
	//ap[0][0]*bp[0][0]+ap[0][1]*bp[1][0]+ap[0][2]*bp[2][0] => cp[0][0]
	//ap[0][0]*bp[0][0]+ap[0][1]*bp[1][1]+ap[0][2]*bp[2][1] => cp[0][1]
	free(ap);
	free(bp);
	free(cp);
	
	return 0;
}
