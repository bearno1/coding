#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
#define L (index*2)
#define R ((index*2)+1)
const long long MOD ((long long)(1e9+7));
using namespace std;
int seq[800005][4],val[200005],a,b,n,m,k,uu;
struct rr
{
   int a,b,c,d;
}re,id,ii1[800005],ii2[800005];
void UP(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(st>a||ed<a)return;
   if(st==ed)
   {
      seq[index][0]=uu;
      seq[index][1]=uu;
      seq[index][2]=uu;
      seq[index][3]=uu;
      return;
   }
   UP(st,mid,L);
   UP(mid+1,ed,R);
   seq[index][0]=seq[L][0]+seq[R][0];
   seq[index][1]=max(max(seq[L][1],seq[R][1]),seq[L][3]+seq[R][2]);
   seq[index][2]=max(seq[L][2],seq[L][0]+seq[R][2]);
   seq[index][3]=max(seq[R][3],seq[R][0]+seq[L][3]);
   return;
}
rr SS(int st,int ed,int index)
{
   //printf("++++ %d %d %d\n",st,ed,seq[index][0]);
   int mid=(st+ed)/2;
   if(b<st||a>ed)
   {
      re.a=0;
      re.b=0;
      re.c=0;
      re.d=0;
      //printf("@@ %d %d %d\n",st,ed,re.a);
      return re;
   }
   if(a<=st&&b>=ed)
   {
      re.a=seq[index][0];
      re.b=seq[index][1];
      re.c=seq[index][2];
      re.d=seq[index][3];
      return re;
   }
   ii1[index]=SS(st,mid,L);
   ii2[index]=SS(mid+1,ed,R);
   re.a=ii1[index].a+ii2[index].a;
   re.b=max(max(ii1[index].b,ii2[index].b),ii1[index].d+ii2[index].c);
   re.c=max(ii1[index].c,ii1[index].a+ii2[index].c);
   re.d=max(ii2[index].d,ii2[index].a+ii1[index].d);
   return re;
}
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<n;i++)
   {
      scanf("%d",&val[i]);
      a=i;
      uu=val[i];
      UP(0,n-1,1);
   }
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d",&a,&b);
      id=SS(0,n-1,1);
      printf("%d\n",max(id.b,0));
   }
}
/*
4 1
1 -2 3 -4
2 2
*/
