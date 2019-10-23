%%cu
#include "cuda.h"
#include <iostream>
#include <numeric>
using namespace std;

__global__ void max(int* input,int count)
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
		  {
		      snd = fst;
		      fst = 0;
		  }  
		  if(input[fst]<input[snd])
         	 input[fst] = input[snd]; 
		}

		step_size *= 2; 
		number_of_threads /= 2;
	}
}

int main()
{
	int count = 15;
  srand(time(NULL));
	const int size = count * sizeof(int);
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
	{
	max<<<1,count/2>>>(d,count);
	}else
	{
	max<<<1,(count/2)+1>>>(d,count);
	}
	
	int result;
	cudaMemcpy(&result,d, sizeof(int), cudaMemcpyDeviceToHost);

    
	cout << "Max is " << result << endl;
	cudaFree(d);

	return 0;
}