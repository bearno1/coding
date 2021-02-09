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
int n;
LL dp[100005][2];
vector<int>v[100005];
void dfs(int N,int pr)
{
    LL d1=0,d2=0;
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i]!=pr)
        {
            dfs(v[N][i],N);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0,-1);
    printf("%lld",(dp[0][0]+dp[0][1])%MOD);
}
