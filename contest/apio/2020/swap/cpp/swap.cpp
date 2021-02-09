#include "swap.h"
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
int mx=0,go[100005];
vector<pii>v;
bool p;
void init(int N, int M,std::vector<int> U, std::vector<int> V, std::vector<int> W)
{
    // for(int i=0;i<100005;i++)for(int j=0;j<20;j++)par[i][j]=-1,wi[i][j]=imx;
    // if(N-1!=M)return;
    // for(int i=0;i<M;i++)v[U[i]].pb({V[i],W[i]}),v[V[i]].pb({U[i],W[i]});
    // dfs(0,-1,1,0);
    for(int i=0;i<M;i++)go[V[i]]=W[i],v.pb({W[i],V[i]});
    sort(all(v));
    return;
}
int getMinimumFuelCapacity(int X, int Y)
{
    if(X==0||Y==0)return -1;
    if(v.size()==2)return -1;
    int k=-1;
    for(int i=0;i<v.size();i++)
    {
        if(X!=v[i].S&&Y!=v[i].S)
        {
            k=v[i].F;
            break;
        }
    }
    return max(k,max(go[X],go[Y]));
}
