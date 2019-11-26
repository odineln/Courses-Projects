#include<stdio.h>
#include <string>
#include<iostream>
#include <list>
using namespace std;
int main(){
/*freopen("sample.in", "r", stdin);
freopen("sample.out", "w", stdout);
	int p,c,i,time,index,stat,temp;

	string t;
	time=0;
	while (cin>>p>>c)
	{
		if (p==0 && c==0)
			return 0;
		int *line=new int[c+p];
		fill(line,line+c+p,1);
		time++;
		printf("Case %d\n",time);
		index=1;
		cin.ignore();
		for (i=0;i<c;i=i+1)
		{
			getline(cin,t);
			if (t[0]=='N')
			{
				if (line[index]==1)
				{temp=index%p;
				if (temp==0)
					temp=p;
				cout<<temp<<endl;
				index++;}
				else
				{while(line[index]!=1)
					index++;
				temp=index%p;
				if (temp==0)
					temp=p;
				cout<<temp<<endl;
				index++;
				}
			}
			else if (t[0]=='E')
			{
			temp=t[2]-'0';
			cout<<temp<<endl;
			line[(index/p+1)*p+temp]=0;
			}
		}
		delete[]   line;   
	}
	fclose(stdin);
    fclose(stdout);*/
	int p,c,i,time,temp;
	char t[5];
	time=0;
	while(cin>>p>>c)
	{
		if (p==0 && c==0)
			return 0;
		time++;
		printf("Case %d:\n",time);
		cin.ignore();
		list <int> line;
		if(p>c)
			p=c;
		for (i=1;i<=p;i++)
			line.push_back(i);
		for (i=0;i<c;i++)
		{
			scanf("%s",t);
			if (t[0]=='N')
			{
				
				cout<<line.front()<<endl;
				line.push_back(line.front());
				line.pop_front();
			}
			else
			{
				scanf("%d",&temp);
				line.remove(temp);
				line.push_front(temp);
			}
		
		}
			
	}
	return 0;
}