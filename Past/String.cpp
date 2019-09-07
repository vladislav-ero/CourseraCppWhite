#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& st) {
        current_string = st;
    }
    string ToString() const {
        return current_string;
    }
    void Reverse() {
        reverse(begin(current_string), end(current_string));
    }
private:
    string current_string;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
    
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
    
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
    
    return 0;
}
