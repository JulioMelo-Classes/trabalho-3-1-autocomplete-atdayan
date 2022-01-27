#include <algorithm>
#include "Result.hpp"

std::string Result::results() {
    if (m_results.empty())
        return "";

    std::sort(m_results.begin(), m_results.end(), [](auto r1, auto r2) {
                return r1->first > r2->first;
            });

    std::string result_list = "";
    std::for_each(m_results.begin(), m_results.end(), [&result_list](auto r) {
                result_list += r->second + '\n';
            });

    return result_list;
}

void Result::add_entry(std::pair<unsigned long, std::string> *entry) {
    m_results.push_back(entry);
}
