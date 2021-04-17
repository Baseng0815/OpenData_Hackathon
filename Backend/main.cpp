#include <iostream>
#include <fstream>
#include <string>

const std::string filename = "N50E008.hgt";
uint16_t* data;
int size[2] = {3601, 3601};

uint16_t swapBytes(uint16_t number)  {
    uint8_t lower = number & 0x00ff;
    uint8_t higher = (number & 0xff00) >> 8;

    return higher | (lower << 8);
}

uint16_t* readData(const std::string& filename) {
    std::ifstream file = std::ifstream(filename);

}

uint_16_t getHeight(int lat, int lon) {

}

int main(int, char**) {
    data = readData(filename);
}
