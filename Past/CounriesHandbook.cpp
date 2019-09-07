#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void PrintMap(const map<string, string>& m) {
    for (const auto& item : m) {
        cout << item.first << "/" << item.second << endl;
    }
}

int main() {
    
    map<string, string> countries;
    int Q;
    //cout << "Enter the ammount of your commands: " << endl;
    cin >> Q;
    //cout << "Enter your commands: " << endl;
    for (int comm = 0; comm < Q; comm++) {
        string command;
        cin >> command;

        if (command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (countries.count(country)) { //if the country exists
                if (countries[country] == new_capital) { //new capital is the same
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                }
                else { //new capital differ from previous
                    string old_capital = countries[country];
                    countries[country] = new_capital;
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
                }
            }
            else { //add country to the list with new capital
                countries[country] = new_capital;
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            }
        }

        else if (command == "RENAME") { /* если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует; */
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (!(countries.count(old_country_name)) || old_country_name == new_country_name || countries.count(new_country_name)) {
                cout << "Incorrect rename, skip" << endl;
            }
            else if (countries[old_country_name] > ""){ /* если запрос корректен и страна имеет столицу capital. */
                string capital = countries[old_country_name];
                countries.erase(old_country_name);
                countries[new_country_name] = capital;
                cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
            }
        }

        else if (command == "ABOUT") {
            string country;
            cin >> country;
            if (countries.count(country) && countries[country] > "") {
                cout <<  "Country " << country << " has capital " << countries[country] << endl;
            }
            else {
                cout << "Country " << country << " doesn't exist" << endl;
            }
        }

        else if (command == "DUMP") {
            if (countries.size() == 0) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                PrintMap(countries);
                }
        }

        else {}
    }

    return 0;
}
