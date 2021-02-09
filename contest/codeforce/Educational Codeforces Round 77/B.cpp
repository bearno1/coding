#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin()s,(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int t,n,m,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        b=n;
        n=max(n,m);
        m=min(m,b);
        if(m*2<n)printf("No\n");
        else
        {
            while(n>0&&m>0)
            {
                int dif=abs(n-m);
                if(n==m)
                {
                    if(n%3==0)n=0,m=0;
                    else n=0;
                }
                if(n>m)
                {
                    n-=dif*2;
                    m-=dif;
                }
                else
                {
                    m-=dif*2;
                    n-=dif;
                }
            }
            if(n==0&&m==0)printf("Yes\n");
            else printf("No\n");
        }
    }
}
