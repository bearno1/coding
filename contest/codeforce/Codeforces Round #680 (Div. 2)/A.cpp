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
int main()
{
    int t,a[50],b[50],n,x;
    scanf("%d",&t);
    while(t--)
    {
        bool p=true;
        scanf("%d %d",&n,&x);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=n;i>=1;i--)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)if(a[i]+b[i]>x)p=false;
        if(p)printf("Yes\n");
        else printf("No\n");
    }
}
