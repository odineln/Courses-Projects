#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
vector< pair<int,int> > v;
int b[51][51];
void add(int t)
{
	for (int i=1;i<51;i++)
		if (b[t][i]>0)
		{b[t][i]-=1;b[i][t]-=1;add(i);cout<<i<<" "<<t<<endl;}
}
int main(){

	int i,t,n,t1,t2,d[51];
	

	cin>>t;
	for (int tt=0;tt<t;tt++)
	{
		fill(b[0],b[0]+51*51,0);
		fill(d,d+51,0);
		v.clear();
		cin>>n;
		for (i=0;i<n;i++)
		{cin>>t1>>t2;
		d[t1]++;d[t2]++;
		b[t1][t2]+=1;b[t2][t1]+=1;}
		int flag=1;
		int index=t1,begin=index;
		int num=0;
		for (i=1;i<51;i++)
			if (d[i]%2==1)
			{flag=0;break;}
	/*	while (num<n)
		{
			flag=0;
			if (b[index][index]>0)
			{v.push_back(make_pair(index,index));flag=1;b[index][index]-=2;num+=1;continue;}
			for (i=0;i<51;i++)
				if (b[index][i]>0)
				{v.push_back(make_pair(index,i));flag=1;b[index][i]-=1;b[i][index]-=1;index=i;num+=1;}
		}
*/		
		cout<<"Case #"<<tt+1<<endl;
		if (flag==0)
		{cout<<"some beads may be lost\n"<<endl;}		
		else
			add(begin);
			/*
		{for (i=0;i<v.size();i++)
			cout<<v[i].first<<" "<<v[i].second<<endl;
		cout<<endl;}*/
	}
	return 0;


}