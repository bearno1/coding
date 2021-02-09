#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int t,n,dp[1005],x,ans;
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      ans=0;
      memset(dp,0,sizeof(dp));
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
      {
         scanf("%d",&x);
         for(;x>0;x--)
         {
            dp[x]++;
         }
      }
      for(int i=1;i<=n;i++)
      {
         if(dp[i]>=i)ans=max(ans,i);
      }
      printf("--%d\n",ans);
   }
}
