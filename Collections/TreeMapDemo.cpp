
#include <string>
#include <map>
#include <vector>
#include <iostream>

int main()
{
    // Create a hash map.
    std::map<std::string, int> tm;

    // Put elements into the map
    tm["Mason"] = 55;
    tm["Jacob"] = 77;
    tm["William"] = 99;
    tm["Alexander"] = 80;
    tm["Michae"] = 50;
    tm["Emma"] = 65;
    tm["Olivia"] = 77;
    tm["Sophia"] = 88;
    tm["Emily"] = 99;
    tm["Isabella"] = 100;

    std::cout << "Total number of students in class :: " << tm.size() << std::endl;
    for (auto key : tm)
    {
        std::cout << key.first << " score marks :" << tm[key.first] << std::endl;
    }

    std::cout << "Emma present in class :: " << (tm.find("Emma") != tm.end()) << std::endl;

    std::cout << "John present in class :: " << (tm.find("John") != tm.end()) << std::endl;
    tm.erase("Emma");
    std::cout << "Emma present in class :: " << (tm.find("Emma") != tm.end()) << std::endl;

}
