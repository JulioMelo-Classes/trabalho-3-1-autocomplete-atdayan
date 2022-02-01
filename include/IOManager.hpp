#ifndef IOMANAGER_HPP
#define IOMANAGER_HPP
#include <string>

class IOManager {
    public:
        Database* read_database_file(std::string filename);
        std::string input_term();
        void print(std::string result);
        unsigned error(unsigned code);
        void close();
};
#endif //IOMANAGER_HPP
