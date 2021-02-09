#include<bits/stdc++.h>
#define F first
#define S second
const long long MOD = (long long)(1e9+7);
using namespace std;
int n,m,k,t;
char c[105][105],p[105][105],pp[105],r=0;
int main()
{
    scanf("%d",&t);
    for(int i='a';i<='z';i++)++r,pp[r]=i;
    for(int i='A';i<='Z';i++)++r,pp[r]=i;
    for(int i='0';i<='9';i++)++r,pp[r]=i;
    while(t--)
    {
        int hay=0,ch=1,chi,le,r=0;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",c[i]+1);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(c[i][j]=='R')hay++;
            }
        }
        chi=hay/k;
        le=hay%k;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                for(int j=1;j<=m;j++)
                {
                    if(c[i][j]=='R')r++;
                    if(ch<=le&&r>chi+1)
                    {
                        ch++;
                        r=1;
                    }
                    else if(ch>le&&r>chi)
                    {
                        ch++;
                        r=1;
                    }
                    p[i][j]=pp[ch];
                }
            }
            else
            {
                for(int j=m;j>0;j--)
                {
                    if(c[i][j]=='R')r++;
                    if(ch<=le&&r>chi+1)
                    {
                        ch++;
                        r=1;
                    }
                    else if(ch>le&&r>chi)
                    {
                        ch++;
                        r=1;
                    }
                    p[i][j]=pp[ch];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%c",p[i][j]);
            }
            printf("\n");
        }
    }
}
