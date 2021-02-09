#include<bits/stdc++.h>
#define F first
#define S second
const long long MOD = (long long)(1e9+7);
using namespace std;
int t,k;
long long n,m;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        bool p=false;
        k=0;
        scanf("%lld %lld",&n,&m);

        while(k<=200)
        {
            if(n>=m)
            {
                p=true;
                break;
            }
            n=(n/2)*3;
            k++;
        }
        if(p)printf("YES\n");
        else printf("NO\n");
    }
}
