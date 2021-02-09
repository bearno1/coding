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
int n,k,a[505],b[505],pr[505],mx,pos,x,y,cc,per[505],ans;
bitset<505>uu;
vector<int>mm,tp;
void gen(int lv)
{
    if(lv==n+1)
    {
        int mn=imx,mx=-1,cc=0;
        for(int i=1;i<=k;i++)
        {
            mn=imx,mx=-1;
            for(int j=a[i];j<=b[i];j++)
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
    x=1,y=n;
    for(int i=1;i<=k;i++)scanf("%d %d",&a[i],&b[i]);
    if(n<=10)
    {
        gen(1);
        for(int i=1;i<=n;i++)printf("%d ",pr[i]);
        return 0;
    }
    while(x<=y)
    {
        mx=-1;
        for(int i=1;i<n;i++)
        {
            cc=0;
            tp.clear();
            if(pr[i]!=0&&pr[i+1]!=0)continue;
            for(int j=1;j<=k;j++)
            {
                if(uu[j])continue;
                if(a[j]<=i&&b[j]>i)cc++,tp.pb(j);
            }
            if(mx<=cc)
            {
                mx=cc;
                pos=i;
                mm.clear();
                for(int j=0;j<cc;j++)mm.pb(tp[j]);
            }
        }
        //printf("=%d %d\n",mx,pos);
        if(pr[pos]==0&&pr[pos+1]==0)
        {
            if(pos%2==1)pr[pos]=x,pr[pos+1]=y;
            else pr[pos]=y,pr[pos+1]=x;
            x++;
            y--;
        }
        else if(pr[pos]!=0)
        {
            if(abs(pr[pos]-x)>abs(pr[pos]-y))pr[pos+1]=x,x++;
            else pr[pos+1]=y,y--;
        }
        else
        {
            if(abs(pr[pos+1]-x)>abs(pr[pos+1]-y))pr[pos]=x,x++;
            else pr[pos]=y,y--;
        }
        for(int i=0;i<mm.size();i++)uu[mm[i]]=true;
        //printf("%d %d\n",x,y);
    }
    for(int i=1;i<=n;i++)printf("%d ",pr[i]);
}
