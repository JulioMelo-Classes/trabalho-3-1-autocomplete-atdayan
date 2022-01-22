#ifndef IOMANAGER_HPP
#define IOMANAGER_HPP
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class IOManager {
    private:
    
    public:
        bool read_database_file(std::string filename);
        std::string read_search(std::string substring);
        void print_result(std::string result);
};
#endif //IOMANAGER_HPP
