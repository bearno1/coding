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
int t,n,cc,pp;
char c[1000],o[1000],nw[1000],ans[1000];
bool p,aa;
int main()
{
    o[0]='a';
    o[1]='b';
    o[2]='a';
    o[3]='c';
    o[4]='a';
    o[5]='b';
    o[6]='a';
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        aa=false;
        pp=0;
        scanf("%d",&n);
        scanf("%s",c+1);
        for(int i=1;i<=n-6;i++)
        {
            cc=0;
            p=true;
            for(int j=i;j<=i+6;j++)
            {
                if(!(c[j]==o[cc]||c[j]=='?'))p=false;
                cc++;
            }
            if(p)
            {
                int op=0;
                for(int j=1;j<=n;j++)nw[j]=c[j];
                for(int j=0;j<7;j++)
                {
                    nw[j+i]=o[j];
                }
                for(int j=1;j<=n;j++)if(nw[j]=='?')nw[j]='x';
                for(int j=1;j<=n-6;j++)
                {
                    cc=0;
                    p=true;
                    for(int l=j;l<=j+6;l++)
                    {
                        if(!(nw[l]==o[cc]))p=false;
                        cc++;
                    }
                    if(p)
                    {
                        op++;
                    }
                }
                if(op<2)
                {
                    aa=true;
                    for(int i=1;i<=n;i++)ans[i]=nw[i];
                }
            }
        }
        if(aa)
        {
            printf("YES\n");
            for(int i=1;i<=n;i++)printf("%c",ans[i]);
            printf("\n");
        }
        else printf("NO\n");
    }
}
