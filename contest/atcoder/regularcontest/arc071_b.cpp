#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,m;
LL a=-MMX,b=MMX,c=-MMX,d=MMX,x,k;
__int128 cc;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&x),a=max(x,a),b=min(x,b);
    for(int i=1;i<=m;i++)scanf("%d",&x),c=max(x,c),d=min(x,d);
    cc=(a-b)*(c-d);
    cc%=MOD;
    cc*=(n-1);
    cc%=MOD;
    cc*=(m-1);
    cc%=MOD;
    k=cc;
    printf("%d",k);
}
