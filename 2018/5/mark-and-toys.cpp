// https://www.hackerrank.com/challenges/mark-and-toys/problem
#include <bits/stdc++.h>

using namespace std;

int maximumToys(vector <int> prices, int k) {
    
    /*
        This is basically the knapsack problem.
        Sort prices in ascending order and take them one by one, subtracting their
        price from k until you run out of k.
    */    
   int count = 0;
   sort(prices.begin(), prices.end());
   for (vector<int>::iterator i = prices.begin(); i != prices.end(); i++) {
       if (*i < k){
           k -= *i;
           count++;
       }
       else {
           break;
       }
   }
   return count;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> prices(n);
    for(int prices_i = 0; prices_i < n; prices_i++){
       cin >> prices[prices_i];
    }
    int result = maximumToys(prices, k);
    cout << result << endl;
    return 0;
}
