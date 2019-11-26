#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
/*freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);*/

	int nx,ny,i,j,flag;
	float len,x[1000],y[1000],tt,t;
	while (cin>>nx>>ny>>len) 
	{
		flag=1;
		if (nx==0 && ny==0 && len==0.0)
		{	
			return 0;}
		else
		{	i=0;
			while(i<nx){
				cin>>tt;
				x[i]=tt;
				//cout<<x[i]<<endl;
				i++;}
			for (i=0;i<nx;i++)
				for (j=i+1;j<nx;j++)
					if (x[i]>x[j])
					{t=x[i];x[i]=x[j];x[j]=t;}
			if (x[0]>len/2 || x[nx-1]<75-len/2)		
				flag=0;
			else
				for (i=1;i<nx;i++)
				  if (x[i]-x[i-1]>len)
					flag=0;
			i=0;
			while(i<ny){
				cin>>y[i];
			//	cout<<y[i]<<" ";
				i++;}
			for (i=0;i<ny;i++)
				for (j=i+1;j<ny;j++)
					if (y[i]>y[j])
					{t=y[i];y[i]=y[j];y[j]=t;}
			if (y[0]>len/2 || y[ny-1]<100-len/2)		
				flag=0;
			else
				for (i=1;i<ny;i++)
				  if (y[i]-y[i-1]>len)
					flag=0;

			for (i=0;i<nx;i++)
				x[i]=0;
			for (i=0;i<ny;i++)
				y[i]=0;
			if (flag==0)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
/*fclose(stdin);
    fclose(stdout);
	system("pause");*/
	return 0;
}
