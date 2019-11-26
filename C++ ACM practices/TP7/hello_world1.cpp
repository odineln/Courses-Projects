#include<iostream>
#include<vector>
#include<math.h>
#include <limits>
#include<stdio.h>
using namespace std;
int main()
{
    int n,m,k,i,j;
    cin>>n>>m>>k;
    double data[n][k];
    for (i=0;i<n;i++)
        for (j=0;j<k;j++)
            cin>>data[i][j];
    double res=0,small=(numeric_limits<double>::max)();
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
        {
            double temp=0;
            for (int l=0;l<k;l++)
                temp+=(data[i][l]-data[j][l])*(data[i][l]-data[j][l]);
            temp=sqrt(temp);
            res+=temp;
            if (temp<small) small=temp;
        }
    //res+=(m-n*(n-1)/2)*small;
    //res/=m;
    printf("%.3f",res);
    return 0;

}
