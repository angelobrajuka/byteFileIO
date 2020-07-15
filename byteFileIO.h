#include <fstream>
#include <iostream>
#include <string>

#ifndef BYTE_FILE_IO_H
#define BYTE_FILE_IO_H

namespace byteFileIO {
    namespace {
        char getByte(int i, uint8_t byte) {
            return (uint8_t)(i >> (byte*8));
        }

        char getByte(float i, uint8_t byte) {
            std::cerr << "this function is still empty, fill it" << std::endl;
            std::exit(1);
        }
    }
    
    void openStream(std::ifstream &ifs, const char *name) {
        ifs.open(name, std::ios::binary);
    }

    void openStream(std::ofstream &ofs, const char *name) {
        ofs.open(name, std::ios::binary);
    }

    void closeStream(std::ifstream &ifs) {
        ifs.close();
    }

    void closeStream(std::ofstream &ofs) {
        ofs.close();
    }

    void writeCharsToFile(std::ofstream &ofs, char chars[], int length) {
        for(int i = 0; i < length; i++) {
            ofs << chars[i];
        }
    }

    void writeIntsToFile(std::ofstream &ofs, int32_t ints[], int length) {
        char chars[length*sizeof(int32_t)];
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < sizeof(int32_t); j++) {
                chars[i*4+j] = getByte(ints[i], j);
            }
        }
        writeCharsToFile(ofs, chars, length*sizeof(int32_t));
    }

    void writeFloatsToFile(std::ofstream &ofs, float floats[], int length) {
        char chars[length*sizeof(float)];
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < sizeof(float); j++) {
                chars[i+j] = getByte(floats[i], j);
            }
        }
        writeCharsToFile(ofs, chars, length*sizeof(float));
    }

    void readCharsFromFile(std::ifstream &ifs, char chars[], int length) {
        unsigned char uchars[length];
        ifs >> uchars;
        for(int i = 0; i < length; i ++) {
            chars[i] = (char)uchars[i];
        }
    }

    void readIntsFromFile(std::ifstream &ifs, int32_t ints[], int length) {
        char chars[length*sizeof(int32_t)];
        readCharsFromFile(ifs, chars, length*sizeof(int32_t));
        for(int i = 0; i < length; i ++) {
            for(uint8_t j = 0; j < sizeof(int32_t); j ++) {
                ints[i] |= (uint8_t)chars[i*sizeof(int32_t)+j] << (j*8);
            }
        }
    }

    void readFloatsFromFile(std::ifstream &ifs, float floats[], int length) {

    }
}

#endif