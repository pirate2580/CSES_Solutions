#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<int>applicants;
    vector<int>apartments;
    applicants.resize(n);
    apartments.resize(m);
    for (int i = 0; i < n; i++) {
        cin>>applicants[i];
    }
    for (int i = 0; i < m; i++) {
        cin>>apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    // for(int i = 0; i < n; i++){cout<<applicants[i]<<' ';}cout<<endl;
    int cnt = 0;
    int applicant_index = 0;
    int apartment_index = 0;

    while (applicant_index < n && apartment_index < m) {
        if (apartments[apartment_index] <= applicants[applicant_index] + k &&
            applicants[applicant_index] - k <= apartments[apartment_index]) {
            cnt++;
            apartment_index++;
            applicant_index++;
        }
        else if (apartments[apartment_index] > applicants[applicant_index] + k) {
            applicant_index++;
        }
        else {
            apartment_index++;
        }
    }
    cout<<cnt<<endl;

    // for each apartment, greedily try to assign the leftmost available applicant
    // Reasoning: if you assign the leftmost applicant if available, it is just as good if not better


    // for (int i = 0; i < m; i++) {
    //     cout<<i<<' '<<applicant_index<<' ';
    //     if (apartments[i] < applicants[applicant_index] - k) {
    //         applicant_index++;
    //         // cout<<"qwht"<<endl;
    //     }
    //     else if (apartments[i] <= applicants[applicant_index] + k && applicants[applicant_index] - k <= apartments[i]) {
    //         cout<<applicants[i];
    //         cnt++;
    //         applicant_index++;
    //     }
    //
    //     if (applicant_index == n) {
    //         break;
    //     }
    //     cout<<endl;
    // }

    // cout<<cnt<<endl;
    return 0;
}
