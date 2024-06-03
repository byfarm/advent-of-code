#include <fstream>
#include <iostream>
#include <string>


bool checktrue(int green, int red, int blue);

int main() {
    std::ifstream inf{ "smpldata" };
    if (!inf)
        return -1;

    int sum = 0;
    while (inf) {
        std::string str;
        while (std::getline(inf, str)) {
            std::string strcpy = str;
            std::getline(str, ':');

            while (std::getline(str, ' '))


        }
    }
}



bool checktrue(int green, int red, int blue) {
    return (green <= 13 && red <= 12 && blue <= 14);
}
