#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,k,ss,ans=INT_MIN,x,val[1000005];
int main()
{
   scanf("%d %d",&n,&k);
   for(int i=1;i<k;i++)
   {
      scanf("%d",&val[i]);
      ss+=val[i];
   }
   for(int i=k;i<=n;i++)
   {
      scanf("%d",&val[i]);
      ss+=val[i];
      ss-=val[i-k];
      ans=max(ans,ss);
   }
   printf("%d",ans);
}
