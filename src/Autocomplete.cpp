#include <iostream>
#include <string>
#include "IOManager.hpp"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Usage: autocomplete <database_file>\n\t"
            "Where <database_file> is the ascii file that contains the query terms and weights.\n";
        return EXIT_FAILURE;
    }

    IOManager io;
    io.read_database_file(argv[1]);

    return EXIT_SUCCESS;
}
