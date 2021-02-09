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
int t,n,x;
vector<int>a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        a.clear();
        b.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&x),a.pb(x);
        for(int i=1;i<=n;i++)scanf("%d",&x),b.pb(x);
        sort(all(a));
        sort(all(b));
        for(int i=0;i<n;i++)printf("%d ",a[i]);
        printf("\n");
        for(int i=0;i<n;i++)printf("%d ",b[i]);
        printf("\n");
    }
}
