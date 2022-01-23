#ifndef RESULT_HPP
#define RESULT_HPP
#include <string>
#include <utility>
#include <vector>

class Result {
    private:
        std::vector<std::pair<std::string, unsigned>> m_results;

    public:
        std::string results_by_relevance();
};
#endif //RESULT_HPP
