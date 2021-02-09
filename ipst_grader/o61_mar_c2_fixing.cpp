#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,m,k,num[100005],ans;
priority_queue<int>pq;
int main()
{
   scanf("%d %d %d",&n,&m,&k);
   for(int i=1;i<=m;i++)
   {
      scanf("%d",&num[i]);
      if(i!=1)
      {
         if(num[i]-num[i-1]-1!=0)
         {
            pq.push(-(num[i]-num[i-1]-1));
         }
      }
   }
   k=pq.size()-k+1;
   while(!pq.empty())
   {
      if(k<=0)break;
      ans-=pq.top();
      pq.pop();
      k--;
   }
   printf("%d",ans);
}
