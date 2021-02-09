#include<bits/stdc++.h>
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
char c[200005];
int n,rr;
LL ans;
int main()
{
    scanf("%s",c+1);
    n=strlen(c+1);
    rr=1;
    for(int i=1;i<=n;i++)
    {
        if(c[i]=='W')
        {
            ans+=i-rr;
            rr++;
        }
    }
    printf("%lld",ans);
}
