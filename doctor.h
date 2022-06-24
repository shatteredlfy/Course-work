#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "person.h"
#include "person.cpp"


class Doctor : public Person
{
public:

    Doctor(std::string tmp_fn, std::string tmp_ln, int tmp_d, int tmp_m, int tmp_y, int tmp_h, int tmp_w, std::string tmp_em,
    std::string tmp_spec, int tmp_pc, int tmp_sal, int tmp_cat);

    ~Doctor();

    std::string getspec() const { return specialization; }
    int getcount() { return patientCount; }
    int getsalary() const { return salary; }
    int getcategory() const { return category; }
    int consPrice() const { return category*salary/16; }

    void consult()
    {
        ++patientCount;
    }


    void setspec(std::string tmp_spec) { specialization = tmp_spec; }
    void setcount(int tmp_pc) { patientCount = tmp_pc; }
    void setsalary(int tmp_sal) { salary = tmp_sal; }
    void setcategory(int tmp_cat) { category = tmp_cat; }

    virtual std::string Info() const override;

protected:
  void checkInfo() override;

private:
    std::string specialization;
    int patientCount;
    int salary;
    int category;
};
