#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
#define L (index*2)
#define R ((index*2)+1)
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,m,p[3005],ans=INT_MAX,seq[24005],cc;
queue<pair<int,int> >q;
bool ch;
vector<pair<int,int> >v;
void UP(int pos,int val,int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(st>pos||ed<pos)return;
   if(st==ed)
   {
      //printf("----%d %d\n",st,val);
      seq[index]=val;
      return;
   }
   UP(pos,val,st,mid,L);
   UP(pos,val,mid+1,ed,R);
   seq[index]=max(seq[L],seq[R]);
   return;
}
int MX(int a,int b,int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(b<st||a>ed)return 0;
   if(a<=st&&b>=ed)
   {
      //printf("{%d %d %d %d %d}\n",a,b,st,ed,seq[index]);
      return seq[index];
   }
   return max(MX(a,b,st,mid,L),MX(a,b,mid+1,ed,R));
}
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&p[i]);
      v.push_back({p[i],i});
   }
   v.push_back({-1,-1});
   v.push_back({100000000,-1});
   sort(v.begin(),v.end());
   if(m==0)ans=0;
   int st=1,ed=n,mid,k;
   while(st<=ed)
   {
      ch=false;
      while(!q.empty())q.pop();
      mid=(st+ed)/2;
      //printf("++++%d\n",mid);
      for(int i=0;i<24005;i++)
      {
         seq[i]=0;
      }
      //printf("--%d\n",MX(1,n,1,n*2,1));
      for(int i=1;i<=n;i++)
      {
         k=v[i].S;
         //printf("<>%d\n",MX(1,n,1,n*2,1));
         cc=MX(n+k-mid,n+k-1,1,n*2,1);
         //printf("%d %d %d %d\n",n+k-mid,n+k-1,MX(5,5,1,n*2,1),k);
         if(v[i].F!=v[i+1].F)
         {
            while(!q.empty())
            {
               int f=q.front().F,s=q.front().S;
               q.pop();
               UP(f,s,1,n*2,1);
               UP(f+n,s,1,n*2,1);
            }
            UP(k,max(cc+1,1),1,n*2,1);
            UP(k+n,max(cc+1,1),1,n*2,1);
         }
         else
         {
            q.push({k,max(cc+1,1)});
         }
         //printf("%d %d %d\n",cc+1,v[i].F,v[i].S);
         if(cc+1>m)
         {
            ch=true;
            //printf("[]%d\n",i);
            break;
         }
         //printf("(%d)\n",cc+1);
      }
      if(ch)ans=min(ans,mid),ed=mid-1;
      else st=mid+1;
   }
   printf("%d",ans);
}
