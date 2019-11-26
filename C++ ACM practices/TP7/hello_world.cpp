#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,k,i,j;
    cin>>n>>m>>k;
    double data[n][k];
    for (i=0;i<n;i++)
        for (j=0;j<k;j++)
            cin>>data[i][j];

    return 0;

}
