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
typedef pair<int,pii> PQ;
int n,m,k,vis,val,c,cc,co,pos,a,b,w,aa,bb,ans=imx,nna=imx,nnb=imx;
vector<pair<int,int> >v[100005];
vector<int>sp;
priority_queue<PQ,vector<PQ>,greater<PQ> >pq;
vector<pair<int,pair<int,int> > >vc;
struct node
{
    pii a[5];
}N[100005];
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&w);
        v[a].pb({b,w});
        v[b].pb({a,w});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<5;j++)
        {
            N[i].a[j]={imx,-1};
        }
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a);
        sp.pb(a);
        N[a].a[1]={0,a};
        pq.push({0,{a,a}});
    }
    while(!pq.empty())
    {
        a=pq.top().F;
        b=pq.top().S.F;
        c=pq.top().S.S;
        pq.pop();
        for(int i=0;i<v[b].size();i++)
        {
            vis=v[b][i].F;
            val=v[b][i].S;
            cc=0,co=0,pos=10;
            for(int j=1;j<5;j++)
            {
                if(N[vis].a[j].S==c)cc=j,co=N[vis].a[j].F;
                if(N[vis].a[j].F>a+val)pos=min(pos,j);
            }
            if(pos==10)continue;
            if(cc==0)
            {
                for(int j=4;j>pos;j--)
                {
                    N[vis].a[j]=N[vis].a[j-1];
                }
                N[vis].a[pos]={a+val,c};
                pq.push({a+val,{vis,c}});
            }
            else
            {
                if(co<a+val)continue;
                for(int j=cc;j>pos;j--)
                {
                    N[vis].a[j]=N[vis].a[j-1];
                }
                N[vis].a[pos]={a+val,c};
                pq.push({a+val,{vis,c}});
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        // printf("%d ",sp[i]);
        // for(int j=1;j<5;j++)printf("{%d %d} ",N[sp[i]].a[j].F,N[sp[i]].a[j].S);
        // printf("\n");
        for(int ii=1;ii<4;ii++)
        {
            for(int jj=ii+1;jj<5;jj++)
            {
                a=N[sp[i]].a[ii].S;
                b=N[sp[i]].a[jj].S;
                //printf("%d %d\n",a,b);
                if(a>b)swap(a,b);
                if(a==-1||b==-1)continue;
                vc.pb({N[sp[i]].a[ii].F+N[sp[i]].a[jj].F,{a,b}});
            }
        }
    }
    sort(all(vc));
    aa=vc[0].S.F;
    bb=vc[0].S.S;
    //printf("=%d=",vc.size());
    for(int i=0;i<vc.size();i++)
    {
        //printf("=%d %d %d\n",vc[i].F,vc[i].S.F,vc[i].S.S);
        if(aa!=vc[i].S.F&&aa!=vc[i].S.S)nna=min(nna,i);
        if(bb!=vc[i].S.F&&bb!=vc[i].S.S)nnb=min(nnb,i);
        if(aa!=vc[i].S.F&&aa!=vc[i].S.S&&bb!=vc[i].S.F&&bb!=vc[i].S.S)ans=min(ans,vc[0].F+vc[i].F);
    }
    aa=vc[nna].S.F;
    bb=vc[nna].S.S;
    for(int i=0;i<vc.size();i++)
    {
        if(aa!=vc[i].S.F&&aa!=vc[i].S.S&&bb!=vc[i].S.F&&bb!=vc[i].S.S)ans=min(ans,vc[nna].F+vc[i].F);
    }
    aa=vc[nnb].S.F;
    bb=vc[nnb].S.S;
    for(int i=0;i<vc.size();i++)
    {
        if(aa!=vc[i].S.F&&aa!=vc[i].S.S&&bb!=vc[i].S.F&&bb!=vc[i].S.S)ans=min(ans,vc[nnb].F+vc[i].F);
    }
    printf("%d",ans);
}
