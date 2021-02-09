#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define L (idx*2)
#define R ((idx*2)+1)
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,q,x[100005],a,b,c,sq,div[505],r;
LL rr[500][105],ans[105];
int main()
{
	for(int i=0;i<4005;i++)seq[i][0]=1,rr[i][0]=1;
	sq=sqrt(n);
	for(int i=1;i<=n;i+=sq)
	{
		r++;
		div[r]=i;
	}
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
	}

}
