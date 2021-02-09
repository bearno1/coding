#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
LL ans;
bool dd[15];
int ll;
char c[15];
void gen(int lv)
{
    if(lv==ll)
    {
        LL k=0;
        for(int i=1;i<=ll;i++)
        {
            k*=10;
            k+=c[i]-'0';
            if(dd[i])ans+=k,k=0;
        }
        ans+=k;
    }
    else
    {
        for(int i=0;i<=1;i++)
        {
            dd[lv]=i;
            gen(lv+1);
        }
    }
    return;
}
int main()
{
    scanf("%s",c+1);
    ll=strlen(c+1);
    gen(1);
    printf("%lld",ans);
}
