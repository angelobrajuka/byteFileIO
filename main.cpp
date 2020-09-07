#include "byteFileIO.h"

using namespace io;

int main() {
    openofs("file.sav");
    int32_t i[3] = {0x00};
    i[0] = 12345678;
    i[1] = 245349070;
    i[2] = 98765432;
    writeIntsToFile(i, 3);
    char x[2] = {0};
    x[0] = 'a';
    x[1] = 'B';
    writeCharsToFile(x, 2);
    closeofs();

    std::ifstream ifs;
    openifs("file.sav");
    int32_t j[3];
    readIntsFromFile(j, 3);
    char y[2];
    readCharsFromFile(y, 2);
    closeifs();

    std::cout << j[0] << " " << j[1] << " " << j[2] << std::endl;
    std::cout << y[0] << " " << y[1] << std::endl;
    std::cout << sizeof(float) << std::endl;

    openofs("file.sav");
    float f[4] = {0.0, 0.1, 0.2, 5.1};
    writeFloatsToFile(f, 4);
    closeofs();

    openifs("file.sav");
    float f2[4];
    readFloatsFromFile(f2, 4);
    closeifs();
    
    for(int i = 0; i < 4; i ++) {
        std::cout << f2[i] << std::endl;
    }
}