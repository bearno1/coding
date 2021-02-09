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
int n,m,t,a[100005],b[100005],c[100005],ans[100005],et,co,cal[100005];
bool p;
vector<int>v1[100005],v2[100005];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        et=0,co=0,p=true;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[i])v1[b[i]].pb(i),co++;
            else v2[b[i]].pb(i);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&c[i]);
        }
        for(int i=m;i>0;i--)
        {
            if(v1[c[i]].size()>cal[c[i]])
            {
                ans[i]=v1[c[i]][cal[c[i]]];
                et=v1[c[i]][cal[c[i]]];
                cal[c[i]]++;
                co--;
            }
            else
            {
                if(et!=0)
                {
                    ans[i]=et;
                }
                else if(v2[c[i]].size()!=0)
                {
                    ans[i]=v2[c[i]][0];
                    et=v2[c[i]][0];
                }
                else
                {
                    p=false;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cal[a[i]]=0;
            v1[a[i]].clear();
            v2[a[i]].clear();
            cal[b[i]]=0;
            v1[b[i]].clear();
            v2[b[i]].clear();
        }
        if(p&&(co<=0))
        {
            printf("YES\n");
            for(int i=1;i<=m;i++)printf("%d ",ans[i]);
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
