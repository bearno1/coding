#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
long long n,k,p=-1,sq,ans1,ans2;
bitset<1000005>B;
int main()
{
   scanf("%lld",&n);
   for(long long i=2;i<1000005;i++)
   {
      if(!B[i])
      {
         k=i;
         while(k<1000005)
         {
            B[k]=true;
            k+=i;
         }
         if(i<n)
         {
            if(n%i==0)
            {
               ans1++,ans2=i;
               if(i*i!=n&&__gcd(n/i,i)==1)
               {
                  ans1++;
               }
            }
         }
      }
   }
   if(ans1==0)
   {
      printf("%lld",n);
   }
   else if(ans1==1)
   {
      printf("%lld",ans2);
   }
   else
   {
      printf("1");
   }
}
