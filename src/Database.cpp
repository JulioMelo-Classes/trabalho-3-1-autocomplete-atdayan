#include <algorithm>
#include <fstream>
#include <iostream>
#include "Database.hpp"

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

bool Database::read_file(std::string filename) {
    std::ifstream file {filename};
    if (file.is_open()) {
        std::string word;
        unsigned long file_size, weight;

        file >> file_size;

        while (file >> weight) {
            std::getline(file, word);
            prepare_string(word);
            auto entry = new std::pair<unsigned long, std::string>(weight, word);
            m_entries.push_back(entry);
        }
        file.close();

        //sort entries in alphabetical order
        std::sort(m_entries.begin(), m_entries.end(), [](auto e1, auto e2) {
                    return (e1->second < e2->second);
                });

        return true;
    }
    return false;
}

Result* Database::query(std::string search_term) {
    auto low = std::lower_bound(m_entries.begin(), m_entries.end(), search_term,
            [](auto e, std::string s) {
                return e->second < s;
            });
    auto up = std::upper_bound(m_entries.begin(), m_entries.end(), search_term,
            [](std::string s, auto e) {
                return s < e->second.substr(0, s.length());
            });

    Result *result = new Result();

    if (*low == *up)
        return result;

    std::for_each(low, up, [&result](auto e){
                result->add_entry(e);
            });

    return result;
}
