#include<bits/stdc++.h>
using namespace std;
int n,t,laz,sw,zz;
long long m;
char c[1000005],tmm;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		laz=0;
		scanf("%d %lld",&n,&m);
		scanf("%s",c+1);
		for(int i=1;i<=n;i++)
		{
			if(c[i]=='1')continue;
			if(m<=0)continue;
			if(laz==i-1)c[laz+1]='0',laz++;
			else if(m>=i-laz)
			{
				c[i]='1';
				c[laz+1]='0';
				laz++;
				m-=(i-laz);
			}
			else
			{
				sw=i;
				while(m--)
				{
					tmm=c[sw];
					c[sw]=c[sw-1];
					c[sw-1]=tmm;
					sw--;
				}
			}
			//printf("----%d %d %d\n",laz,i,m);
		}
		for(int i=1;i<=n;i++)
		{
			printf("%c",c[i]);
		}
		printf("\n");
	}
}
