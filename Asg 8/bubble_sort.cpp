#include <iostream>
#include <omp.h>

using namespace std;

void bubblesort(int *a, int n){
	
	int first;
	for(int i=0;i<n;i++){
		
		first = i%2;
		#pragma omp parallel for shared(first,a)
		for(int j=first;j<n-1;j+=2){
			
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}


void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	
	int *a,n;
	cout<<"Enter total number of elements => ";
	cin>>n;
	
	a = new int[n];
	cout<<"\nEnter elemets : "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	bubblesort(a,n);
	
	cout<<"Sorted Array :\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	
	return 0;
}
