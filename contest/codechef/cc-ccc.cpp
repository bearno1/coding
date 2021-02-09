#include<bits/stdc++.h>
using namespace std;
long long dp[1005][1005],ans,ss[1005];
int t,n,m,x;
vector<int>co;
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      co.clear();
      ans=(long long)1e18;
      scanf("%d %d",&n,&m);
      m=n-m;
      co.push_back(0);
      for(int i=1;i<=n;i++)
      {
         scanf("%d",&x);
         co.push_back(x);
      }
      sort(co.begin(),co.end());
      for(int i=1;i<=n;i++)
      {
         ss[i]=ss[i-1]+co[i];
      }
      dp[1][n]=0;
      for(int d=n-1;d>=m;d--)
      {
         dp[1][d]=dp[1][d+1]+co[d+1];
         dp[n-d+1][n]=dp[n-d][n]+((co[n-d]-co[n-d-1])*(d+1));
         if(d==m)ans=min(ans,dp[1][d]);
         if(d==m)ans=min(ans,dp[n-d+1][n]);
         for(int i=2;i+d-1<n;i++)
         {
            int j=i+d-1;
            dp[i][j]=min(dp[i-1][j]+((co[i-1]-co[i-2])*(d+1)),dp[i][j+1]+co[j+1]-co[i-1]);
            if(d==m)ans=min(ans,dp[i][j]);
            //printf("%d %d %d\n",i,j,d);
         }
      }
      if(m==1)printf("%d\n",min(co[n],n*co[1]));
      else printf("%lld\n",ans);
   }
}
