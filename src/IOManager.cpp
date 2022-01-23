#include <algorithm>
#include <utility>
#include "IOManager.hpp"

using std::string, std::cin, std::cout;

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
                [](unsigned char c){
                    return std::tolower(c);
                });
}

Database* IOManager::read_database_file(string filename) {
    std::ifstream file {filename};
    if (file.is_open()) {
        string word;
        unsigned long file_size, weight;

        file >> file_size;
        Database *db = new Database;

        cout << "file size: " << file_size << "\n";
        for (int i = 0; i < 10; i++) {
            file >> weight;
            std::getline(file, word);
            prepare_string(word);

            auto entry = new std::pair<unsigned long, string>(weight, word);
            db->add_entry(entry);

            cout << "weight: " << entry->first << " | word: " << entry->second << "\n";
        }
        //while (file >> weight) {
        //    std::getline(file, word);
        //    auto entry = new std::pair<unsigned, string>(weight, word);
        //    db->add_entry(entry);
        //}

        file.close();
        return new Database;
    }
    return nullptr;
}

string IOManager::input_term() {
    cout << ">>> Type a word and hit ENTER or Ctrl-D to quit: ";
    string term;
    cin >> term;
    if (term == "0")
        return "";
    return term;
}

void IOManager::print(string result) {
    if (result.empty())
        cout << "No matches found.\n";
    else
        cout << ">>> The matches are:\n" << result << "\n";
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
    std::cout << "Bye.\n";
    //m_database_file->close();
    //delete m_database_file;
}
