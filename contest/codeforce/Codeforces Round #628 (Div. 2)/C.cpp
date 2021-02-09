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
bitset<100005>go;
int n,r,ans[100005],a,b;
vector<pair<int,int> >v[100005];
void dfs(int N)
{
    go[N]=true;
    for(int i=0;i<v[N].size();i++)
    {
        if(!go[v[N][i].F])
        {
            dfs(v[N][i].F);
            ans[v[N][i].S]=r;
            r++;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb({b,i});
        v[b].pb({a,i});
    }
    dfs(1);
    for(int i=1;i<n;i++)
    {
        printf("%d\n",ans[i]);
    }
}
