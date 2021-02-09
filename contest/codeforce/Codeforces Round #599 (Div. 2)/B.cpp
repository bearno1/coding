#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int t,n,k;
char c1[10005],c2[10005];
vector<int>c[2];
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      k=0;
      c[0].clear();
      c[1].clear();
      scanf("%d",&n);
      scanf("%s",c1);
      scanf("%s",c2);
      for(int i=0;i<n;i++)
      {
         if(c1[i]!=c2[i])k++,c[0].push_back(c1[i]),c[1].push_back(c2[i]);
         //printf("%c %c\n",c1[i],c2[i]);
      }
      //printf("%c %c %c %c\n",c[0][0],c[0][1],c[1][0],c[1][1]);
      if(k==0||k==2)
	  {
	  	bool p=true;
	  	if(k==2)
		{
         if(c[0][0]==c[1][1]||c[0][1]==c[1][0])printf("No\n");
         else
         {
            sort(c[0].begin(),c[0].end());
            sort(c[1].begin(),c[1].end());
            if(c[0][0]==c[0][1]&&c[1][0]==c[1][1])printf("Yes\n");
            else printf("No\n");
         }
		}
		else printf("Yes\n");
	  }
      else printf("No\n");
   }
}
