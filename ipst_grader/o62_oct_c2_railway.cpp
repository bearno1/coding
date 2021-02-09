#include<bits/stdc++.h>
#define F first
#define S second
#define L (idx*2)
#define R ((idx*2)+1)
using namespace std;
int n,m,a,b,c,d,pp,boss[100005],cur1,tem;
long long w,S1,S2,ww[200005];
vector<pair<long long,int> >use;
vector<pair<long long,int> >sw;
priority_queue<pair<pair<long long,int>,pair<int,int> > >pq;
int F(int x)
{
   if(boss[x]==x)return x;
   else return boss[x]=F(boss[x]);
}
void un(int x,int y)
{
   boss[F(x)]=F(y);
   return;
}
int main()
{
   scanf("%d %d",&n,&m);
   pp=n-1;
   for(int i=1;i<=n;i++)boss[i]=i;
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %lld",&a,&b,&w);
      if(i<n)S1+=w;
      pq.push({{-w,i},{a,b}});
      ww[i]=w;
   }
   while(!pq.empty())
   {
      a=-pq.top().F.F;
      b=pq.top().F.S;
      c=pq.top().S.F;
      d=pq.top().S.S;
      pq.pop();
      if(F(c)!=F(d))
      {
         un(c,d);
         S2+=a;
         //printf("%d\n",a);
         pp--;
         use.push_back({a,b});
      }
      else
      {
         sw.push_back({-a,b});
      }
   }
   //printf("%lld %lld\n",S1,S2);
   for(int i=0;i<use.size();i++)
   {
      if(use[i].S<n)continue;
      if(cur1>sw.size())break;
      while(sw[cur1].S<n)
      {
         cur1++;
         if(cur1>sw.size())break;
      }
      if(cur1>sw.size())break;
      if(-sw[cur1].F>use[i].F)
      {
         ww[sw[cur1].S]=use[i].F;
         ww[use[i].S]=-sw[cur1].F;
         //printf("%lld\n",(-sw[cur1].F+use[i].F));
         S2+=(-sw[cur1].F-use[i].F);
         cur1++;
      }
   }
   //printf("%lld %lld\n",S1,S2);
   if(S1<=S2)
   {
      printf("1\n");
      for(int i=n;i<=m;i++)printf("%lld\n",ww[i]);
   }
   else printf("0");
}
