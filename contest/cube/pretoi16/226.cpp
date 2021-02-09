#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
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
int n,q,boss[200005],a,b,c,d,x[200005],nx[200005],cc,dd;
bitset<200005>vis;
int F(int x)
{
	return boss[x];
}
void dfs(int N,int st,int nn)
{
	vis[N]=true;
	boss[N]=st;
	nx[N]=nn;
	if(vis[x[N]])return;
	dfs(x[N],st,nn+1);
	return;
}
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<200005;i++)boss[i]=i;
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i,i,0);
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
		if(a==b)printf("DEAD\n");
		else if(F(c)==F(d))
		{
			if(F(a)==F(c)&&F(b)==F(c))
			{
				cc=nx[c];
				dd=nx[d];
				if(cc>dd)swap(cc,dd);
				cc++;
				if(nx[a]<=dd&&nx[a]>=cc)
				{
					if(nx[b]<=dd&&nx[b]>=cc)printf("DEAD\n");
					else printf("SURVIVE\n");
				}
				else
				{
					if(nx[b]<=dd&&nx[b]>=cc)printf("SURVIVE\n");
					else printf("DEAD\n");
				}
			}
			else
			{
				if(F(a)==F(b))printf("DEAD\n");
				else printf("SURVIVE\n");
			}
		}
		else
		{
			a=F(a);
			b=F(b);
			c=F(c);
			d=F(d);
			if(b==c||b==d)
			{
				if(a!=c&&a!=d)printf("SURVIVE\n");
				else printf("DEAD\n");
			}
			else
			{
				if(a==b)printf("DEAD\n");
				else printf("SURVIVE\n");
			}
		}
    }
}
