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
int n,m,rr,k,x,sy;
LL ans;
vector<int>nn,mm;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==0&&rr!=0)nn.pb(rr),rr=0;
        if(x==1) rr++;
        if(i==n&&rr!=0)nn.pb(rr),rr=0;
    }
    rr=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        if(x==0&&rr!=0)mm.pb(rr),rr=0;
        if(x==1) rr++;
        if(i==m&&rr!=0)mm.pb(rr),rr=0;
        //printf("(%d)",rr);
    }
    // for(int i=0;i<nn.size();i++)printf("[%d]\n",nn[i]);
    // for(int i=0;i<mm.size();i++)printf("-[%d]\n",mm[i]);
    sort(all(nn));
    sort(all(mm));
    for(int sx=1;sx<=n;sx++)
    {
        if(k%sx==0)sy=k/sx;
        else sy=0;
            if(sx*sy==k)
            {
                for(int i=nn.size()-1;i>-1;i--)
                {
                    if(nn[i]<sx)break;
                    for(int j=mm.size()-1;j>-1;j--)
                    {
                        if(mm[j]<sy)break;
                        LL a=nn[i],b=mm[j];
                        a-=sx,b-=sy;
                        a++;
                        b++;
                        //printf("%lld %lld\n",a,b);
                        ans+=a*b;
                    }
                }
            }
    }
    printf("%lld",ans);
}
