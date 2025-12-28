/* merge sort code for counting inversions */

function<ll(vector<ll>&, ll, ll)> rec = [&](vector<ll>& vec, ll low, ll high) {
    ll cnt = 0;
    ll mid = low + (high - low) / 2;
    ll i = low, j = mid + 1;
    vector<ll> temp;
    while (i <= mid and j <= high) {
        if (vec[i] < vec[j]) {
            temp.push_back(vec[i]);
            i++;
        } else {
            temp.push_back(vec[j]);
            cnt += mid - i + 1;
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(vec[i]);
        i++;
    }
    while (j <= high) {
        temp.push_back(vec[j]);
        j++;
    }
    for (int i = low; i <= high; i++) {
        vec[i] = temp[i - low];
    }
    return cnt;
};

function<ll(vector<ll>&, ll, ll)> f = [&](vector<ll>& vec, ll low, ll high) {
    if (low >= high) return 0ll;
    ll ans = 0, mid = low + (high - low) / 2;
    ans += f(vec, low, mid);
    ans += f(vec, mid + 1, high);
    ans += rec(vec, low, high);
    return ans;
};