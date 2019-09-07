#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    int Q;
    //cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
    //cout << "Enter your commands: " << endl;
    vector<string> commands(Q);
    vector<int> pos(Q);
    vector<bool> worriedLine(0,false);
    
    
    for (int i = 0; i < Q; i++) {
        cin >> commands[i];
        if (commands[i] == "WORRY") {
            cin >> pos[i];
            worriedLine[pos[i]] = true;
        } else if (commands[i] == "QUIET") {
            cin >> pos[i];
            worriedLine[pos[i]] = false;
        } else if (commands[i] == "COME") {
            cin >> pos[i];
            worriedLine.resize(worriedLine.size()+pos[i]);
        } else { //WORRY_COUNT
            int worriedCount = 0;
            for (auto c : worriedLine) {
                if (c == true)
                    ++worriedCount;
            }
            cout << worriedCount << endl;
        }
    }
    
    return 0;
}
