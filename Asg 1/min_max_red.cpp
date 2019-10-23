#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

int main(){
	int n;
	cout<<"\nEnter No. of Elements => ";
	cin>>n;
	
	int *a = new int[n];
	
	for(int i=0;i<n;i++)
		a[i] = rand()%n;
	
	cout<<"\nRandom elements are => "<<endl;
	cout<<"{ ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<", ";
	cout<<"}\n\n";
	
	int max_v=0,min_v=999999;
	
	#pragma omp parallel for reduction(max:max_v)
	for(int i=0;i<n;i++)
	{
		if(a[i]>max_v)
			max_v = a[i];
	}
	cout<<"\nMiximum Element in Array is => "<<max_v<<endl;
	
	#pragma omp parallel for reduction(min:min_v)
	for(int i=0;i<n;i++)
	{
		if(a[i]<min_v)
			min_v = a[i];
	}
	cout<<"\nMinimum Element in Array is => "<<min_v<<endl;
	return 0;
}
