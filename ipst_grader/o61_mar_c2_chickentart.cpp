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
int n,m,k,co[100005],len,ans,st,ed,mid,divv[100005][2],r,ss,ll;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    len=min((n-k+1),m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&co[i]);
    }
    st=0,ed=1e9+5,ans=imx;
    while(st<=ed)
    {
        bool p=false;
        mid=(st+ed)/2;
        r=1,ss=0,ll=0;
        for(int i=1;i<=n;i++)
        {
            if(co[i]>mid)r=1000000;
            ss+=co[i];
            ll++;
            if(ss>mid||ll>m)r++,ss=co[i],ll=1;
            divv[i][0]=r;
        }
        r=1,ss=0,ll=0;
        for(int i=n;i>0;i--)
        {
            if(co[i]>mid)r=1000000;
            ss+=co[i];
            ll++;
            if(ss>mid||ll>m)r++,ss=co[i],ll=1;
            divv[i][1]=r;
        }
        for(int i=0,j=len+1;j<=n+1;i++,j++)
        {
            if(divv[i][0]+divv[j][1]<k)p=true;
        }
        if(p)ed=mid-1,ans=min(ans,mid);
        else st=mid+1;
    }
    printf("%d",ans);
}
