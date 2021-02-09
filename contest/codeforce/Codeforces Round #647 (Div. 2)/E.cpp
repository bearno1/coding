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
LL k,ans;
int t,n,p,num[1000005][2],x,cc,ss,ls[1000005],tp;
set<int>s;
set<int>::iterator it;
bool di;
LL po(LL a,LL b)
{
    if(b==0)return 1;
    k=po(a,b/2);
    if(b%2==1)
    {
        k=k*k;
        k%=MOD;
        k=k*a;
        k%=MOD;
        return k;
    }
    else
    {
        k=k*k;
        k%=MOD;
        return k;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        di=true;
        ans=0;
        s.clear();
        scanf("%d %d",&n,&p);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            s.insert(x);
            num[x][0]++;
            ls[x]=num[x][0];
        }
        if(p==1)printf("%d\n",n%2);
        else
        {
            it=s.begin();
            while(it!=s.end())
            {
                cc=*it;
                if(num[cc][0]+num[cc][1]>=p)
                {
                    tp=(num[cc][0]+num[cc][1])%p;
                    num[cc+1][1]+=(num[cc][0]+num[cc][1])/p;
                    if(num[cc][0]>=tp)
                    {
                        num[cc][0]=tp;
                        num[cc][1]=0;
                    }
                    else
                    {
                        num[cc][1]=tp-num[cc][0];
                    }
                    s.insert(cc+1);
                }
                it++;
            }
            it--;
            while(1)
            {
                cc=*it;
                ss=num[cc][0]+num[cc][1];
                if(di)
                {
                    if((ss)%2==1)
                    {
                        if(num[cc][1]>0)
                        {
                            num[cc][1]--;
                            if(ls[cc-1]-num[cc-1][0]>=p)
                            {
                                num[cc-1][0]+=p;
                            }
                            else
                            {
                                num[cc-1][1]+=p-(ls[cc-1]-num[cc-1][0]);
                                num[cc-1][0]=ls[cc-1];
                            }
                        }
                        else
                        {
                            di=false;
                            ans=po(p,cc);
                        }
                    }
                }
                else
                {
                    ans-=(po(p,cc)*(LL)ss);
                    ans=(ans+(MOD*(LL)ss))%MOD;
                }
                //printf("[%lld %d]",ans,cc);
                if(it==s.begin())break;
                it--;
            }
            printf("%lld\n",ans);
        }
        while(it!=s.end())
        {
            cc=*it;
            num[cc][0]=0,num[cc][1]=0;
            ls[cc]=0;
            it++;
        }
    }
}
