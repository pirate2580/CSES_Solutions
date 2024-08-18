#include <iostream>
#include <vector>
#include<set>
using namespace std;

set<string> wordslist;
vector<bool>chosen;
void solve(string word, vector<int>permutation) {
    // cout<<"permutation size"<<permutation.size()<<endl;
    if (permutation.size() == word.size()) {
        string ans;
        for (int i:permutation) {
            ans += word[i];
        }
        wordslist.insert(ans);
    }
    for (int i = 0; i < chosen.size(); i++) {
        if (chosen[i])continue;
        permutation.push_back(i);
        chosen[i] = true;
        solve(word, permutation);
        chosen[i] = false;
        permutation.pop_back();
    }
}

int main() {
    string word;
    cin>>word;
    set<int> nums;
    for (int i =0; i < word.size(); i++) {
        nums.insert(i);
    }
    chosen.resize(word.size());
    solve(word, vector<int>());
    cout<<wordslist.size()<<endl;
    for (string word: wordslist) {
        cout<<word<<endl;
    }
    return 0;
}
