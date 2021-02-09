#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,dp[1005][5][10][1005],ss[1005][5][10],M[5],p;
int main()
{
   scanf("%d %d %d %d",&n,&M[0],&M[1],&M[2]);
   dp[1][0][1][1]=1;
   ss[1][0][1]=1;
   for(int i=2;i<=n;i++)
   {
      for(int j=0;j<3;j++)
      {
         for(int go=1;go<=7;go++)
         {
            p=go|(1<<j);
            //printf("%d %d %d\n",go,p,j);
            if(j==0)dp[i][j][p][1]+=ss[i-1][2][go];
            else if(j==1)dp[i][j][p][1]+=ss[i-1][0][go];
            else dp[i][j][p][1]+=ss[i-1][0][go]+ss[i-1][1][go];
            dp[i][j][p][1]%=MOD;
            //if(dp[i][j][p][1]!=0)printf("%d %d %d %d\n",i,j,p,dp[i][j][p][1]);
            for(int k=2;k<=M[j];k++)
            {
               dp[i][j][go][k]+=dp[i-1][j][go][k-1];
               dp[i][j][go][k]%=MOD;
               ss[i][j][go]+=dp[i][j][go][k];
               ss[i][j][go]%=MOD;
               //if(dp[i-1][j][go][k-1]!=0)printf("ooo\n");
               //if(dp[i][j][go][k]!=0)printf("--%d %d %d %d %d\n",i,j,go,k,dp[i][j][go][k]);
            }
         }
         for(int go=1;go<=7;go++)
         {
            ss[i][j][go]+=dp[i][j][go][1];
            ss[i][j][go]%=MOD;
         }
      }
   }
   long long ans=0;
   for(int i=0;i<3;i++)
   {
      ans+=ss[n][i][7];
      //printf("%d\n",ss[n][i][7]);
   }
   printf("%lld",ans%MOD);
}
