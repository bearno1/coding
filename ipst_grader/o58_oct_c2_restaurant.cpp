#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
vector<int>v[405];
priority_queue<pair<int,pair<int,int> > >path;
int n,op,x,ans,boss[405],nn,a,b,c;
int F(int pos)
{
   if(pos==boss[pos])return pos;
   else return boss[pos]=F(boss[pos]);
}
void UN(int p,int q)
{
   boss[F(p)]=F(q);
   return;
}
int main()
{
   scanf("%d %d",&n,&op);
   nn=n-1;
   for(int i=1;i<=n;i++)
   {
      boss[i]=i;
      for(int j=1;j<=n;j++)
      {
         scanf("%d",&x);
         if(i==j)continue;
         path.push({-x,{i,j}});
      }
   }
   while(nn)
   {
      a=-path.top().F;
      b=path.top().S.F;
      c=path.top().S.S;
      path.pop();
      if(F(b)!=F(c))
      {
         v[c].push_back(b);
         v[b].push_back(c);
         nn--;
         UN(c,b);
      }
   }
   //printf("pp");
   for(int i=1;i<=n;i++)
   {
      if(v[i].size()>=3)ans=i;
   }
   if(op==1)
   {
      printf("%d",ans);
   }
   else
   {
      printf("%d\n%d",ans,v[ans].size());
   }
}
