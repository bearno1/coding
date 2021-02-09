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
int n,par[100005][20],wi[100005][20],lv[100005],a,b,t,k,m,ri;
void genlv(int N)
{
    if(lv[N]!=-1)return;
    genlv(par[N][0]);
    lv[N]=lv[par[N][0]]+1;
    return;
}
void genlca()
{
    for(int i=1;i<20;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(par[j][i-1]!=-1)
            {
                par[j][i]=par[par[j][i-1]][i-1];
                wi[j][i]=min(wi[j][i-1],wi[par[j][i-1]][i-1]);
            }
        }
    }
    return;
}
int lca(int a,int b)
{
    if(a==b)return 0;
    if(lv[a]<lv[b])swap(a,b);
    int dif=lv[a]-lv[b],re=imx;
    for(int i=0;i<20;i++)
        if((dif>>i)&1)
            re=min(re,wi[a][i]),a=par[a][i];
    if(a==b)return re;
    for(int i=19;i>-1;i--)
    {
        if(par[a][i]!=par[b][i])
        {
            re=min(re,min(wi[a][i],wi[b][i]));
            a=par[a][i];
            b=par[b][i];
        }
    }
    re=min(re,min(wi[a][0],wi[b][0]));
    return re;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<100005;i++)for(int j=0;j<20;j++)par[i][j]=-1,wi[i][j]=imx;
    lv[0]=1;
    for(int i=1;i<n;i++)
    {
        lv[i]=-1;
        scanf("%d %d",&a,&b);
        par[i][0]=a;
        wi[i][0]=b;
    }
    for(int i=0;i<n;i++)
    {
        genlv(i);
    }
    genlca();
    scanf("%d %d %d %d %d",&t,&k,&m,&a,&b);
    printf("%d\n",ri=lca(a,b));
    for(int i=2;i<=t;i++)
    {
        swap(a,b);
        b=(((a*k)+ri)%m)%n;
        //printf("{%d %d}\n",a,b);
        printf("%d\n",ri=lca(a,b));
    }
}
