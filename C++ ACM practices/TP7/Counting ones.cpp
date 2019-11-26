#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll count(ll n)
{
	ll c=0,t=n;
	ll l=0;
	while (t)
	{
		t=t>>1;
		l++;
	}
	n=n+1;
	for (ll i=1;i<=l;i++)
	{
		ll t1=n%(1ll<<i);
		c+=(n-t1)>>1;
		if (t1>(1ll<<(i-1))) c+=t1-(1ll<<(i-1));
	}
	return c;
}
int main()
{

	ll  begin,end;
	//while (scanf("%I64d %I64d",&begin,&end))
	while(cin>>begin>>end)
	{
	//printf("%I64d\n",count(end)-count(begin-1));
	cout<<count(end)-count(begin-1)<<endl;
	}
	return 0;
}