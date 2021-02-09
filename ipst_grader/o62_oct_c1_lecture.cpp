#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const long long LLX ((long long)1e18);
long long ti[100005],path[305][305],k,di[100005],st,ed,mid,ans=0,cl[100005],c,n,m,a,b,w;
bool ch(long long sp)
{
   long long t=0;
   for(int i=2;i<=c;i++)
   {
      t=max(t,ti[i-2]);
      t+=(di[i]*sp);
      if(t>ti[i])
      {
         return false;
      }
   }
   return true;
}
int main()
{
   freopen("in.txt","r",stdin);
   ti[0]=0;
   scanf("%lld %lld %lld",&c,&n,&m);
   for(int i=1;i<=c;i++)
   {
      scanf("%lld",&cl[i]);
   }
   for(int i=1;i<=c;i++)
   {
      scanf("%lld",&k);
      ti[i]=ti[i-1]+k;
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         path[i][j]=LLX;
         if(i==j)path[i][j]=0;
      }
   }
   for(int i=1;i<=m;i++)
   {
      scanf("%lld %lld %lld",&a,&b,&w);
      path[a][b]=w;
      path[b][a]=w;
   }
   for(int o=1;o<=n;o++)
   {
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=n;j++)
         {
            if(path[i][o]==LLX||path[o][j]==LLX)continue;
            path[i][j]=min(path[i][j],path[i][o]+path[o][j]);
         }
      }
   }
   for(int i=2;i<=c;i++)
   {
      di[i]=path[cl[i]][cl[i-1]];
   }
   st=1,ed=1005;
   while(st<=ed)
   {
      mid=(st+ed)/2;
      if(ch(mid))
      {
         ans=max(ans,mid);
         st=mid+1;
      }
      else
      {
         ed=mid-1;
      }
   }
   if(ans==1005)
   {
      st=ans,ed=100005;
      while(st<=ed)
      {
         mid=(st+ed)/2;
         if(ch(mid))
         {
            ans=max(ans,mid);
            st=mid+1;
         }
         else
         {
            ed=mid-1;
         }
      }
   }
   if(ans==100005)
   {
      st=ans,ed=1900000005;
      while(st<=ed)
      {
         mid=(st+ed)/2;
         if(ch(mid))
         {
            ans=max(ans,mid);
            st=mid+1;
         }
         else
         {
            ed=mid-1;
         }
      }
   }
   printf("%lld",ans);
}
/*
5 5 4
1 2 3 4 5
1 2 3 4 5
1 2 1
2 3 1
3 4 1
4 5 1
*/
