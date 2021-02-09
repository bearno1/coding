#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
struct node
{
   long long val;
   int st,ed;
   node *l,*r;
};

class Segment_Tree
{
   private:
      node *root=NULL;
      int size=0;
      vector<int> data;
   public:
      Segment_Tree(vector<int> &input):data(input),size(input.size()-1)
      {
         root=build(1,size);
      }

      node* build(int l,int r)
      {
         node *ptr=new node;
         if (l==r)ptr->v=data[v];
         else
         {
            ptr->l=build(l,(l+r)/2);
            ptr->r=build(((l+r)/2)+1,r);
            ptr->v=max(ptr->l->v,ptr->r->v);
         }
         return ptr;
      }

      int query(int x,int y)
      {
         return query(root,1,size,x,y);
      }

      int query(node *ptr,int l,int r,int x,int y)
      {
         if (l>y||r<x)return 0;
         else if (l>=x&&r<=y)return ptr->v;
         else return max(query(ptr->l,l,(l+r)/2,x,y),query(ptr->r,((l+r)/2)+1,r,x,y));
      }
};

using namespace std;
int main()
{
   vector<int> data;

   Segment_Tree st(data);
}
