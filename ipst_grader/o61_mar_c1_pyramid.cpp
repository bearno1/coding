#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,fen[100005],a[100005],b[100005],h,pp,sq,ans[100005],pa,pb,cur1,cur2,pi,ta,tb;
priority_queue<pair<pair<int,int>,pair<int,int> > >pq;
vector<pair<int,int> >v[20005];
void up(int pos,int val)
{
   while(pos<100005)
   {
      fen[pos]+=val;
      pos+=pos&(-pos);
   }
   return;
}
int SS(int pos)
{
   int re=0;
   while(pos>0)
   {
      re+=fen[pos];
      pos-=pos&(-pos);
   }
   return re;
}
int main()
{
    scanf("%d",&n);
    sq=122;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&pp,&h);
        a[i]=(pp+5001)-(5000-h);
        b[i]=(pp+5001)+(5000-h);
        v[a[i]].pb({i,b[i]});
        v[b[i]].pb({i,a[i]});
        pq.push({{a[i]/sq,i},{a[i],b[i]}});
    }
    cur1=0;
    cur2=1;
    while(!pq.empty())
    {
        pa=pq.top().S.F;
        pb=pq.top().S.S;
        pi=pq.top().F.S;
        pq.pop();
        if(cur1<pa-1)
        {
           for(int i=cur1+1;i<pa;i++)
           {
               for(int j=0;j<v[i].size();j++)
               {
                   ta=min(i,v[i][j].S);
                   tb=max(i,v[i][j].S);
                   if(ta>cur1&&tb<cur2)up(v[i][j].F,-1);
               }
           }
        }
        if(cur1>pa-1)
        {
           for(int i=cur1;i>pa-1;i--)
           {
               for(int j=0;j<v[i].size();j++)
               {
                   ta=min(i,v[i][j].S);
                   tb=max(i,v[i][j].S);
                   if(ta>=pa&&tb<=pb)up(v[i][j].F,1);
               }
           }
        }
        cur1=pa-1;
        if(cur2<pb+1)
        {
           for(int i=cur2;i<pb+1;i++)
           {
               for(int j=0;j<v[i].size();j++)
               {
                   ta=min(i,v[i][j].S);
                   tb=max(i,v[i][j].S);
                   if(ta>=pa&&tb<=pb)up(v[i][j].F,1);
               }
           }
        }
        if(cur2>pb+1)
        {
           for(int i=cur2-1;i>pb;i--)
           {
               for(int j=0;j<v[i].size();j++)
               {
                   ta=min(i,v[i][j].S);
                   tb=max(i,v[i][j].S);
                   if(ta>cur1&&tb<cur2)up(v[i][j].F,-1);
               }
           }
        }
        cur2=pb+1;
        //printf("{%d %d}\n",cur1,cur2);
        ans[pi]=SS(pi-1);
    }
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
}
