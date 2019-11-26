#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cmath>
using namespace std;
const double e=0.000001;
const double pi=acos(-1);
int main()
{
	double x1,y1,x2,y2,x3,y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		double cx=(x1+x2+x3)/3.0,cy=(y1+y2+y3)/3.0;
		double a1,a2,a3,r;
		int	flag=0;
		r=(sqrt((cx-x1)*(cx-x1)+(cy-y1)*(cy-y1))+sqrt((cx-x2)*(cx-x2)+(cy-y2)*(cy-y2))+sqrt((cx-x3)*(cx-x3)+(cy-y3)*(cy-y3)))/3.0;
		double d1=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		double d2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		double d3=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		a1=acos((d2*d2+d3*d3-d1*d1)/(2.0*d2*d3))*2.0;
		a2=acos((d1*d1+d3*d3-d2*d2)/(2.0*d1*d3))*2.0;
		a3=acos((d2*d2+d1*d1-d3*d3)/(2.0*d1*d2))*2.0;
		double i=3.0;
		double ea=asin(e/2.0/r);
		while (i<1000)
		{
			double a=2.0*pi/i;
			int n1=round(a1/a),n2=round(a2/a),n3=round(a3/a);
			if ((fabs(a1/a-n1)<e) && (fabs(a2/a-n2)<e) && (fabs(a3/a-n3)<e))	break;
			else i+=1;
		}
		cout<<i<<endl;
	}
	return 0;

}