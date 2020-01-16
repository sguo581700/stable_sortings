#include<iostream>
#include<math.h>
using namespace std;
void counting_sort(int a[], int n)
{
	int max =INT_MIN;
	for(int i=0; i<n;++i)
	{
		if(a[i]>max)
			max = a[i];
	}
	int counter_size = max+1;
	int counter[counter_size];
	for(int i=0; i<counter_size;++i)
	{
		counter[i]=0;
	}
	for(int i=0; i<n;++i)
	{
		counter[a[i]]++;
	}
/*	for(int i=0; i<counter_size;++i)
	{
		cout<<counter[i]<<" ";
	}*/
	for(int i =1; i<=counter_size;++i)
	{
		counter[i]=counter[i]+counter[i-1];
	}
	for(int i=0; i<counter_size;++i)
	{
		cout<<counter[i]<<" ";
	}
	int b[n];
	for(int i=n-1; i>=0; --i)
	{
		b[--counter[a[i]]]=a[i];
	}	
	for(int i=0; i<n; ++i)
		a[i] = b[i];
	
}
int main()
{
	int a[] = {1,1,3,1,1,3,4,4,1,3};
	counting_sort(a, 10);
	/*for(int i=0; i<10;++i)
		cout<<a[i]<<" ";*/
}
