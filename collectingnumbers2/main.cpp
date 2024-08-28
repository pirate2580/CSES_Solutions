#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    vector<int>pos(n+1);
    vector<pair<int, int>> operations(m);
    for (int i = 1; i <= n; i++) {
        cin>>nums[i];
        pos[nums[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin>>operations[i].first>>operations[i].second;
    }
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i+1]) {
            cnt++;
        }
    }

    for (int _ = 0; _ < m; _++) {
        int l = operations[_].first; int r = operations[_].second;
        set<pair<int,int>> check;
        if (nums[l] -1 >= 1) {
            check.insert({nums[l]-1, nums[l]});
        }
        if (nums[l] + 1 <= n) {
            check.insert({nums[l], nums[l]+1});
        }
        if (nums[r] - 1 >= 1) {
            check.insert({nums[r]-1, nums[r]});
        }
        if (nums[r] + 1 <= n) {
            check.insert({nums[r], nums[r]+1});
        }

        for (auto idx: check) {
            cnt -= pos[idx.first] > pos[idx.second];
        }

        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;

        pos[nums[l]] = l;
        pos[nums[r]] = r;

        for (auto idx: check) {
            cnt += pos[idx.first] > pos[idx.second];
        }
        cout<<cnt<<endl;
    }

    return 0;
}

