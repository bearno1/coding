#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,val[105],dp[105][105];
int main()
{
   scanf("%d",&n);
   n=n*2;
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&val[i]);
   }
   for(int d=n-2;d>-1;d-=2)
   {
      for(int i=1;i+d-1<=n;i++)
      {
         int j=i+d-1;
         if(i!=1&&j!=n)dp[i][j]=max(val[i-1],val[j+1])+dp[i-1][j+1];
         if(i-2>0)dp[i][j]=max(dp[i][j],val[i-2]+dp[i-2][j]);
         if(j+2<=n)dp[i][j]=max(dp[i][j],val[j+2]+dp[i][j+2]);
         //printf("%d %d %d\n",i,j,dp[i][j]);
      }
   }
   int ans=0;
   for(int i=1;i<=n;i++)
   {
      ans=max(ans,dp[i][i-1]);
   }
   printf("%d",ans);
}
