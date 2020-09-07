#include <fstream>
#include <iostream>
#include <string>

#ifndef BYTE_FILE_IO_H
#define BYTE_FILE_IO_H

namespace io {
    namespace {
        std::ofstream ofs;
        std::ifstream ifs;

        char getByte(int i, uint8_t byte) {
            return (uint8_t)(i >> (byte*8));
        }

        char getByte(float i, uint8_t byte) {
            return ((char*)&i)[byte];
        }
    }
    
    void openifs(const char *name) {
        ifs.open(name, std::ios::binary);
        ifs >> std::noskipws;
    }

    void openofs(const char *name) {
        ofs.open(name, std::ios::binary);
    }

    void closeifs() {
        ifs.close();
    }

    void closeofs() {
        ofs.close();
    }

    void writeCharsToFile(char chars[], int length) {
        for(int i = 0; i < length; i++) {
            ofs << chars[i];
            //std::cout << "charout: " << (int)chars[i] << std::endl;
        }
    }

    void writeIntsToFile(int32_t ints[], int length) {
        char chars[length*sizeof(int32_t)];
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < sizeof(int32_t); j++) {
                chars[i*4+j] = getByte(ints[i], j);
            }
        }
        writeCharsToFile(chars, length*sizeof(int32_t));
    }

    void writeFloatsToFile(float floats[], int length) {
        char chars[length*sizeof(float)];
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < sizeof(float); j++) {
                chars[i*4+j] = getByte(floats[i], j);
            }
        }
        writeCharsToFile(chars, length*sizeof(float));
    }

    void readCharsFromFile(char chars[], int length) {
        for(int i = 0; i < length; i ++) {
            chars[i] = (int8_t)0x00;
            ifs >> chars[i];
            //std::cout << "charin: " << (int)chars[i] << std::endl;
        }
    }

    void readIntsFromFile(int32_t ints[], int length) {
        char chars[length*sizeof(int32_t)];
        readCharsFromFile(chars, length*sizeof(int32_t));
        for(int i = 0; i < length; i ++) {
            ints[i] = 0x00;
            for(uint8_t j = 0; j < sizeof(int32_t); j ++) {
                ints[i] |= (uint8_t)chars[i*sizeof(int32_t)+j] << (j*8);
            }
        }
    }

    void readFloatsFromFile(float floats[], int length) {
        char chars[length*sizeof(float)];
        readCharsFromFile(chars, length*sizeof(float));
        for(int i = 0; i < length; i ++) {
            floats[i] = *((float *)&chars[i*4]);
        }
    }
}

#endif