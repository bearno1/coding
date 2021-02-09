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
LL ans,d,dmg,ss,x,mm;
int n;
queue<pair<LL,LL> >q;
vector<pair<LL,LL> >mon;
int main()
{
    scanf("%d %lld %lld",&n,&d,&dmg);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld",&x,&mm);
        mon.PB({x,mm});
    }
    sort(all(mon));
    for(int i=0;i<n;i++)
    {
        if(!q.empty())
        {
            while(q.front().F<mon[i].F)
            {
                ss-=q.front().S;
                q.pop();
                if(q.empty())break;
            }
        }
        if(ss>=mon[i].S)continue;
        else
        {
            LL k=(mon[i].S-ss+dmg-1)/dmg;
            ans+=k;
            ss+=k*dmg;
            q.push({mon[i].F+(d*2),k*dmg});
        }
    }
    printf("%lld",ans);
}
