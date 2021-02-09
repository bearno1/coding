#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
long long dif[15][15],N[80005],NN[15][15][15],ans=LLX,a;
int sp[15],n,m,l,lx,b,w,pos[15],c,d;
vector<pair<int,int> >v[80005];
priority_queue<pair<long long,int> >pq;
priority_queue<pair<pair<long long,int>,pair<int,int> > >q;
int main()
{
   scanf("%d %d %d %d",&n,&m,&l,&lx);
   pos[0]=1;
   pos[l+1]=n;
   sp[0]=1;
   for(int i=1;i<=12;i++)sp[i]=sp[i-1]*2;
   for(int i=1;i<=m;i++)
   {
      scanf("%lld %d %d",&a,&b,&w);
      v[a].push_back({b,w});
      //v[b].push_back({a,w});
   }
   for(int i=1;i<=l;i++)
   {
      scanf("%d",&pos[i]);
   }
   for(int i=0;i<=l+1;i++)
   {
      //printf("^_^ %d\n",pos[i]);
      for(int j=0;j<80005;j++)
      {
         N[j]=LLX;
      }
      N[pos[i]]=0;
      pq.push({0,pos[i]});
      while(!pq.empty())
      {
         a=-pq.top().F;
         b=pq.top().S;
         pq.pop();
         //printf("__ %d %d\n",a,b);
         for(int j=0;j<v[b].size();j++)
         {
            if(N[v[b][j].F]>a+v[b][j].S)
            {
               N[v[b][j].F]=a+v[b][j].S;
               pq.push({-N[v[b][j].F],v[b][j].F});
            }
         }
      }
      //printf("{{}}");
      for(int j=0;j<=l+1;j++)
      {
         dif[i][j]=N[pos[j]];
         //printf("%d %d %lld\n",pos[i],pos[j],N[pos[j]]);
      }
   }
   //printf("T_T");
   for(int i=0;i<15;i++)
      for(int j=0;j<15;j++)
         for(int k=0;k<15;k++)
            NN[i][j][k]=LLX;
   NN[0][0][0]=LLX;
   q.push({{0,0},{0,0}});
   while(!q.empty())
   {
      a=-q.top().F.F;
      b=q.top().F.S;
      c=q.top().S.F;
      d=q.top().S.S;
      q.pop();
      if(dif[b][0]!=LLX)
         if(NN[0][c][d]>a+(dif[b][0]/sp[c]))
         {
            NN[0][c][d]=a+(dif[b][0]/sp[c]);
            q.push({{-NN[0][c][d],0},{c,d}});
         }
      if(dif[b][l+1]!=LLX)
         if(NN[l+1][c][d]>a+(dif[b][l+1]/sp[c]))
         {
            NN[l+1][c][d]=a+(dif[b][l+1]/sp[c]);
            ans=min(ans,NN[l+1][c][d]);
            q.push({{-NN[l+1][c][d],0},{c,d}});
         }
      for(int i=1;i<=l;i++)
      {
         if(dif[b][i]==LLX)continue;
         if(i!=d&&c<lx)
         {
            if(NN[i][c][d]>a+(dif[b][i]/sp[c]))
            {
               NN[i][c][d]=a+(dif[b][i]/sp[c]);
               q.push({{-NN[i][c][d],i},{c+1,i}});
            }
         }
         else
         {
            if(NN[i][c][d]>a+(dif[b][i]/sp[c]))
            {
               NN[i][c][d]=a+(dif[b][i]/sp[c]);
               q.push({{-NN[i][c][d],i},{c,d}});
            }
         }
      }
   }
   printf("%lld",ans);
}
