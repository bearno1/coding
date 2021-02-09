#include<bits/stdc++.h>
#define F first
#define S second
#define L (index*2)
#define R ((index*2)+1)
using namespace std;
int n,k,seq[400005][2],x;
long long ans;
pair<int,int>pp;
void UP(int pos,int val,int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(pos<st||pos>ed)return;
   if(st==ed)
   {
      seq[index][0]=val;
      seq[index][1]=val;
      return;
   }
   UP(pos,val,st,mid,L);
   UP(pos,val,mid+1,ed,R);
   seq[index][0]=min(seq[L][0],seq[R][0]);
   seq[index][1]=max(seq[L][1],seq[R][1]);
   return;
}
pair<int,int> MX(int a,int b,int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(b<st||a>ed)return {INT_MAX,-1};
   if(a<=st&&b>=ed)return {seq[index][0],seq[index][1]};
   pair<int,int>aa,bb;
   aa=MX(a,b,st,mid,L);
   bb=MX(a,b,mid+1,ed,R);
   return {min(aa.F,bb.F),max(aa.S,bb.S)};
}
int main()
{
   scanf("%d %d",&n,&k);
   for(int i=0;i<400005;i++)seq[i][0]=INT_MAX,seq[i][1]=-1;
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&x);
      UP(i,x,1,n,1);
   }
   for(int i=1;i<=n;i++)
   {
      int a=i,b=n,mid,go=i;
      while(a<=b)
      {
         mid=(a+b)/2;
         pp=MX(i,mid,1,n,1);
         //printf("%d %d %d %d %d %d\n",i,mid,pp.F,pp.S,a,b);
         if(pp.S-pp.F<=k)
         {
            go=max(go,mid);
            a=mid+1;
         }
         else
         {
            b=mid-1;
         }
      }
      ans+=(go-i+1);
      //printf("===%d %d\n",go,i);
   }
   printf("%lld",ans);
}
