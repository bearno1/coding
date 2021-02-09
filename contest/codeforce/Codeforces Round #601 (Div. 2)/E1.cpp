#include<bits/stdc++.h>
#define F first
#define S second
const long long MOD = (long long)(1e9+7);
const long long LLX = (long long)(1e18+7);
using namespace std;
int n,val[100005],k;
long long p,ans,qs[100005][2],md,ppc;
bitset<100005>pr;
int main()
{
    scanf("%d",&n);
    ans=0;
    ppc=LLX;
    for(int i=2;i<=100000;i++)
    {
        if(!pr[i])
        {
            int z=i+i;
            while(z<=100000)
            {
                pr[z]=true;
                z+=i;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        if(val[i]==1)k++;
    }
    if(k%2==0)
    {
        int cc=0;
        for(int i=1;i<=n;i++)
        {
            if(val[i]==1)
            {
                cc++;
                if(cc%2==0)
                {
                    ans+=i-p;
                }
                else
                {
                    p=i;
                }
            }
        }
        ppc=min(ppc,ans);
    }
        int cc=0;
        for(int i=3;i<=k;i++)
        {
            if(!pr[i])
            {
                if(k%i==0)
                {
                    ans=0;
                    md=i/2;
                    md++;
                    p=0;
                    for(int j=1;j<=n;j++)
                    {
                        if(val[j]==1)
                        {
                            cc++;
                            if(cc%i==md)
                            {
                                ans+=((md-1)*j)-p;
                                p=j;
                            }
                            else if(cc<md)
                            {
                                p+=j;
                            }
                            else if(cc%i==0)
                            {
                                ans+=j-p;
                                cc=0;
                                p=0;
                            }
                            else if(cc>md)
                            {
                                ans+=j-p;
                            }
                        }
                    }
                    ppc=min(ppc,ans);
                }
            }
        }
    if(ppc==LLX)printf("-1");
    else printf("%lld",ppc);
}
