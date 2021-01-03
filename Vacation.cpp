#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   prlong longf("%d\n",x)
#define pl(x)   prlong longf("%lld\n",x)
#define ps(s)   prlong longf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<long long, long long>  pii;
typedef pair<ll, ll>    pl;
typedef vector<long long>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
long long dp[10000005][3];
long long a[10000004];
long long b[10000004];
long long c[10000004];
const long long mod = 1'000'000'007;
const long long N = 3e5, M = N;
long long k;

void i_am_horny()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
}

long long taro(long long N, long long h)
{
    if(N == 0)
    {
      return 0;
    }





    if(dp[N][h] != -1)
    {

        return dp[N][h];
    }
   else {
      
        long long g;

        if(h == 3)
        {
            long long x, y, z;
            x = taro(N - 1, 0) + a[N - 1];
            y = taro(N - 1, 1) + b[N - 1];
            z = taro(N - 1, 2) + c[N - 1];
            g = max(x, max(y, z));
            dp[N][h] = g;
  
        }
        else if(h == 0)
        {
            long long x, y, z;
            x = taro(N - 1, 1) + b[N - 1];
            y = taro(N - 1, 2) + c[N - 1];

            g = max(x, y);
            dp[N][h] = g;
        
        }

       else if(h == 1)
        {
            long long x, y;
            x = taro(N - 1, 0) + a[N - 1];
            y = taro(N - 1, 2) + c[N - 1];

            g = max(x, y);
            dp[N][h] = g;
      
        }
        else if(h == 2)
        {
            long long x, y;
            x = taro(N - 1, 0) + a[N - 1];
            y = taro(N - 1, 1) + b[N - 1];

            g = max(x, y);
            dp[N][h] = g;
      
        }

        return g;
    }



}

void solve()
{
    long long N;
    cin >> N;
    long long h = 3;
    // a=0,b=1,c=2,all =3
    for (long long i = 0; i < N; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (long long i = 0; i <= N; i++)
        for (long long j = 0; j <= 3; j++)
            dp[i][j] = -1;



  

    cout << taro(N, h);


}


signed main()
{

    i_am_horny();

    long long t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }

}
