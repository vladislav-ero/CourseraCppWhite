#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    
    set<string> words;
    int Q;
    //cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
    //cout << "Enter your commands: " << endl;
    for (int comm = 0; comm < Q; ++comm) {
        
        string temp_word;
        cin >> temp_word;
        words.insert(temp_word);
        
    }
    cout << words.size() << endl;
        
    return 0;
}
