#include <iostream>
#include <math.h>
#include <set>

using namespace std;

void solve(int n, int source, int auxiliary, int target) {
    /*
     *For n blocks on a source, move n-1 blocks to the auxilary, move bottom block to target, auxilary to target
     *
     */
    if (n == 1) {
        cout<<source<<' '<<target<<endl;
    }
    else {
        solve(n-1, source, target, auxiliary); // move top n-1 blocks from source to auxilary, using target to help
        cout<<source<<' '<<target<<endl;    // move largest block to right
        solve(n-1, auxiliary, source, target);  // move top n-1 blocks from auxiliary to target using source to hlep
    }
}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    cin>>n;
    int moves = pow(2, n) - 1;
    cout<<moves<<endl;
    solve(n, 1, 2, 3);
    return 0;
}


// #include <iostream>
// #include <math.h>
// #include <set>
// using namespace std;
// vector<string> find_path(string left, string middle, string right, vector<string> path, set<string> state) {
//     int n1 = left.size();
//     int n2 = middle.size();
//     int n3 = right.size();
//
//     // Debug output
//     // cout<<left<<"|"<< middle<< "|"<< right<<endl;
//     // for (auto a: state) {
//     //     cout<<a<<' ';
//     // }
//     // cout<<endl<<endl;
//
//     // for(auto a: path) {
//     //     cout<<a<<' ';
//     // }
//     // cout<<endl<<endl;
//
//     if (n1 == 0 && n2 == 0) {
//         cout << "success" << endl;
//         return path;
//     }
//     else if (state.find(left + "|"+middle + "|"+right) != state.end()) {
//         // cout<<"end"<<endl;
//         return {};
//     }
//     else {
//         state.insert(left +"|" + middle + "|"+ right);
//
//         // Check and perform valid moves
//         if (n1 > 0) {
//             char top_left = left[n1 - 1];
//             vector<string> ans;
//             if (n2 == 0 || stoi(string(1, top_left)) < stoi(string(1,middle[n2 - 1]))) {
//                 int prev_size = path.size();
//                 for(auto a: path) {
//                     cout<<a<<' ';
//                 }
//                 cout<<endl;
//                 path.push_back("12");
//                 ans = find_path(left.substr(0, n1 -1), middle + top_left, right, path, state);
//                 if (!ans.empty())return ans;
//                 path.resize(prev_size);
//                 for(auto a: path) {
//                     cout<<a<<' ';
//                 }
//                 cout<<endl;
//             }
//             if (n3 == 0 || stoi(string(1, top_left)) < stoi(string(1, right[n3 - 1]))) {
//                 int prev_size = path.size();
//                 path.push_back("13");
//                 ans = find_path(left.substr(0, n1-1), middle, right + top_left, path, state);
//                 if (!ans.empty())return ans;
//                 path.resize(prev_size);
//             }
//         }
//         if (n2 > 0) {
//             char top_middle = middle[n2 - 1];
//             vector<string> ans;
//
//             if (n1 == 0 || stoi(string(1, top_middle)) < stoi(string(1, left[n1 - 1]))) {
//                 int prev_size = path.size();
//                 path.push_back("21");
//                 ans = find_path(left + top_middle, middle.substr(0, n2 - 1), right, path, state);
//                 if (!ans.empty())return ans;
//                 path.resize(prev_size);
//             }
//             if (n3 == 0 || stoi(string(1, top_middle)) < stoi(string(1, right[n3 - 1]))) {
//                 int prev_size = path.size();
//                 path.push_back("23");
//                 ans = find_path(left, middle.substr(0, n2-1), right + top_middle, path, state);
//                 if (!ans.empty())return ans;
//                 path.resize(prev_size);
//             }
//         }
//         if (n3 > 0) {
//             char top_right = right[n3 - 1];
//             vector<string>ans;
//             if (n1 == 0 || stoi(string(1, top_right)) < stoi(string(1, left[n1 - 1]))) {
//                 int prev_size = path.size();
//                 path.push_back("31");
//                 ans = find_path(left + top_right, middle, right.substr(0, n3 - 1), path, state);
//                 if (!ans.empty())return ans;
//                 path.resize(prev_size);
//             }
//             if (n2 == 0 || stoi(string(1, top_right)) < stoi(string(1, middle[n2 - 1]))) {
//                 int prev_size = path.size();
//                 path.push_back("32");
//                 ans = find_path(left, middle + top_right, right.substr(0, n3 - 1), path, state);
//                 if (!ans.empty())return ans;
//                 path.resize(prev_size);
//             }
//         }
//     }
//
//     return {}; // Default return statement
// }
//
// //
// // vector<string> find_path(string left, string middle, string right, vector<string >path, set<string>state) {
// //     int n1 = left.size(); int n2 = middle.size(); int n3 = right.size();
// //     // cout<<left<< "|"<<middle<<"|"<<right<<endl;
// //     // for (auto tmp: path) {
// //     //     cout<<tmp<< ' ';
// //     // }
// //     for (auto tmp: state) {
// //         cout<<tmp<<' ';
// //     }
// //     cout<<endl;
// //     cout<<endl;
// //     if (n1==0 || n2 == 0) {
// //         cout<<"success"<<endl;
// //         return path;
// //     }
// //     else if(state.find(left + middle + right) != state.end()) {
// //         cout<<'t'<<endl;
// //     }
// //     else {
// //         // left -> middle
// //         if (n1 > 0 && stoi(string(1, left[n1 - 1])) < stoi(string(1, middle[n2 - 1]))) {
// //             string new_left = left.substr(0, n1 - 1);
// //             string new_middle = middle + left[n1-1];
// //             vector<string> new_path = path;
// //             new_path.push_back("12");
// //             state.insert(new_left + new_middle + right);
// //             return find_path(new_left, new_middle, right, new_path, state );
// //         }
// //         // left <- middle
// //         if (n2 > 0 && stoi(string(1, left[n1 - 1])) > stoi(string(1, middle[n2 - 1]))) {
// //             string new_middle = left.substr(0, n2 - 1);
// //             string new_left = left + middle[n1-1];
// //             vector<string> new_path = path;
// //             new_path.push_back("21");
// //             state.insert(new_left + new_middle + right);
// //             return find_path(new_left, new_middle, right, new_path, state );
// //         }
// //         // left -> right
// //         if (n1 > 0 && stoi(string(1, left[n1 - 1])) < stoi(string(1, right[n3 - 1]))) {
// //             string new_left = left.substr(0, n1 - 1);
// //             string new_right = right + left[n1-1];
// //             vector<string> new_path = path;
// //             new_path.push_back("13");
// //             state.insert(new_left + middle + new_right);
// //             return find_path(new_left, middle, new_right, new_path, state );
// //         }
// //         // left <- right
// //         if (n3 > 0 && stoi(string(1, left[n1 - 1])) > stoi(string(1, right[n3 - 1]))) {
// //             string new_right = right.substr(0, n3 - 1);
// //             string new_left = left + right[n3-1];
// //             vector<string> new_path = path;
// //             new_path.push_back("31");
// //             state.insert(new_left + middle + new_right);
// //             return find_path(new_left, middle, new_right, new_path, state );
// //         }
// //         // middle -> right
// //         if (n2 > 0 && stoi(string(1, middle[n2 - 1])) < stoi(string(1, right[n3 - 1]))) {
// //             string new_middle = middle.substr(0, n2 - 1);
// //             string new_right = right + middle[n2-1];
// //             vector<string> new_path = path;
// //             new_path.push_back("23");
// //             state.insert(left + new_middle + new_right);
// //             return find_path(left, new_middle, new_right, new_path, state );
// //         }
// //         if (n3 > 0 && stoi(string(1, middle[n2 - 1])) > stoi(string(1, right[n3 - 1]))) {
// //             string new_right = right.substr(0, n3 - 1);
// //             string new_middle = middle + right[n3-1];
// //             vector<string> new_path = path;
// //             new_path.push_back("32");
// //             state.insert(left + new_middle + new_right);
// //             return find_path(left, new_middle, new_right, new_path, state );
// //         }
// //     }
// // }
//