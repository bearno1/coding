#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,ans=imx;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<1000;i++)
    {
        if((360*i)%n==0)
        {
            ans=min(ans,(360*i)/n);
        }
    }
    printf("%d",ans);
}
