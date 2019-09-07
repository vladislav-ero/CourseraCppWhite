#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// class SortedStrings {
// public:
//   void AddString(const string& s) {
//     data.push_back(s);
//   }
//   vector<string> GetSortedStrings() {
//     sort(begin(data), end(data));
//     return data;
//   }
// private:
//   vector<string> data;
// };

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        // добавить строку s в набор
        if (map_of_sorted_strings.count(s)) {
            ++map_of_sorted_strings[s];
        }
        else {
            map_of_sorted_strings[s] = 1;
        }
    }
    vector<string> GetSortedStrings() {
        // получить набор из всех добавленных строк в отсортированном порядке
        vector<string> sorted_strings;
        for (const auto& item : map_of_sorted_strings) {
            for (int i = 0; i < item.second; ++i) {
                sorted_strings.push_back(item.first);
            }
        }
        return sorted_strings;
    }
private:
    // приватные поля
    map<string, int> map_of_sorted_strings;
};
    
void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {

    SortedStrings strings;
    
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    return 0;
}
