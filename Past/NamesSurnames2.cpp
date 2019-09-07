#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно
    
    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }
    
    return name;
}

vector<string> FindFormerNamesByYear(const map<int, string>& names, int year){
    vector<string> former_names;
    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    string last_string = "";
    for (const auto& item : names) {
        // если очередной год не больше данного, записываем имя в вектор
//        string curr_name = FindNameByYear(names, year);
        if (item.first < year) {
            if (item.second != last_string) {
                former_names.push_back(item.second);
                last_string = item.second;
            }
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }
    if (!former_names.empty()) {
        string curr_name = FindNameByYear(names, year);
        if (former_names.back() == curr_name) {
            former_names.pop_back();
        }
        reverse(begin(former_names), end(former_names));
        }
    return former_names;
}

string VectorToString(const vector<string> vector_of_strings) {
    string st;
    if (vector_of_strings.size() > 1) {
        st = " (";
        int i = 0;
        while (i < vector_of_strings.size()-1) {
            st += vector_of_strings[i] + ", ";
            ++i;
        }
        st += vector_of_strings[i] + ")";
    }
    else if (vector_of_strings.size() == 1) {
        st = " (" + vector_of_strings[0] + ")";
    }
    return st;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
//        cout << "First name changes: ";
//        for (const auto& item : first_names) {
//            cout << "(" << item.first << ":" << item.second << ") ";
//        }
//        cout << endl;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
//        cout << "Last name changes: ";
//        for (const auto& item : last_names) {
//            cout << "(" << item.first << ":" << item.second << ") ";
//        }
//        cout << endl;
    }
    string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        
        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
            
            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
            
            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
            
            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }
    string GetFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        const vector<string> former_first_names = FindFormerNamesByYear(first_names, year);
        const vector<string> former_last_names = FindFormerNamesByYear(last_names, year);
        const string former_fn = VectorToString(former_first_names);
        const string former_ln = VectorToString(former_last_names);
        
        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
            
            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + former_ln + " with unknown first name";
            
            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + former_fn + " with unknown last name";
            
            // если известны и имя, и фамилия
        } else {
            return first_name + former_fn + " " + last_name + former_ln;
        }
    }
    
private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
    Person person;
    
    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;
    
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1990, "Polina");
//    person.ChangeLastName(1990, "Volkova-Sergeeva");
//    cout << person.GetFullNameWithHistory(1990) << endl;
//
//    person.ChangeFirstName(1966, "Pauline");
//    cout << person.GetFullNameWithHistory(1966) << endl;
//
//    person.ChangeLastName(1960, "Sergeeva");
//    for (int year : {1960, 1967}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeLastName(1961, "Ivanova");
//    cout << person.GetFullNameWithHistory(1967) << endl;
    
    return 0;
}
