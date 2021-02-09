#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define imx INT_MAX
typedef long long LL;
typedef pair<int,int> pii;
char c[55];
int n,co[205],ans,cc[205];
int main()
{
    scanf("%s",c+1);
    n=strlen(c+1);
    co['H']=1;
    co['N']=14;
    co['O']=16;
    co['C']=12;
    for(int i=1;i<=n;i++)
    {
        if(c[i]<='9'&&c[i]>='0')continue;
        cc[c[i]]++;
        if(c[i+1]<='9'&&c[i+1]>='0')
        {
            ans+=co[c[i]]*(c[i+1]-'0');
        }
        else
        {
            ans+=co[c[i]];
        }
    }
    printf("%d\n",ans);
    if(cc['N']>=1)
    {
        if(cc['O']==0)printf("This compound is amine");
        else printf("This compound is amide");
        return 0;
    }
    if(c[n]=='O')
    {
        printf("This compound is aldehyde");
        return 0;
    }
    for(int i=2;i<n;i++)
    {
        if(c[i]=='O'&&c[i-1]=='C'&&c[i+1]=='C')
        {
            printf("This compound is ketone");
            return 0;
        }
    }
    if(cc['O']==2)
    {
        if(c[n]=='H')printf("This compound is carboxylic acid");
        else printf("This compound is ester");
        return 0;
    }
    if(c[n]=='H')printf("This compound is alcohol");
    else printf("This compound is ether");
}
