#include<iostream>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

int record[1<<21],num[1<<21],back[1<<21];
int main()
{
	int n,m,i,j,p1,p2,v[21];
	bool flag=false;

	while (cin>>n>>m)
	{
		if (n==0 &&m==0) break;
		if (m>n-1) cout<<"Impossible"<<endl;
		for (i=0;i<(1<<n);i++) back[i]=record[i]=0;
		fill(v,v+21,0);
		for (i=0;i<m;i++)
		{
			cin>>p1>>p2;
			v[p1]=v[p1]|(1<<p2);
			v[p2]=v[p2]|(1<<p1);
		}
		record[(1<<n)-1]=1;
		queue<int> q;
		q.push((1<<n)-1);
		while(!q.empty() && flag==false)
		{
			int t=q.front();
			q.pop();
			for (i=0;i<n;i++)
			{
				if ((1<<i)&t==1)
				{
					int next=0;
					for (j=0;j<n;j++)
						if (1<<j&t==1 && j!=i)
							next=next|v[j];
					if (record[next]==0)
					{
						
						{q.push(next);
						record[next]=1;
						back[next]=t;
						num[next]=i;}
						if (next==0) {flag=true; break;}
					}

				}

			}
		}
			if (flag==true)
			{
				vector<int> res;
				res.push_back(i);
				int t=0;
				while(back[t]!=(1<<n)-1)
				{t=back[t];res.push_back(num[t]);}
				printf("%d: ",res.size());
				for (i=res.size()-1;i>=0;i--)
					if (i!=0) cout<<res[i]<<" ";
					else cout<<res[i]<<endl;
				break;
			}
			else
				cout<<"Impossible"<<endl;


	}
	return 0;

}