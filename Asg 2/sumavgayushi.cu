using namespace std;

__global__ void sum(int *input,int *n)
{
	int tid=threadIdx.x;
	int num_of_threads=blockDim.x;
	float tsize=(float)num_of_threads;

	int step_size=1;
	while(num_of_threads>0)
	{
		if(tid<num_of_threads)
		{
			int fst=tid*step_size*2;
			int snd=fst+step_size;

			if(snd<*n)
			{
				printf("fst = %d %d snd = %d %d\n",fst,input[fst],snd,input[snd]);
				input[fst]+=input[snd];
			}
		}

		step_size*=2;
		if(num_of_threads!=1)
		{
			
			tsize/=2;
			num_of_threads=(int)ceil(tsize);
	
		}
		else
		{
			num_of_threads=0;
		}

	}
}

int main()
{

	int count=5;
	
	//cout<<"Enter number of elements\n";
	//cin>>count;
	int *c=&count;
	const int size=count*sizeof(int);
	
	int a[count];
	for(int i=0;i<count;i++)
	{
		a[i]=rand()%100;
	}

	for(int i=0;i<count;i++)
	{
		cout<<a[i]<<endl;
	}

	int *d;
	int *n;

	cudaMalloc(&d,size);
	cudaMalloc(&n,sizeof(int));
	cudaMemcpy(d,a,size,cudaMemcpyHostToDevice);
	cudaMemcpy(n,c,sizeof(int),cudaMemcpyHostToDevice);
	if(count%2==0)
	{
		sum<<<1,count/2>>>(d,n);
	}else
	{
		sum<<<1,(count/2)+1>>>(d,n);
	}
	int result;
	cudaMemcpy(&result,d,sizeof(int),cudaMemcpyDeviceToHost);

	cout<<"sum = "<<result<<endl;
	double ans = (double)result/count;  
	cout << " Average is: " << ans << endl;

	cudaFree(d);

	return 0;
}
