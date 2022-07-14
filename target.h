#pragma once
#include <string>

class Target
{
public:
    Target(std::string tmp_name, int tmp_requiredRank, int tmp_requiredExp)
        : name(tmp_name)
        , RequiredRank(tmp_requiredRank)
        , RequiredExp(tmp_requiredExp)
    {

    }

    std::string getName() const { return name; }
    int getReqRank() const { return RequiredRank; }
    int getReqExp() const { return RequiredExp; }

private:
    std::string name;
    int RequiredRank;
    int RequiredExp;
};

