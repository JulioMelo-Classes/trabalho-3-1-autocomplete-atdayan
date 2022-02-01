#include <algorithm>
#include <iostream>
#include "IOManager.hpp"

inline void prepare_string(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                [](char ch) {
                    return !std::isspace(ch);
                }));
    s.erase(std::find_if(s.rbegin(), s.rend(),
                [](char ch) {
                    return !std::isspace(ch);
                }).base(), s.end());
    std::transform(s.begin(), s.end(), s.begin(),
                [](char ch){
                    return std::tolower(ch);
                });
}

std::string IOManager::input_term() {
    std::cout << ">>> Type a word and hit ENTER or Ctrl-D to quit: ";
    std::string term;

    if (!std::getline(std::cin, term))
        return "";

    while (term == "") {
        std::cout << ">>> Type a word and hit ENTER or Ctrl-D to quit: ";
        std::getline(std::cin, term);
    }
    prepare_string(term);

    return term;
}

void IOManager::print(std::string result) {
    if (result.empty())
        std::cout << "No matches found.\n";
    else
        std::cout << ">>> The matches are:\n" << result << "\n";
}

unsigned IOManager::error(unsigned code) {
    switch (code) {
        case 0:
            std::cerr << "Usage: autocomplete <database_file>\n\t"
                "Where <database_file> is the ascii file that contains the query terms and weights.\n";
            break;
        case 1:
            std::cerr << "Database file not found or corrupted.\n";
            break;
    }
    return EXIT_FAILURE;
}

void IOManager::close() {
    std::cout << "\nBye.\n";
}
