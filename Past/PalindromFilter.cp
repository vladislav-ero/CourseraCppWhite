#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom (string x) {
    string y;
    for (int c = x.size() - 1; c >= 0; --c) {
        y.push_back(x[c]);
    }
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

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> output;
    for (auto i : words) {
        if (IsPalindrom(i) && i.size() >= minLength) {
            output.push_back(i);
        }
    }
    return output;
}

int main() {
    vector<string> input = {"weew", "bro", "code"};
    int MinLength = 4;
    vector<string> finalOutput = PalindromFilter(input, MinLength);
   
   
    //cout << "Enter any vector of stirngs:" << endl;
   // cin >> input;
    //cout << IsPalindrom(input) << endl;
    
    return 0;
}
