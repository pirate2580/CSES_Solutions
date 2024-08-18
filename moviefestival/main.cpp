#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int>a, pair<int, int>b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int n; cin>>n;
    vector<pair<int,int>>movies;
    movies.resize(n);
    for (int i = 0; i < n; i++) {
        cin>>movies[i].first>>movies[i].second;
    }
    sort(movies.begin(), movies.end(), cmp);

    // for (int i = 0; i < n; i++) {
    //     cout<<movies[i].first<<' '<<movies[i].second<<endl;
    // }


    int maximum = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (end <= movies[i].first) {
            maximum++;
            end = movies[i].second;
        }
    }
    // while (i < n) {
    //     if (movies[i].second <= movies[j].first) {
    //         maximum++;
    //         j++;
    //     }
    //     i = max(i + 1, j);
    // }
    cout<<maximum<<endl;
    return 0;
}
