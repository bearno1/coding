#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
int val[305][305],QS[305][305][2],n,m,dp[305][305][305][2],ans=INT_MIN,cc;
using namespace std;
void DP(int pos)
{
   for(int i=0;i<=n+1;i++)
   {
      for(int j=0;j<=m+1;j++)
      {
         dp[i][j][0][0]=-1000000000;
         dp[i][j][0][1]=-1000000000;
         dp[i][j][pos+1][0]=-1000000000;
         dp[i][j][pos+1][1]=-1000000000;
         dp[i][j][pos+2][0]=-1000000000;
         dp[i][j][pos+2][1]=-1000000000;
      }
   }
   return;
}
int main()
{
   //freopen("ww.txt","w",stdout);
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         scanf("%d",&val[i][j]);
         QS[i][j][0]=QS[i][j-1][0]+val[i][j];
         QS[i][j][1]=QS[i-1][j][1]+val[i][j];
      }
   }
   /*printf("--------------------\n");
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         printf("%d ",QS[i][j][0]);
      }
      printf("\n");
   }
   printf("++++++++++++++++++++++++\n");
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         printf("%d ",QS[i][j][1]);
      }
      printf("\n");
   }*/
   DP(n);
   //F1
   for(int k=n;k>0;k--)
   {
      for(int i=1;i<=m;i++)
      {
         for(int j=i;j<=m;j++)
         {
            cc=QS[k][j][0]-QS[k][i-1][0];
            //printf("%d\n",cc);
            dp[i][j][k][1]=max(dp[i][j][k+1][1]+cc,cc);
         }
      }
   }
   for(int k=n;k>0;k--)
   {
      for(int d=2;d<=m;d++)
      {
         int O=m-d+1;
         for(int i=1;i<=O;i++)
         {
            int j=i+d-1;
            dp[i][j][k][1]=max(max(dp[i][j][k][1],dp[i][j][k+1][1]),max(dp[i+1][j][k][1],dp[i][j+1][k][1]));
         }
      }
   }
   for(int k=1;k<=n;k++)
   {
      for(int i=1;i<=m;i++)
      {
         for(int j=i;j<=m;j++)
         {
            cc=QS[k][j][0]-QS[k][i-1][0];
            //printf("%d\n",cc);
            dp[i][j][k][0]=max(dp[i][j][k-1][0]+cc,cc);
            ans=max(ans,dp[i][j][k][0]+dp[i][j][k+2][1]);
            //printf("%d %d %d %5d %5d %5d %5d\n",i,j,k,dp[i][j][k][0],dp[i][j][k+2][1],dp[i][j][k][0]+dp[i][j][k+2][1],ans);
         }
      }
   }
   //F2
   /*for(int k=1;k<=n;k++)
   {
      for(int i=1;i<=m;i++)
      {
         for(int j=i;j<=m;j++)
         {
            cc=QS[k][j][0]-QS[k][i-1][0];
            //printf("%d\n",cc);
            dp[i][j][k][1]=max(dp[i][j][k-1][1]+cc,cc);
         }
      }
   }
   for(int k=1;k<=n;k++)
   {
      for(int d=2;d<=m;d++)
      {
         int O=m-d+1;
         for(int i=1;i<=O;i++)
         {
            int j=i+d-1;
            dp[i][j][k][1]=max(max(dp[i][j][k][1],dp[i][j][k-1][1]),max(dp[i+1][j][k][1],dp[i][j+1][k][1]));
         }
      }
   }
   for(int k=n;k>1;k--)
   {
      for(int i=1;i<=m;i++)
      {
         for(int j=i;j<=m;j++)
         {
            cc=QS[k][j][0]-QS[k][i-1][0];
            //printf("%d\n",cc);
            dp[i][j][k][0]=max(dp[i][j][k+1][0]+cc,cc);
            ans=max(ans,dp[i][j][k][0]+dp[i][j][k-2][1]);
            //printf("%d %d %d %5d %5d %5d %5d\n",i,j,k,dp[i][j][k][0],dp[i][j][k-2][1],dp[i][j][k][0]+dp[i][j][k-2][1],ans);
         }
      }
   }
   //F3
   DP(m);
   for(int k=m;k>0;k--)
   {
      for(int i=1;i<=n;i++)
      {
         for(int j=i;j<=n;j++)
         {
            cc=QS[j][k][1]-QS[i-1][k][1];
            //printf("{ %d %d %d %d }\n",cc,i,j,k);
            dp[i][j][k][1]=max(dp[i][j][k+1][1]+cc,cc);
         }
      }
   }
   for(int k=m;k>0;k--)
   {
      for(int d=2;d<=n;d++)
      {
         int O=n-d+1;
         for(int i=1;i<=O;i++)
         {
            int j=i+d-1;
            dp[i][j][k][1]=max(max(dp[i][j][k][1],dp[i][j][k+1][1]),max(dp[i+1][j][k][1],dp[i][j+1][k][1]));
         }
      }
   }
   for(int k=1;k<=m;k++)
   {
      for(int i=1;i<=n;i++)
      {
         for(int j=i;j<=n;j++)
         {
            cc=QS[j][k][1]-QS[i-1][k][1];
            //printf("{ %d %d %d %d }\n",cc,i,j,k);
            dp[i][j][k][0]=max(dp[i][j][k-1][0]+cc,cc);
            ans=max(ans,dp[i][j][k][0]+dp[i][j][k+2][1]);
            //printf("%d %d %d %5d %5d %5d %5d\n",i,j,k,dp[i][j][k][0],dp[i][j][k+2][1],dp[i][j][k][0]+dp[i][j][k+2][1],ans);
         }
      }
   }
   //F4
   for(int k=1;k<=m;k++)
   {
      for(int i=1;i<=n;i++)
      {
         for(int j=i;j<=n;j++)
         {
            cc=QS[j][k][1]-QS[i-1][k][1];
            //printf("{ %d %d %d %d }\n",cc,i,j,k);
            dp[i][j][k][1]=max(dp[i][j][k-1][1]+cc,cc);
         }
      }
   }
   for(int k=1;k<=m;k++)
   {
      for(int d=2;d<=n;d++)
      {
         int O=n-d+1;
         for(int i=1;i<=O;i++)
         {
            int j=i+d-1;
            dp[i][j][k][1]=max(max(dp[i][j][k][1],dp[i][j][k-1][1]),max(dp[i+1][j][k][1],dp[i][j+1][k][1]));
         }
      }
   }
   for(int k=m;k>1;k--)
   {
      for(int i=1;i<=n;i++)
      {
         for(int j=i;j<=n;j++)
         {
            cc=QS[j][k][1]-QS[i-1][k][1];
            //printf("{ %d %d %d %d }\n",cc,i,j,k);
            dp[i][j][k][0]=max(dp[i][j][k+1][0]+cc,cc);
            ans=max(ans,dp[i][j][k][0]+dp[i][j][k-2][1]);
            //printf("%d %d %d %5d %5d %5d %5d\n",i,j,k,dp[i][j][k][0],dp[i][j][k-2][1],dp[i][j][k][0]+dp[i][j][k-2][1],ans);
         }
      }
   }*/
   printf("%d",ans);
}
