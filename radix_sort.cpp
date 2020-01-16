#include<iostream>
using namespace std;
void counting_sort(int a[], int n, int pos)
{	
	int counter_size = 10;
	int counter[counter_size];
	for(int i=0; i<counter_size;++i)
		counter[i]=0;

	for(int i=0; i<n;++i)
		counter[(a[i]/pos)%10]++;


	for(int i=1; i<=counter_size;++i)
		counter[i] = counter[i]+counter[i-1];


	int b[n];
	for(int i=n-1; i>=0;--i)
		b[--counter[(a[i]/pos)%10]]=a[i];

	for(int i=0; i<n;++i)
		a[i]=b[i];

}
void radix_sort(int a[], int n)
{
	int max = INT_MIN;
        for(int i=0; i<n;++i)
                (a[i]>max)?(max=a[i]):(max);


	for(int pos=1; (max/pos)>0; pos*=10)
	{
		counting_sort(a,n,pos);
		for(int i=0; i<n;++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int a[] = {14431,51154,33691,1603,76453,42439,57201,35079,9839,67547};
	radix_sort(a,10);
/*	for(int i=0; i<10;++i)
		cout<<a[i]<<" ";	
*/
}
