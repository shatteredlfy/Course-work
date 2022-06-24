#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "electric.h"
#include "person.h"
#include "person.cpp"

Electric::Electric(std::string tmp_fn, std::string tmp_ln, int tmp_d, int tmp_m, int tmp_y, int tmp_h,
int tmp_w, std::string tmp_em, int tmp_exp, int tmp_rk, std::string tmp_obj) :

    Person(tmp_fn, tmp_ln, tmp_d, tmp_m, tmp_y, tmp_h, tmp_w, tmp_em),

    expirience(tmp_exp),
    rank(tmp_rk),
    object(tmp_obj)
{
    checkInfo();
}

std::string Electric::Info() const
{
    std::stringstream ee;

    ee << "Name: " << getfname() << ' ' << getlname()
       << "\nBirthdate: " << getday() << '.' << getmonth() << '.' << getyear()
       << "\nHeight: " << getheight() << " Weight: " << getweight()
       << "\nEmail: " << getemail() << "\nExpirience: " << std::to_string(expirience)
       << "\nRank" << std::to_string(rank) << "\nObject: " << object;

    return ee.str();
}

void Electric::checkInfo()
{
    Person::checkInfo();

    if(expirience < 0)
        throw std::invalid_argument("Error..\nExpirience can't be less than 0.");

    if(rank < 0)
        throw std::invalid_argument("Error..\nRank can't be less than 0.");
}
