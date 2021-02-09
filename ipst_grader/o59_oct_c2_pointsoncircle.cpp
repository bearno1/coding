#include<bits/stdc++.h>
using namespace std;
int n,k,pos[1005],dif[1005][1005],pre;
int main()
{
	pos[1]=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&dif[i][j]);
		}
	}
	for(int i=2;i<=k;i++)
	{
		pre=dif[1][i];
		pos[i]=pre;
		bool p=true;
		for(int j=2;j<i;j++)
		{
			if((pos[j]+dif[i][j])%n!=pre&&(pos[j]-dif[i][j]+n)%n!=pre)p=false;
		}
		if(p)continue;
		pre=(n-dif[1][i])%n;
		pos[i]=pre;
		p=true;
		for(int j=2;j<i;j++)
		{
			if((pos[j]+dif[i][j])%n!=pre&&(pos[j]-dif[i][j]+n)%n!=pre)p=false;
		}
	}
	for(int i=1;i<=k;i++)printf("%d\n",pos[i]);
}
