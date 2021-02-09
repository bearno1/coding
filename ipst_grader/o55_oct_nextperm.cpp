#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,num[1005],sw[1005],a=-1,b;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&num[i]);
      sw[i]=-100000;
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=i-1;j>0;j--)
      {
         if(num[i]>num[j])
         {
            sw[i]=j;
            break;
         }
      }
   }
   for(int i=1;i<=n;i++)
   {
      if(sw[i]>=a)
      {
         a=sw[i];
         b=i;
      }
   }
   for(int i=1;i<=n;i++)
   {
      if(i==a)
      {
         printf("%d\n",num[b]);
      }
      else if(i==a+1)
      {
         printf("%d\n",num[a]);
      }
      else
      {
         printf("%d\n",num[i+1]);
      }
   }
}
