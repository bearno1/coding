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
#define R (idx*2)+1
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,a,b,k,t[200005],ss,arr[200005],ans,l[200005],r[200005],nn[200005],lz[800005],seq[800005],seq1[800005],lz1[800005],c,kk;
vector<int>v[200005];
void gen(int N,int pr,int cc)
{
    arr[cc]=t[N];
    for(int i=0;i<v[N].size();i++)
    {
        if(v[N][i]!=pr)
        {
            gen(v[N][i],N,cc+1);
        }
    }
    return;
}
void up_seq(int st,int ed,int idx,int ll,int rr,int val)
{
    int mid=(st+ed)/2;
    if(lz[idx]!=0)
    {
        seq[idx]+=lz[idx];
        if(st!=ed)
        {
            lz[L]+=lz[idx];
            lz[R]+=lz[idx];
        }
        lz[idx]=0;
    }
    if(st>rr||ed<ll)return;
    if(ll<=st&&rr>=ed)
    {
        seq[idx]+=val;
        if(st!=ed)
        {
            lz[L]+=val;
            lz[R]+=val;
        }
        return;
    }
    up_seq(st,mid,L,ll,rr,val);
    up_seq(mid+1,ed,R,ll,rr,val);
    seq[idx]=max(seq[L],seq[R]);
}
int mx_seq(int st,int ed,int idx,int ll,int rr)
{
    int mid=(st+ed)/2;
    if(lz[idx]!=0)
    {
        seq[idx]+=lz[idx];
        if(st!=ed)
        {
            lz[L]+=lz[idx];
            lz[R]+=lz[idx];
        }
        lz[idx]=0;
    }
    if(st>rr||ed<ll)return -1;
    if(ll<=st&&rr>=ed)return seq[idx];
    return max(mx_seq(st,mid,L,ll,rr),mx_seq(mid+1,ed,R,ll,rr));
}
void up_seq1(int st,int ed,int idx,int ll,int rr,int val)
{
    int mid=(st+ed)/2;
    if(lz1[idx]!=0)
    {
        seq1[idx]+=lz1[idx];
        if(st!=ed)
        {
            lz1[L]+=lz1[idx];
            lz1[R]+=lz1[idx];
        }
        lz1[idx]=0;
    }
    if(st>rr||ed<ll)return;
    if(ll<=st&&rr>=ed)
    {
        seq1[idx]+=val;
        if(st!=ed)
        {
            lz1[L]+=val;
            lz1[R]+=val;
        }
        return;
    }
    up_seq1(st,mid,L,ll,rr,val);
    up_seq1(mid+1,ed,R,ll,rr,val);
    seq[idx]=max(seq[L],seq[R]);
}
int mx_seq1(int st,int ed,int idx,int ll,int rr)
{
    int mid=(st+ed)/2;
    if(lz1[idx]!=0)
    {
        seq1[idx]+=lz1[idx];
        if(st!=ed)
        {
            lz1[L]+=lz1[idx];
            lz1[R]+=lz1[idx];
        }
        lz1[idx]=0;
    }
    if(st>rr||ed<ll)return -1;
    if(ll<=st&&rr>=ed)return seq1[idx];
    return max(mx_seq1(st,mid,L,ll,rr),mx_seq1(mid+1,ed,R,ll,rr));
}
int main()
{
    scanf("%d %d",&n,&k);
    ans=k-1;
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t[i]);
        if(v[i].size()==1)ss=i;
    }
    gen(ss,0,1);
    for(int i=1;i<=n;i++)
    {
        nn[arr[i]]++;
        if(nn[arr[i]]==1)
        {
            l[arr[i]]=i;
        }
        r[arr[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        up_seq(1,n,1,i,i,i-1);
    }
    for(int i=1;i<=n;i++)
    {
        if(r[arr[i]]==i)
        {
            //printf("==%d %d\n",l[arr[i]],nn[arr[i]]);
            up_seq(1,n,1,1,l[arr[i]],nn[arr[i]]);
            up_seq1(1,n,1,1,l[arr[i]],1);
        }
        else continue;
        a=1,b=i,kk=0;
        //printf("%d\n",mx_seq(1,n,1,1,i));
        if(mx_seq(1,n,1,1,i)!=i)continue;
        while(a<=b)
        {
            c=(a+b)/2;
            if(mx_seq(1,n,1,c,i)==i)
            {
                kk=max(kk,c);
                a=c+1;
            }
            else
            {
                b=c-1;
            }
        }
        ans=min(ans,mx_seq1(1,n,1,kk,kk)-1);
    }
    printf("%d",ans);
}
