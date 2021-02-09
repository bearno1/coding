#include<bits/stdc++.h>
using namespace std;
int d[1005],las[1005],p[1005],st,k,ll,o;
bool cc=false;
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&d[i]);
	}
	las[m+1]=n+1;
	for(int i=m;i>0;i--)
	{
		las[i]=las[i+1]-d[i];
	}
	st=1;
	if(k==n+1)cc=true;
	for(int i=1;i<=m;i++)
	{
		st--;
		ll=st;
		st=min(st+k,las[i]);
		if(st==las[i])
		{
			if(las[i+1]-1<ll+k)
			{
				//printf("[%d %d]\n",las[i+1]-1,ll+k);
				st=ll+1;
			}
		}
		o=st+d[i]-1;
		for(;st<=o;++st)
		{
			p[st]=i;
			if(st+1==n+1||st+k==n+1)cc=true;
		}
		//printf("%d %d %d\n",k,i,ll);
	}
	if(cc)
	{
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			printf("%d ",p[i]);
		}
	}
	else printf("NO");
}
