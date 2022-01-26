#include <algorithm>
#include <fstream>
#include <iostream>
#include "Database.hpp"

using std::pair, std::string;

inline void prepare_string(std::string &s) {

    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                [](unsigned char ch) {
                    return !std::isspace(ch);
                }));
    s.erase(std::find_if(s.rbegin(), s.rend(),
                [](unsigned char ch) {
                    return !std::isspace(ch);
                }).base(), s.end());
    std::transform(s.begin(), s.end(), s.begin(),
                [](unsigned char ch){
                    return std::tolower(ch);
                });
}

bool Database::read_file(string filename) {

    std::ifstream file {filename};
    if (file.is_open()) {
        string word;
        unsigned long file_size, weight;

        file >> file_size;

        //std::cout << "file size: " << file_size << "\n";
        //for (int i = 0; i < 10; i++) {
        //    file >> weight;
        //    std::getline(file, word);
        //    prepare_string(word);

        //    auto entry = new std::pair<unsigned long, string>(weight, word);
        //    m_entries.push_back(entry);

        // //   std::cout << "weight: " << entry->first << " | word: " << entry->second << "\n";
        //}

        while (file >> weight) {
            std::getline(file, word);
            prepare_string(word);
            auto entry = new std::pair<unsigned long, string>(weight, word);
            m_entries.push_back(entry);
        }
        file.close();

        //sort entries in alphabetical order
        std::sort(m_entries.begin(), m_entries.end(), [](auto e1, auto e2) {
                    return (e1->second < e2->second);
                });

        for (int i = 0; i < m_entries.size(); i++)
            std::cout << i+1 << ": " << m_entries[i]->second << "\n";

        return true;
    }
    return false;
}

void Database::query(string search_term) {
    auto low = std::lower_bound(m_entries.begin(), m_entries.end(), search_term, [](auto e, string s) {
                return e->second < s;
            });
    auto up = std::upper_bound(m_entries.begin(), m_entries.end(), search_term, [](string s, auto e) {
                return s < e->second;
            });

    std::cout << "low is: " << (low - m_entries.begin()) + 1 << "\n";
    std::cout << "upper is: " << (up - m_entries.begin()) + 1 << "\n";
}
