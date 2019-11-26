#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
const double pi=acos(-1);
using namespace std;
bool cmp(pair<double,int> x1,pair<double,int> x2)
{
return x1.first<=x2.first;
}
int main()
{
	int n,i;
	
	while(cin>>n)
	{
		vector<int> x(n),y(n),dx(n-1),dy(n-1);
		vector<pair<double,int> > point;
		map<double,int> m;
		map<double,int>::iterator iter;
		int rank=1;
		int lower=0,higher=0;
		double angle;
		for (i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		for (i=1;i<n;i++)
		{
			dx[i-1]=x[i]-x[0];
			dy[i-1]=y[i]-y[0];
			angle=atan2(dx[i-1],dy[i-1]);
			if (angle>0 && angle<pi/2.0) rank++;
			if (angle<=pi && angle>=pi/2.0) {point.push_back(make_pair(angle-pi/2.0,1));higher++;}
			if (angle<=0 && angle>=-pi/2.0) {point.push_back(make_pair(angle+pi/2.0,0));lower++;}
		}
		int more=0,less=higher+lower;
		sort(point.begin(),point.end(),cmp);
		m[0]=lower;
		m[pi/2]=higher;
		for (i=0;i<point.size();i++)
		{
			if (point[i].second==1) {m[point[i].first]=lower;lower--;}
			else	{if (i>0) m[point[i].first]=m[point[i-1].first]+1; else m[point[i].first]=lower+1;higher--;	}
		}
		for (iter=m.begin();iter!=m.end();iter++)
		{	if (iter->second>more) more=iter->second;
			if (iter->second<less) less=iter->second;}
		cout<<rank+less<<" "<<rank+more<<endl;
	}
	return 0;

}