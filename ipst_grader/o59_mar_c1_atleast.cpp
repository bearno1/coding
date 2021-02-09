#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,m,val[100005],cur1=0,cur2=1,st,ed,mid,a,b,sn,ss,nn,ans,ii,ppp[50005];
long long fen[2000005][2];
double dou;
priority_queue<pair<pair<int,int>,pair<int,pair<double,int> > > >pq;
pair<long long,long long>p;
pair<long long,long long> SS(int pos)
{
   long long re1=0,re2=0;
   while(pos>0)
   {
      re1+=fen[pos][0];
      re2+=fen[pos][1];
      pos-=pos&(-pos);
   }
   return {re1,re2};
}
void up(int pos,int k1,int k2)
{
   while(pos<2000005)
   {
      fen[pos][0]+=k1;
      fen[pos][1]+=k2;
      pos+=pos&(-pos);
   }
   return;
}
int main()
{
   scanf("%d %d",&n,&m);
   sn=(int)sqrt(n);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&val[i]);
   }
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %lf",&a,&b,&dou);
      pq.push({{a/sn,b},{a,{dou,i}}});
   }
   while(!pq.empty())
   {
      a=pq.top().S.F;
      b=pq.top().F.S;
      dou=pq.top().S.S.F;
      ii=pq.top().S.S.S;
      pq.pop();
      if(cur1<a-1)
      {
         for(int i=cur1+1;i<a;i++)
         {
            up(val[i]+1000001,-1,-val[i]);
         }
      }
      if(cur1>a-1)
      {
         for(int i=cur1;i>a-1;i--)
         {
            up(val[i]+1000001,1,val[i]);
         }
      }
      cur1=a-1;
      if(cur2<b+1)
      {
         for(int i=cur2;i<b+1;i++)
         {
            up(val[i]+1000001,1,val[i]);
         }
      }
      if(cur2>b+1)
      {
         for(int i=cur2-1;i>b;i--)
         {
            up(val[i]+1000001,-1,-val[i]);
         }
      }
      cur2=b+1;
      st=1,ed=2000004,ans=INT_MAX;
      //printf("%d %d %.3lf\n",a,b,dou);
      p=SS(2000004);
      //printf("%lld %lld\n",p.F,p.S);
      while(st<=ed)
      {
         mid=(st+ed)/2;
         p=SS(mid);
         //printf("%d %lld %lld\n",mid,p.F,p.S);
         if(p.F==0&&ans==INT_MAX)
         {
            st=mid+1;
            continue;
         }
         else if(p.F==0)break;
         if((double)p.S/(double)p.F>=dou)
         {
            ans=min((long long)ans,b-a+1-p.F);
            ed=mid-1;
         }
         else
         {
            st=mid+1;
         }
      }
      if(ans!=INT_MAX)ppp[ii]=ans;
      else ppp[ii]=-1;
   }
   for(int i=1;i<=m;i++)printf("%d\n",ppp[i]);
}
