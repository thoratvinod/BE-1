%%cu
#include "cuda.h"
#include <iostream>
#include <numeric>
using namespace std;

__global__ void sum(int* input,int count)
{
	int tid = threadIdx.x;

	int step_size = 1;
	int number_of_threads = blockDim.x;

	while (number_of_threads > 0)
	{
		if (tid < number_of_threads) // still alive?
		{
			int fst = tid * step_size * 2;
			int snd = fst + step_size;
			if(fst==count-1)
		    	input[0]+=input[fst];
		    else  
				input[fst] += input[snd];
		}
		step_size *= 2; 
		number_of_threads /= 2;
	}
}

int main()
{
	int count = 5;
    int size = count * sizeof(int);
	int h[count];
	for(int i=0;i<count;i++)
    {
		h[i] = rand()%50;
        cout<<h[i]<<" ";
    }
	int* d;
	
	cudaMalloc(&d, size);
	cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);

	if(count%2==0)
		sum<<<1,count/2>>>(d,count);
	else
		sum<<<1,(count/2)+1>>>(d,count);
	
	int result;
	cudaMemcpy(&result,d, sizeof(int), cudaMemcpyDeviceToHost);
  cout << " Sum is: " << result;
    double ans = (double)result/count;  
	cout << " Average is: " << ans << endl;

	cudaFree(d);

	return 0;
}