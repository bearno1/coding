#include<bits/stdc++.h>
#define MOD ((long long)(1e9+7))
using namespace std;
long long dp[105][105],las[105][105],tri,ans;
int n,k;
int main()
{
   scanf("%d %d",&n,&k);
   tri=((n+2)/3)*2;
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         dp[i][j]=min(k,i-1)+min(k,j-1);
      }
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         las[i][j]=las[i-1][j]+las[i][j-1]-las[i-1][j-1]+dp[i][j];
         las[i][j]%=MOD;
      }
   }
   ans+=las[n][n];
   ans%=MOD;
   for(int S=2;S<=tri;S++)
   {
      memset(dp,0,sizeof(dp));
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=n;j++)
         {
            for(int r=max(1,i-k);r<i;r++)
            {
               dp[i][j]+=las[r-1][j-1];
               dp[i][j]%=MOD;
            }
            for(int r=max(1,j-k);r<j;r++)
            {
               dp[i][j]+=las[i-1][r-1];
               dp[i][j]%=MOD;
            }
         }
      }
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=n;j++)
         {
            las[i][j]=las[i-1][j]+las[i][j-1]-las[i-1][j-1]+dp[i][j];
            las[i][j]%=MOD;
         }
      }
      ans+=las[n][n];
      ans%=MOD;
   }
   printf("%lld",ans);
}
