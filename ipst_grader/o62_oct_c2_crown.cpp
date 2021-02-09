#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n,hi,h[200005];
long long ans,dp[200005][6][2],a;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&hi);
      h[i]=hi;
      a+=hi;
      if(hi==0)continue;
      if(hi>=dp[i-1][0][1])
      {
         dp[i][0][0]=dp[i-1][0][0]+hi;
         dp[i][0][1]=hi;
         if(hi>1)
         {
            dp[i][1][0]=dp[i-1][0][0]+hi;
            dp[i][1][1]=hi;
         }
      }
      else
      {
         dp[i][0][0]=hi;
         dp[i][0][1]=hi;
         if(hi>1)
         {
            dp[i][1][0]=hi;
            dp[i][1][1]=hi;
         }
      }
      if(hi>=dp[i-1][1][1]&&dp[i-1][1][1]!=0)
      {
         dp[i][2][0]=dp[i-1][1][0]+dp[i-1][1][1]-1;
         dp[i][2][1]=dp[i-1][1][1]-1;
      }
      else if(dp[i-1][1][1]!=0)
      {
         dp[i][2][0]=dp[i-1][1][0]+hi;
         dp[i][2][1]=hi;
      }
      if(hi>=dp[i-1][2][1]&&dp[i-1][2][1]!=0)
      {
         if(dp[i][2][0]<dp[i-1][2][0]+dp[i-1][1][1])
         {
            dp[i][2][0]=dp[i-1][2][0]+dp[i-1][2][1];
            dp[i][2][1]=dp[i-1][2][1];
         }
      }
      else if(dp[i-1][1][1]!=0)
      {
         if(dp[i][2][0]<dp[i-1][2][0]+hi)
         {
            dp[i][2][0]=dp[i-1][2][0]+hi;
            dp[i][2][1]=hi;
         }
      }
      if(hi>dp[i-1][2][1]&&dp[i-1][2][1]!=0)
      {
         dp[i][3][0]=dp[i-1][2][0]+hi;
         dp[i][3][1]=hi;
         dp[i][4][0]=dp[i-1][2][0]+hi;
         dp[i][4][1]=hi;
      }
      if(hi>=dp[i-1][4][1]&&dp[i-1][4][1]!=0)
      {
         if(dp[i][4][0]<dp[i-1][4][0]+hi)
         {
            dp[i][4][0]=dp[i-1][4][0]+hi;
            dp[i][4][1]=hi;
         }
      }
      if(hi>=dp[i-1][4][1]&&dp[i-1][4][1]!=0)
      {
         dp[i][5][0]=dp[i-1][4][0]+dp[i-1][4][1]-1;
         dp[i][5][1]=dp[i-1][4][1]-1;
      }
      else if(dp[i-1][4][1]!=0)
      {
         dp[i][5][0]=dp[i-1][4][0]+hi;
         dp[i][5][1]=hi;
      }
      if(hi>=dp[i-1][5][1]&&dp[i-1][5][1]!=0)
      {
         if(dp[i][5][0]<dp[i-1][5][0]+dp[i-1][5][1])
         {
            dp[i][4][0]=dp[i-1][5][0]+dp[i-1][5][1];
            dp[i][4][1]=dp[i-1][5][1];
         }
      }
      else if(dp[i-1][5][1]!=0)
      {
         if(dp[i][5][0]<dp[i-1][5][0]+hi)
         {
            dp[i][5][0]=dp[i-1][5][0]+hi;
            dp[i][5][1]=hi;
         }
      }
      //printf("%lld %lld %lld %lld %llld %lld\n",dp[i][0][0],dp[i][1][0],dp[i][2][0],dp[i][3][0],dp[i][4][0],dp[i][5][0]);
      ans=max(ans,dp[i][4][0]);
      ans=max(ans,dp[i][5][0]);
   }
   if(n<=5)
   {
      if(ans!=0)printf("%lld",ans);
      else printf("-1");
   }
   else
   {
      if(ans==0)printf("-1");
      else
      {
         ans=0;
         for(int i=2;i<n;i++)
         {
            if(min(h[i-1],h[i+1])-1>0)ans=max(ans,a-h[i]+(min(h[i-1],h[i+1])-1));
         }
         printf("%lld",ans);
      }
   }
}
