#pragma once
#include <string>

class Electric : public Person
{
public:
    Electric(std::string tmp_fn, std::string tmp_ln, int tmp_d, int tmp_m, int tmp_y, int tmp_h, int tmp_w, std::string tmp_em,
    int tmp_exp, int rank, std::string object);

    ~Electric();

    int getExpirience() const { return expirience; }
    int getRank() const { return rank; }
    std::string getObject() const { return object; }

    void setfirstname(int tmp_exp) { expirience = tmp_exp; }
    void setlastname(int tmp_rk) { rank = tmp_rk; }
    void setlastname(std::string tmp_obj) { object = tmp_obj; }

    virtual std::string Info() const override;

protected:
    void checkInfo() override;

private:
    int expirience;
    int rank;
    std::string object;
};
