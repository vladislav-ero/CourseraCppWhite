#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    vector<int> days_of_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int current_month = 0;
    vector<vector<string>> days(days_of_months[current_month]);
    
    int Q;
    cout << months[current_month] << ", max day is " << days_of_months[current_month] << endl;
    cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
    cout << "Enter your commands: " << endl;
    for (int comm = 0; comm < Q; comm++) {
        string command;
        cin >> command;
        
        
        if (command == "NEXT") {
            if (current_month < 11) {
                vector<string> temp_vec;
                if (days_of_months[current_month] > days_of_months[current_month + 1]) { //if current month has more days than current
                    for (int i = days_of_months[current_month + 1]; i < days_of_months[current_month]; ++i) { //go through days to be deleted
                        for (auto c : days[i]) { //go through all works for each day
                            temp_vec.push_back(c); //form a vector of works to be deleted
                        }
                        days[i].clear();
                    }
                    ++current_month; //increment the value
                    days.resize(days_of_months[current_month]);
                    days[days_of_months[current_month] - 1].insert(end(days[days_of_months[current_month] - 1]), begin(temp_vec), end(temp_vec));
                }
                else {
                    ++current_month; //increment the value
                    days.resize(days_of_months[current_month]);
                }
            } else {
                current_month = 0;
            }
            cout << months[current_month] << ", max day is " << days_of_months[current_month] << endl;
        }
        else if (command == "ADD") {
            int number_of_day;
            string work;
            cin >> number_of_day >> work;
            --number_of_day;
            days[number_of_day].push_back(work); //add the new work to required day
        }
        else if (command == "DUMP") {
            int number_of_day;
            cin >> number_of_day;
            --number_of_day;
            cout << days[number_of_day].size() << " ";
            for (auto c : days[number_of_day]) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
