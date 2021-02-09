#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long N ((long long)(1e18));
using namespace std;
long long dp[100005];
int n,w,cost,ww,ans;
int main()
{

   scanf("%d %d",&n,&w);
   for(int i=0;i<100005;i++)
   {
      dp[i]=N;
   }
   dp[0]=0;
   for(int i=1;i<=n;i++)
   {
      scanf("%d %d",&ww,&cost);
      for(int j=100004;j>=0;j--)
      {
         if(dp[j]!=N)
         {
            dp[j+cost]=min(dp[j+cost],dp[j]+ww);
         }
      }
   }
   for(int i=0;i<=100004;i++)
   {
      if(dp[i]<=w)ans=i;
   }
   printf("%d",ans);
}
