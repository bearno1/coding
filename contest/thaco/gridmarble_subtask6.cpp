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
int n,m,a,b,k,qs[2][100005][2];
char c[3][100005];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=1;i<=m;i++)
    {
        if(c[1][i]=='G')a++;
        else b++;
    }
    k=min(a,b);
    a=0,b=0;
    printf("%d\n",k*2);
    for(int i=1;i<=m;i++)
    {
        if(c[1][i]=='G')
        {
            if(a<k)a++,printf("Y ");
            else printf("N ");
        }
        else
        {
            if(b<k)b++,printf("Y ");
            else printf("N ");
        }
        if(i!=m)printf("R");
        printf("\n");
    }
}
