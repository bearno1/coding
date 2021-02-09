#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define all(x) ((x)).begin(),((x)).end()
#define F first
#define S second
#define pb push_back
#define L (idx*2)
#define R ((idx*2)+1)
#define X 30
typedef long long LL;
int n,m,o,cc[30],l,nw,ll;
LL qs[355],num[355],ansr=1e15;
vector<int>x;
LL dp[355][355][X],ans,an[30];
pair<int,int>ba[355][355][X];
vector<pair<int,pair<int,int> > >re;
vector<LL>tr;
bool ck=true;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&o),x.pb(o);
    sort(all(x));
    for(int i=1;i<=n;i++)qs[i]=qs[i-1]+x[i-1],num[i]=x[i-1];
    for(int i=1;i<=n;i++)if(num[i]!=num[1])ck=false;
    if(ck)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=min(2*m,i);j++)
            {
                an[0]=1e18;
                if(j==1)
                {
                    an[0]=(qs[i]-qs[0])*(i-1);
                    cc[0]=0;
                }
                else
                {
                    for(int k=0;k<i;k++)
                    {
                        if(dp[k][j-1][0]+(qs[i]-qs[k])*(i-k-1)<an[0])an[0]=dp[k][j-1][0]+(qs[i]-qs[k])*(i-k-1),cc[0]=k;
                        else if(dp[k][j-1][0]+(qs[i]-qs[k])*(i-k-1)==an[0])cc[0]=max(cc[0],k);
                    }
                }
                dp[i][j][0]=an[0];
                ba[i][j][0].F=cc[0];
                //printf("%d ",an);
            }
            //printf("\n");
        }
        ans=dp[n][2*m][0];
        //printf("%lld ",ans);
        nw=n;
        for(int i=2*m;i>0;i--)
        {
            l=ba[nw][i][0].F;
            tr.pb(nw-l);
            nw=l;
        }
        sort(all(tr));
        //for(int i=0;i<2*m;i++)printf("%lld ",tr[i]);
        for(int i=0;i<m;i++)
        {
            ans+=(tr[i])*(tr[(2*m)-i-1])*2;
        }
        printf("%lld",ans);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=min(2*m,i);j++)
            {
                re.clear();
                for(int k=0;k<X;k++)an[k]=1e15;
                if(j==1)
                {
                    for(int k=0;k<X;k++)an[k]=(qs[i]-qs[0])*(i-1),cc[k]=0;
                    for(int k=0;k<X;k++)
                    {
                        dp[i][j][k]=an[k];
                        ba[i][j][k]={cc[k],0};
                    }
                }
                else
                {
                    for(int rr=0;rr<X;rr++)
                    for(int k=0;k<i;k++)
                    {
                        re.pb({(dp[k][j-1][rr]+(qs[i]-qs[k])*(i-k-1)),{k,rr}});
                    }
                    sort(all(re));
                    for(int k=0;k<X&&k<re.size();k++)
                    {
                        dp[i][j][k]=re[k].F;
                        ba[i][j][k]={re[k].S.F,re[k].S.S};
                    }
                }
                //printf("%d ",an);
            }
            //printf("\n");
        }
        for(int k=0;k<X;k++)
        {
            tr.clear();
            bool p=false;
            ans=dp[n][2*m][k];
            //printf("%lld ",ans);
            nw=n;
            ll=k;
            for(int i=2*m;i>0;i--)
            {
                l=ba[nw][i][ll].F;
                ll=ba[nw][i][ll].S;
                tr.pb(nw-l);
                if(nw==l)p=true;
                nw=l;
            }
            sort(all(tr));
            //for(int i=0;i<2*m;i++)printf("%lld ",tr[i]);
            for(int i=0;i<m;i++)
            {
                ans+=(tr[i])*(tr[(2*m)-i-1])*2;
            }
            if(!p)ansr=min(ans,ansr);
        }
        printf("%lld",ansr);
    }
}
