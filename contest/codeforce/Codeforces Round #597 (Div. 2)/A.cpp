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
   int t,a,b;
   scanf("%d",&t);
   for(int i=1;i<=t;i++)
   {
      scanf("%d %d",&a,&b);
      if(__gcd(a,b)==1)printf("Finite\n");
      else printf("Infinite\n");
   }
}
