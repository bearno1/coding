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
int n,m,vis,sh[200005],x,y,ans1,ans2,ed,pa,pb;
vector<int>v[200005],vor,bac[200005];
priority_queue<pair<int,int> >pq;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)sh[i]=imx;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        v[y].pb(x);
    }
    scanf("%d",&vis);
    for(int i=1;i<=vis;i++)
    {
        scanf("%d",&x);
        vor.pb(x);
        ed=x;
    }
    sh[x]=0;
    pq.push({0,x});
    while(!pq.empty())
    {
        x=-pq.top().F;
        y=pq.top().S;
        pq.pop();
        for(int i=0;i<v[y].size();i++)
        {
            if(sh[v[y][i]]>x+1)
            {
                bac[v[y][i]].clear();
                bac[v[y][i]].pb(y);
                sh[v[y][i]]=x+1;
                pq.push({-sh[v[y][i]],v[y][i]});
            }
            else if(sh[v[y][i]]==x+1)
            {
                bac[v[y][i]].pb(y);
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     printf("[ %d %d ]\n",i,sh[i]);
    //     for(int j=0;j<bac[i].size();j++)printf("%d ",bac[i][j]);
    //     printf("\n");
    // }
    for(int i=vis-2;i>=0;i--)
    {
        //printf("==%d\n",vor[i]);
        bool eq=false;
        int a=0,b=0;
        for(int j=0;j<bac[vor[i]].size();j++)
        {
            //printf("(%d) ",bac[vor[i]][j]);
            if(bac[vor[i]][j]!=vor[i+1])
            {
                a=1;
                b=1;
            }
            else
            {
                eq=true;
            }
        }
        //printf("\n");
        if(eq)a=0;
        // a=max(a,pa);
        // b=max(b,pb);
        ans1+=a;
        ans2+=b;
        // pa=a,pb=b;
        //printf("{%d %d}\n",ans1,ans2);
    }
    printf("%d %d",ans1,ans2);
}
