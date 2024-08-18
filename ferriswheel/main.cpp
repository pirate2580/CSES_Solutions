#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int  n, x;
    cin>>n>>x;
    vector<int>weights;
    weights.resize(n);
    for (int i = 0 ; i < n; i++) {
        cin>>weights[i];
    }
    sort(weights.begin(), weights.end());
    int l = 0; int r = n - 1;
    int cnt = 0;
    while (l <= r) {
        if (weights[l] + weights[r] <= x) {
            l++;
            r--;
            cnt++;
        }
        else {
            r--;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
