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
int n,k,x,ck,nn;
LL ans,rr,st,ed,mid,cc;
vector<int>v;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&x),v.pb(x);
    sort(all(v),greater<int>());
    for(int i=0;i<n;i++)
    {
        ans+=rr;
        rr+=v[i];
    }
    st=0,ed=-rr;
    while(st<=ed)
    {
        mid=(st+ed)/2;
        rr=0,cc=0,ck=k,nn=n;
        for(int i=0;i<nn;i++)
        {
            cc+=rr;
            rr+=v[i];
            if(rr<-mid&&ck>0)
            {
                nn--;
                rr=0,ck--;
                i--;
            }
        }
        //printf("%lld %lld\n",mid,cc);
        if(ans<=cc)
        {
            ed=mid-1;
            ans=cc;
        }
        else
        {
            st=mid+1;
        }
    }
    printf("%lld",ans);
}
