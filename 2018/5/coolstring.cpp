#include <bits/stdc++.h>
using namespace std;

string coolstring(int n) {

    if (n == 1) return "1";
    string str = "11";

    int i;

    string tmp;
    for (i = 3; i <= n; i++) {

        tmp = "";
        char current = str[0];
        //cout << "current char = " << current << endl;
        int count = 1;
        str += "A";
        for (int j = 1; j < str.size(); j++) {
            //cout << i << " " << str[j] << " " << j << endl;
            if(current == str[j]) {
                count++;
                //cout << "Yes" << " " << current << " " << count << endl;
            }
            else {
                //cout << "NO";
                tmp += ('0' + count);
                tmp += current;

                current = str[j];
                count = 1;
            }
        }
        //cout << tmp << endl;
        str = tmp;
    }

    return str;
}

int main() {
    cout << coolstring(5);
}