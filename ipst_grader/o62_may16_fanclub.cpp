#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define L (idx*2)
#define R (idx*2+1)
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,m,a,b,val[200005],dis[200005][2],u,v,w,num[200005],k,tp,conv[200005];
vector<pii>path[200005];
vector<int>fan;
struct seqment
{
    pii mx1={-1,-1},mx2={-1,-1};
}seq[800100][2];
void update_seq(int st,int ed,int idx,int pos,int val,int ty)
{
    int mid=(st+ed)/2;
    if(st>pos||ed<pos)return;
    if(st==ed)
    {
        seq[idx][ty].mx1.F=val;
        seq[idx][ty].mx1.S=pos;
        return;
    }
    update_seq(st,mid,L,pos,val,ty);
    update_seq(mid+1,ed,R,pos,val,ty);
    if(seq[L][ty].mx1.F>seq[idx][ty].mx1.F)
    {
        seq[idx][ty].mx2=seq[idx][ty].mx1;
        seq[idx][ty].mx1=seq[L][ty].mx1;
    }
    else if(seq[L][ty].mx1.F>seq[idx][ty].mx2.F)
    {
        seq[idx][ty].mx2=seq[L][ty].mx1;
    }
    if(seq[L][ty].mx2.F>seq[idx][ty].mx1.F)
    {
        seq[idx][ty].mx2=seq[L][ty].mx2;
    }
    if(seq[R][ty].mx1.F>seq[idx][ty].mx1.F)
    {
        seq[idx][ty].mx2=seq[idx][ty].mx1;
        seq[idx][ty].mx1=seq[R][ty].mx1;
    }
    else if(seq[R][ty].mx1.F>seq[idx][ty].mx2.F)
    {
        seq[idx][ty].mx2=seq[R][ty].mx1;
    }
    if(seq[R][ty].mx2.F>seq[idx][ty].mx1.F)
    {
        seq[idx][ty].mx2=seq[R][ty].mx2;
    }
    return;
}
pair<pii,pii> mx_seq(int st,int ed,int idx,int l,int r,int ty)
{
    int mid=(st+ed)/2;
    pair<pii,pii>re={{-1,-1},{-1,-1}},tl;
    if(st>r||ed<l)return re;
    if(l<=st&&r>=ed)return {seq[idx][ty].mx1,seq[idx][ty].mx2};
    re=mx_seq(st,mid,L,l,r,ty);
    tl=mx_seq(mid+1,ed,R,l,r,ty);
    if(tl.F.F>re.F.F)
    {
        re.S=re.F;
        re.F=tl.F;
    }
    else if(tl.F.F>re.S.F)
    {
        re.S=tl.F;
    }
    if(tl.S.F>re.S.F)
    {
        re.S=tl.S;
    }
    return re;
}
int dfs(int N,int prev,int di,bool ty)
{
    if(ty)
    {
        if(N==b)
        {
            ++k;
            fan.pb(N);
            conv[N]=k;
            num[k]=N;
            dis[k][0]=di;
            dis[k][1]=di;
            return 1;
        }
        for(int i=0;i<path[N].size();i++)
        {
            if(path[N][i].F!=prev)
            {
                if(dfs(path[N][i].F,N,path[N][i].S,ty)==1)
                {
                    ++k;
                    fan.pb(N);
                    conv[N]=k;
                    num[k]=N;
                    dis[k][0]=di;
                    dis[k][1]=di;
                    return 1;
                }
            }
        }
        return 0;
    }
    else
    {
        int re=0;
        for(int i=0;i<path[N].size();i++)
        {
            if((path[N][i].F!=prev)&&conv[path[N][i].F]==0)
            {
                re=max(re,dfs(path[N][i].F,N,di+path[N][i].S,ty));
            }
        }
        return max(re,di);
    }
}
int main()
{
    pair<pii,pii> p1,p2;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        path[u].pb({v,w});
        path[v].pb({u,w});
    }
    dfs(a,-1,0,true);
    for(int i=0;i<k;i++)
    {
        tp=dfs(fan[i],-1,0,false);
        val[i+1]=tp;
        printf("%d %d\n",num[i+1],tp);
    }
    for(int i=1;i<=k;i++)
    {
        //printf("%d ",dis[i][0]);
        dis[i][0]+=dis[i-1][0];
        dis[k-i+1][1]+=dis[k-i+2][1];
    }
    //printf("\n");
    // for(int i=1;i<=k;i++)
    // {
    //     update_seq(1,200000,1,i,val[i]+dis[i-1][0],0);
    //     update_seq(1,200000,1,i,val[i]+dis[i][1],1);
    //     //printf("[%d %d %d]\n",num[i],val[i]+dis[i-1][0],val[i]+dis[i][1]);
    // }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        a=conv[a];
        b=conv[b];
        if(a>b)swap(a,b);
        int ans=0;
        // p1=mx_seq(1,200000,1,a,b,0);
        // p2=mx_seq(1,200000,1,a,b,1);
        // if(p1.F.S!=p2.F.S)
        // {
        //     //printf("{%d %d}\n",p1.F.S,p2.F.S);
        //     if(p1.F.S>p2.F.S)swap(p1.F.S,p2.F.S);
        //     printf("%d\n",val[p1.F.S]+val[p2.F.S]+dis[p2.F.S-1][0]-dis[p1.F.S-1][0]);
        // }
        // else
        // {
        //     //printf("%d %d %d %d\n",p1.F.S,p2.S.S,p1.S.S,p2.F.S);
        //     if(p1.S.S>p2.F.S)swap(p1.S.S,p2.F.S);
        //     if(p1.F.S>p2.S.S)swap(p1.F.S,p2.S.S);
        //     printf("%d\n",max(val[p1.F.S]+val[p2.S.S]+dis[p2.S.S-1][0]-dis[p1.F.S-1][0],val[p1.S.S]+val[p2.F.S]+dis[p2.F.S-1][0]-dis[p1.S.S-1][0]));
        // }
        for(int i=a;i<b;i++)
        {
            for(int j=a+1;j<=b;j++)
            {
                ans=max(ans,val[i]+val[j]+dis[j-1][0]-dis[i-1][0]);
            }
        }
        printf("%d\n",ans);
    }
}
/*
10 3 1 7
1 2 1
2 3 4
2 5 2
5 4 3
5 6 5
6 7 1
6 8 2
8 9 10
2 10 9
1 7
5 6
1 2
*/
