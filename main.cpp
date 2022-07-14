#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <algorithm>
#include "person.h"
#include "doctor.h"
#include "electric.h"

// Lab variant 24 / Work variant 15

void printDoctors(std::vector<Doctor*> people)
{
    int i = 1;
    for(auto person : people)
    {
        std::cout << i++ << " " << std::setprecision(2) << std::fixed 
            << person->Info() << std::endl;
    }
}
void printElectric(Electric* e)
{

}
void printElectrics(std::vector<Electric*> people)
{
    int i = 1;
    for (auto person : people)
    {
        std::cout << i++ << " " << std::setprecision(2) << std::fixed 
            << person->Info() << std::endl;
    }
}

void printTargets(std::vector<Target*> targets)
{
    int i = 1;
    for (Target* target : targets)
    {
        std::cout << i++ << ". Name: " << target->getName() 
            << "\nRequired rank: " << target->getReqRank() 
            << "\nRequired experience: " << target->getReqExp() << std::endl;
    }
}

int main()
{
    std::vector<Doctor*> doctors;
    std::vector<Electric*> electrics;

    std::vector<Target*> targets =
    {
        new Target("House", 1, 2),
        new Target("School", 2, 4),
        new Target("Factory", 2, 6),
        new Target("High voltage station", 3, 8)
    };


    std::string firstname, lastname, email;
    int dateofbirth_d, dateofbirth_m, dateofbirth_y, weight, height;

    std::cout << "Welcome" << std::endl;
    while (true)
    {
        std::cout << "Choose your next step:" << std::endl;
        std::cout << "1. Add person."<< std::endl;
        std::cout << "2. Remove person."<< std::endl;
        std::cout << "3. Print all avaliable people."<< std::endl;
        std::cout << "Doctors:" << std::endl;
        std::cout << "4. Consultation." << std::endl;
        std::cout << "5. Sort by consultation price." << std::endl;
        std::cout << "Electricians:" << std::endl;
        std::cout << "6. Set new target." << std::endl;
        std::cout << "7. Sort by target." << std::endl;
        std::cout << "0. Exit."<< std::endl;
        int num;
        std::cin >> num;
        system("cls");

        try
        {
            bool exit = false;
            switch (num)
            {
                case 1:  // add person
                {
                    int num1;
                    std::cout << "1. Doctor." << std::endl;
                    std::cout << "2. Electric." << std::endl;
                    std::cout << "0. Exit." << std::endl;
                    std::cin >> num1;
                    system("cls");

                    switch (num1)
                    {
                    case 1: // add Doctor
                    {
                        std::string specialization;
                        int patientCount, salary, category;
                        std::cout << "Enter all fields for Doctor."
                            << std::endl;
                        std::cout << "Firstname: ";
                        std::cin.ignore();
                        std::getline(std::cin, firstname);
                        std::cout << "Lastname: ";
                        std::getline(std::cin, lastname);
                        std::cout << "Date of birth (day month year): "
                            << std::endl;
                        std::cin >> dateofbirth_d;
                        std::cin >> dateofbirth_m;
                        std::cin >> dateofbirth_y;
                        std::cout << "Weight (in kg): ";
                        std::cin >> weight;
                        std::cout << "Height (in cm): ";
                        std::cin >> height;
                        std::cout << "Email: ";
                        std::cin.ignore();
                        std::getline(std::cin, email);
                        std::cout << "Specialization: ";
                        std::getline(std::cin, specialization);
                        std::cout << "Patientcount: ";
                        std::cin >> patientCount;
                        std::cout << "Salary: ";
                        std::cin >> salary;
                        std::cout << "Category: ";
                        std::cin >> category;
                        doctors.emplace_back(new Doctor(firstname, lastname,
                            dateofbirth_d, dateofbirth_m, dateofbirth_y,
                            weight, height, email, specialization, patientCount,
                            salary, category));
                        system("cls");
                        break;
                    }

                    case 2: // add Electric
                    {
                        int experience, rank;
                        std::cout << "Enter all fields for Electrician."
                            << std::endl;
                        std::cout << "Firstname: ";
                        std::cin.ignore();
                        std::getline(std::cin, firstname);
                        std::cout << "Lastname: ";
                        std::getline(std::cin, lastname);
                        std::cout << "Date of birth (day month year): "
                            << std::endl;
                        std::cin >> dateofbirth_d;
                        std::cin >> dateofbirth_m;
                        std::cin >> dateofbirth_y;
                        std::cout << "Weight (in kg): ";
                        std::cin >> weight;
                        std::cout << "Height (in cm): ";
                        std::cin >> height;
                        std::cout << "Email: ";
                        std::cin.ignore();
                        std::getline(std::cin, email);
                        std::cout << "Experience: ";
                        std::cin >> experience;
                        std::cout << "Rank: ";
                        std::cin >> rank;
                        electrics.emplace_back(new Electric(firstname,
                            lastname, dateofbirth_d, dateofbirth_m, dateofbirth_y,
                            weight, height, email, experience, rank));
                        system("cls");
                        break;
                    }
                    case 0:
                    {
                        break;
                    }
                    default:
                    {
                        std::cout << "Wrong command" << std::endl;
                        break;
                    }
                    }
                    break;
                }
                case 2: // Remove person
                {
                    int rem;
                    std::cout << "1. Doctor." << std::endl;
                    std::cout << "2. Electric." << std::endl;
                    std::cout << "0. Exit." << std::endl;
                    std::cin >> rem;
                    system("cls");
                    switch (rem)
                    {
                    case 1: // rem doc
                    {
                        if (!doctors.empty())
                        {
                            int position;
                            printDoctors(doctors);
                            std::cout << "Choose position of doctor you "
                                "want to remove : " << std::endl;
                            std::cin >> position;
                            position--;
                            if (position >= doctors.size() && position < 0)
                                throw std::invalid_argument("Error...");

                            doctors.erase(doctors.begin() + position);
                            system("cls");
                        }

                        else
                        {
                            std::cout << "There is no doctors here. "
                                << std::endl;
                        }
                        break;
                    }

                    case 2: // rem electric
                    {
                        if (!electrics.empty())
                        {
                            int position;
                            printElectrics(electrics);
                            std::cout << "Choose position of electric you "
                                "want to remove : " << std::endl;
                            std::cin >> position;
                            position--;
                            if (position >= electrics.size() && position < 0)
                            {
                                throw std::invalid_argument("Error...");
                            }
                            
                            electrics.erase(
                                electrics.begin() + position);
                            system("cls");
                        }

                        else
                        {
                            std::cout << "There is no electricians here. "
                                << std::endl;
                        }
                        break;
                    }

                    case 0:
                    {
                        break;
                    }
                    default:
                    {
                        std::cout << "Wrong command" << std::endl;
                        break;
                    }
                    }
                    break;
                }
                case 3:
                {
                    if (!doctors.empty())
                    {
                        printDoctors(doctors);
                    }

                    else
                    {
                        std::cout << "There is no doctors here. " << std::endl;
                    }
                    if (!electrics.empty())
                    {
                        printElectrics(electrics);
                    }

                    else
                    {
                        std::cout << "There is no electricians here. "
                            << std::endl;
                    }
                    break;


                case 4:
                {

                    if (!doctors.empty())
                    {

                        printDoctors(doctors);

                        int position = 0;
                        std::cout << "0. Exit\nEnter: ";
                        std::cin >> position;
                        position--;
                        if (position >= doctors.size() && position < 0)
                            throw std::invalid_argument("Error...");

                        doctors[position]->consult();     
                        system("cls");
                    }
                    else
                        std::cout << "There is no doctors here." << std::endl;
                    break;
                }

                case 5:
                {
                    if (!doctors.empty())
                    {
                        std::sort(doctors.begin(), doctors.end(),
                            [](Doctor* lhs, Doctor* rhs) {
                                return lhs->consPrice() < rhs->consPrice();
                            });
                        printDoctors(doctors);
                    }
                    else
                        std::cout << "There is no doctors here." << std::endl;
                    break;
                }
                case 6:
                {
                    if (!electrics.empty())
                    {
                        int pos1, pos2;
                        printElectrics(electrics);
                        std::cout << "Choose position of electric you "
                            "want to give a target to: " << std::endl;
                        std::cin >> pos1;
                        pos1--;
                        if (pos1 >= electrics.size() && pos1 < 0)
                            throw std::invalid_argument("Error...");

                        printTargets(targets);
                        std::cout << "Choose target you want "
                            "to give this electrician: " << std::endl;
                        std::cin >> pos2;
                        pos2--;
                        if (pos2 >= targets.size() && pos2 < 0)
                            throw std::invalid_argument("Error...");

                        Electric* e = electrics[pos1];
                        Target* t = targets[pos2];
                        if(e->getRank() < t->getReqRank() ||
                           e->getExperience() < t->getReqRank())
                            throw std::invalid_argument("Error...");

                        e->setTarget(t);

                    }
                    else
                        std::cout << "There is no electricians here." << std::endl;
                    break;   
                }
                case 7:
                {
                    int position;
                    printTargets(targets);
                    std::cout << "Choose target you want to check who can "
                        "work on it: ";
                    std::cin >> position;
                    position--;
                    if (position >= electrics.size() && position < 0)
                        throw std::invalid_argument("Error...");

                    for (int i = 0; i < electrics.size(); ++i) 
                    {
                        if (electrics[i]->getTarget() == targets[position])
                            std::cout << electrics[i]->Info();
                    }
                    break;
                }
                case 0:
                {
                    exit = true;
                    break;
                }
                default:
                {
                    std::cout << "Wrong command" << std::endl;
                    break;
                }
                }
                if (exit)
                {
                    break;
                }
            }
        }
        catch (const std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
        }
    }
    return 0;
}
