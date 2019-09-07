#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom (string x) {
    string y;
    for (int c = x.size() - 1; c >= 0; --c) {
        y.push_back(x[c]);
    }
    
    /*
    cout << "String x is:" << endl << x << endl;
    cout << "String y is:" << endl << y << endl;
     */
    
    if (x == y)
        return true;
    else
        return false;
}

/*
 bool IsPalindrom(string s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
 }
 */

int main() {
    string input;
    //cout << "Enter any string:" << endl;
    cin >> input;
    cout << IsPalindrom(input) << endl;
    
    return 0;
}
