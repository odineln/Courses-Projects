#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		int n=s.length();
		long long c=0,c1=0,c2=0,c3=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]<'0' || s[i]>'9') {c1=c2=c3=0;continue;}
			int temp=s[i]-'0',t;
			if (temp%3==0) {c1+=1;c+=c1;}
			if (temp%3==1) {t=c2;c2=c1+1;c1=c3;c3=t;c+=c1;}
			if (temp%3==2) {t=c3;c3=c1+1;c1=c2;c2=t;c+=c1;}
			/*{int j=i-1,temp=s[i];
			if (temp%3==0) c++;
			while(j>=0)
			if (s[j]>='0' && s[j]<='9')
			{temp+=s[j];
			if (temp%3==0) c++;
			j--;}
			else break;}*/
		}
		cout<<c<<endl;
	}

	return 0;
}