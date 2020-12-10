#include "CountMap.h"

int main()
{
    CountMap<int> *cm = new CountMap<int>();
    cm->add(2);
    cm->add(2);
    cm->remove(2);
    std::cout << "count is : " << cm->get(2) << std::endl;
    std::cout << "count is : " << cm->get(3) << std::endl;
    return 0;
}
/*
count is : 1
count is : 0
*/