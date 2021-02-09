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
LL ans,n,l,pos[200005],ra,rb,now,da,db;
LL di(int x,int y,int k)
{
    if(k==1)
    {
        if(x<y)return y-x;
        else return l-x+y;
    }
    else
    {
        if(x<y)return l-y+x;
        else return x-y;
    }
}
int main()
{
    scanf("%lld %lld",&l,&n);
    for(int i=1;i<=n;i++)scanf("%lld",&pos[i]);
    ra=1,rb=n;
    for(int i=1;i<=n;i++)
    {
        da=di(now,pos[ra],1);
        db=di(now,pos[rb],2);
        printf("[%lld %lld %lld %lld %lld] ",now,pos[ra],da,pos[rb],db);
        if(da>db)
        {
            now=pos[ra];
            ans+=da;
            ra++;
        }
        else
        {
            now=pos[rb];
            ans+=db;
            rb--;
        }
        printf("%d %lld\n",i,ans);
    }
    printf("%lld",ans);
}
