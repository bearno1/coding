#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int x,n;
long long dp[100005][3];
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&x);
      if(i<=2)continue;
      dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
      dp[i][1]=dp[i-1][0]+x;
      dp[i][2]=dp[i-1][1];
   }
   printf("%lld",max(dp[n][0],max(dp[n][1],dp[n][2])));
}
