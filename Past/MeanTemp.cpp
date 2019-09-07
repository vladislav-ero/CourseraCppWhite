#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> temp(n);
    double tempsr = 0;
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
        tempsr += temp[i];
    }
    tempsr /= n;
    
    int count = 0;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (temp[i] > tempsr) {
            ++count;
            pos.push_back(i);
        }
    }
    
    cout << count << endl;
    
    for (auto c: pos) {
        cout << c << " ";
    }
    
    return 0;
}
