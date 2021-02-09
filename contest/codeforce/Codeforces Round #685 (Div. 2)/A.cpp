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
int t,n,ans;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d",&n);
        ans=0;
        while(n!=1)
        {
            if(n%2!=0||n==2)n--;
            else n=n/(n/2);
            ans++;
        }
        printf("%d\n",ans);
    }
}
