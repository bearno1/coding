#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,m,cc,k,di[]={-1,-1,0},dj[]={0,-1,-1},ii,jj,ni,nj,nn,sn,sm;
char c[7020][7020];
queue<pair<int,int> >q,qq;
int main()
{
	scanf("%d %d",&n,&m);
	k=min(n,m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]=='1')cc++;
			else q.push({i,j});
		}
	}
	printf("%d\n",cc);
	for(int i=1;i<k;i++)
	{
		sn=n-i;
		sm=m-i;
		if(i%2==1)
		{
			while(!q.empty())
			{
				ii=q.front().F;
				jj=q.front().S;
				q.pop();
				//printf("[%d %d]\n",ii,jj);
				if(ii>sn+1||jj>sm+1)continue;
				for(int j=0;j<3;j++)
				{
					ni=ii+di[j];
					nj=jj+dj[j];
					//printf("{%d %d}\n",ni,nj);
					if(ni<1||nj<1||ni>n||nj>m)continue;
                    if(c[ni][nj]=='0')continue;
					c[ni][nj]='0';
					cc--;
					qq.push({ni,nj});
				}
			}
		}
		else
		{
			while(!qq.empty())
			{
				ii=qq.front().F;
				jj=qq.front().S;
				qq.pop();
				//printf("[%d %d]\n",ii,jj);
				if(ii>sn+1||jj>sm+1)continue;
				for(int j=0;j<3;j++)
				{
					ni=ii+di[j];
					nj=jj+dj[j];
					//printf("{%d %d}\n",ni,nj);
                    if(ni<1||nj<1||ni>n||nj>m)continue;
                    if(c[ni][nj]=='0')continue;
					c[ni][nj]='0';
					cc--;
					q.push({ni,nj});
				}
			}
		}
		for(int i=1;i<=sm;i++)
		{
			if(c[sn+1][i]=='1')cc--;
		}
		for(int i=1;i<=sn+1;i++)
		{
			if(c[i][sm+1]=='1')cc--;
		}
		printf("%d\n",cc);
	}
}
