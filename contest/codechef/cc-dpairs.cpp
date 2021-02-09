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
vector<pii>a,b;
int n,m,x;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a.pb({x,i-1});
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        b.pb({x,i-1});
    }
    sort(all(a));
    sort(all(b));
    for(int i=0;i<m;i++)printf("%d %d\n",a[0].S,b[i].S);
    for(int i=1;i<n;i++)printf("%d %d\n",a[i].S,b[m-1].S);
}
