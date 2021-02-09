#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
int cor[2100000],ans=-1;
int main()
{
   int n,m,k,a,b;
   scanf("%d %d",&n,&m);
   k=pow(2,n);
   for(int i=0;i<2100000;i++)cor[i]=INT_MAX;
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d",&a,&b);
      cor[b]=min(cor[b],i);
      a=b+pow(2,a)-1;
      cor[a+1]=min(cor[a+1],i);
   }
   for(int i=0;i<=k;i++)
   {
      ans=max(ans,cor[i]);
   }
   printf("%d",ans);
}
