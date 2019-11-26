#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
const	double	pi=acos(-1);
struct B
{
	double r,x,y,z;
};
B ball[10000];
int n,s;
double small_part(double r,double d)
{
	return 2.0/3.0*pi*r*r*r-pi*r*r*d+1.0/3.0*pi*d*d*d;
}
double cal(double level)
{
	double res=100*100*level;
	for (int i=1;i<=n;i++)
	{
		if (ball[i].z+ball[i].r<=level)
			res-=4.0/3.0*pi*ball[i].r*ball[i].r*ball[i].r;
		else if (ball[i].z+ball[i].r>level && ball[i].z<level)
			res-=(4.0/3.0*pi*ball[i].r*ball[i].r*ball[i].r-small_part(ball[i].r,level-ball[i].z));
		else if (ball[i].z-ball[i].r<=level && ball[i].z>=level)
			res-=small_part(ball[i].r,ball[i].z-level);
	}
	return res;
}
double find(double left,double but)
{
	double right=100.0;
	while (right-left>1e-6)
	{
		double mid=(left+right)/2.0;
		double v=cal(mid);
		if (fabs(v-but)<1e-6)
			return mid;
		else
			if (v>but) right=mid;
			else	left=mid;
	}
	return (left+right)/2.0;
}
int main(){
	int i;
	double volume;
	while(scanf("%d%d",&n,&s)==2)
	{
		volume=100.0*100.0*100.0;
		for (i=1;i<=n;i++)
		{
			double r_,x_,y_,z_;
			scanf("%lf%lf%lf%lf",&r_,&x_,&y_,&z_);
			ball[i].r=r_/1000.0;
			ball[i].x=x_/1000.0;
			ball[i].y=y_/1000.0;
			ball[i].z=z_/1000.0;
			volume-=4.0/3.0*pi*ball[i].r*ball[i].r*ball[i].r;
		}
		double low,high,piece;
		low=0;
		piece=volume/s;
		for (i=1;i<=s;i++)
		{
			if (i==s)
			{printf("%.9lf\n",100-low);break;}
			high=find(low,piece*i);
			printf("%.9lf\n",high-low);
			low=high;
		}
	}
	return 0;

}