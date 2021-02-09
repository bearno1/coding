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
int n,x,ans,pa[30][2],k;
vector<int>v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        v.pb(x);
    }
    sort(all(v));
    k=v[0];
    for(int i=1;i<n;i++)
    {
        ans=ans xor (k+v[i]);
        k=k xor v[i];
    }
    printf("%d",ans);
}
