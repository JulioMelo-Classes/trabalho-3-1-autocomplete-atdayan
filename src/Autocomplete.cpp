#include <iostream>
#include <string>
#include "IOManager.hpp"
#include "QueryProcessor.hpp"

using std::string;

int main(int argc, char* argv[]) {

    IOManager io;
    if (argc < 2)
        return io.error(0);

    if (!io.read_database_file(argv[1]))
        return io.error(1);

    //QueryProcessor query_proc {io.get_database()};
    string term = "";
    do {
        //Result result = query_proc.find_results(term);
        //io.print(query_proc.query_results(term));
        term = io.input_term();
        // teste output
        io.print("---> input: " + term);
    } while (term != "");
    io.close();

    return EXIT_SUCCESS;
}
