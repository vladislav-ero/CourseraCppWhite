#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void PrintMap(const map<string, vector<string>>& m) {
    for (const auto& item : m) {
        cout << "Bus " << item.first << ": ";
        for (const string& stop : item.second) {
            cout << stop << " ";
        }
        cout << endl;
    }
}

int main() {
    
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    
    int Q;
    //cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
    //cout << "Enter your commands: " << endl;
    for (int comm = 0; comm < Q; ++comm) {
        string command;
        cin >> command;

        if (command == "NEW_BUS") {
            string new_bus;
            cin >> new_bus;
            int stops_count;
            cin >> stops_count;
            vector<string> new_stops;
            for (int bus_stops = 0; bus_stops < stops_count; ++bus_stops) {
                string new_stop;
                cin >> new_stop;
                new_stops.push_back(new_stop);
                stops[new_stop].push_back(new_bus);
            }
            buses[new_bus] = new_stops;
        }

        else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stops.count(stop)) {
                for (const string& b : stops[stop]) {
                    cout << b << " ";
                }
            }
            else {
                cout << "No stop";
            }
            cout << endl;
        }

        else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses.count(bus)){
                for (const string& st : buses[bus]) {
                    cout << "Stop " << st << ": ";
                    //if (stops.count(st) == 1 && stops[st][0] == bus) {
                    if (stops[st].size() == 1 && stops[st][0] == bus) {
                        cout << "no interchange";
                    }
                    else {
                        for (const string& b : stops[st]) {
                            if (b != bus) {
                                cout << b << " ";
                            }
                        }
                    }
                    cout << endl;
                }
            }
            else {
                cout << "No bus" << endl;
            }
        }

        else if (command == "ALL_BUSES") {
            if (buses.empty()) {
                cout << "No buses" << endl;
            }
            else {
                PrintMap(buses);
            }
        }

        else {}
    }

    return 0;
}
