#include<bits/stdc++.h>
#define F first
#define S second
const long long MOD = (long long)(1e9+7);
using namespace std;
int t,n,m,a,b,d1,d2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&a,&b);
        d1=min(a,b);
        d2=max(a,b);
        for(;d2<=n&&m>0;d2++)
        {
            m--;
        }
        for(;d1>0&&m>0;d1--)
        {
            m--;
        }
        printf("%d\n",abs(d1-d2));
    }
}
