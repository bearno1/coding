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
int t,n,x;
map<int,int>mp;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        bool p=false;
        mp.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            mp[x]++;
            if(mp[x]>1)p=true;
        }
        if(p)printf("YES\n");
        else printf("NO\n");
    }
}
