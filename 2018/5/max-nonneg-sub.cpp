#include <bits/stdc++.h>
using namespace std;

vector<long> maxset(vector<long> A) {

    long n = A.size();

    long current_sum = 0;
    long max_sum = LONG_MIN;

    long current_start = 0;
    long current_end = 0;

    long max_start = -1;
    long max_end = -1;

    for (long i = 0; i < n; i++) {
        if (A[i] >= 0) {
            current_sum += A[i];
            current_end++;
        }
        else {
            if (current_sum > max_sum) {
                max_sum = current_sum;
                max_start = current_start;
                max_end = current_end;
            }
            else if (current_sum == max_sum) {
                if (current_end - current_start < max_end-max_start) {
                    max_start = current_start;
                    max_end = current_end;
                }
            }

            current_sum = 0;
            if (i+1 >= n) {
                break;
            }
            current_start = i+1;
            current_end = i+1;
        }
    }

    vector<long> B;
    for (long i = max_start; i < max_end; i++) {
        B.push_back(A[i]);
    }
    return B;
}

int main() {
    vector<long> A = {1967513926, 1540383426, -1303455736, -521595368};
    vector<long> B = maxset(A);
    for (vector<long>::iterator b = B.begin(); b != B.end(); b++) {
        cout << *b << " ";
    }
    cout << endl << endl;
}