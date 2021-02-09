#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int x[305][305];
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=n;j++)
     {
        if(j%2==1)
        {
           printf("%d ",((j-1)*n)+i);
        }
        else
        {
           printf("%d ",((j*n)-(i-1)));
        }
     }
     printf("\n");
  }
}
