#include <iostream>
#include <omp.h>

using namespace std;

void merge(int *a, int i1, int i2, int j1, int j2){
	int k=0;
	int temp[1000];
	int i = i1;
	int j = j1;
	while(i1<=i2&&j1<=j2){
		
		if(a[i1]<a[j1])
			temp[k++] = a[i1++];
		else
			temp[k++] = a[j1++];
	}
	
	while(i1<=i2)
		temp[k++] = a[i1++];
	
	while(j1<=j2)
		temp[k++] = a[j1++];
		
	k=0;
	while(i<=j2){
		a[i]=temp[k];
		i++;k++;
	}
		
}

void mergeSort(int *a, int low, int high){
	
	if(low<high){
		
		int mid = (low+high)/2;
		
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				mergeSort(a,low,mid);
			}
			#pragma omp section
			{
				mergeSort(a,mid+1,high);
			}
		}
		merge(a,low,mid,mid+1,high);
	}
	
}

int main(){
	
int *a,n;
	cout<<"Enter total number of elements => ";
	cin>>n;
	
	a = new int[n];
	cout<<"\nEnter elemets : "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	mergeSort(a,0,n-1);
	
	cout<<"Sorted Array :\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	
	return 0;
}
