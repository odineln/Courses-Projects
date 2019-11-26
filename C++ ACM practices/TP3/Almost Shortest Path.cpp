#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;
int c[500][500],path[500],S,D,d[500],n,m;
bool visit[500];
const int inf=pow(2,16);
int min_dist()
{

	int i;
	fill(visit,visit+n,false);
	fill(path,path+n,-1);
	visit[S]=true;
	for (i=0;i<n;i++)
		d[i]=c[S][i];
	int flag=1,index=-1;
	while (flag==1)
	{
		flag=0;
		index=-1;
		int temp=inf;
		for (i=0;i<n;i++)
			if (visit[i]==false && d[i]<temp)
			{temp=d[i];index=i;}
		if (index==-1)
		{flag=0;break;}
		else
			flag=1;
		visit[index]=true;
		for (i=0;i<n;i++)
			if (visit[i]==false && c[index][i]!=inf && d[index]+c[index][i]<d[i])
			{d[i]=d[index]+c[index][i];path[i]=index;}
	}
	if (d[D]==inf)
		return -1;
	else
		return d[D];
}
void reduce_route()
{
	int i=D;
	while (path[i]!=-1)
	{c[path[i]][i]=inf;i=path[i];}
	c[S][i]=inf;
}
int main()
{
	int i,a,b,cost;
	while (cin>>n>>m)
	{
		if (n==0 && m==0)
			return 0;
		cin>>S>>D;
		fill(c[0],c[0]+250000,inf);
		fill(path,path+n,-1);
		for (i=0;i<m;i++)
		{
			cin>>a>>b>>cost;
			c[a][b]=cost;
		}
		/*
		for (i=0;i<n;i++)
			d[i]=c[S][i];
		fill(visit[0],visit[0]+n,false);
		visit[S]=true;
		int flag=1,index=-1;
		while (flag==1)
		{
			flag=0;
			index=-1;
			temp=inf;
			for (i=0;i<n;i++)
				if (visit[i]==false && d[i]<temp)
					index=i;
			if (index==-1)
			{flag=0;break;}
			visit[index]=true;
			for (i=0;i<n;i++)
				if (visit[i]==false && c[index][i]!=inf && d[index]+c[index][i]<d[i])
				{d[i]=d[index]+c[index][i];path[i]=index;}
		}
		*/

		int best=min_dist();
		if (best==inf)
		{cout<<-1<<endl;continue;}
		/*i=D;
		while (path[i]!=-1)
		{c[path[i]][i]=inf;i=path[i];}
		c[S][i]=inf;*/
		reduce_route();
		int best_new=min_dist();
		while (best_new==best)
		{reduce_route();best_new=min_dist();}
		if (best_new==-1)
			cout<<-1<<endl;
		else
			cout<<best_new<<endl;


	}

}