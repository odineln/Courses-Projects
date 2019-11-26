#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int b[100000];
int m,n,k;

bool bs(int d)
{
	int c=0;
	for (int j=m-1;j>0;j--)
	{
		if (b[j]-b[j-1]<=d)
			if (m-j+1>=(c+1)*2*k)
			{
				c++;
				j--;
				if (c==n)
					return true;
			}
	}
	return false;
}

int main(){
	int temp=0;
	while (cin>>n>>k)
	{
		m=2*n*k;
		for (int i=0;i<m;i++)
		{cin>>b[i];
		if(b[i]>temp)
			temp=b[i];}
		sort(b,b+m);
		int l=0,r=temp,d,mid;
		while(l<=r)
		{	
			mid=(l+r)/2;
			if (bs(mid))
				r=mid-1;
			else
				l=mid+1;
		}
		printf("%d\n",r+1);
	}
	return 0;
}