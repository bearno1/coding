#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define imx INT_MAX
typedef long long LL;
typedef pair<int,int> pii;
int a[1005],b[1005],c[1005],n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=n-1;i>0;i--)
    {
        b[(i-1)/2]+=a[i];
        c[(i-1)/2]+=c[i]+a[i];
    }
    for(int i=1;i<n;i++)
    {
        if((i*2)+1<n)
        {
            printf("%d %d %d\n",a[i],b[i],c[i]);
        }
    }
    printf("%d %d %d\n",a[0],b[0],c[0]);
    printf("%d\n",c[0]+a[0]);
}
