#include<bits/stdc++.h>
#include "rescuelib.h"
#define F first
#define S second
using namespace std;
int R,C,d[10],ff,a,b,st,ed,mid,kk=0;
int main()
{
   int R,C;
   get_size(R,C);
   d[1]=drop_robot(1,1);
   d[2]=drop_robot(R,1);
   d[3]=drop_robot(1,C);
   d[4]=drop_robot(R,C);
   for(int i=1;i<=4;i++)
   {
      if(d[i]==-1)ff++;
   }
   if(ff==3)
   {
      if(d[1]!=-1)
      {
         if(d[1]==0)
         {
            answer(1,1);
            return 0;
         }
         st=1,ed=R;
         while(st<=ed)
         {
            mid=(st+ed)/2;
            if(drop_robot(mid,1)!=-1)kk=max(kk,mid),st=mid+1;
            else ed=mid-1;
         }
         d[5]=drop_robot(kk,1);
         R=kk;
         b=(d[1]+d[5]-R+3)/2;
         a=(d[1]-b+2);
         answer(a,b);
      }
      else if(d[2]!=-1)
      {
         if(d[2]==0)
         {
            answer(R,1);
            return 0;
         }
         st=1,ed=R;
         kk=INT_MAX;
         while(st<=ed)
         {
            mid=(st+ed)/2;
            if(drop_robot(mid,1)!=-1)kk=min(kk,mid),ed=mid-1;
            else st=mid+1;
         }
         d[5]=drop_robot(kk,1);
         R=R-kk+1;
         b=(d[2]+d[5]-R+3)/2;
         a=(d[2]-b+2);
         R=R+kk-1;
         a=R-a+1;
         answer(a,b);
      }
      else if(d[3]!=-1)
      {
         if(d[3]==0)
         {
            answer(1,C);
            return 0;
         }
         st=1,ed=R;
         while(st<=ed)
         {
            mid=(st+ed)/2;
            if(drop_robot(mid,C)!=-1)kk=max(kk,mid),st=mid+1;
            else ed=mid-1;
         }
         d[5]=drop_robot(kk,C);
         R=kk;
         b=(d[3]+d[5]-R+3)/2;
         a=(d[3]-b+2);
         b=C-b+1;
         answer(a,b);
      }
      else
      {
         if(d[4]==0)
         {
            answer(R,C);
            return 0;
         }
         st=1,ed=R;
         kk=INT_MAX;
         while(st<=ed)
         {
            mid=(st+ed)/2;
            if(drop_robot(mid,C)!=-1)kk=min(kk,mid),ed=mid-1;
            else st=mid+1;
         }
         d[5]=drop_robot(kk,C);
         R=R-kk+1;
         b=(d[4]+d[5]-R+3)/2;
         a=(d[4]-b+2);
         b=C-b+1;
         R=R+kk-1;
         a=R-a+1;
         answer(a,b);
      }
   }
   else
   {
      if(d[1]!=-1)
      {
         if(d[2]!=-1)
         {
            b=(d[1]+d[2]-R+3)/2;
            a=(d[1]-b+2);
            answer(a,b);
         }
         else
         {
            a=(d[1]+d[3]-C+3)/2;
            b=(d[1]-a+2);
            answer(a,b);
         }
      }
      if(d[4]!=-1)
      {
         if(d[2]!=-1)
         {
            a=(d[2]+d[4]-C+3)/2;
            b=(d[2]-a+2);
            a=R-a+1;
            answer(a,b);
         }
         else
         {
            b=(d[3]+d[4]-R+3)/2;
            a=(d[3]-b+2);
            b=C-b+1;
            answer(a,b);
         }
      }
   }
}
/*
6 6
5 5
2
4 4 4 6
4 4 6 4
*/
