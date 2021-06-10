/*
AUTHOR: Aman Raj
College:IIT JODHPUR
LANG: C++
*/

using namespace std;

typedef     long long ll;
#include <bits/stdc++.h>


//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
#define fast  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
#define all(a) a.begin(),a.end()
//#define mod 998244353


#define mod  1000000007


#define inf 1e18
//#define mod 3
#define flush fflush(stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<ll, ll, hash< ll > > ht;

// find_by_order()  // order_of_key
typedef tree<
    pair<ll,ll>,
    null_type,
    less<pair<ll,ll> >,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;






ll power1(ll a, ll b)//a raised to power b
   {  if(b<=0) return 1; if(b==1) return a;
       ll c=power1(a,b/2);
        c*=c;c%=mod;if(b%2==1) c*=a;c%=mod;
        return c;
   }
   ll mi(ll a,ll m)
   { ll c= power1(a,m-2);

     return c;
   }



 struct less_then_greater {
    template<typename T, typename U>
    bool operator()(T const& lhs, U const& rhs) const {
        if (lhs.first < rhs.first) return true;
        if (rhs.first < lhs.first) return false;
        return lhs.second > rhs.second;
    }
};

 /*std::priority_queue<std::pair<int, int>,
                    std::vector<std::pair<int, int>>,
                    less_then_greater
                    > pq;*/
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<pair<ll,pair<ll,ll> > > vpar;
vector<vector<pair<ll,pair<ll,ll> > > > v;
vector<ll> visited;
vector<vector<pair<ll,ll> > > vq;//query no and weight
vector<ll> vans;
// SEGMENT TREE with N size and balanced
 vector<ll > vseg;

ll siz=2e5+5;
vector<ll> vh(siz);
 ll N;// this is perfect power of two and segment tree starts with 0
 /* void build(ll l,ll r,ll p)// l is 0 and r is N-1 in beginning and p is 0
  {
      if(l==r)
      {
         if(l>=n)vseg[p]={1e7,0};
         else vseg[p]={v[l],v[l]};
         return;
      }
      ll mid=(l+r)/2;
      build(l,mid,2*p+1);build(mid+1,r,2*p+2);
      vseg[p].first=min(vseg[2*p+1].first,vseg[2*p+2].first);

      vseg[p].second=gcd(vseg[2*p+1].second,vseg[2*p+2].second);

  }*/

   ll get(ll l,ll r,ll l1,ll r1,ll p)// l1 and r1 is one which has to be considered
   { //cout<<l<<" "<<r<<endl;
       ll a=1e7;
       if(r1<l||l1>r)return 0;
        if(l1<=l&&r1>=r)return vseg[p];


      ll mid=(l+r)/2;
      ll p1=get(l,mid,l1,r1,2*p+1);
      ll p2=get(mid+1,r,l1,r1,2*p+2);

      return __gcd(p1,p2);

   }
   void update(ll l,ll r,ll l1,ll p)
  { //cout<<p<<"p"<<endl;

        if(l1<l||l1>r)return ;
     if(l==r)
      {
         vseg[p]=vh[l];
          //cout<<p<<" "<<vh[l]<<"update"<<endl;
         return;
      }

ll mid=(l+r)/2;
      update(l,mid,l1,2*p+1);update(mid+1,r,l1,2*p+2);

      ll p1=vseg[2*p+1];
       ll p2=vseg[2*p+2];

       vseg[p]=__gcd(p1,p2);
  }
void dfs(ll a,pair<ll,ll> p)
{
    visited[a]=1;
   for(auto x:vq[a])
   {
       ll i=x.first,w=x.second;
       ll gcd=get(0,N-1,0,w,0);

       vans[i]=gcd;
   }
   for(auto x:v[a])
   {
       if(!visited[x.first])
       {  // put charge corresponding to road limit on segment tree
           ll l=x.second.first,c=x.second.second;
           //cout<<l<<" "<<c<<"hhhh"<<endl;
            vh[l]=c;
           update(0,N-1,l,0);
           dfs(x.first,x.second);
       }
   }
   //cout<<"here"<<endl;
   //cout<<a<<endl;
   //for(auto x:vseg)cout<<x<<" ";cout<<endl;
   vh[p.first]=0;
   update(0,N-1,p.first,0);
   //remove charge corresponding to road limit here
}
ll n;
int main()
{  fast;
 ll tt=0;
  ll t;cin>>t;
   while(t--)
   {  tt++;
      ll q;cin>>n>>q;
     v.resize(n);vpar.resize(n);
        visited.resize(n);
        vq.resize(n);
        vans.resize(q);
       for(ll i=0;i<n-1;i++)
       {
           ll a,b;cin>>a>>b;a--;b--;
            ll l,c;cin>>l>>c;
           v[a].push_back({b,{l,c}});v[b].push_back({a,{l,c}});


       }

   N=1;
    while(N<siz)N*=2;
    vseg.resize(5*N);

      for(ll i=0;i<q;i++)
      {//cout<<i<<endl;
          ll a,w;cin>>a>>w;a--;
         vq[a].push_back({i,w});

      }
      cout<<"Case #"<<tt<<": ";
      dfs(0,{0,0});
      //cout<<vans.size()<<endl;
      for(auto x:vans)cout<<x<<" ";cout<<endl;
     //cout<<endl;
   visited.clear();vpar.clear();v.clear();
vq.clear();vans.clear();
vh.clear();vh.resize(siz);
   }
    return 0;
}
