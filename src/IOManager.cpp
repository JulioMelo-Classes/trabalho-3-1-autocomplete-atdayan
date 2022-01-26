#include <utility>
#include "IOManager.hpp"

using std::string, std::cin, std::cout;

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
