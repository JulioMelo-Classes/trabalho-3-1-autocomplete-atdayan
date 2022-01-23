#ifndef QUERYPROCESSOR_HPP
#define QUERYPROCESSOR_HPP
#include <string>
#include "Database.hpp"

class QueryProcessor {
    private:
        Database database;
    public:
        QueryProcessor(Database database);
        std::string query_results(std::string term);
};
#endif //QUERYPROCESSOR_HPP
