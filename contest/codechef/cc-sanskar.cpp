#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
int t,n,all,k;
bool p;
long long val[25],dp[25][2097160],SS,div;
using namespace std;
long long FIND(int las,int mask)
{
   if(mask==all)
   {
      return 0;
   }
   if(dp[mask][node]!=-1)
   {
      return dp[mask][node];
   }
   for(int i=1;i<=n;i++)
   {
      if((mask>>i))
   }
}
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      SS=0;
      memset(dp,-1,sizeof(dp));
      scanf("%d %d",&n,&k);
      all=(1<<n)-1;
      for(int i=1;i<=n;i++)
      {
         scanf("%lld",&val[i]);
         SS+=val[i];
      }
      div=SS-((long long)k);
      p=FIND(1,1);
      if(dp[1][1]==0)printf("yes\n");
      else printf("no\n");
   }
}
