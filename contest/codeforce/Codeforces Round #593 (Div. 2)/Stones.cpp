#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int main()
{
   int n,a,b,c;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      int ans=0;
      scanf("%d %d %d",&a,&b,&c);
      ans+=3*(min(c/2,b));
      b-=(min(c/2,b));
      ans+=3*(min(b/2,a));
      printf("%d\n",ans);
   }
}
