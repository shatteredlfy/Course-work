#pragma once
#include "person.h"

Person::Person(std::string tmp_fn, std::string tmp_ln, int tmp_d, int tmp_m, int tmp_y, int tmp_h, int tmp_w, std::string tmp_em ) :
    firstname(tmp_fn),
    lastname(tmp_ln),
    dateofbirth_d(tmp_d),
    dateofbirth_m(tmp_m),
    dateofbirth_y(tmp_y),
    height(tmp_h),
    weight(tmp_w),
    email(tmp_em)
{
    checkInfo();
}

std::string Person::Info() const
{
    std::stringstream pp;

    pp << "Name: " << firstname << ' ' << lastname
       << "\nBirthdate: " << dateofbirth_d << '.' <<  dateofbirth_m << '.' << dateofbirth_y
       << "\nHeight: " << height << " Weight: " << weight
       << "\nEmail: " << email;

    return pp.str();
}

void Person::checkInfo()
{
    if(dateofbirth_d <= 0 || dateofbirth_d > 31)
        throw std::invalid_argument("Error..\nDay of birth cannot be less than 0 and more than 31.");

    if(dateofbirth_m <= 0 || dateofbirth_m > 12)
        throw std::invalid_argument("Error..\nBirthmonth cannot be less than 0 and more than 12.");

    if(dateofbirth_y <= 0 || dateofbirth_y > 2022)
        throw std::invalid_argument("Error..\nBirthyear cannot be less than 0 and more than current year.");

    if(height <= 0)
        throw std::invalid_argument("Error..\nHeight cannot be so small.");

    if(weight <= 0)
        throw std::invalid_argument("Error..\nWeight cannot be so small.");
}
