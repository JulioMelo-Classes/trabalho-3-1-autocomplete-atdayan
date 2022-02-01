#include <string>
#include "Database.hpp"
#include "IOManager.hpp"
#include "Result.hpp"

int main(int argc, char* argv[]) {

    IOManager io;
    if (argc < 2)
        return io.error(0);

    Database db;
    if (!db.read_file(argv[1]))
        return io.error(1);

    std::string term = io.input_term();
    while(!term.empty()) {
        auto result = db.query(term);
        io.print(result->results());
        term = io.input_term();
    }

    io.close();

    return EXIT_SUCCESS;
}
