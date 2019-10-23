#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <time.h>
#define N 4
using namespace std;

int main(){
	
	int a[N][N],b[N][N],c[N][N];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			a[i][j]=rand()%5;
			b[i][j]=rand()%5;
		}
	}
	
	cout<<"First Matrix : \n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Second Matrix : \n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<b[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	clock_t c_1,c_2;
	float t;
	
	c_1 = clock();
	
	cout<<"Max Number of Threads : "<<omp_get_max_threads()<<endl;;
	
	#pragma omp parallel
	#pragma omp single
	{
		cout<<"Number of Threads : "<<omp_get_num_threads()<<endl;;
	}
	int i,j,k;
	#pragma omp parallel for shared(j,k)
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			c[i][j] = 0;
			for(k=0;k<N;k++){
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	
	cout<<"Matrix Multiplication of two matrix : "<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
	c_2 = clock();
	
	t = (float)(c_2-c_1)/CLOCKS_PER_SEC;
	cout<<"Execution Time : "<<t<<" in Seconds";
	
	
	
}
