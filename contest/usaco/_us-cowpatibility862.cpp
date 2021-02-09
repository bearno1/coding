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
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(99999999769);
const long long MOD2 = (long long)(1e9+7);
const long long MOD1 = (long long)(49698992347);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,x,k;
LL ans;
pair<LL,pair<LL,LL> >a;
vector<int>v[50005];
queue<pair<LL,pair<LL,LL> > >q;
map<pair<LL,pair<LL,LL> >,int>mm;
bool co[7];
void sel(int lv,int ss)
{
    if(lv==5)
    {
        if(ss!=0)return;
        for(int i=1;i<=n;i++)
        {
            LL tp=0,tp1=0,tp2=0;
            for(int j=0;j<5;j++)
            {
                if(co[j])
                {
                    tp*=14071;
                    tp+=v[i][j];
                    tp%=MOD;
                    tp1*=1002577;
                    tp1+=v[i][j];
                    tp1%=MOD1;
                    tp2*=1205609;
                    tp2+=v[i][j];
                    tp2%=MOD2;
                }
            }
            //printf("[%lld]\n",tp);
            if(mm[{tp,{tp1,tp2}}]==0)q.push({tp,{tp1,tp2}});
            mm[{tp,{tp1,tp2}}]++;
        }
    }
    else
    {
        for(int i=0;i<=1;i++)
        {
            if(ss==0&&i==1)continue;
            if(i==1)ss--;
            co[lv]=i;
            sel(lv+1,ss);
            if(i==1)ss++;
        }
    }
    return;
}
int main()
{
    freopen("cowpatibility.in","r",stdin);
    freopen("cowpatibility.out","w",stdout);
    scanf("%d",&n);
    ans=(n*(n-1))/2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        v[i].pb(x);
        scanf("%d",&x);
        v[i].pb(x);
        scanf("%d",&x);
        v[i].pb(x);
        scanf("%d",&x);
        v[i].pb(x);
        scanf("%d",&x);
        v[i].pb(x);
        sort(all(v[i]));
    }
    for(int r=1;r<=5;r++)
    {
        mm.clear();
        sel(0,r);
        while(!q.empty())
        {
            a=q.front();
            q.pop();
            //printf("%lld ",a);
            LL k=mm[a];
            //printf("%lld %lld %d\n",a,(a*(a-1))/2,r%2);
            if(r%2==1)ans-=(k*(k-1))/2;
            else ans+=(k*(k-1))/2;
        }
    }
    printf("%lld",ans);
}
