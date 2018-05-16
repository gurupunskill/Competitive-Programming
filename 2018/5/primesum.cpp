// https://www.longerviewbit.com/problems/prime-sum/

#include <bits/stdc++.h>
using namespace std;

// Sieve of sundaram
vector<bool> prime(long n) {
    long n_sieve = (n-2)/2;
    vector<bool> marked (n_sieve+1, true);

    for (long i = 1; i <= n_sieve; i++) {
        for (long j = i; i+j+(2*i*j) <= n_sieve; j++) {
            marked[i+j+(2*i*j)] = false;
        }
    }

    /*vector<long> primes;
    if (n > 2){
        primes.push_back(2);
    }

    for(long i = 1; i <= n_sieve; i++) {
        if(marked[i]) {
            primes.push_back(2*i + 1);
        }
    }*/

    return marked;
}

vector<long> primesum(long n) {
    vector<long> answer;
    answer.reserve(2);

    if (n%2 != 0) {
        answer.push_back(-1);
        answer.push_back(-1);
        return answer;
    }

    if (n == 4) {
        answer.push_back(2);
        answer.push_back(2);
        return answer;        
    }

    vector<bool> primes = prime(n);
    long n_sieve = primes.size();

    long diff = 0;
    long index = 0;
    for(long i = 1; i < n_sieve; i++) {
        if(primes[i]) {
            diff = n - (2*i + 1);
            index = (diff-1)/2;
            if (primes[index]) {
                answer.push_back(2*i + 1);
                answer.push_back(diff);
                break;
            }
        }
    }

    return answer;
    
}

int main() {
    long t;
    cin >> t;
    vector<long> test = primesum(t);
    for (long i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;
    return 0;
}