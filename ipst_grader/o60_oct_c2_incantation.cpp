#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,k,kk,cc,tr,dd;
long long pre[20][130][130],cost[130],re[130][130],tem[130][130],ans;
void div(int N)
{
   //printf("%d\n",N);
   if(N<=dd)
   {
      for(int i=0;i<cc;i++)
      {
         for(int j=0;j<cc;j++)
         {
            re[i][j]=pre[N][i][j];
         }
      }
      return;
   }
   div(((N-k)/2)+k);
   for(int i=0;i<cc;i++)
   {
      for(int j=0;j<cc;j++)
      {
         tem[i][j]=re[i][j];
         re[i][j]=0;
      }
   }
   for(int st=0;st<cc;st++)
   {
      for(int ed=0;ed<cc;ed++)
      {
         for(int mid=0;mid<cc;mid++)
         {
            if(tem[st][mid]==0||tem[mid][ed]==0)continue;
            re[st][ed]=max(re[st][ed],tem[st][mid]+tem[mid][ed]-cost[mid]);
            //printf("{%d %d %d %lld %lld %lld %lld}\n",st,mid,ed,tem[st][mid],tem[mid][ed],cost[mid],tem[st][mid]+tem[mid][ed]-cost[mid]);
         }
      }
   }
   if((N-k)%2==1)
   {
      for(int i=0;i<cc;i++)
      {
         for(int j=0;j<cc;j++)
         {
            tem[i][j]=re[i][j];
            re[i][j]=0;
         }
      }
      for(int st=0;st<cc;st++)
      {
         for(int ed=0;ed<cc;ed++)
         {
            if(tem[st][ed]==0)continue;
            int e=ed;
            e=e&tr;
            e=e*2;
            re[st][e]=max(re[st][e],tem[st][ed]+cost[e]);
            re[st][e+1]=max(re[st][e+1],tem[st][ed]+cost[e+1]);
         }
      }
   }
   return;
}
int main()
{
   scanf("%d %d",&n,&k);
   dd=k*2;
   kk=(k*2);
   tr=(int)pow(2,k-1)-1;
   cc=(int)pow(2,k);
   for(int i=0;i<cc;i++)
   {
      scanf("%lld",&cost[i]);
      pre[k][i][i]=cost[i];
   }
   for(int i=k;i<kk;i++)
   {
      for(int st=0;st<cc;st++)
      {
         for(int ed=0;ed<cc;ed++)
         {
            if(pre[i][st][ed]==0)continue;
            int e=ed;
            e=e&tr;
            e=e*2;
            pre[i+1][st][e]=max(pre[i+1][st][e],pre[i][st][ed]+cost[e]);
            pre[i+1][st][e+1]=max(pre[i+1][st][e+1],pre[i][st][ed]+cost[e+1]);
         }
      }
   }
   // for(int st=0;st<cc;st++)
   // {
   //    for(int ed=0;ed<cc;ed++)
   //    {
   //       printf("%d %d %lld\n",st,ed,pre[3][st][ed]);
   //    }
   // }
   div(n);
   for(int st=0;st<cc;st++)
   {
      for(int ed=0;ed<cc;ed++)
      {
         ans=max(ans,re[st][ed]);
      }
   }
   printf("%lld",ans);
}
/*
5 2
1
5
4
1
--------------
1000 2
1
1
1
1
*/
