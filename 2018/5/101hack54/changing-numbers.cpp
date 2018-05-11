#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long getprimes(long n)
{
    bool prime[n+1];
    long count = 0;
    memset(prime, true, sizeof(prime));
 
    for (long p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (long i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    for (long p=2; p<=n; p++)
       if (prime[p])
          count++;
    
    return count;
}

long getdivprimes(long q, long k) {
    long n = min(q,k);
    bool prime[n+1];
    long count = 0;
    memset(prime, true, sizeof(prime));
 
    for (long p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (long i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    for (long p=2; p<=n; p++)
       if (prime[p] && (q%p == 0))
          count++;
    
    return count;
}

long nCrModpDP(long n, long r, long p)
{
    long C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // Top row of Pascal Triangle
    for (long i = 1; i <= n; i++)
    {
        for (long j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
 
long nCrModp(long n, long r, long p)
{
   if (r==0)
      return 1;
 
   long ni = n%p, ri = r%p;
 
   return (nCrModp(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}

long distinctNumbers(long n, long k) {
    long nprimes = getprimes(n);
    long long sum = 0;
    for (long i = 1; i <= n; i++) {
        long poss = getdivprimes(i, n) + nprimes;
        //cout << poss;
        sum += i*(nCrModp(poss, k, 1000000007)+1);
    }
    return (sum%1000000007);
}

int main()
{
    
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    long n = stoi(nk[0]);

    long k = stoi(nk[1]);

    long result = distinctNumbers(n, k);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
