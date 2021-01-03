#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)  scanf("%d",&x)
#define sl(x)  scanf("%lld",&x)
#define ss(s)  scanf("%s",s)
#define pi(x)  printf("%d\n",x)
#define pl(x)  printf("%lld\n",x)
#define ps(s)  printf("%s\n",s)
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
typedef pair<ll, ll>  pl;
typedef vector<int>    vi;
typedef vector<ll>    vl;
typedef vector<pii>    vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());


const int mod = 1'000'000'007;
const int N = 3e5, M = N;
long long arr[101][1000005]; // DP matrix

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

int subset( long long val[], long long sum, long long N)
{
    // base case
    if(N == 0)
    {
        return 0;
    }
    if(sum == 0)
    {
        return 1;
    }


    if(arr[N][sum] != -1)
    {
        return  arr[N][sum];
    }
    else
    {
        int res;
        if(val[N - 1] <= sum)
        {


            res = subset(val, sum - val[N - 1], N - 1) || subset( val, sum, N - 1);
            arr[N][sum] = res;


        }
        else
        {
            res =  subset( val, sum, N - 1);
            arr[N][sum] = res;


        }

        return res;
    }
}

void solve()
{

    long long n, eq = 0 ;
    cin >> n; // number of items
    long long val[n]; // values and wts array
    for (long long i = 0; i < n; i++)
    {
        cin >> val[i];
        eq += val[i];
    }




    if(eq % 2 == 0)
    {
        eq = eq / 2;
        // matrix initialization
        for (long long i = 0; i <= n; i++)
            for (long long j = 0; j <= eq; j++)
                arr[i][j] = -1 ;
        int ans;

        ans = subset( val, eq, n);

        if(ans == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

}


int main()
{

    i_am_horny();

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }


    return 0;
}



