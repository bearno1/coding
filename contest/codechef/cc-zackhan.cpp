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
int n,m,t,k;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        k=1;
        scanf("%d %d",&n,&m);
        for(int x=1;x<=n&&x<=m;x++)
        {
            if((n%x==0)&&(m%x==0))k=max(k,x);
        }
        printf("%d\n",k);
    }
}
