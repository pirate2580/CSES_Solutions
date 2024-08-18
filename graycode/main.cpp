#include <iostream>
#include <cmath>
#include<vector>
using namespace std;

vector<string> generate_gray(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> prev_codes = generate_gray(n - 1);
    vector<string> result;

    for (int i = 0; i < prev_codes.size(); i++) {
        result.push_back("0" + prev_codes[i]);
    }

    for (int i = prev_codes.size() - 1; i >= 0; i--) {
        result.push_back("1"+ prev_codes[i]);
    }
    return result;
}



int main() {
    // std::cout << "Hello, World!" << std::endl;
    // cout<<binary(3)<<endl;
    int n;
    cin>>n;
    int total = pow(2, n);

    vector<string> result = generate_gray(n);

    for(auto ans: result) {
        cout<<ans<<endl;
    }


    return 0;
}

