#pragma warning(disable : 4786)
#include<iostream>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

vector< pair<int,vector<int> > > sub;
vector< pair<int,pair<int,int> > > edge;
vector< pair<int,int> > point;
std::map<int,int> Set;

void MakeSet(int x)
{
	Set.insert(make_pair(x,x));
}

int find(int x)
{
	if (Set[x]==x)  return x;
	else return Set[x]=find(Set[x]);
}

void Union (int x,int y){
	int parentx=find(x),parenty=find(y);
	if (parentx==parenty) return;
	Set[parentx]=parenty;
}

int main()
{
	int cas,ni;
	vector<int> temp;
	sub.clear();
	point.clear();
	cin>>cas;
	for (ni=0;ni<cas;ni++)
	{
		int n,m,m_node,m_cost,x,y,i,j;
		cin>>n>>m;
		for (int mm=0;mm<m;mm++)
		{
			cin>>m_node>>m_cost;
			temp.clear();
			for (int mi=0;mi<m_node;mi++)
			{	
				int m_t;
				cin>>m_t;
				temp.push_back(m_t);
			}
			sub.push_back(make_pair(m_cost,temp));
		}
		for (i=0;i<n;i++)
		{
			cin>>x>>y;
			point.push_back(make_pair(x,y));
		}
		for (i=0;i<n;i++)
			for (j=i+1;j<n;j++)
			{
				int dis;
				dis=(point[i].first-point[j].first)*(point[i].first-point[j].first)+(point[i].second-point[j].second)*(point[i].second-point[j].second);
				edge.push_back(make_pair(dis,make_pair(i+1,j+1)));
			}
		sort(edge.begin(),edge.end());
		int best=0;
		Set.clear();
		for (i=1;i<=n;i++)
			MakeSet(i);
		for (i=0;i<edge.size();i++)
		{
			pair<int,int> e;
			e=edge[i].second;

			if (find(e.first)!=find(e.second))
			{best+=edge[i].first;
			Union(e.first,e.second);
			}
		}

		for (i=0;i< (1 << m);i++)
		{
			Set.clear();
			for (j=1;j<=n;j++)
				MakeSet(j);
			int cost=0;
			int cc=0;
			for (j=0;j<m;j++)
			{
				if ((i>> j) % 2==1)
					continue;
				cost+=sub[j].first;
				vector<int> nod;
				nod=sub[j].second;
				for (int k=0;k<nod.size()-1;k++)
				{Union(nod[k],nod[k+1]);}
			}
			
			for (int k=0;k<edge.size();k++)
			{
				pair<int,int> e;
				e=edge[k].second;
				if (find(e.first)!=find(e.second))
				{cost+=edge[k].first;
				Union(e.first,e.second);
				cc++;
				if (cc==n-1) break;}
			}
			/*for (j=1;j<=n;j++)
				cout<<Set[j]<<" ";
			cout<<endl;*/
			
			if (cost<best)
			{best=cost;
			}

		}
		cout<<best<<'\n'<<endl;
	}
	return 0;
}