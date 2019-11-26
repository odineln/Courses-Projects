#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
double const inf=1<<31-1;
int main()
{
	int n,i;
	
	while(cin>>n)
	{
		vector<int> x(n+1),y(n+1);
		int xmin=inf,xmax=-inf;
		for (i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
			if (y[i]==0)
			{
				if (x[i]<xmin) xmin=x[i];
				if (x[i]>xmax) xmax=x[i];
			}
		}
		if (xmin>=xmax) {cout<<"unstable"<<endl;continue;}
		x[n]=x[0];y[n]=y[0];
		double area=0,sum=0,temp;
		for (i=0;i<n;i++)
		{
			temp=(double)(x[i]*y[i+1]-x[i+1]*y[i])/2.0;
			area+=temp;
			sum+=(double)(x[i]+x[i+1])/3.0*temp;
		}
		double center=sum/area;
		if (center<xmin && center>xmax) {cout<<"unstable"<<endl;continue;}
		double low=-inf,high=inf,weight;
		for (int i=0;i<n;i++)
		{
			if (x[i]<=xmax && x[i]>=xmin) {low=0;continue;}
			if (x[i]>xmax) weight=area*(xmax-center)/(x[i]-xmax);
			if (x[i]<xmin) weight=area*(xmin-center)/(x[i]-xmin);
			if (weight<high) high=weight;
		}
		if (high<=0) cout<<"unstable"<<endl;
		else if (high==inf) cout<<floor(low)<<" .. inf"<<endl;
		else cout<<floor(low)<<" .. "<<ceil(high)<<endl;
	}
}