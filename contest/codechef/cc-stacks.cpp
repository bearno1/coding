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
multiset<int>ss;
multiset<int>::iterator it;
int t,n,x;
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ss.clear();
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&x);
            it=ss.upper_bound(x);
            if(it==ss.end())ss.insert(x);
            else ss.erase(it),ss.insert(x);
        }
        printf("%d ",ss.size());
        for(auto val:ss)
        {
            printf("%d ",val);
        }
        printf("\n");
    }
}
