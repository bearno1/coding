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
int n,m,op,a,b,c,q[300005][4],boss[20005],gr[20005],grl[20005],r;
vector<int>v[20005];
bitset<20005>vis;
vector<int>ans[20005];
stack<int>stk;
int F(int x)
{
    if(x==boss[x])return x;
    else return boss[x]=F(boss[x]);
}
void un(int x,int y)
{
    boss[F(x)]=F(y);
    return;
}
void dfs(int x)
{
    vis[x]=true;
    for(int i=0;i<v[x].size();i++)
    {
        if(!vis[v[x][i]])dfs(v[x][i]);
    }
    stk.push(x);
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)boss[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&q[i][0],&q[i][1],&q[i][2],&q[i][3]);
        if(q[i][0]==3)
        {
            un(q[i][1],q[i][2]);
            un(q[i][1],q[i][3]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(boss[i]==i)gr[i]=i;
        else gr[i]=F(i),vis[i]=true;
    }
    for(int i=1;i<=m;i++)
    {
        if(q[i][0]==3)continue;
        else if(q[i][0]==1)
        {
            v[F(q[i][1])].pb(F(q[i][2]));
            v[F(q[i][1])].pb(F(q[i][3]));
        }
        else
        {
            v[F(q[i][2])].pb(F(q[i][1]));
            v[F(q[i][3])].pb(F(q[i][1]));
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[gr[i]])dfs(gr[i]);
    }
    r=0;
    while(!stk.empty())
    {
        r++;
        grl[stk.top()]=r;
        stk.pop();
    }
    for(int i=1;i<=n;i++)
    {
        ans[grl[gr[i]]].pb(i);
    }
    printf("%d\n",r);
    for(int i=r;i>0;i--)
    {
        sort(all(ans[i]));
        printf("%d ",ans[i].size());
        for(int j=0;j<ans[i].size();j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}
