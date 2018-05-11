#include <bits/stdc++.h>

using namespace std;

string catAndMouse(int x, int y, int z) {
    // Complete this function
    int a_to_mouse = abs(x-z);
    int b_to_mouse = abs(y-z);
    if (a_to_mouse < b_to_mouse)
        return ("Cat A");
    if (a_to_mouse > b_to_mouse)
        return ("Cat B");
    return ("Mouse C");
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        string result = catAndMouse(x, y, z);
        cout << result;
        cout << endl;


    }
    return 0;
}

