#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
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
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int dp[100005];

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
int k;

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

int frog(int N, int h[])
{
    if(N == 1)
    {
        return 0;
    }
    if (N <= 0)
    {
        return INT_MAX;
    }




    if(dp[N] != -1)
    {
        return dp[N];
    }
    else
    {



   int x, minval = INT_MAX;
    for (int i = 1; i <= k; ++i)
    {
        if(N > (i))
            x = frog(N - i, h) + abs(h[N - 1] - h[N - 1 - i]);
        else
            x = INT_MAX;


        minval = min(minval, x);

    }

 
        dp[N] = minval;
        return dp[N];
    }





}

void solve()
{
    int N;
    cin >> N >> k;
    int h[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << frog(N, h);

}


signed main()
{

    i_am_horny();

    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }


}
