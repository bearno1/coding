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
int n,a[105],b[105],aa,bb,ans,st,ed,mid,oa,ob;
int main()
{
    st=1,ed=1000,ans=imx;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    while(st<=ed)
    {
        mid=(st+ed)/2;
        oa=0,ob=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[i])continue;
            else if(a[i]>b[i])
            {
                oa+=mid;
            }
            else
            {
                ob++;
            }
        }
        if(oa>ob)ans=min(ans,mid),ed=mid-1;
        else st=mid+1;
    }
    if(ans==imx)printf("-1");
    else printf("%d",ans);
}
