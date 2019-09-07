#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(const string& word) {
    map<char, int> counters;
    for (char c : word) {
        ++counters[c];
    }
    return counters;
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        string first_word, second_word;
        cin >> first_word >> second_word;
        if (BuildCharCounters(first_word) == BuildCharCounters(second_word)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
