#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
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
typedef pair<int, int>    pii;
typedef pair<ll, ll>    pl;
typedef vector<int>        vi;
typedef vector<ll>        vl;
typedef vector<pii>        vpii;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());


const int mod = 1'000'000'007;
const int N = 3e5, M = N;

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


const long long inf = 1e18;

long long arr[101][100003]; // DP matrix


int solve()
{

    ll N, W, maxval = 0 ;
    cin >> N >> W;
    long long val[N], wt[N];
    for (long long i = 0; i < N; i++)
    {
        cin >> wt[i] >> val[i];
        maxval += val[i];
    }
    for(ll i = 0 ; i <= maxval; i++)
    {
        arr[0][i] = inf;
    }
    for(ll i = 0 ; i <= N; i++)
    {
        arr[i][0] = 0;
    }

    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= maxval; j++)
        {
            if(val[i - 1] > j)
            {
                arr[i][j] = arr[i - 1][j];

            }
            else
            {
                arr[i][j] = min(arr[i - 1][j], wt[i - 1] + arr[i - 1][j - val[i - 1]]);

            }

        }
    }

    ll ans;
    for (long long i = 0; i <= maxval; i++)
    {

        if(arr[N][i] <= W)
            ans = i;

    }

    return ans;
}


int main()
{

    i_am_horny();

    int t = 1;
    // cin >> t;
    while(t--)
    {
        cout << solve();
    }

    return 0;
}
















