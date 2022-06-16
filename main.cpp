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

// Lab variant 24 / Work variant 15


int main()
{
    People people;
    Person* person = nullptr;
    std::string firstname, lastname, email;
    int dateofbirth_d, dateofbirt_m, dateofbirt_y, weight, height;
    while (true)
    {
        std::cout << "Welcome" << std::endl;
        std::cout << "Choose your next step:" << std::endl;
        std::cout << "1. Add person."<< std::endl;
        std::cout << "2. Remove person."<< std::endl;
        std::cout << "3. Print all available people."<< std::endl;
        std::cout << "0. Exit."<< std::endl;
        int num;
        std::cin >> num;
        system("cls");

        try
        {
            bool exit = false;
            switch (num)
            {
                case 1:  // Add person
                {
                    int num1;
                    std::cout << "1. Doctor." << std::endl;
                    std::cout << "2. Electric." << std::endl;
                    std::cin >> num1;
                    system("cls");
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
