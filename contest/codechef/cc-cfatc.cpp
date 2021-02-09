#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
#define L ((index*2))
#define R ((index*2)+1)
const long long MOD ((long long)(1e9+7));
int n,m,k,lazy[400005],seq[400005][15],x,op,l,r,temp[15];
bool p=true;
using namespace std;
void OP(int index,int mm)
{
   for(int i=0;i<k;i++)
   {
      temp[i]=seq[index][i];
   }
   for(int i=0;i<k;i++)
   {
      seq[index][(i+mm)%k]=temp[i];
      //printf("===%d\n",temp[i]);
   }
   return;
}
void UP(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(lazy[index]!=0)
   {
      OP(index,lazy[index]);
      if(st!=ed)
      {
         lazy[L]+=lazy[index];
         lazy[R]+=lazy[index];
         lazy[L]%=k;
         lazy[R]%=k;
      }
      lazy[index]=0;
   }
   if(st>r||ed<l)return;
   if(st>=l&&ed<=r)
   {
      if(p)seq[index][x]++;
      else OP(index,x);
      if(st!=ed)
      {
         lazy[L]+=x;
         lazy[R]+=x;
         lazy[L]%=k;
         lazy[R]%=k;
      }
      return;
   }
   UP(st,mid,L);
   UP(mid+1,ed,R);
   for(int i=0;i<k;i++)
   {
      seq[index][i]=seq[L][i]+seq[R][i];
   }
   return;
}
int SS(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(lazy[index]!=0)
   {
      OP(index,lazy[index]);
      if(st!=ed)
      {
         lazy[L]+=lazy[index];
         lazy[R]+=lazy[index];
         lazy[L]%=k;
         lazy[R]%=k;
      }
      lazy[index]=0;
   }
   //printf("<<< %d %d %d\n",st,ed,seq[index][0]);
   if(st>r||ed<l)return 0;
   if(st>=l&&ed<=r)return seq[index][0];
   return SS(st,mid,L)+SS(mid+1,ed,R);
}
int main()
{
   scanf("%d %d %d",&n,&m,&k);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&x);
      x%=k;
      l=i,r=i;
      UP(1,n,1);
   }
   p=false;
   while(m--)
   {
      scanf("%d",&op);
      if(op==1)
      {
         scanf("%d %d %d",&l,&r,&x);
         x%=k;
         UP(1,n,1);
      }
      else
      {
         scanf("%d %d",&l,&r);
         printf("%d\n",SS(1,n,1));
      }
      //printf("----------%d\n",m);
   }
}
