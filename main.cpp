#include "byteFileIO.h"

using namespace byteFileIO;

int main() {
    std::ofstream ofs;
    openStream(ofs, "file.sav");
    int32_t i[3];
    i[0] = 12345678;
    i[1] = 245349070;
    i[2] = 98765432;
    writeIntsToFile(ofs, i, 3);
    closeStream(ofs);

    std::ifstream ifs;
    openStream(ifs, "file.sav");
    int32_t j[3] = {0};
    readIntsFromFile(ifs, j, 3);
    closeStream(ifs);

    std::cout << j[0] << " " << j[1] << " " << j[2] << std::endl;
}