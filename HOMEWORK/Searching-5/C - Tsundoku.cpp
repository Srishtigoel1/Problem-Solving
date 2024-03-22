#include <iostream>
#include <vector>
using namespace std;

int countBooks(vector<long long>& pb, long long k) {
    int l = 0;
    int h = pb.size() - 1;
    int ans = 0;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (pb[mid] <= k) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    vector<long long> b(m);
    for(int j=0;j<m;j++)
    {
        cin >> b[j];
    }

    vector<long long> pa(n + 1, 0);
    vector<long long> pb(m + 1, 0);


    for (int i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + a[i - 1];
    }

 
    for (int i = 1; i <= m; i++) {
        pb[i] = pb[i - 1] + b[i - 1];
    }

    int mb = 0;
    for (int i = 0; i <= n; i++) {
        long long rc = k - pa[i];
        if (rc < 0) {
            break;
        }
        int bfb = countBooks(pb, rc);
        mb = max(mb, i + bfb);
    }

    cout << mb << endl;

    return 0;
}
