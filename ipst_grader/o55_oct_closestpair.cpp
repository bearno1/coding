#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,rr;
long long x,y;
vector<pair<int,int> >pos;
long long dif(int a,int b)
{
   return (((long long)pos[a].F-(long long)pos[b].F)*((long long)pos[a].F-(long long)pos[b].F))+(((long long)pos[a].S-(long long)pos[b].S)*((long long)pos[a].S-(long long)pos[b].S));
}
long long dif2(long long a,long long b)
{
   return (a-b)*(a-b);
}
long long dif3(long long x1,long long x2,long long y1,long long y2)
{
   return ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
}
long long merge(int st,int mid,int ed,long long d)
{
   rr=0;
   vector<pair<int,int> >A;
   vector<pair<int,int> >B;
   for(int i=st;i<=mid;i++)
   {
      if(dif2(pos[i].F,pos[mid].F)<=d)
      {
         A.push_back({pos[i].F,pos[i].S});
      }
   }
   for(int i=mid+1;i<=ed;i++)
   {
      if(dif2(pos[i].F,pos[mid].F)<=d)
      {
         B.push_back({pos[i].F,pos[i].S});
      }
   }
   sort(A.begin(),A.end());
   sort(B.begin(),B.end());
   /*printf("----{%d %d}----\n",st,ed);
   for(int i=0;i<A.size();i++)
   {
      printf("%d %d\n",A[i].F,A[i].S);
   }
   for(int i=0;i<B.size();i++)
   {
      printf("%d %d\n",B[i].F,B[i].S);
   }*/
   if(A.size()==0||B.size()==0)return d;
   for(int i=0;i<A.size();i++)
   {
      if(rr>=B.size())break;
      while(dif2(A[i].F,B[rr].F)>d)
      {
         rr++;
         if(rr>=B.size())break;
      }
      int ck=rr;
      while(dif2(A[i].F,B[rr].F)<=d)
      {
         d=min(d,dif3(A[i].F,B[ck].F,A[i].S,B[ck].S));
         ck++;
         if(ck>=B.size())break;
      }
   }
   return d;
}
long long clos(int st,int ed)
{
   int mid=(st+ed)/2;
   if(ed-st+1<=100)
   {
      long long re=(long long)1e18;
      for(int i=st;i<=ed;i++)
      {
         for(int j=i+1;j<=ed;j++)
         {
            re=min(dif(i,j),re);
         }
      }
      return re;
   }
   else
   {
      long long P;
      P=min(clos(st,mid),clos(mid+1,ed));
      return merge(st,mid,ed,P);
   }
}
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      scanf("%lld %lld",&x,&y);
      pos.push_back({x,y});
   }
   sort(pos.begin(),pos.end());
   printf("%lld",clos(0,n-1));
}
