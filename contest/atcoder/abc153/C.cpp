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
int a,b,x;
LL ss;
vector<int>v;
int main()
{
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(all(v));
    for(int i=0;i<a-b;i++)ss+=v[i];
    printf("%lld",ss);
}
