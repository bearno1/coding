#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int t,a,b,n,S,k,num[105],pos[105];
bitset<105>op;
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      op=n-1;
      for(int i=0;i<105;i++)op[i]=false;
      for(int i=1;i<=n;i++)
      {
    	   scanf("%d",&num[i]);
         pos[num[i]]=i;
	   }
	  for(int i=1;i<=n;i++)
	  {
	       if(pos[i]==i)continue;
	  	    for(int j=pos[i]-1;j>=i;j--)
	  	    {
   	  		if(op[j])break;
   	  		op[j]=true;
            if(num[j]<i)continue;
   	  		pos[num[j]]++;
   	  		num[j+1]=num[j];
   	  		pos[i]--;
   	  		num[j]=i;
		    }
	  }
	  for(int i=1;i<=n;i++)
	  {
	  	printf("%d ",num[i]);
	  }
	  printf("\n");
   }
}
