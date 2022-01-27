#include <string>
#include "Database.hpp"
#include "IOManager.hpp"
#include "QueryProcessor.hpp"

using std::string;

int main(int argc, char* argv[]) {

    IOManager io;
    if (argc < 2)
        return io.error(0);

    Database db;
    if (!db.read_file(argv[1]))
        return io.error(1);

    //QueryProcessor query_proc {io.get_database()};
    string term = "";
    do {
        term = io.input_term();
        Result result = db.query(term);
        io.print(result.results());
        // teste output
        //io.print("---> input: " + term);
    } while (term != "");
    io.close();

    return EXIT_SUCCESS;
}
