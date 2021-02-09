#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
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
int t,n,x,ans;
vector<int>v,v1;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        ans=-1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            v.pb(x);
        }
        sort(all(v));
        for(int i=1;i<=1024;i++)
        {
            v1.clear();
            for(int j=0;j<n;j++)v1.pb(v[j] xor i);
            sort(all(v1));
            bool p=true;
            for(int j=0;j<n;j++)
            {
                if(v[j]!=v1[j])
                {
                    p=false;
                    break;
                }
            }
            if(p)
            {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
}
