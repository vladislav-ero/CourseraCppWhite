#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//struct NameSurname {
//    string name;
//    string surname;
//};
//
//struct ChangesOfName {
//    int year_of_change;
//    NameSurname name_surname;
//};

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
//        ChangesOfName{year, {first_name, ""}};
        year_change_fn.push_back(year);
        sort(begin(year_change_fn), end(year_change_fn));
        map_change_fn[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        year_change_ln.push_back(year);
        sort(begin(year_change_ln), end(year_change_ln));
        map_change_ln[year] = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string FullName;
        
        int count_first = 0;
        for (const auto& yf : year_change_fn) {
            if (yf <= year) {
                ++count_first;
            }
        }
        
        int count_last = 0;
        for (const auto& yl : year_change_ln) {
            if (yl <= year) {
                ++count_last;
            }
        }
        
        if (count_first > 0 && count_last > 0) {
            string first_name = map_change_fn[year_change_fn[count_first - 1]];
            string last_name = map_change_ln[year_change_ln[count_last - 1]];
            FullName = first_name + " " + last_name;
        }
        else if (count_first > 0 && count_last == 0) {
            string first_name = map_change_fn[year_change_fn[count_first - 1]];
            FullName = first_name + " with unknown last name";
        }
        else if (count_first == 0 && count_last > 0) {
            string last_name = map_change_ln[year_change_ln[count_last - 1]];
            FullName = last_name + " with unknown first name";
        }
        else if (count_first == 0 && count_last == 0) {
            FullName =  "Incognito";
        }
        
        return FullName;
    }
private:
    // приватные поля
    
    vector<int> year_change_fn;
    vector<int> year_change_ln;
    map<int, string> map_change_fn;
    map<int, string> map_change_ln;
};


int main() {
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    return 0;
}


//
// #include <map>
// #include <string>

// // если имя неизвестно, возвращает пустую строку
// string FindNameByYear(const map<int, string>& names, int year) {
//   string name;  // изначально имя неизвестно
//   // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
//   for (const auto& item : names) {
//     // если очередной год не больше данного, обновляем имя
//     if (item.first <= year) {
//       name = item.second;
//     } else {
//       // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
//       break;
//     }
//   }
  
//   return name;
// }

// class Person {
// public:
//   void ChangeFirstName(int year, const string& first_name) {
//     first_names[year] = first_name;
//   }
//   void ChangeLastName(int year, const string& last_name) {
//     last_names[year] = last_name;
//   }
//   string GetFullName(int year) {
//     // получаем имя и фамилию по состоянию на год year
//     const string first_name = FindNameByYear(first_names, year);
//     const string last_name = FindNameByYear(last_names, year);
    
//     // если и имя, и фамилия неизвестны
//     if (first_name.empty() && last_name.empty()) {
//       return "Incognito";
    
//     // если неизвестно только имя
//     } else if (first_name.empty()) {
//       return last_name + " with unknown first name";
      
//     // если неизвестна только фамилия
//     } else if (last_name.empty()) {
//       return first_name + " with unknown last name";
      
//     // если известны и имя, и фамилия
//     } else {
//       return first_name + " " + last_name;
//     }
//   }

// private:
//   map<int, string> first_names;
//   map<int, string> last_names;
// };