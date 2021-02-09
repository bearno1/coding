#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
priority_queue<pair<long long,int> >pq;
vector<pair<int,int> >v[205];
long long node[205];
int pos[205][2],nn,dif,x,y,st,ed,a,b,n,m;
int main()
{
   scanf("%d %d",&n,&m);
   nn=n*2;
   st=((n*2)+1);
   ed=((n*2)+2);
   for(int i=1;i<=n;i++)
   {
      scanf("%d %d %d %d",&pos[i][0],&pos[i][1],&pos[i+n][0],&pos[i+n][1]);
      v[i].push_back({i+n,1});
      v[i+n].push_back({i,1});
   }
   for(int i=1;i<=nn;i++)
   {
      for(int j=1;j<=nn;j++)
      {
         x=abs(pos[i][0]-pos[j][0]);
         y=abs(pos[i][1]-pos[j][1]);
         if((y%2==1&&x%2==0)||(y%2==0&&x%2==1))
         {
            v[i].push_back({j,max(x,y+1)});
            v[j].push_back({i,max(x,y+1)});
         }
         else
         {
            v[i].push_back({j,max(x,y)});
            v[j].push_back({i,max(x,y)});
         }
      }
   }
   for(int i=1;i<=m;i++)
   {
      v[st].clear();
      v[ed].clear();
      scanf("%d %d %d %d",&pos[st][0],&pos[st][1],&pos[ed][0],&pos[ed][1]);
      node[st]=0;
      node[ed]=(long long)1e18;
      x=abs(pos[ed][0]-pos[st][0]);
      y=abs(pos[ed][1]-pos[st][1]);
      if((y%2==1&&x%2==0)||(y%2==0&&x%2==1))
      {
         v[ed].push_back({st,max(x,y+1)});
         v[st].push_back({ed,max(x,y+1)});
      }
      else
      {
         v[ed].push_back({st,max(x,y)});
         v[st].push_back({ed,max(x,y)});
      }
      for(int i=1;i<=nn;i++)
      {
         node[i]=(long long)1e18;
         x=abs(pos[i][0]-pos[st][0]);
         y=abs(pos[i][1]-pos[st][1]);
         if((y%2==1&&x%2==0)||(y%2==0&&x%2==1))
         {
            v[i].push_back({st,max(x,y+1)});
            v[st].push_back({i,max(x,y+1)});
         }
         else
         {
            v[i].push_back({st,max(x,y)});
            v[st].push_back({i,max(x,y)});
         }
         x=abs(pos[i][0]-pos[ed][0]);
         y=abs(pos[i][1]-pos[ed][1]);
         if((y%2==1&&x%2==0)||(y%2==0&&x%2==1))
         {
            v[i].push_back({ed,max(x,y+1)});
            v[ed].push_back({i,max(x,y+1)});
         }
         else
         {
            v[i].push_back({ed,max(x,y)});
            v[ed].push_back({i,max(x,y)});
         }
      }
      pq.push({0,st});
      while(!pq.empty())
      {
         a=-pq.top().F;
         b=pq.top().S;
         pq.pop();
         for(int i=0;i<v[b].size();i++)
         {
            if(node[v[b][i].F]>a+v[b][i].S)
            {
               node[v[b][i].F]=a+v[b][i].S;
               pq.push({-node[v[b][i].F],v[b][i].F});
            }
         }
      }
      printf("%lld\n",node[ed]);
      for(int i=1;i<=nn;i++)
      {
         v[i].pop_back();
         v[i].pop_back();
      }
   }
}
