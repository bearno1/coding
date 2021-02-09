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
int n,a,b,ans;
vector<int>v[100005];
void dfs(int N,int pr)
{
    int child,x=1;
    if(pr!=0)child=v[N].size()-1;
    else child=v[N].size();
    ans+=child;
    while(x<child+1)
    {
        x*=2;
        ans++;
    }
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i]!=pr)dfs(v[N][i],N);
    }
    return;
}
int main()
{ื
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,0);
    printf("%d",ans);
}
