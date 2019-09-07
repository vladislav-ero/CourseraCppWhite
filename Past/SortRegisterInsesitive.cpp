#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    
    
    int Q;
//    cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
//    cout << "Enter your commands: " << endl;
    vector<string> letters(Q);
    for (string& n : letters) {
        cin >> n;
    }
    
    sort(letters.begin(), letters.end(),
         [](string i, string j) {
             for (char& n: i) {
                 n = tolower(n);
             }
             for (char& n: j) {
                 n = tolower(n);
             }
             return (i < j);
         }
    );
    
    for (const string& n : letters) {
        cout << n << " ";
    }
    
    cout << endl;
    
    return 0;
}
