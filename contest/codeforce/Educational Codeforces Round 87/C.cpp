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
#define PI 3.141592654
int t,n,k;
double cc,co,ans,se,ss;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        k*=2;
        co=(double)90/(double)k;
        co=(co*PI)/(double)180;
        co=sin(co);
        ans=(double)2*co;
        ans=(double)1/ans;
        printf("%.8f\n",ans);
    }
}
