#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    
    map<vector<string>, int> routes;
    int Q;
    //cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
    //cout << "Enter your commands: " << endl;
    for (int comm = 0; comm < Q; ++comm) {
        int quantity;
        cin >> quantity;
        vector<string> temp_stops;
        for (int count = 0; count < quantity; ++count) {
            string temp_stop;
            cin >> temp_stop;
            temp_stops.push_back(temp_stop);
        }
        
        if (routes.count(temp_stops)) { //if the route exists
            cout << "Already exists for " << routes[temp_stops] << endl;
        }
        else {
            int cur_size = routes.size();
            routes[temp_stops] = ++cur_size;
            cout << "New bus " << routes[temp_stops] << endl;
        }
        
    }
        
    return 0;
}
