#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> str;
int n,m,l;
int mmax(int x,int y){if (x>=y) return x; else return y;}
int mmin(int x,int y){if (x<=y) return x; else return y;}

void mysort(vector<string> &str,int j,int begin,int end)
{
	int r=0,p=0,s=0,left=begin-1,right=end+1,k;
	if (begin>=end || j>=l) return;
	for (int i=0;i<m;i++)
		if (str[i][j]=='R') r++;
		else if (str[i][j]=='P') p++;
		else if (str[i][j]=='S') s++;
	if (s==r && r==p) {mysort(str,j+1,begin,end);return;}
	int max,min;
	max=mmax(mmax(r,p),s);
	min=mmin(mmin(r,p),s);
	int flagmax=0,flagmin=0;
	char cmax,cmin;
	if ((r==max && r>p && r>s) || (p==max && r<p && p>s) || (s==max && r<s && s>p))
	{
		flagmax=1;
		if (r==max) cmax='R';if (p==max) cmax='P';if (s==max) cmax='S';
		for (int i=begin;i<=end;i++)
			if (str[i][j]==cmax)
			{
				k=i-1;
				while(k>=begin && str[k][j]!=cmax)
				{string temp=str[k];str[k]=str[i];str[i]=temp;k--;}
			}
		left=k+1;
	}

	if ((r==min && r<p && r<s) || (p==min && p<r && p<s) || (s==min && r>s && s<p))
	{
		flagmin=1;
		if (r==min) cmin='R';if (p==min) cmin='P';if (s==min) cmin='S';
		for (int i=begin;i<=end;i++)
			if (str[i][j]==cmin)
			{
				k=i+1;
				while(k<=end && str[k][j]!=cmin)
				{string temp=str[k];str[k]=str[i];str[i]=temp;k++;}
			}
		right=k-1;
	}
	
	if (flagmax==1) mysort(str,j+1,begin,left);
	if (flagmin==1) mysort(str,j+1,right,end);
	mysort(str,j+1,left+1,right-1);
}
int main(){
	int i;
	while(cin>>n>>m)
	{
		string temp;
		str.clear();
		getchar();
		for ( i=0;i<m;i++)
		{getline(cin,temp);str.push_back(temp);}

		l=temp.length();
		mysort(str,0,0,m-1);
		for ( i=0;i<m;i++)
			cout<<str[i]<<endl;
	}
	return 0;
}