#pragma once

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
