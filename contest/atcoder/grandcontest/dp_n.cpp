#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
long long SS[405],dp[405][405],re;
int x,n;
using namespace std;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&x);
      SS[i]=SS[i-1]+x;
   }
   for(int d=2;d<=n;d++)
   {
      for(int i=1;i+d-1<=n;i++)
      {
         int j=i+d-1;
         re=LLX;
         for(int k=i;k<j;k++)
         {
            re=min(re,dp[i][k]+dp[k+1][j]+SS[j]-SS[i-1]);
         }
         dp[i][j]=re;
      }
   }
   printf("%lld",dp[1][n]);
}
