#pragma once
#include <string>
#include "person.h"
#include "target.h"

class Electric : public Person
{
public:
    Electric(std::string tmp_fn, std::string tmp_ln, int tmp_d, int tmp_m, 
    int tmp_y, int tmp_h, int tmp_w, std::string tmp_em,
    int tmp_exp, int rank);

    int getExperience() const { return experience; }
    int getRank() const { return rank; }
    Target* getTarget() { return target; }

    void setExperience(int tmp_exp) { experience = tmp_exp; }
    void setRank(int tmp_rk) { rank = tmp_rk; }
    void setTarget(Target* tmp_tg) { target = tmp_tg;  }

    virtual std::string Info() const override;

protected:
    void checkInfo() override;

private:
    int experience;
    int rank;
    Target* target;
};
