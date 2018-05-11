#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumTimeToEnd function below.
void minimumTimeToEnd(vector<long> x, long w, long v, int q) {
    // Take the descriptions of the people from standard input and print the answers to standard output
    double trip = *(x.end() - 1)/v;
    while (q--) {
        int ti, ui, pi;
        cin >> pi >> ti >> ui;

        vector<long>::iterator lower = lower_bound(x.begin(), x.end(), pi);
        vector<long>::iterator upper = upper_bound(x.begin(), x.end(), pi);
        
        if (*lower > pi) {
            lower -= 1;
        }
        cout << "Current time ==> " << ti << endl;
        cout << "Lower Bus Stop ==> " << *lower << endl;
        cout << "Upper Bus Stop ==> " << *upper << endl;
        
        double low = abs(*lower - pi);
        double high = abs(*upper - pi);
        
        double toLower = (low/ui);
        double toUpper = (high/ui);

        cout << "Current position of person ==> " << pi << endl;
        cout << "Distance to lower bus stop ==> " << low << endl;
        cout << "Distance to upper bus stop ==> " << high << endl;
        cout << "Time to walk tp lower bus stop ==> " << toLower << endl;
        cout << "Time to walk upper bus stop ==> " << toUpper << endl;
        
        double busLow = *lower/v;
        double busHigh = *upper/v;

        cout << "Bus from 0 to lower bus stop ==> " << busLow << endl;
        cout << "Bus from 0 to upper bus stop ==> " << busHigh << endl;
            
        double reachlow = busLow + (ceil((ti + toLower - busLow)/w))*w;
        double reachhigh = busHigh + (ceil((ti + toUpper - busHigh)/w))*w;

        cout << reachlow << " " << reachhigh << endl;
        
        double waitlow = reachlow + trip - busLow;
        double waithigh = reachhigh + trip - busHigh;

        cout << waitlow << " " << waithigh << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<long> x(n);

    for (int x_itr = 0; x_itr < n; x_itr++) {
        long x_item = stol(x_temp[x_itr]);

        x[x_itr] = x_item;
    }

    string wv_temp;
    getline(cin, wv_temp);

    vector<string> wv = split_string(wv_temp);

    long w = stol(wv[0]);

    long v = stol(wv[1]);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    minimumTimeToEnd(x, w, v, q);

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
