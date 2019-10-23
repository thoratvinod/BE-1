#include <iostream>
#include <cstdlib>
#include <omp.h>
#define M 3 
#define N 2
using namespace std;

int main(){
	
	
	int mat[M][N],vect[N],c[M];
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			mat[i][j]=1;
		}
	}
	for(int i=0;i<N;i++){
		vect[i] = 2;
	}
	
	cout<<"Matrix is \n";
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Vector is \n";
	for(int i=0;i<N;i++){
		cout<<vect[i]<<endl;
	}
	
	#pragma omp parallel
	{
		#pragma omp parallel for
		for(int i=0;i<M;i++){
			c[i] = 0;
			
			for(int j=0;j<N;j++){
				c[i] += mat[i][j]*vect[j];
			}
		}
	}
	cout<<"Resultant Col-Vector"<<endl;
	for(int i=0;i<M;i++){
		cout<<"vect["<<i<<"] : "<<c[i]<<endl;
	}
	
	return 0;
	
	
	
	
	
	
	
	
	
}
