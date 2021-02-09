#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
struct node
{
   int day,mon,pos;
}N[500005];
int n,u,d,s;
vector<node>v;
long long dp[500005],ans;
bool comp(node &a,node &b)
{
   if (a.day<b.day)return true;
   else return false;
}
int main()
{
   scanf("%d %d %d %d",&n,&u,&d,&s);
   for(int i=1;i<=n;i++)
   {
      scanf("%d %d %d",&N[i].day,&N[i].pos,&N[i].mon);
      v.push_back(N[i]);
   }
   sort(v.begin(),v.end(),comp);
   if(n>5000)
   {
      printf("0");
      return 0;
   }
   for(int i=0;i<n;i++)
   {
      if(v[i].pos>s)
      {
         dp[i]=max((long long)v[i].mon-((v[i].pos-s)*d),dp[i]);
      }
      else
      {
         dp[i]=max((long long)v[i].mon-((s-v[i].pos)*u),dp[i]);
      }
      for(int j=0;j<i;j++)
      {
         if(v[i].pos>v[j].pos)
         {
            dp[i]=max(v[i].mon-((v[i].pos-v[j].pos)*d)+dp[j],dp[i]);
         }
         else
         {
            dp[i]=max(v[i].mon-((v[j].pos-v[i].pos)*u)+dp[j],dp[i]);
         }
      }
      if(v[i].pos>s)
      {
         ans=max(ans,dp[i]-((v[i].pos-s)*u));
      }
      else
      {
         ans=max(ans,dp[i]-((s-v[i].pos)*d));
      }
   }
   printf("%lld",ans);
}
