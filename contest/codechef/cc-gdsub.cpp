#include<bits/stdc++.h>

#define MOD ((long long)(1e9+7))
long long m[8005],dp[8005][8005],ans=1,l[8005];
int n,k,A,x;
using namespace std;
int main()
{
   scanf("%d %d",&n,&k);
   A=min(n,min(k,8000));
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&x);
      m[x]++;
   }
   if(k==0)
   {
      printf("1");
      return 0;
   }
   for(int i=2;i<=8000;i++)
   {
      for(int j=2;j<=A;j++)
      {
         dp[i][j]=((l[j-1]-dp[i][j-1]+MOD)%MOD)*m[i];
         dp[i][j]%=MOD;
         ans+=dp[i][j];
         ans%=MOD;
         l[j]+=dp[i][j];
         l[j]%=MOD;
      }
      dp[i][1]=m[i];
      ans+=dp[i][1];
      ans%=MOD;
      l[1]+=dp[i][1];
      l[1]%=MOD;
   }
   printf("%lld",ans);
}
