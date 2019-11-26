#include<iostream>
#include<vector>

using namespace std;
double dp[1000][11][11][11];
int main()
{
	int n,d,c,i,j,k,time;
	int com[51][51];
	for (i=0;i<51;i++)
	{com[i][i]=1;com[0][i]=1;}
	fill(dp[0][0][0],dp[0][0][0]+1000000,0.0);
	for (i=1;i<51;i++)
		for (j=1;j<i;j++)
			com[j][i]=com[j-1][i-1]+com[j][i-1];
	while(cin>>n>>d>>c)
	{
		vector<int> x1(c),x2(c),same(n+1,0);
		double ans=0.0;
		int dup=0;
		for (i=0;i<c;i++)
		{cin>>x1[i];same[x1[i]]++;}
		for (i=0;i<c;i++)
		{cin>>x2[i];same[x2[i]]++;if (same[x2[i]]==2) dup++;}
		int own=c-dup;
		int rest=n-2*own-dup;
		if (rest+own+dup<=d) {ans=1.0;printf("%.6f\n",ans);continue;}
		dp[0][own][own][dup]=1.0;
		for (time=1;time<=1000;time++)
			for (i=own;i>=0;i--)
				for (j=own;j>=0;j--)
					for (k=dup;k>=0;k--)
					{
						
						for (int ii=i;ii<=own;ii++)
							for (int jj=j;jj<=own;jj++)
								for (int kk=k;kk<=dup;kk++)
								{
									if ( (ii-i+jj-j+kk-k)>d || (ii+kk==0)||(jj+kk==0) ) continue;
									dp[time][i][j][k]+=dp[time-1][ii][jj][kk]/com[d][n]*com[ii-i][ii]*com[jj-j][jj]*com[kk-k][kk]*com[d-(ii-i+jj-j+kk-k)][n-ii-jj-kk];
								}
					
					}
		ans=0;
		for (time=1;time<=100;time++)		
		{for (i=own;i>0;i--)
			{ans+=dp[time][0][i][0]*time+dp[time][i][0][0]*time;}
			ans+=dp[time][0][0][0]*time;
			//cout<<dp[time][i][0][0]<<endl;
		}	
		printf("%.5f\n",ans);
	}
	return 0;
}