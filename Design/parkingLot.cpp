#include <unordered_map>

class parkingLot
{
private:
    std::unordered_map<int, Space*> unreservedMap;
    std::unordered_map<int, Space*> reservedMap;

public:
    virtual bool reserveSpace(Space);
    virtual int unreserveSpace(Space);
};

bool parkingLot::reserveSpace(Space)
{
    //It will find if there is space in the
    //unreserved map
    //If yes, then we will pick that element and
    //put into the reserved map with the current time value.
}

int parkingLot::unreserveSpace(Space)
{
    // It will find the entry in reserve map
    // if yes then we will pick that
    // Element and put into the unreserved map.
    // And return the charge units with the current time value.
}
