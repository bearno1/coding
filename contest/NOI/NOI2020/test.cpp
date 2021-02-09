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
int a,b,c,n,k,ans=20;
vector<pair<int,int> >v[20];
vector<int>an;
vector<int>ok;
bool vis[20];
void dfs(int N,int prev,int dis)
{
    if(dis>k)return;
    vis[N]=true;
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i].F!=prev)dfs(v[N][i].F,N,dis+v[N][i].S);
    }
    return;
}
void gen(int lv)
{
    if(lv==n+1)
    {
        bool p=true;
        if(ok.size()>=ans)return;
        for(int i=1;i<=n;i++)vis[i]=false;
        for(int i=0;i<ok.size();i++)
        {
            dfs(ok[i],ok[i],0);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])p=false;
        }
        if(p)
        {
            ans=ok.size();
            an.clear();
            for(int i=0;i<ans;i++)an.pb(ok[i]);
        }
    }
    else
    {
        gen(lv+1);
        ok.pb(lv);
        gen(lv+1);
        ok.pop_back();
    }
    return;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    gen(1);
    printf("%d\n",ans);
    for(int i=0;i<ans;i++)
    {
        printf("%d ",an[i]);
    }
}
