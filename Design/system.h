#pragma once

class system
{
private:
	map<int, int> *personIdToMachineIdMap;
	map<int, Machine*> *machineIdToMachineMap;

	Machine getMachine(int machineId);

public:
	virtual Person *getPerson(int personId);
};
