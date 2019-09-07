#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {

    map<string, set<string>> synonyms;
    int Q;
    //cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
    //cout << "Enter your commands: " << endl;
    for (int comm = 0; comm < Q; ++comm) {
        string command;
        cin >> command;
        
        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        
        else if (command == "COUNT") {
            string word;
            cin >> word;
            
            cout << synonyms[word].size() << endl;
        }
        
        else if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
           
            if (synonyms[word1].count(word2)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        
    }
    return 0;
}
