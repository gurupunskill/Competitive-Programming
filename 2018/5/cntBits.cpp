#include<bits/stdc++.h>
using namespace std;

int cntBits(vector<int> &A) {

    int ans = 0;
    int n = A.size();
    for (int i = 0; i < 32; i++) {
        long long count = 0;
        for (int j = 0; j < n; j++) {
            if(A[j] & (1 << i))
                count++;
        }
        ans += (count*((long long)n - count)*2)%1000000007;
        if (ans >= 1000000007) ans -= 1000000007;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> A;
    A.reserve(n);

    int a;
    while(n--) {
        cin >> a;
        A.push_back(a);
    }
    cout << endl << cntBits(A) << endl;
    return 0;
}
