#ifndef RESULT_HPP
#define RESULT_HPP
#include <string>
#include <utility>
#include <vector>

class Result {
    private:
        std::vector<std::pair<unsigned long, std::string>*> m_results;

    public:
        std::string results();
        void add_entry(std::pair<unsigned long, std::string> *entry);
};
#endif //RESULT_HPP
