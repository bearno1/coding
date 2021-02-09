#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define L (idx*2)
#define R ((idx*2)+1)
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,m,val[100005],q,t,a,b,k,ans[100005],rr,con[200005],pp,seq2[800005][6],c;
vector<int>seq[400005][6];
vector<pair<pii,pii> >qr;
vector<pair<int,pii> >qq[100005];
vector<pii>sd[100005];
set<int>reidx;
set<int>::iterator it;
map<int,int>mm;
multiset<int>mmx[200005];
void up_seq(int st,int ed,int idx,int pos,int va)
{
    int mid=(st+ed)/2;
    if(pos<st||pos>ed)return;
    if(st==ed)
    {
        seq[idx][va].pb(pos);
        return;
    }
    seq[idx][va].pb(pos);
    up_seq(st,mid,L,pos,va);
    up_seq(mid+1,ed,R,pos,va);
    return;
}
void debug(int st,int ed,int idx)
{
    int mid=(st+ed)/2;
    printf("=%d %d=\n",st,ed);
    for(int i=1;i<=5;i++)
    {
        printf("(%d) ",i);
        for(int j=0;j<seq[idx][i].size();j++)
        {
            printf("%d ",seq[idx][i][j]);
        }
        printf("\n");
    }
    if(st!=ed)
    {
        debug(st,mid,L);
        debug(mid+1,ed,R);
    }
    return;
}
void up1_seq(int st,int ed,int idx,int l,int r,int tt,int sp)
{
    int mid=(st+ed)/2;
    if(st>r||ed<l)return;
    if(l<=st&&r>=ed)
    {
        //printf("{%d %d}\n",tt,sp);
        for(int i=5;i>sp;i--)
        {
            //printf("(%d)",i);
            for(int j=0;j<seq[idx][i].size();j++)
            {
                //printf("%d ",seq[idx][i][j]);
                if(val[seq[idx][i][j]]>sp)
                {
                    val[seq[idx][i][j]]=sp;
                    seq[idx][sp].pb(seq[idx][i][j]);
                    sd[seq[idx][i][j]].pb({tt,sp});
                }
                else
                {
                    seq[idx][val[seq[idx][i][j]]].pb(seq[idx][i][j]);
                }
            }
            //printf("\n");
            seq[idx][i].clear();
        }
        return;
    }
    up1_seq(st,mid,L,l,r,tt,sp);
    up1_seq(mid+1,ed,R,l,r,tt,sp);
    return;
}
void up2_seq(int st,int ed,int idx,int pos,int tt)
{
    int mid=(st+ed)/2;
    if(pos<st||pos>ed)return;
    if(st==ed)
    {
        for(int i=1;i<=5;i++)
        {
            seq2[idx][i]=((tt-1)*(-i))+con[pos];
        }
        return;
    }
    up2_seq(st,mid,L,pos,tt);
    up2_seq(mid+1,ed,R,pos,tt);
    for(int i=1;i<=5;i++)seq2[idx][i]=max(seq2[L][i],seq2[R][i]);
    return;
}
int mx_seq(int st,int ed,int idx,int l,int r,int ty)
{
    int mid=(st+ed)/2;
    if(r<con[st]||l>con[ed])return -1e9;
    if(l<=con[st]&&r>=con[ed])return seq2[idx][ty];
    return max(mx_seq(st,mid,L,l,r,ty),mx_seq(mid+1,ed,R,l,r,ty));
}
int main()
{
    for(int i=0;i<800005;i++)for(int j=0;j<6;j++)seq2[i][j]=-1e9;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        up_seq(1,n,1,i,val[i]);
        sd[i].pb({1,val[i]});
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d %d %d",&q,&t,&a,&b,&k);
        if(q==2)qr.pb({{t,k},{a+1,b+1}});
        if(q==1)
        {
            qq[a+1].pb({1,{t,k}});
            qq[b+2].pb({0,{t,k}});
            reidx.insert(k);
        }
    }
    it=reidx.begin(),rr=0;
    while(it!=reidx.end())
    {
        rr++;
        mm[*it]=rr;
        con[rr]=*it;
        it++;
    }
    sort(all(qr));
    //debug(1,n,1);
    for(int i=0;i<qr.size();i++)
    {
        up1_seq(1,n,1,qr[i].S.F,qr[i].S.S,qr[i].F.F,qr[i].F.S);
        //printf("[%d]------------------------\n",qr[1][i].F.F);
        //debug(1,n,1);
    }
    for(int i=1;i<=n;i++)
    {
        sd[i].pb({1e8+1,val[i]});
        //printf("[%d %d]",i,val[i]);
        //printf("{%d}",i);
        for(int j=0;j<qq[i].size();j++)
        {
            pp=mm[qq[i][j].S.S];
            if(qq[i][j].F==0)
            {
                //printf("-%d ",con[pp]);
                mmx[pp].erase(mmx[pp].find(qq[i][j].S.F));
                if(mmx[pp].empty())up2_seq(1,rr,1,pp,2e8);
                else up2_seq(1,rr,1,pp,*mmx[pp].begin());
            }
            else
            {
                //printf("+%d ",con[pp]);
                mmx[pp].insert(qq[i][j].S.F);
                up2_seq(1,rr,1,pp,*mmx[pp].begin());
            }
        }
        //printf("\n");
        for(int j=0;j<sd[i].size()-1;j++)
        {
            int ti=sd[i][j+1].F-sd[i][j].F,ss=sd[i][j].S,pl,co;
            pl=ti*ss;
            co=(sd[i][j].F-1)*ss;
            //printf("[%d %d] ",i,j);
            //printf("%d\n",mx_seq(1,rr,1,ans[i],ans[i]+pl,ss));
            if(mx_seq(1,rr,1,ans[i],ans[i]+pl,ss)>=ans[i]-co)
            {
                int op=imx;
                a=ans[i],b=ans[i]+pl;
                while(a<=b)
                {
                    c=(a+b)/2;
                    if(mx_seq(1,rr,1,ans[i],c,ss)<ans[i]-co)a=c+1;
                    else b=c-1,op=min(op,c);
                }
                ans[i]=op;
                break;
            }
            ans[i]+=pl;
        }
        printf("%d\n",ans[i]);
    }
}
/*
10 11
5 5 4 5 5 5 3 5 5 1
2 10 1 3 4
2 20 4 7 4
2 30 0 9 4
2 40 3 8 4
2 50 7 9 2
2 60 0 8 3
2 70 2 4 2
2 90 0 2 1
2 100 2 9 2
2 110 4 9 5
2 120 1 5 4
*/
