#pragma once
#include <vector>
#include "person.h"
#include "doctor.h"
//#include "electric.h"

class People
{
public:
    People() = default;
    ~People();

    void addPerson(Person* person);

    void removePerson(int pos);

    bool isEmpty() const;

    void printPerson() const;

    Person* getPerson(int pos) const;
    Person* editPerson(Person* person) const;

    int getAmount() const { return humans.size(); }

private:
    std::vector<Person*> humans;
};
