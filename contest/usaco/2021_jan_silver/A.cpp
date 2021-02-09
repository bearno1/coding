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
int n,m,x[100005],a,b,bs[100005];
set<int>vis[100005];
set<int>::iterator it;
bitset<100005>vi;
void dfs(int N,int pr)
{
    if(vi[N])return;
    vi[N]=true;
    it=vis[N].begin();
    bs[N]=pr;
    while(it!=vis[N].end())
    {
        vis[pr].insert(*it);
        it++;
    }
    dfs(x[N],pr);
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)vis[i].insert(i),x[i]=i,bs[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        vis[x[a]].insert(b);
        vis[x[b]].insert(a);
        swap(x[a],x[b]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vi[i])
        {
            dfs(i,i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",vis[bs[i]].size());
    }
}
