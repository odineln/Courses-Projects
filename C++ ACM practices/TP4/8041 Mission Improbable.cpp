#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int r,c,t;
	int b[100][100],mr[100],mc[100];
	while (cin>>r>>c)
	{
		int i,j;
		fill(b[0],b[0]+10000,0);
		fill(mr,mr+100,0);
		fill(mc,mc+100,0);
		for (i=0;i<r;i++)
			for (j=0;j<c;j++)
			{cin>>t;b[i][j]=t;}
		for (i=0;i<r;i++)
			for (j=0;j<c;j++)
			{if (b[i][j]>mr[i])
					mr[i]=b[i][j];
			if (b[i][j]>mc[j])
				mc[j]=b[i][j];
			}
		int res=0;
		for (i=0;i<r;i++)
			for (j=0;j<c;j++)
				if (b[i][j]<mr[i] && b[i][j]<mc[j] && b[i][j]!=0)
				{res+=b[i][j]-1;b[i][j]=1;}
		cout<<res<<endl;
	}

}