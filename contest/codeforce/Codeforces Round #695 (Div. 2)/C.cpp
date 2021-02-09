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
int a,b,c,x;
vector<int>val[3];
LL sa,sb,sc,ans=LLONG_MIN;
int main()
{
    scanf("%d %d %d",&a,&b,&c);
    for(int i=1;i<=a;i++)
    {
        scanf("%d",&x);
        sa+=x;
        val[0].pb(x);
    }
    for(int i=1;i<=b;i++)
    {
        scanf("%d",&x);
        sb+=x;
        val[1].pb(x);
    }
    for(int i=1;i<=c;i++)
    {
        scanf("%d",&x);
        sc+=x;
        val[2].pb(x);
    }
    sort(all(val[0]));
    sort(all(val[1]));
    sort(all(val[2]));
    //printf("%lld %lld %lld\n",sa,sb,sc);
    for(int i=0;i<a;i++)
    {
        ans=max(ans,val[0][i]-((-(sa-val[0][i]))+sb-sc));
        ans=max(ans,val[0][i]-((-(sa-val[0][i]))-sb+sc));
    }
    if(b!=1&&c!=1)
    {
        LL k=(((val[1][0]+val[2][0])*2)-sb-sc);
        for(int i=0;i<a;i++)
        {
            ans=max(ans,val[0][i]-((-(sa-val[0][i]))+k));
        }
    }
    for(int i=0;i<b;i++)
    {
        ans=max(ans,val[1][i]-((-(sb-val[1][i]))+sa-sc));
        ans=max(ans,val[1][i]-((-(sb-val[1][i]))-sa+sc));
    }
    if(a!=1&&c!=1)
    {
        LL k=(((val[0][0]+val[2][0])*2)-sa-sc);
        for(int i=0;i<b;i++)
        {
            ans=max(ans,val[1][i]-((-(sb-val[1][i]))+k));
        }
    }
    for(int i=0;i<c;i++)
    {
        ans=max(ans,val[2][i]-((-(sc-val[2][i]))+sb-sa));
        ans=max(ans,val[2][i]-((-(sc-val[2][i]))-sb+sa));
    }
    if(a!=1&&b!=1)
    {
        LL k=(((val[0][0]+val[1][0])*2)-sa-sb);
        for(int i=0;i<c;i++)
        {
            ans=max(ans,val[2][i]-((-(sc-val[2][i])+k)));
        }
    }
    printf("%lld",ans);
}
