#include<bits/stdc++.h>
#define MOD ((long long)(1e9-1))
using namespace std;
int fen[45][80005],n,k,temp,x;
void UP(int pos,int lv,int ss)
{
	while(pos<80005)
	{
		fen[lv][pos]+=ss;
		fen[lv][pos]%=MOD;
		pos+=pos&(-pos);
	}
	return;
}
int SUM(int pos,int lv)
{
	int re=0;
	while(pos>0)
	{
		re+=fen[lv][pos];
		re%=MOD;
		pos-=pos&(-pos);
	}
	return re;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		x=n-x+1;
		UP(x,1,1);
		for(int j=1;j<k;j++)
		{
			temp=SUM(x-1,j);
			UP(x,j+1,temp);
		}
	}
	printf("%d",SUM(n,k));
}
