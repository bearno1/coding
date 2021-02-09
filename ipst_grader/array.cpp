#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
#define L (index*2)
#define R ((index*2)+1)
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,t,op,a,b,r=0;
long long seq[1610000],val;
int lazy[1610000],pos[401000];
bitset<1610000>lz;
queue<pair<pair<int,int>,pair<int,int> > >qr;
vector<int>v;
void up(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(lz[index])
   {
      seq[index]=((long long)pos[ed+1]-(long long)pos[st])*(long long)lazy[index];
      lz[index]=false;
      if(st!=ed)
      {
         lz[L]=true;
         lz[R]=true;
         lazy[L]=lazy[index];
         lazy[R]=lazy[index];
      }
   }
   if(b<pos[st]||a>pos[ed+1]-1)return;
   if(a<=pos[st]&&b>=pos[ed+1]-1)
   {
      seq[index]=((long long)pos[ed+1]-(long long)pos[st])*val;
      lz[index]=false;
      if(st!=ed)
      {
         lz[L]=true;
         lz[R]=true;
         lazy[L]=val;
         lazy[R]=val;
      }
      //printf("==%lld %lld %lld %lld %d %d\n",pos[st],pos[ed],seq[index],val,st,ed);
      return;
   }
   up(st,mid,L);
   up(mid+1,ed,R);
   seq[index]=seq[L]+seq[R];
   //printf("==%lld %lld %lld %lld %d %d\n",pos[st],pos[ed],seq[index],val,st,ed);
   return;
}
long long SUM(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(lz[index])
   {
      seq[index]=((long long)pos[ed+1]-(long long)pos[st])*(long long)lazy[index];
      lz[index]=false;
      if(st!=ed)
      {
         lz[L]=true;
         lz[R]=true;
         lazy[L]=lazy[index];
         lazy[R]=lazy[index];
      }
   }
   //printf("++%lld %lld %lld\n",pos[st],pos[ed],seq[index]);
   if(b<pos[st]||a>pos[ed+1]-1)return 0;
   if(a<=pos[st]&&b>=pos[ed+1]-1)return seq[index];
   return SUM(st,mid,L)+SUM(mid+1,ed,R);
}
int main()
{
   scanf("%d %d",&n,&t);
   v.push_back(-1);
   v.push_back(1);
   v.push_back(n);
   v.push_back(n+1);
   while(t--)
   {
      val=0;
      scanf("%d",&op);
      scanf("%d %d",&a,&b);
      a++;
      if(op==0)scanf("%d",&val);
      qr.push({{op,val},{a,b}});
      v.push_back(a);
      v.push_back(b);
      v.push_back(a-1);
      v.push_back(b+1);
   }
   sort(v.begin(),v.end());
   for(int i=1;i<v.size();i++)
   {
      if(v[i]!=v[i-1])
      {
         r++;
         pos[r]=v[i];
         //printf("%lld %d\n",pos[r],r);
      }
   }
   while(!qr.empty())
   {
      op=qr.front().F.F;
      val=qr.front().F.S;
      a=qr.front().S.F;
      b=qr.front().S.S;
      qr.pop();
      if(op==0)
      {
         up(1,r-1,1);
      }
      else
      {
         printf("%lld\n",SUM(1,r-1,1));
      }
   }
}
