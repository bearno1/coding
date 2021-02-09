#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MN ((long long)-1e11);
long long ans,cost[25],n,w;
using namespace std;
long long craft(long long wi,int N)
{
   if(wi<=0)return MN;
   if(N==1)
   {
      return wi;
   }
   long long B=(wi*2)+1-cost[N],MB;
   if(B%2==0)
   {
      MB=craft(B/2,N-1)*2;
   }
   else
   {
      MB=craft((B/2)+1,N-1)+craft(B/2,N-1);
   }
   return MB;
}
int main()
{
   scanf("%lld %lld",&n,&w);
   for(int i=2;i<=n;i++)
   {
      scanf("%lld",&cost[i]);
   }
   printf("%lld",max(craft(w,n),(long long)-1));
}
