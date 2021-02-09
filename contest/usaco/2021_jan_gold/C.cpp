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
typedef pair<int,LL> pii;
int bs[100005],x[100005],a,b,ans[100005],co,rr,tp,tp1,pos[100005];
LL k,n,m,mx,mn;
vector<pii>vis[100005];
vector<int>cl[100005];
bitset<100005>vi;
map<int,int>mm;
queue<pii>q;
void dfs(int N,int pr,int lv)
{
    if(lv!=0&&N==pr)return;
    cl[pr].pb(N);
    bs[N]=pr;
    vi[N]=true;
    if(lv!=0)
    {
        for(int i=0;i<vis[N].size();i++)
        {
            vis[pr].pb({vis[N][i].F,lv*m+vis[N][i].S});
        }
    }
    dfs(pos[N],pr,lv+1);
    return;
}
int main()
{
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=1;i<=n;i++)vis[i].pb({i,0}),bs[i]=i,x[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        vis[x[a]].pb({b,i});
        vis[x[b]].pb({a,i});
        swap(x[a],x[b]);
    }
    for(int i=1;i<=n;i++)pos[x[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(!vi[i])
        {
            dfs(i,i,0);
            co=0;
            mm.clear();
            rr=0;
            while(!q.empty())q.pop();
            tp=vis[i].size(),tp1=cl[i].size();
            for(int j=0;j<tp;j++)
            {
                vis[i].pb({vis[i][j].F,vis[i][j].S+(tp1*m)});
            }
            // printf("\n");
            // for(int j=0;j<vis[i].size();j++)
            // {
            //     printf("[%d %lld] ",vis[i][j].F,vis[i][j].S);
            // }
            for(int j=0;j<cl[i].size();j++)
            {
                //printf("{%d} ",cl[i][j]);
                mn=j*m;
                mx=mn+k;
                //printf("%lld %lld\n",mn,mx);
                if(rr<vis[i].size())
                {
                    while(vis[i][rr].S<=mx)
                    {
                        q.push(vis[i][rr]);
                        mm[vis[i][rr].F]++;
                        if(mm[vis[i][rr].F]==1)co++;
                        rr++;
                        if(rr>=vis[i].size())break;
                    }
                }
                if(!q.empty())
                {
                    while(q.front().S<mn)
                    {
                        mm[q.front().F]--;
                        if(mm[q.front().F]==0)co--;
                        q.pop();
                        if(q.empty())break;
                    }
                }
                ans[cl[i][j]]=co;
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
}
