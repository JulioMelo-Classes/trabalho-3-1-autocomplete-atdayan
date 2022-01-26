#include <utility>
#include "IOManager.hpp"

std::string IOManager::input_term() {
    std::cout << ">>> Type a word and hit ENTER or Ctrl-D to quit: ";
    std::string term;
    std::cin >> term;
    if (term == "0")
        return "";
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
    std::cout << "Bye.\n";
    //m_database_file->close();
    //delete m_database_file;
}
