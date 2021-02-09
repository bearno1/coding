#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int a,b,c,d,pri[1000005],val[1000005],ans1,ans2,ans,ss;
bitset<1000005>BIT;
int main()
{
   scanf("%d %d %d %d",&a,&b,&c,&d);
   for(int i=1;i<=1000005;i++)val[i]=i;
   for(int i=2;i<=1000005;i++)
   {
      if(!BIT[i])
      {
         int c=i;
         while(c<1000005)
         {
            BIT[i]=true;
            while(val[c]%i==0)
            {
               val[c]=val[c]/i;
               pri[c]++;
            }
            c+=i;
         }
      }
   }
   for(int i=2;i<1000005;i++)
   {
      if((b/i)*i>=a&&(d/i)*i>=c)
      {
         if(pri[i]>ans)
         {
            ans=pri[i];
            ss=((b/i)*i)+((d/i)*i);
            ans1=((b/i)*i),ans2=((d/i)*i);
         }
         else if(pri[i]==ans)
         {
            if(ss<((b/i)*i)+((d/i)*i))
            {
               ss=((b/i)*i)+((d/i)*i);
               ans1=((b/i)*i),ans2=((d/i)*i);
            }
         }
      }
   }
   printf("%d %d",ans1,ans2);
}
