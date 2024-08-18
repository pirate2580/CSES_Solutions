#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     unordered_set<int>used;
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         int num;
//         cin>>num;
//         if (used.find(num) == used.end()) {
//             cnt++;
//             used.insert(num);
//         }
//     }
//     cout<<cnt<<endl;
//     return 0;
// }

int main() {
    int n;
    cin>>n;
    vector<int>nums;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    // for (int i = 0; i < n; i++) {
    //     cout<<nums[i]<<' ';
    // }
    int curr_index = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != nums[curr_index]) {
            curr_index = i;
            cnt++;
        }
    }
    cout<<cnt + 1<<endl;
    return 0;
}
