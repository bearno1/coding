#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
#define L (index*2)
#define R ((index*2)+1)
const long long MOD ((long long)(1e9+7));
using namespace std;
long long seq[2][4000020][2],L0[1000005],spi[1000005],ans;
pair<long long,long long>k;
int a,b,val,n,l,t;
char c[5];
void UP(int sw,int st,int ed,int index,int pos,int VAL,int nn)
{
   int mid=(st+ed)/2;
   if(pos<st||pos>ed)return;
   if(st==ed)
   {
      seq[sw][index][0]+=VAL;
      seq[sw][index][1]+=nn;
      return;
   }
   UP(sw,st,mid,L,pos,VAL,nn);
   UP(sw,mid+1,ed,R,pos,VAL,nn);
   seq[sw][index][0]=seq[sw][L][0]+seq[sw][R][0];
   seq[sw][index][1]=seq[sw][L][1]+seq[sw][R][1];
   return;
}
pair<long long,long long> SUM(int sw,int st,int ed,int index,int a1,int b1)
{
   int mid=(st+ed)/2;
   if(b1<st||a1>ed)return {0,0};
   if(a1<=st&&b1>=ed)return {seq[sw][index][0],seq[sw][index][1]};
   pair<long long,long long>x,y;
   x=SUM(sw,st,mid,L,a1,b1),y=SUM(sw,mid+1,ed,R,a1,b1);
   return {x.F+y.F,x.S+y.S};
}
int main()
{
   scanf("%d %d %d",&n,&l,&t);
   memset(seq,0,sizeof(seq));
   UP(0,0,l,1,0,0,n);
   for(int i=1;i<=n;i++)
   {
      L0[i]=0;
   }
   while(t--)
   {
      scanf("%s",c);
      if(c[0]=='s')
      {
         scanf("%d %d",&a,&val);
         if(spi[a]==0)
         {
            UP(spi[a],0,l,1,L0[a],-L0[a],-1);
            L0[a]-=val;
            L0[a]+=l;
            L0[a]%=l;
            UP(spi[a],0,l,1,L0[a],L0[a],1);
         }
         else
         {
            UP(spi[a],0,l,1,L0[a],-L0[a],-1);
            L0[a]+=val;
            L0[a]%=l;
            UP(spi[a],0,l,1,L0[a],L0[a],1);
         }
      }
      else if(c[0]=='f')
      {
         scanf("%d",&a);
         UP(spi[a],0,l,1,L0[a],-L0[a],-1);
         spi[a]=(spi[a]+1)%2;
         L0[a]=(l-L0[a])%l;
         UP(spi[a],0,l,1,L0[a],L0[a],1);
      }
      else
      {
         scanf("%d",&val);
         ans=0;
         k=SUM(0,0,l,1,0,l-val);
         ans+=(k.F+(k.S*val));
         k=SUM(0,0,l,1,l-val+1,l);
         if(k.S!=0)ans+=(k.F+(k.S*val))%(k.S*l);
         val=l-val;
         k=SUM(1,0,l,1,0,l-val);
         ans+=(k.F+(k.S*val));
         k=SUM(1,0,l,1,l-val+1,l);
         if(k.S!=0)ans+=(k.F+(k.S*val))%(k.S*l);
         printf("%lld\n",ans);
      }
   }
}
