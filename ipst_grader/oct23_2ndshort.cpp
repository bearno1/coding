#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,m,s,t,a,b,w,N[10005][2],nx,nc;
vector<pair<int,int> >v[10005];
priority_queue<pair<int,int> >pq;
int main()
{
   scanf("%d %d %d %d",&n,&m,&s,&t);
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %d",&a,&b,&w);
      v[a].push_back({b,w});
   }
   for(int i=1;i<=n;i++)N[i][0]=INT_MAX,N[i][1]=INT_MAX;
   N[s][0]=0;
   pq.push({0,s});
   while(!pq.empty())
   {
      a=-pq.top().F;
      b=pq.top().S;
      pq.pop();
      for(int i=0;i<v[b].size();i++)
      {
         nx=v[b][i].F;
         nc=v[b][i].S+a;
         if(N[nx][0]>nc)
         {
            if(N[nx][0]!=INT_MAX)
            {
               N[nx][1]=N[nx][0];
               pq.push({-N[nx][1],nx});
            }
            N[nx][0]=nc;
            pq.push({-N[nx][0],nx});
         }
         else if(N[nx][1]>nc)
         {
            N[nx][1]=nc;
            pq.push({-N[nx][1],nx});
         }
      }
   }
   printf("%d",N[t][1]);
}
