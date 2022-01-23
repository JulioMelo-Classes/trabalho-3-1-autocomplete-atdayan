#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <utility>
#include <vector>
#include "Result.hpp"

class Database {
    private:
        std::vector<std::pair<unsigned long, std::string>*> m_entries;

    public:
        //Database(unsigned size);
        Result query(std::string substring);
        void add_entry(std::pair<unsigned long, std::string> *entry);
};
#endif //DATABASE_HPP
