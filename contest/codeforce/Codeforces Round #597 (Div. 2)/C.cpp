#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
char c[100005];
int n;
long long dp[100005][2];
bool p=false;
int main()
{
   scanf("%s",c+1);
   n=strlen(c+1);
   c[0]='1';
   dp[0][0]=1;
   for(int i=1;i<=n;i++)
   {
      if(c[i]=='m'||c[i]=='w')
      {
         p=true;
      }
   }
   if(p)printf("0");
   else
   {
      for(int i=1;i<=n;i++)
      {
         if(c[i]!='n'&&c[i]!='u')
         {
            dp[i][0]=dp[i-1][0];
         }
         else if(c[i]=='n')
         {
            dp[i][1]=dp[i-1][0];
            if(c[i-1]=='n')dp[i][0]=dp[i-1][0]+dp[i-1][1];
            else dp[i][0]=dp[i-1][0];
         }
         else
         {
            dp[i][1]=dp[i-1][0];
            if(c[i-1]=='u')dp[i][0]=dp[i-1][0]+dp[i-1][1];
            else dp[i][0]=dp[i-1][0];
         }
         dp[i][0]%=MOD;
      }
      printf("%lld",dp[n][0]);
   }
}
