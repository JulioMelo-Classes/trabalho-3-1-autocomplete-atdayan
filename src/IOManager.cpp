#include <fstream>
#include "IOManager.hpp"

using std::string, std::cin, std::cout;

bool IOManager::read_database_file(string filename) {
    std::fstream file;
    file.open(filename);
    if (file.is_open()) {
        cout << "está aberto\n";
        string str;
        std::getline(file, str);
        std::getline(file, str);
        cout << str << "\n";
        return true;
    } 
    cout << "erro\n";
    return false;
}
