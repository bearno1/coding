#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long MX ((long long)(1e18+7));
using namespace std;
int n,m,l,lv[50005],st,ed,a,b,c;
long long node[50005][35],co;
priority_queue<pair<long long,pair<int,int> > >pq;
vector<pair<int,int> >v[50005];
int main()
{
   scanf("%d %d %d",&n,&m,&l);
   scanf("%d %d",&st,&ed);
   for(int i=1;i<=n;i++)scanf("%d",&lv[i]);
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %d",&a,&b,&c);
      v[a].push_back({b,c});
   }
   for(int i=0;i<50005;i++)
   {
      for(int j=0;j<35;j++)
      {
         node[i][j]=MX;
      }
   }
   node[st][0]=0;
   pq.push({0,{st,0}});
   while(!pq.empty())
   {
      co=-pq.top().F;
      b=pq.top().S.F;
      c=pq.top().S.S;
      pq.pop();
      for(int i=0;i<v[b].size();i++)
      {
         if(c+1==lv[v[b][i].F]&&c+1!=l+1)
         {
            if(node[v[b][i].F][c+1]>co+v[b][i].S)
            {
               node[v[b][i].F][c+1]=co+v[b][i].S;
               pq.push({-node[v[b][i].F][c+1],{v[b][i].F,c+1}});
            }
         }         else
         {
            if(node[v[b][i].F][c]>co+v[b][i].S)
            {
               node[v[b][i].F][c]=co+v[b][i].S;
               pq.push({-node[v[b][i].F][c],{v[b][i].F,c}});
            }
         }
      }
      //printf("%lld %d %d\n",co,b,c);
   }
   printf("%lld",node[ed][l]);
}
