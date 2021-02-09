#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e10));
using namespace std;
int t,n,k,a,b;
long long dp[2][210];
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d %d",&n,&k);
      for(int i=0;i<2;i++)
         for(int j=0;j<210;j++)
            dp[i][j]=LLX;
      dp[0][105]=0;
      for(int i=1;i<=n;i++)
      {
         int x=(i%2),y=(i+1)%2;
         scanf("%d %d",&a,&b);
         for(int j=1;j<209;j++)
         {
            dp[x][j]=min(a+dp[y][j-1],b+dp[y][j+1]);
            //printf("%d %d %d\n",x,j,dp[x][j]);
         }
      }
      long long ans=LLX;
      for(int i=0;i<k;i++)
      {
         ans=min(ans,dp[n%2][105-i]);
         ans=min(ans,dp[n%2][105+i]);
         //printf("%d %lld %lld\n",i,dp[n%2][105-i],dp[n%2][105-i]);
      }
      printf("%lld\n",ans);
   }
}
