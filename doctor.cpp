#pragma once
#include "doctor.h"
#include "person.h"
#include "person.cpp"

Doctor::Doctor(std::string tmp_fn, std::string tmp_ln, int tmp_d, int tmp_m, int tmp_y, int tmp_h, int tmp_w, std::string tmp_em,
std::string tmp_spec, int tmp_pc, int tmp_sal, int tmp_cat) :

    Person(tmp_fn, tmp_ln, tmp_d, tmp_m, tmp_y, tmp_h, tmp_w, tmp_em),

    specialization(tmp_spec),
    patientCount(tmp_pc),
    salary(tmp_sal),
    category(tmp_cat)
{
    checkInfo();
}

std::string Doctor::Info() const
{
  /*  return "Name: " + getfname() + ' ' + getlname()
       + "\nBirthdate: " + getday() + '.' +  getmonth() + '.' + getyear()
       + "\nHeight: " + getheight() + " Weight: " + getweight()
       + "\nEmail: " + getemail() + "\nSpecification: " + specialization
       + "\nCount of patients: " + std::to_string(patientCount)
       + "\nSalary: " + std::to_string(salary)
       + "\nCategory: " + std::to_string(category)
       + "\nConsultation price: " + std::to_string(consPrice());*/

       std::stringstream dd;

       dd << "Name: " << getfname() << ' ' << getlname()
          << "\nBirthdate: " << getday() << '.' << getmonth() << '.' << getyear()
          << "\nHeight: " << getheight() << " Weight: " << getweight()
          << "\nEmail: " << getemail() << "\nSpecification: " << specialization
          << "\nCount of patients: " << std::to_string(patientCount)
          << "\nSalary: " << std::to_string(salary)
          << "\nCategory: " << std::to_string(category)
          << "\nConsultation price: " << std::to_string(consPrice());

       return dd.str();
}

void Doctor::checkInfo()
{
    Person::checkInfo();

    if(patientCount < 0)
        throw std::invalid_argument("Error..\nNumber of patients can't be equal or less than 0.");

    if(salary < 0)
        throw std::invalid_argument("Error..\nSalary can't be less than 0.");
}
