#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct point
{
	int x,y,z;
};
int b[6]={0,1,2,3,4,5};
double r[6];
point  ball[6],p1,p2;
const double pi=acos(-1);
double min(double m1,double m2)
{
	if (m1<m2)
		return m1;
	else
		return m2;
}
double dist(int i,int j)
{
	double d1,d2,d3,dd;
	d1=(ball[b[i]].x-ball[b[j]].x)*(ball[b[i]].x-ball[b[j]].x);
	d2=(ball[b[i]].y-ball[b[j]].y)*(ball[b[i]].y-ball[b[j]].y);
	d3=(ball[b[i]].z-ball[b[j]].z)*(ball[b[i]].z-ball[b[j]].z);
	dd=sqrt(d1+d2+d3);
	return dd;
}
double get_r(int index,int num)
{
	double dx,dy,dz;
	dx=min(fabs(ball[index].x-p1.x),fabs(ball[index].x-p2.x));
	dy=min(fabs(ball[index].y-p1.y),fabs(ball[index].y-p2.y));
	dz=min(fabs(ball[index].z-p1.z),fabs(ball[index].z-p2.z));
	r[num]=min(min(dx,dy),dz);
	for (int i=0;i<num;i++)
	{
		double temp;
		temp=dist(i,num);
		r[num]=min(r[num],temp-r[i]);
	}
	if (r[num]<0)
		r[num]=0;
	return r[num];
}
int main(){
/*freopen("sample.in", "r", stdin);
freopen("sample.out", "w", stdout);*/
	int n,j,i,time=0;
	double best;
	while (cin>>n)
	{
		if(n==0)
			return 0;
		time++;
		cin>>p1.x>>p1.y>>p1.z;
		cin>>p2.x>>p2.y>>p2.z;
		for (i=0;i<n;i++)
			cin>>ball[i].x>>ball[i].y>>ball[i].z;
		best=fabs(p2.x-p1.x)*fabs(p2.y-p1.y)*fabs(p2.z-p1.z);
		for (i=0;i<n;i++)
			b[i]=i;
		do
		{
			double sum=fabs(p2.x-p1.x)*fabs(p2.y-p1.y)*fabs(p2.z-p1.z);
			for(i=0;i<n;i++)
			{
				r[i]=get_r(b[i],i);
				sum-=4.0/3.0*pi*r[i]*r[i]*r[i];
			}
			if (sum<best)
				best=sum;
		}while(next_permutation(b,b+n));
		printf("Box %d: %.0lf\n",time,best);
		cout<<endl;
	}
	/*fclose(stdin);
    fclose(stdout);*/
	return 0;
}
/*
	int i,t[10],n;
	n=5;
	for (i=0;i<n;i++)
		t[i]=i;
	int j=1;
	while (j<=120)
	{	
		j++;
		
		for (i=0;i<n;i++)
			cout<<t[i]<<" ";
		next_permutation(t,t+n);
		cout<<endl;}

	int t[10]={1,2,6,4,3},int n=5,i;
	for (i=0;i<n;i++)
		cout<<t[i]<<" ";
	cout<<endl;
	sort(t,t+n);
	for (i=0;i<n;i++)
		cout<<t[i]<<" ";
	return 0;*/