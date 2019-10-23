#include "cuda.h"
#include <iostream>
#include <numeric>
using namespace std;

__global__ void sum(float* input,int count)
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

__global__ void ss(float* input,float *output,float mean)
{
   int index = threadIdx.x; 
   output[index] = (input[index]-mean)*(input[index]-mean);
}

int main()
{
	int count = 10;
  int size = count * sizeof(float);
	float h[count],sm[count]; 
    
  srand(time(NULL));
	for(int i=0;i<count;i++)
    {
	     	h[i] = rand()%50;
        cout<<h[i]<<",";
    }
	
  float *d,*output;
	
	cudaMalloc(&d, size);
  cudaMalloc(&output, size);
    
	cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);

	if(count%2==0)
		sum<<<1,count/2>>>(d,count);
	else
		sum<<<1,(count/2)+1>>>(d,count);
	
	float result;
	cudaMemcpy(&result,d, sizeof(float), cudaMemcpyDeviceToHost);

  float mean = (float)result/count; 
  
  cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);

  cout << "\nMean is " << mean << endl;
  
	ss<<<1,count>>>(d,output,mean);
	
  //cudaMemcpy(&sm,output, size, cudaMemcpyDeviceToHost);
  
  //for(int i=0;i<count;i++)
  //  cout<<sm[i]<<" ";
  
  if(count%2==0)
		sum<<<1,count/2>>>(output,count);
	else
		sum<<<1,(count/2)+1>>>(output,count);
	
  float ans;           
	cudaMemcpy(&ans,output, sizeof(float), cudaMemcpyDeviceToHost);

  ans = (float)ans/count;
  ans = sqrt(ans);  
	cout<<"Standard Deviation is: "<<ans<<endl;
	cudaFree(d);

	return 0;
}