#ifndef RESULT_HPP
#define RESULT_HPP
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Result {
    private:
        std::vector<std::shared_ptr<std::pair<unsigned long, std::string>>> m_results;

    public:
        std::string results();
        void add_entry(std::shared_ptr<std::pair<unsigned long, std::string>> entry);
};
#endif //RESULT_HPP
