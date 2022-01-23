#include "Database.hpp"

using std::pair, std::string, std::vector;

//Result Database::query(const string substring) {
//}
void Database::add_entry(pair<unsigned long, string> *entry) {
    m_entries.push_back(entry);
}
