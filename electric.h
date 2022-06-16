#pragma once
#include

class Electric
{
public:

    int getExpirience() const { return expirience; }
    int getRank() const { return rank; }

    void setfirstname(int m_exp) { expirience = m_exp; }
    void setlastname(int m_rk) { rank = m_rk; }

    bool objCheck()
    {
        if(object == "house" && rank < 2)
        {
            return false;
        }
        else if(object == "electriostation" && rank < 3)
        {
            return false;
        }
        else if(object == "highvoltagetower" && rank < 4)
        {
            return false;
        }
        else
        {
          std::cout << "unknown object" << std::endl;
        }
    }

    virtual std::string ElInfo()
    {
        return "Expirience: " + expirience
               "\nRank: " + rank
               "\nObject: " + object;
    }

    friend std::ostream& operator << (std::ostream &os, const Person &p);
    friend std::istream& operator >> (std::istream &is, Person &p);

private:
    int expirience;
    int rank;
    std::string object;
};
