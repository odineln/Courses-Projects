#include<iostream>
#include<vector>

using namespace std;


const long long mmax=100;

//int factor[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
long long dp[mmax+1][mmax+1];
long long n;
vector<long long> factor;
//__int64 dp[max+1][max+1];
void dfs(long long n_now,long long k_now,long long &ans,long long index,long long e,long long e_max)
//void dfs(__int64 n_now,__int64 k_no	w,__int64 &ans,__int64 n,int index,int e,int e_max)
{
	if (k_now>ans) return;
	if (n_now==n) {ans=k_now;return;}
	if (n_now>n || index>=factor.size()) return;
	//__int64 t=1;
	long long t=1;
	for (long long l=1;l<=e_max;l++)
	{
		t*=factor[index];
		if (k_now>ans/t) return;
		dfs(n_now*dp[l][e+l],k_now*t,ans,index+1,e+l,l);
	}
}

int main()
{
	long long i,j;
	vector<int> flag(mmax,0);
	for (i=2;i<mmax;i++)
		if (flag[i]==0) 
	{
		factor.push_back(i);
		for (j=i*2;j<mmax;j+=i)
			flag[j]=1;
	}
	
	for (i=0;i<mmax;i++)
	{dp[i][i]=1;dp[0][i]=1;}
	for (i=1;i<mmax;i++)
		for (j=1;j<i;j++)
			dp[j][i]=dp[j-1][i-1]+dp[j][i-1];

	while (cin>>n)
	{
		if (n==1) {cout<<"1 2"<<endl;continue;}
		long long  ans=(long long)1<<63;
		//__int64 ans=(__int64)1<<63-1;
		dfs(1,1,ans,0,0,63);
		//printf("%d %I64d\n",n,ans);
		cout<<n<<" "<<ans<<endl;
	}
	return 0;
}
