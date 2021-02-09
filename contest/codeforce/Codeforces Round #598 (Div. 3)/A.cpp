#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int t,a,b,n,S,k;
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d %d %d %d",&a,&b,&n,&S);
      k=S/n;
      S-=min(k,a)*n;
      if(S<=b)printf("YES\n");
      else printf("NO\n");
   }
}
