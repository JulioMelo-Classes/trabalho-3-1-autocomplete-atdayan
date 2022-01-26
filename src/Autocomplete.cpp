#include <string>
#include "Database.hpp"
#include "IOManager.hpp"

int main(int argc, char* argv[]) {

    IOManager io;
    if (argc < 2)
        return io.error(0);

    Database db;
    if (!db.read_file(argv[1]))
        return io.error(1);

    std::string term;
    Result *result;
    do {
        term = io.input_term();
        result = db.query(term);
        io.print(result->results());
    } while (!term.empty());

    delete result;
    io.close();

    return EXIT_SUCCESS;
}
