#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <string>
#include <utility>
#include <vector>
#include "Result.hpp"

class Database {
    private:
        std::vector<std::pair<unsigned long, std::string>*> m_entries;

    public:
        bool read_file(std::string filename);
        Result* query(std::string search_term);
};
#endif //DATABASE_HPP
