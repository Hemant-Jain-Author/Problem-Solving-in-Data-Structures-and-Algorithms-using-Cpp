
class system
{
private:
    map<int, int> *personIdToMachineIdMap;
    map<int, Machine*> *machineIdToMachineMap;

    Machine getMachine(int machineId);

public:
    virtual Person *getPerson(int personId);
};

Person *system::getPerson(int personId)
{
    int machienId = personIdToMachienIdMap[personId];
    Machine *m = machineIdToMachineMap[machienId];
    return m->getPersonWithId(personId);
}
