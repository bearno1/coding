#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
#define L (index*2)
#define R ((index*2)+1)
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,m,seq[400005][2],cd[100005],a,b,val,op;
void up(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(a<st||a>ed)return;
   if(st==ed)
   {
      seq[index][0]=cd[a];
      seq[index][1]=cd[a];
      return;
   }
   up(st,mid,L);
   up(mid+1,ed,R);
   seq[index][0]=min(seq[L][0],seq[R][0]);
   seq[index][1]=max(seq[L][1],seq[R][1]);
   return;
}
pair<int,int> MM(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(b<st||a>ed)return {INT_MAX,-1};
   if(a<=st&&b>=ed)return {seq[index][0],seq[index][1]};
   pair<int,int>x,y;
   x=MM(st,mid,L);
   y=MM(mid+1,ed,R);
   return {min(x.F,y.F),max(x.S,y.S)};
}
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<n;i++)cd[i]=i;
   for(int i=0;i<n;i++)a=i,up(0,n-1,1);
   while(m--)
   {
      scanf("%d %d %d",&op,&a,&b);
      if(op==1)
      {
         pair<int,int>p=MM(0,n-1,1);
         if(p.F<a||p.S>b)printf("NO\n");
         else printf("YES\n");
         //printf("%d %d\n",p.F,p.S);
      }
      else
      {
         val=cd[a];
         cd[a]=cd[b];
         cd[b]=val;
         up(0,n-1,1);
         a=b;
         up(0,n-1,1);
      }
      //printf("----%d\n",m);
   }
}
/*
5 8
1 0 4
1 1 2
0 1 3
1 2 2
1 1 3
1 0 0
1 0 2
1 2 4
*/
