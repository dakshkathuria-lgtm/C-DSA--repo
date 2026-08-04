#include <iostream>
using namespace std;
const int T = 1e5; // 1*10^5

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i += 1) {
        cin >> a[i];
    }
    int q;
    cin >> q;

    int pre[n + 1]{};

    pre[0] = a[0];
    for (int i = 1; i < n; i += 1) {
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 0) {
        cout << pre[r] << endl;
        } else {
        cout << pre[r] - pre[l - 1] << endl;
        }
    }
    return 0;
}