#include <iostream>
#include <vector>
using namespace std;
vector<string>board;
vector<bool>row;
vector<bool>col;
vector<bool>diag1;
vector<bool>diag2;
int ans = 0;
// 4, 1
void move(int i) {
    if (i == 8) {
        ans ++;
        return;
    }
    for (int j = 0; j < 8; j++) {
        if (board[i][j] == '*') {
        }
        else if (row[i] || col[j] || diag1[i + j] || diag2[7 - i + j]) {
        }
        else {
            row[i] = true;
            col[j] = true;
            diag1[i+j] = true;
            diag2[7-i+j] = true;
            move(i + 1);
            row[i] = false;
            col[j] = false;
            diag1[i+j] = false;
            diag2[7-i+j] = false;
        }
    }
}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    string new_row;
    int i = 0;
    while(i < 8) {
        cin>>new_row;
        board.push_back(new_row);
        i++;
    }
    // for (int i = 0; i < 8; i++) {
    //     cout<<board[i][0]<<endl;
    //     for (int j = 0; j < 8; j++) {
    //         // cout<<board[i][0];
    //     }
    //     cout<<endl;
    // }
    cout<<endl;
    row.resize(8);
    col.resize(8);
    diag1.resize(15);
    diag2.resize(15);

    move(0);
    cout<<ans<<endl;
    return 0;
}
