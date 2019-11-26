#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int x[100000],y[100000],w[100000],dp[100000],weight[100000];
int main(){
	int number,l;
	//cout<<"What's wrong?"<<endl;//
	cin>>number;
	for (l=1;l<=number;l++)
	{	
		int c,n,i,j;
		cin>>c>>n;
		for (i=1;i<=n;i++)
			cin>>x[i]>>y[i]>>w[i];
		fill(dp,dp+n+1,0);
		for (i=1;i<=n;i++)
		{
			dp[i]=dp[i-1]+2*x[i]+2*y[i];
			weight[i]=w[i];

			int temp=0,index=0,ww,dd;
			ww=w[i];
			j=i-1;
			dd=2*x[i]+2*y[i];
			while (ww+w[j]<=c && j>=1)
			{
				ww+=w[j];
				dd+=fabs(x[j]-x[j+1])+fabs(y[j]-y[j+1])-x[j+1]-y[j+1]+x[j]+y[j];
				if (dd+dp[j-1]<dp[i])
				{dp[i]=dd+dp[j-1];
				weight[i]=ww;}
				j--;
			}
		}
		cout<<dp[n]<<endl;
		if (l<number)
			cout<<endl;
	}
	return 0;

}