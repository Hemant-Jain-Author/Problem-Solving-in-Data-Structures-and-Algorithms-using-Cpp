#include "system.h"

Person *system::getPerson(int personId)
{
	int machienId = personIdToMachienIdMap[personId];
	Machine *m = machineIdToMachineMap[machienId];
	return m->getPersonWithId(personId);
}
