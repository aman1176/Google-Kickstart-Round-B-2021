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


int main()
{  fast;
 ll tt=0;
  ll t;cin>>t;
   while(t--)
   {  tt++;
      ll n;cin>>n;
      vector<ll> v(n);
      for(auto &x:v)cin>>x;
       ll ans=min(n,3ll);
      vector<ll> dp1(n+5);
      dp1[0]=1;dp1[1]=2;
      for(ll i=2;i<n;i++)
      {
          if(v[i]-v[i-1]==v[i-1]-v[i-2])dp1[i]=dp1[i-1]+1;
          else dp1[i]=2;
      }
      vector<ll> dp2(n+4);
      dp2[n-1]=1;dp2[n-2]=2;
      for(ll i=n-3;i>=0;i--)
      {
          if(v[i]-v[i+1]==v[i+1]-v[i+2])dp2[i]=dp2[i+1]+1;
          else dp2[i]=2;
          //

      }
      for(ll i=0;i<n;i++)
      { ans=max(ans,dp1[i]);ans=max(ans,dp2[i]);
          //change this to meet prev and next
          if(i>0)
          {
              ans=max(ans,dp1[i-1]+1);
              if(i<n-1)
              { ans=max(ans,dp2[i+1]+1);
                 if((v[i+1]-v[i-1])%2==1)continue;;
                 ll d=(v[i+1]-v[i-1])/2;
                 ll prev=1,nex=1;
                 if(i>1&&v[i-1]-v[i-2]==d)prev=dp1[i-1];
                 if(i<n-2&&v[i+2]-v[i+1]==d)nex=dp2[i+1];
                 ans=max(ans,prev+nex+1);
                //if(i==2)cout<<prev<<" "<<nex<<" "<<d;
              }

          }
          else ans=max(ans,dp2[i+1]+1);
          //cout<<i<<" "<<ans<<endl;
      }


      cout<<"Case #"<<tt<<": "<<ans<<endl;
     //cout<<endl;


   }
    return 0;
}
