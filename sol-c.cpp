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

ll findprev(ll a)
{ // less than eq to a
    for(ll i=a;;i--)
    {  bool ok=true;
        for(ll j=2;j<=sqrt(i);j++)
        {
            if(i%j==0){ok=false;break; }
        }
        if(ok)return i;
    }
}
ll findnex(ll a)
{
  // greater than eq to a
   for(ll i=a;;i++)
    {  bool ok=true;
        for(ll j=2;j<=sqrt(i);j++)
        {
            if(i%j==0){ok=false;break; }
        }
        if(ok)return i;
    }
}
int main()
{  fast;
 ll tt=0;
  ll t;cin>>t;
   while(t--)
   {  tt++;
       ll z;cin>>z;
        ll ans;
        ll a=sqrt(z);
         ll b=findprev(a);
         ll c=findprev(b-1),d=findnex(a+1);
         //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
         if(b*d<=z)ans=b*d;
         else ans=b*c;


      cout<<"Case #"<<tt<<": "<<ans<<endl;
     //cout<<endl;


   }
    return 0;
}
