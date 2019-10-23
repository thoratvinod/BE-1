#include <iostream>
#include <omp.h>
#include <cstdlib>

using namespace std;

int main(){
	
	int n;
	cout<<"Enter no. of Elements => ";
	cin>>n;
	
	int *a = new int[n];
	for(int i=0;i<n;i++)
		a[i] = rand()%n;
		
	cout<<"\nRandom Elements are =>"<<endl;
	
	cout<<"{ ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<", ";
	cout<<"}\n\n";
	
	int sum=0;
	
	#pragma omp parallel for reduction(+:sum)
	for(int i=0;i<n;i++)
		sum += a[i];
		
	cout<<"Sum of Elements are => "<<sum<<endl<<endl;
	
	cout<<"Average of Elements are => "<<(float)sum/n<<endl;
	return 0;
}
