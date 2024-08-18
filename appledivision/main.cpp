#include <iostream>
#include<set>
#include<vector>
using namespace std;

int n;
vector<int>nums;
vector<bool>chosen;
long long total;
long long best = 1000000000;

void find_best(int k, long long subsetsum) {
    // cout<<k<<endl;
    if (k == n) {
        best = min(best, abs(total - 2 * subsetsum));
        return;
    }
    find_best(k + 1, subsetsum + nums[k]);
    // cout<<subsetsum + nums[k];
    find_best(k + 1, subsetsum);
}

int main() {
    cin>>n;
    chosen.resize(n);
    for (int i = 0; i < n; i++) {
        int a; cin>>a;
        total += a;
        nums.push_back(a);
    }
    // cout<<"total is: "<<total<<endl;

    find_best(0, 0);
    cout<<best<<endl;
    return 0;
}
