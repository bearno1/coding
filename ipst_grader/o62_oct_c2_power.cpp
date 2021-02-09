#include<bits/stdc++.h>
#define F first
#define S second
#define L (idx*2)
#define R ((idx*2)+1)
using namespace std;
int n,m,u,v,w;
long long seq[1000005][2],ans=0,tem,mx;
void up(int st,int ed,int idx,int pos,long long val,int T)
{
   int mid=(st+ed)/2;
   if(st>pos||ed<pos)return;
   if(st==ed)
   {
      seq[idx][T]=max(seq[idx][T],val);
      return;
   }
   up(st,mid,L,pos,val,T);
   up(mid+1,ed,R,pos,val,T);
   seq[idx][T]=max(seq[L][T],seq[R][T]);
}
long long MX(int st,int ed,int idx,int a,int b,int T)
{
   int mid=(st+ed)/2;
   if(a<=st&&b>=ed)return seq[idx][T];
   if(a>ed||b<st)return (long long)(-1e16);
   return max(MX(st,mid,L,a,b,T),MX(mid+1,ed,R,a,b,T));
}
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<1000005;i++)seq[i][0]=INT_MIN,seq[i][1]=INT_MIN;
   for(int i=1;i<=n;i++)
   {
      up(1,n,1,i,i-n,0);
      up(1,n,1,i,-i+1,1);
   }
   for(int i=1;i<=m;i++)
   {
      mx=(long long)(-1e16);
      scanf("%d %d %d",&u,&v,&w);
      mx=max(mx,MX(1,n,1,1,u,0)+(n-u));
      mx=max(mx,MX(1,n,1,u,n,1)+(u-1));
      tem=mx;
      ans=max(ans,mx+w);
      mx=(long long)(-1e16);
      mx=max(mx,MX(1,n,1,1,v,0)+(n-v));
      mx=max(mx,MX(1,n,1,v,n,1)+(v-1));
      up(1,n,1,u,mx+w+(u-n),0);
      up(1,n,1,u,mx+w+(-u+1),1);
      up(1,n,1,v,tem+w+(v-n),0);
      up(1,n,1,v,tem+w+(-v+1),1);
      ans=max(ans,mx+w);
      printf("%lld\n",ans);
   }
}
/*
100 7
1 5 200
90 95 100
90 95 100
90 95 100
90 95 100
1 2 2000
99 100 1
*/
