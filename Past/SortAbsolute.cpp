#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    
    vector<int> nums;
    int Q;
//    cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
//    cout << "Enter your commands: " << endl;
    for (int comm = 0; comm < Q; ++comm) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end(), [](int i, int j) {return (abs(i) < abs(j));});
    
    for (const int& n : nums) {
        cout << n << " ";
    }
    
    cout << endl;
    
    return 0;
}
