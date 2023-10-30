#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template<class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key(k) : Number of items strictly smaller than k
// find_by_order(k) : K-th element in aa set(counting from zero)

const int MOD = 1e9 + 7;
// const int MOD = 998244353;

int power(int aa, int n, int m = MOD) {
    int ans = 1LL;
    while(n) {
        if(n&1) ans = 1LL * (ans%m * aa%m)%m;
        aa = (1LL*aa%m * aa%m)%m;
        n >>= 1;
    }
    return ans;
}

const int N = 1e5+1;


bool check(int mid, vector<int>&a, int k) {
    int n = a.size();
    int tot = 1LL*mid*k;
    for(int i=0; i<n; i++) {
        int x = min(a[i],mid);
        tot -= x;
    }
    return (tot <= 0);
}

void solve() {
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    vector<int> st;
    int i=0,j=n-1;
    while(i < j) {
        int num = abs(a[i]-a[j]);
        if(num > 0) st.push_back(num);
        i++,--j;
    }
    int low = 0, high = accumulate(st.begin(), st.end(), 0LL);
    int tt = high;
    high /= k;
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) >> 1;
        if(check(mid, a, k)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    if(1LL*k*ans == tt) {
        cout << "YES" << endl;
        return ;
    }
    if(n&1) --k;
    low = 0, high = accumulate(st.begin(), st.end(), 0LL);
    tt = high;
    high /= k;
    ans = 0;
    while(low <= high) {
        int mid = (low + high) >> 1;
        if(check(mid, a, k)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    if(1LL*k*ans == tt) {
        cout << "YES" << endl;
        return ;
    }
    cout << "NO" << endl;
}


int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(6);
    
    int t = 1;
    cin >> t;
    // for(int i=1; i<=t; i++) {
    //     cout << "Case #" << i << ": ";
    //     solve();
    // }
    while(t--) {
        solve();
    }
    return 0;
}       
