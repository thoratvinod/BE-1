#include <iostream>
using namespace std;

#define MAX 16
#define MAX_THREAD 4


int a[] = {1, 2, 4, 7, 9, 50, 75, 100, 110, 124, 126, 150, 179, 189, 200, 210};
int key=560;
bool found = false;
int part =0;

void* binary_search(void *arg){
	
	int thread_part = part++;
	int mid;
	
	int low = thread_part * (MAX/4);
	int high = (thread_part+1) * (MAX/4);
	
	while(low<high&&!found){
		
		mid = (high-low) / 2 + low;
		
		if(a[mid]==key){
			found = true;
			break;
		}else if(a[mid]<key)
			low = mid+1;
		else
			high = mid-1;
			
	}
}

int main(){
	
	pthread_t threads[MAX_THREAD];
	
	for(int i=0;i<MAX_THREAD;i++)
		pthread_create(&threads[i], NULL, binary_search, (void*)NULL);
		
	for(int i=0;i<MAX_THREAD;i++)
		pthread_join(threads[i],NULL);
		
	if(found)
		cout<<key<<" is Present in array";
	else
		cout<<key<<" is not present";
}
