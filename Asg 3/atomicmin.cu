#include <iostream>
#include <cuda.h>

using namespace std;

__global__ void minElement(int *a, int *s)
{
    atomicMin(s, a[threadIdx.x]);

}

int main()
{
    int num=10, _min;
   
   
    //cout<<"Enter size of array: ";
    //cin>> num;
   
    int a[num];
    //cout<<"Enter array: ";
    for (int i = 0; i < num; i++)
    {
        a[i]=(i*2)+3;
    }
    for (int i = 0; i < num; i++)
    {
        cout << a[i]<<" ";
    }
   
    int *d_a, *d_min;
   
    cudaMalloc((void **)&d_a, sizeof(int)*num);
    cudaMalloc((void **)&d_min, sizeof(int));    
   
    cudaMemcpy(d_a, a, sizeof(int)*num, cudaMemcpyHostToDevice);
    int temp = 9999;
    cudaMemcpy(d_min, &temp, sizeof(int), cudaMemcpyHostToDevice);
   
   
    minElement<<<1, num>>>(d_a, d_min);
   
    cudaMemcpy(&_min, d_min, sizeof(int), cudaMemcpyDeviceToHost);
   

    cudaFree(d_a);
    cudaFree(d_min);
   
    cout<<"Minimum elemet: "<<_min<<endl;
   
    return 0;
}
