#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start;
    int end;

    Interval(){
        start = 0;
        end = 0;
    }

    Interval(int st, int nd) {
        start = st;
        end = nd;
    }
};

int comparator(Interval A, Interval B) {
    return A.start < B.start;
}

vector<Interval> merge_intervals(vector<Interval> intervals) {

    sort(intervals.begin(), intervals.end(), comparator);

    vector<Interval> S;
    S.reserve(intervals.size());

    S.push_back(*(intervals.begin()));

    vector<Interval>::iterator i = intervals.begin()+1;

    for (;i!=intervals.end(); i++) {
        Interval top = S.back();
        if ((*i).start > top.end) {
            S.push_back(*i);
        }
        else if ((*i).end > top.end) {
            top.end = (*i).end;
            S.pop_back();
            S.push_back(top);
        }
    }

    return S;
}