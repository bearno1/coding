#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int t,n,a,b,dp[1005][5];
vector<int>v[1005];
bitset<1005>vis;
void dfs(int N)
{
   vis[N]=true;
   int mk1=-10000;
   for(int i=0;i<v[N].size();i++)
   {
      if(!vis[v[N][i]])
      {
         dfs(v[N][i]);
         dp[N][0]+=max(dp[v[N][i]][0],max(dp[v[N][i]][1],dp[v[N][i]][2]));
         dp[N][1]+=dp[v[N][i]][0];
         dp[N][2]+=dp[v[N][i]][0];
         mk1=max(mk1,dp[v[N][i]][1]-dp[v[N][i]][0]);
      }
   }
   dp[N][2]+=mk1;
   return;
}
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      for(int i=0;i<1005;i++)v[i].clear(),vis[i]=false,dp[i][0]=0,dp[i][1]=1,dp[i][2]=1;
      scanf("%d",&n);
      for(int i=1;i<n;i++)
      {
         scanf("%d %d",&a,&b);
         v[a].push_back(b);
         v[b].push_back(a);
      }
      dfs(1);
      //for(int i=1;i<=n;i++)printf("{%d %d %d}\n",dp[i][0],dp[i][1],dp[i][2]);
      printf("%d\n",max(dp[1][0],max(dp[1][1],dp[1][2])));
   }
}
