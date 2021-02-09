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
int n,q,x[1000005],fen[1000005],qr;
int ss(int idx)
{
    int re=0;
    while(idx>0)
    {
        //printf("%d\n",idx);
        re+=fen[idx];
        idx-=(idx)&(-idx);
    }
    return re;
}
void up(int idx,int val)
{
    while(idx<1000005)
    {
        fen[idx]+=val;
        idx+=(idx)&(-idx);
    }
    return;
}
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        up(x[i],1);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&qr);
        if(qr>0)
        {
            up(qr,1);
        }
        else
        {
            qr*=-1;
            int st=1,ed=n,mid,del=n;
            while(st<=ed)
            {
                mid=(st+ed)/2;
                if(ss(mid)>=qr)
                {
                    del=min(del,mid);
                    ed=mid-1;
                }
                else
                {
                    st=mid+1;
                }
            }
            up(del,-1);
        }
    }
    int st=1,ed=n,mid,del=imx;
    while(st<=ed)
    {
        mid=(st+ed)/2;
        if(ss(mid)>=1)
        {
            del=min(del,mid);
            ed=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
    if(del==imx)printf("0");
    else printf("%d",del);
}
