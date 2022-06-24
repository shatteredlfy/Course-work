#pragma once
#include <vector>
#include "person.h"
#include "person.cpp"
#include "doctor.h"
#include "doctor.cpp"
#include "electric.h"
#include "electric.cpp"

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
