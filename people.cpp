#pragma once
#include "people.h"
#include "person.h"
#include "person.cpp"
#include "doctor.h"
#include "doctor.cpp"
#include "electric.h"
#include "electric.cpp"

People::~People()
{
    for (auto person : humans)
    {
        delete person;
    }
}

void People::addPerson(Person* person)
{
    humans.push_back(person);
}

void People::removePerson(int pos)
{
    if(pos > humans.size() || pos <= 0)
        throw std::invalid_argument("Wrong position!");

    else
        humans.erase(humans.begin() + pos - 1);

}

bool People::isEmpty() const
{
    return humans.empty();
}

void People::printPerson() const
{
    int i = 1;
    for(auto person : humans){
        std::cout << i++ << " " << std::setprecision(2) << std::fixed << person->Info() << std::endl;
    }
}

Person* People::getPerson(int pos) const
{
    return humans[pos - 1];
}
