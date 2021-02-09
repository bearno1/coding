#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int fen[100005],hi[100005],d[100005],n,sn,a,b,c,cur1,cur2;
long long ans;
priority_queue<pair<pair<int,int>,pair<int,int> > >pq;
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
   sn=sqrt(n);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&hi[i]);
   }
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&d[i]);
      if(d[i]==0)continue;
      a=max(1,i-d[i]);
      b=max(i-1,1);
      //printf("(%d %d)\n",a,b);
      pq.push({{a/sn,b},{a,hi[i]}});
      a=min(i+1,n);
      b=min(n,i+d[i]);
      //printf("%d %d\n",a,b);
      pq.push({{a/sn,b},{a,-hi[i]}});
   }
   hi[n+1]=100001;
   hi[0]=100001;
   cur1=0;
   cur2=1;
   while(!pq.empty())
   {
      a=pq.top().S.F;
      b=pq.top().F.S;
      c=pq.top().S.S;
      pq.pop();
      if(cur1<a-1)
      {
         for(int i=cur1+1;i<a;i++)
         {
            up(hi[i],-1);
         }
      }
      if(cur1>a-1)
      {
         for(int i=cur1;i>a-1;i--)
         {
            up(hi[i],1);
         }
      }
      cur1=a-1;
      if(cur2<b+1)
      {
         for(int i=cur2;i<b+1;i++)
         {
            up(hi[i],1);
         }
      }
      if(cur2>b+1)
      {
         for(int i=cur2-1;i>b;i--)
         {
            up(hi[i],-1);
         }
      }
      cur2=b+1;
      if(c!=0)
      {
         if(c>0)
         {
            ans+=SS(100000)-SS(c);
            //printf("---%d\n",SS(100000)-SS(c));
         }
         else
         {
            ans+=SS(-c-1);
            //printf("---%d\n",SS(-c-1));
         }
      }
      //printf("{%d %d %d %d %d %d}\n",a,b,c,cur1,cur2,SS(100000));
   }
   printf("%lld",ans);
}
