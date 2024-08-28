#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
    int n, k; cin>>n>>k;
    vector<vector<int>>nums;
    int size = sqrt(n);
    vector<int>tmp;
    for (int i = 1; i <= n; i++) {
        if (tmp.size() < size) {
            tmp.push_back(i);
        }
        else {
            nums.push_back(tmp);
            tmp = {i};
        }
        if (i==n)nums.push_back(tmp);
    }
    // for(int i = 0; i < nums.size(); i++) {for (int j = 0; j < nums[i].size(); j++) {cout<<nums[i][j]<<' ';}cout<<endl;}

    int row = 0, col = 0;

    for (int i = 0; i < n; i++){
        int jump = k % (n - i);
        while (jump > 0) {
            if (col + jump < nums[row].size()) {
                col += jump;
                jump = 0;
            }
            else {
                jump -= (nums[row].size() - col);
                col = 0;
                row ++;
            }
            if (row == nums.size()) {
                row = 0;
            }
        }
        // cout<<row<<' '<<col<<endl<<endl<<endl;;
        while (nums[row].size() <= col) {
            col = 0;
            row++;
            if (row == nums.size()) {
                row = 0;
            }
        }
        cout<<nums[row][col]<<' ';
        if (i != n - 1) {
            nums[row].erase(nums[row].begin() + col);
            while (nums[row].size() <= col) {
                col = 0;
                row++;
                if (row == nums.size())
                    row = 0;
            }
        }

    }
    return 0;
}
