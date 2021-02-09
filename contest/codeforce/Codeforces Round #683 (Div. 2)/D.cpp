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
char a[5005],b[5005];
int k[5005][5005],al,bl,mx[5005],ans;
bitset<5005>ch[5005];
int main()
{
    scanf("%d %d",&al,&bl);
    scanf("%s",a+1);
    scanf("%s",b+1);
    for(int i=1;i<=al;i++)
    {
        for(int j=1;j<=bl;j++)mx[j]=0;
        for(int j=1;j<=bl;j++)
        {
            if(a[i]==b[j])
            {
                k[i][j]=k[i-1][j-1]+1;
                ch[i-1][j-1]=true;
                for(int l=k[i][j];l>0&&ans<l*2;l--)
                {
                    if(ans<(l*4)-(i+j)+(mx[k[i][j]-l]))
                    {
                        ans=(l*4)-(i+j)+(mx[k[i][j]-l]);
                        printf("%d %d %d =%d %d\n",i,j,ans,l,mx[k[i][j]-l]);
                    }
                }
            }
            else
            {
                k[i][j]=max(k[i][j-1],k[i-1][j]);
            }
            for(int l=0;l<i;l++)
            {
                if(ch[l][j-1])mx[k[l][j-1]]=max(mx[k[l][j-1]],l+j-1);
            }
            //printf("%d ",k[i][j]);
        }
        //printf("\n");
    }
    printf("%d",ans);
}
