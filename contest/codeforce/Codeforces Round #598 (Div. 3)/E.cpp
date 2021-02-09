#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n,gr[200005],k,g;
vector<pair<long long,int> >v;
long long dp[200005][2],x,mx1=(long long)1e14,mx2=0;
queue<pair<long long,int> >q;
int main()
{
	scanf("%d",&n);
	g=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		v.push_back({x,i});
	}
	sort(v.begin(),v.end());
	dp[2][0]=v[2].F-v[0].F;
	dp[2][1]=-1;
	q.push({2,dp[2][0]});
	for(int i=3;i<n;i++)
	{
		dp[i][0]=v[i].F-v[0].F;
		dp[i][1]=-1;
		if(!q.empty())
		{
			while(q.front().F<=i-3)
			{
				if(mx1>q.front().S-v[q.front().F+1].F)
				{
					mx1=q.front().S-v[q.front().F+1].F;
					mx2=q.front().F;
				}
				q.pop();
				if(q.empty())break;
			}
		}
		if(dp[i][0]>mx1+v[i].F)
		{
			dp[i][0]=mx1+v[i].F;
			dp[i][1]=mx2;
		}
		q.push({i,dp[i][0]});
	}
	k=n-1;
	while(k!=-1)
	{
		++g;
		//printf("%d\n",k);
		for(int i=k;i>dp[k][1];i--)
		{
			gr[v[i].S]=g;
		}
		k=dp[k][1];
	}
	printf("%lld %d\n",dp[n-1][0],g-1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",gr[i]-1);
	}
}
