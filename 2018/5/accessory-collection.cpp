// https://www.hackerrank.com/challenges/accessory-collection/problem
// UNSOLVED

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

string acessoryCollection(long L, long A, long N, long D) {
    /*
        N-D -> number of redundant elements that I can take
        A -> number of available accessories
        L -> number of accessories that can be chosen
    */
    long cost = 0;
    long n_item = ((N-D)/D)+1;
    for (long i = A; i > 0; i--) {
        if (L-n_item >= 0) {
            cost += i*(n_item);
            L -= n_item;
        }
        else {
            cost += i*(L);
            L = 0;
            break;
        }
    }
    if (L > 0) {
        return "SAD";
    }
    else {
        return to_string(cost);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (long T_itr = 0; T_itr < T; T_itr++) {
        string LAND_temp;
        getline(cin, LAND_temp);

        vector<string> LAND = split_string(LAND_temp);

        long L = stoi(LAND[0]);

        long A = stoi(LAND[1]);

        long N = stoi(LAND[2]);

        long D = stoi(LAND[3]);

        string result = acessoryCollection(L, A, N, D);

        fout << result << "\n";
    }

    fout.close();

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
