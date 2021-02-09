#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
long long ans;
int val[100005],fen[100005],las=INT_MIN,x,r=0;
vector<pair<int,int> >v;
void up(int pos)
{
   while(pos<100005)
   {
      fen[pos]++;
      pos+=pos&(-pos);
   }
   return;
}
int ss(int pos)
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
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&x);
      v.push_back({x,i});
   }
   sort(v.begin(),v.end());
   for(int i=0;i<n;i++)
   {
      if(las!=v[i].F)
      {
         r++;
         val[v[i].S]=n-r+1;
         las=v[i].F;
      }
      else
      {
         val[v[i].S]=n-r+1;
      }
   }
   for(int i=1;i<=n;i++)
   {
      //printf("==%d\n",val[i]);
      ans+=ss(val[i]-1);
      up(val[i]);
   }
   printf("%lld",ans);
}
/*
5
10
40
30
50
20
*/
