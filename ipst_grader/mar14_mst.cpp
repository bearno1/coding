#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,m,boss[1005],u,v,ii,k;
double w,ans;
priority_queue<int>pp;
priority_queue<pair<pair<double,int>,pair<int,int> > >pq;
int F(int N)
{
   if(boss[N]==N)return N;
   else return boss[N]=F(boss[N]);
}
void UN(int x,int y)
{
   boss[F(x)]=F(y);
   return;
}
int main()
{
   scanf("%d %d",&n,&m);
   k=n-1;
   for(int i=0;i<=n;i++)boss[i]=i;
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %lf",&u,&v,&w);
      pq.push({{-w,-i},{u,v}});
   }
   while(!pq.empty())
   {
      if(k==0)break;
      w=-pq.top().F.F;
      ii=-pq.top().F.S;
      u=pq.top().S.F;
      v=pq.top().S.S;
      pq.pop();
      if(F(u)!=F(v))
      {
         UN(u,v);
         pp.push(-ii);
         ans+=w;
         k--;
      }
   }
   printf("%.3lf\n",ans);
   while(!pp.empty())
   {
      printf("%d\n",-pp.top()-1);
      pp.pop();
   }
}
/*
4 4
0 1 1
1 2 1
2 3 1
3 0 2
*/
