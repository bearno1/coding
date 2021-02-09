#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e8));
using namespace std;
int n,m,val[3005],p[3005],las;
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)scanf("%d",&val[i]),p[i]=1e8;
   for(int i=1;i<=n;i++)
   {
      las=1e8;
      for(int j=i-1;j>0&&j>i-m;j--)
      {
         if(i-m<=0)las=min(las,val[i]+val[j]);
         else las=min(las,p[j]+val[i]);
         p[i]=min(p[i],las);
         p[min(j+m-1,n)]=min(p[min(j+m-1,n)],las);
      }
   }
   printf("%d",p[n]);
}
