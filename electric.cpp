#pragma once
#include <sstream>
#include "electric.h"
#include "person.h"

Electric::Electric(std::string tmp_fn, std::string tmp_ln, int tmp_d, 
    int tmp_m, int tmp_y, int tmp_h, int tmp_w, std::string tmp_em, 
    int tmp_exp, int tmp_rk) 

    : Person(tmp_fn, tmp_ln, tmp_d, tmp_m, tmp_y, tmp_h, tmp_w, tmp_em)
    , experience(tmp_exp)
    , rank(tmp_rk)
{
    checkInfo();
}

std::string Electric::Info() const
{
    std::stringstream ee;

    ee << "Name: " << getfname() << ' ' << getlname()
       << "\nBirthdate: " << getday() << '.' << getmonth() << '.' << getyear()
       << "\nHeight: " << getheight() << " Weight: " << getweight()
       << "\nEmail: " << getemail() << "\nExpirience: " 
       << std::to_string(experience)
       << "\nRank: " << std::to_string(rank) << '\n';

    return ee.str();
}

void Electric::checkInfo()
{
    Person::checkInfo();

    if(experience < 0 || experience > 40)
        throw std::invalid_argument("Error..\nExpirience can't be less than 0" 
            "and more than 40");

    if(rank < 0 || rank > 10)
        throw std::invalid_argument("Error..\nRank can't be less than 0" 
            "and more than 10");
}
