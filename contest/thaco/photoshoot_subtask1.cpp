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
int n,k,p[25][2],per[15],ans,pr[15];
bitset<15>uu;
void gen(int lv)
{
    if(lv==n+1)
    {
        int mn=imx,mx=-1,cc=0;
        for(int i=1;i<=k;i++)
        {
            mn=imx,mx=-1;
            for(int j=p[i][0];j<=p[i][1];j++)
            {
                mn=min(mn,per[j]);
                mx=max(mx,per[j]);
            }
            cc+=(mx-mn);
        }
        if(cc>ans)
        {
            ans=cc;
            for(int i=1;i<=n;i++)pr[i]=per[i];
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(uu[i])continue;
            uu[i]=true;
            per[lv]=i;
            gen(lv+1);
            uu[i]=false;
        }
    }
    return;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d %d",&p[i][0],&p[i][1]);
    }
    gen(1);
    for(int i=1;i<=n;i++)printf("%d ",pr[i]);
}
