#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,boss[2005];
long long cost[2005],ro[2005],ss,cc,d[2005][2],k,x,dif[2005][2005],a,b,c;
vector<int>pp;
vector<pair<int,int> >ppp;
priority_queue<pair<long long,pair<int,int> > >pq;
bitset<2005>BB;
pair<int,int> F(int N)
{
   if(boss[N]==N)return {N,cost[N]};
   else
   {
      pair<int,int>yy;
      yy=F(boss[N]);
      boss[N]=yy.F;
      cost[N]=yy.S;
      return {boss[N],cost[N]};
   }
}
void un(int z1,int z2)
{
   pair<int,int>y1,y2;
   y1=F(z1);
   y2=F(z2);
   boss[y1.F]=y2.F;
   cost[y1.F]=min(y1.S,y2.S);
   cost[y2.F]=min(y1.S,y2.S);
   return;
}
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      boss[i]=i;
      scanf("%lld %lld",&d[i][0],&d[i][1]);
   }
   for(int i=1;i<=n;i++)
   {
      scanf("%lld",&cost[i]);
      ss+=cost[i];
   }
   for(int i=1;i<=n;i++)
   {
      scanf("%lld",&ro[i]);
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=i+1;j<=n;j++)
      {
         pq.push({-((abs(d[j][0]-d[i][0])+abs(d[i][1]-d[j][1]))*(ro[i]+ro[j])),{i,j}});
      }
   }
   while(!pq.empty())
   {
      c=-pq.top().F;
      a=pq.top().S.F;
      b=pq.top().S.S;
      pq.pop();
      pair<int,int>p1,p2;
      p1=F(a);
      p2=F(b);
      if(p1.F!=p2.F)
      {
         if(c<max(p1.S,p2.S))
         {
            ss-=max(p1.S,p2.S);
            ss+=c;
            un(a,b);
            ppp.push_back({min(a,b),max(a,b)});
         }
      }
   }
   for(int i=1;i<=n;i++)
   {
      pair<int,int>p1;
      p1=F(i);
      if(!BB[p1.F])
      {
         pp.push_back(p1.F);
         BB[p1.F]=true;
      }
   }
   sort(pp.begin(),pp.end());
   sort(ppp.begin(),ppp.end());
   printf("%lld\n",ss);
   printf("%d\n",pp.size());
   for(int i=0;i<pp.size();i++)
   {
      printf("%d ",pp[i]);
   }
   printf("\n");
   printf("%d\n",ppp.size());
   for(int i=0;i<ppp.size();i++)
   {
      printf("%d %d\n",ppp[i].F,ppp[i].S);
   }
}
/*
3
1 1
1 2
100 100
1000 1000 1
1 1 1
*/
