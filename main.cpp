#include "byteFileIO.h"

using namespace byteFileIO;

int main() {
    // std::ofstream ofs;
    // openStream(ofs, "file.sav");
    // int32_t i[3] = {0x00};
    // i[0] = 12345678;
    // i[1] = 245349070;
    // i[2] = 98765432;
    // writeIntsToFile(ofs, i, 3);
    // char x[2] = {0};
    // x[0] = 'a';
    // x[1] = 'B';
    // writeCharsToFile(ofs, x, 2);
    // closeStream(ofs);

    // std::ifstream ifs;
    // openStream(ifs, "file.sav");
    // int32_t j[3];
    // readIntsFromFile(ifs, j, 3);
    // char y[2];
    // readCharsFromFile(ifs, y, 2);
    // closeStream(ifs);

    // std::cout << j[0] << " " << j[1] << " " << j[2] << std::endl;
    // std::cout << y[0] << " " << y[1] << std::endl;
    // std::cout << sizeof(float) << std::endl;

    std::ofstream ofs;
    openStream(ofs, "file.sav");
    float f[4] = {0.0, 0.1, 0.2, 5.1};
    writeFloatsToFile(ofs, f, 4);
    closeStream(ofs);

    std::ifstream ifs;
    openStream(ifs, "file.sav");
    float f2[4];
    readFloatsFromFile(ifs, f2, 4);
    closeStream(ifs);
    
    for(int i = 0; i < 4; i ++) {
        std::cout << f2[i] << std::endl;
    }
}