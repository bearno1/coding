#include<bits/stdc++.h>
using namespace std;
long long dp[10005][4],x,ans,de[10005][2],num[10005];
int t,n;
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      ans=((long long)(-1e18));
      scanf("%d",&n);
      de[n+1][0]=((long long)(1e18));
      de[n+1][1]=((long long)(-1e18));
      dp[n+1][2]=0;
      dp[n+1][3]=0;
      for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
      for(int i=1;i<=n;i++)
      {
         dp[i][0]=min(dp[i-1][0]+num[i],num[i]);
         dp[i][1]=max(dp[i-1][1]+num[i],num[i]);
         dp[n-i+1][2]=min(dp[n-i+2][2]+num[n-i+1],num[n-i+1]);
         dp[n-i+1][3]=max(dp[n-i+2][3]+num[n-i+1],num[n-i+1]);
         de[n-i+1][0]=min(de[n-i+2][0],dp[n-i+1][2]);
         de[n-i+1][1]=max(de[n-i+2][1],dp[n-i+1][3]);
      }
      for(int i=1;i<n;i++)
      {
         ans=max(ans,abs(dp[i][0]-de[i+1][1]));
         ans=max(ans,abs(dp[i][1]-de[i+1][0]));
      }
      printf("%lld\n",ans);
   }
}
