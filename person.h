#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

class Person
{

public:

    Person(std::string tmp_fn, std::string tmp_ln, int tmp_d, int tmp_m, int tmp_y, int tmp_h, int tmp_w, std::string tmp_em);

    std::string getfname() const { return firstname; }
    std::string getlname() const { return lastname; }
    int getday() const { return dateofbirth_d; }
    int getmonth() const { return dateofbirth_m; }
    int getyear() const { return dateofbirth_y; }
    int getheight() const { return height; }
    int getweight() const { return weight; }
    std::string getemail() const { return email; }

    void setfirstname(std::string tmp_fn) { firstname = tmp_fn; }
    void setlastname(std::string tmp_ln) { lastname = tmp_ln; }
    void setday(int tmp_d) { dateofbirth_d = tmp_d; }
    void setmonth(int tmp_m) { dateofbirth_m = tmp_m; }
    void setyear(int tmp_y) { dateofbirth_y = tmp_y; }
    void setheight(int tmp_h) { height = tmp_h; }
    void setweight(int tmp_w) { weight = tmp_w; }
    void setemail(std::string tmp_em) { email = tmp_em; }

    void setnewemail(std::string new_em) { new_em = email; }

    virtual std::string Info() const;

    enum Type{
        doctor
        //electric
    };

    Type getType() const { return type; }

protected:
    virtual void checkInfo();

    Type type;

private:
    std::string firstname;
    std::string lastname;
    int dateofbirth_d;
    int dateofbirth_m;
    int dateofbirth_y;
    int height;
    int weight;
    std::string email;
};
