#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
#define L ((idx*2))
#define R ((idx*2)+1)
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int seq[4000005],n,x,h,m,a,b,ans,ans1;
void up(int st,int ed,int idx,int pos,int val)
{
   int mid=(st+ed)/2;
   if(pos<st||pos>ed)return;
   if(st==ed)
   {
      seq[idx]=val;
      return;
   }
   up(st,mid,L,pos,val);
   up(mid+1,ed,R,pos,val);
   seq[idx]=max(seq[L],seq[R]);
   return;
}
int MX(int st,int ed,int idx,int l,int r)
{
   int mid=(st+ed)/2;
   if(r<st||l>ed)return 0;
   if(l<=st&&r>=ed)return seq[idx];
   return max(MX(st,mid,L,l,r),MX(mid+1,ed,R,l,r));
}
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d",&x,&h);
      x++;
      up(1,n,1,x,h);
      ans=0,a=1,b=n;
      int mid;
      while(a<=b)
      {
         mid=(a+b)/2;
         if(MX(1,n,1,min(x+1,n),min(x+mid,n))<=h)
         {
            ans=max(ans,mid);
            a=mid+1;
         }
         else
         {
            b=mid-1;
         }
      }
      ans1=0,a=1,b=n;
      while(a<=b)
      {
         mid=(a+b)/2;
         if(MX(1,n,1,max(1,x-mid),max(x-1,1))<=h)
         {
            ans1=max(ans1,mid);
            a=mid+1;
         }
         else
         {
            b=mid-1;
         }
      }
      printf("%d\n",min(ans,ans1));
   }
}
/*
10 9
3 1
7 3
5 2
5 1
7 5
4 5
2 5
5 5
7 4
*/
