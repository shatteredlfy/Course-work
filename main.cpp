#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include "people.h"
#include "people.cpp"
#include "person.h"
#include "person.cpp"
#include "doctor.h"
#include "doctor.cpp"
#include "electric.h"
#include "electric.cpp"

// Lab variant 24 / Work variant 15


int main()
{
    People doctors;
    People electrics;

    Person* person = nullptr;
    std::string firstname, lastname, email;
    int dateofbirth_d, dateofbirth_m, dateofbirth_y, weight, height;

    std::cout << "Welcome" << std::endl;
    while (true)
    {
        std::cout << "Choose your next step:" << std::endl;
        std::cout << "1. Add person."<< std::endl;
        std::cout << "2. Remove person."<< std::endl;
        std::cout << "3. Do something with people."<< std::endl;
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
                    std::cout << "0. Exit."<< std::endl;
                    std::cin >> num1;
                    system("cls");

                    switch (num1)
                    {
                        case 1: // add Doctor
                        {
                            std::string specialization;
                            int patientCount, salary, category;
                            std::cout << "Enter all fields for Doctor." << std::endl;
                            std::cout << "Firstname: ";
                            std::cin.ignore();
                            std::getline(std::cin, firstname);
                            std::cout << "Lastname: ";
                            std::getline(std::cin, lastname);
                            std::cout << "Date of birth (day month year): " << std::endl;
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
                            person = new Doctor(firstname, lastname, dateofbirth_d, dateofbirth_m, dateofbirth_y,
                              weight, height, email, specialization, patientCount, salary, category);
                            doctors.addPerson(person);
                            system("cls");
                            break;
                        }

                        case 2: // add Electric
                        {
                            int expirience, rank;
                            std::string object;
                            std::cout << "Enter all fields for Electrician." << std::endl;
                            std::cout << "Firstname: ";
                            std::cin.ignore();
                            std::getline(std::cin, firstname);
                            std::cout << "Lastname: ";
                            std::getline(std::cin, lastname);
                            std::cout << "Date of birth (day month year): " << std::endl;
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
                            std::cout << "Expirience: ";
                            std::cin >> expirience;
                            std::cout << "Rank: ";
                            std::cin >> rank;
                            std::cout << "Object: ";
                            std::getline(std::cin, object);
                            person = new Electric(firstname, lastname, dateofbirth_d, dateofbirth_m, dateofbirth_y,
                              weight, height, email, expirience, rank, object);
                            electrics.addPerson(person);
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
                   std::cin >> rem;
                   system("cls");
                   switch (rem)
                   {
                       case 1:
                       {
                       if(doctors.isEmpty() != true)
                       {
                           int position;
                           doctors.printPerson();
                           std::cout << "Choose position of doctor you want to remove: " << std::endl;
                           std::cin >> position;

                           doctors.removePerson(position);
                           system("cls");
                       }

                       else
                       {
                           std::cout << "There is no doctors here. " << std::endl;
                       }
                       break;
                       }

                       case 2:
                       {
                       if(electrics.isEmpty() != true)
                       {
                           int position;
                           electrics.printPerson();
                           std::cout << "Choose position of electricians you want to remove: " << std::endl;
                           std::cin >> position;

                           electrics.removePerson(position);
                           system("cls");
                       }

                       else
                       {
                           std::cout << "There is no electricians here. " << std::endl;
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
               }
               case 3:
               {
                   int d;
                   std::cout << "1. Print all available people." << std::endl;
                   std::cout << "2. ." << std::endl;
                   std::cout << "0. Exit."<< std::endl;
                   std::cin >> d;
                   system("cls");


                   switch (d)
                   {
                       case 1:
                       {
                           if(doctors.isEmpty() != true)
                           {
                               std::cout << "Doctors: " << std::endl;
                               doctors.printPerson();
                           }
                           else
                           {
                               std::cout << "There is no doctors here. " << std::endl;
                           }
                           if(electrics.isEmpty() != true)
                           {
                               std::cout << "Electricians: " << std::endl;
                               electrics.printPerson();
                           }
                           else
                           {
                               std::cout << "There is no electricians here. " << std::endl;
                           }
                           break;
                       }
                       case 2:
                       {

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
               }
               case 0:
               {
                   return 0;
               }
               default:
               {
                   std::cout << "Wrong command" << std::endl;
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
