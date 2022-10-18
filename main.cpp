#include <iostream>
#include "fullTimeEmployee.h"
#include "partTimeEmployee.h"
#include "employee.h"
#include "schedule.h"
#include <vector>
#include <algorithm>
int main(void){
    int employeeCount = 5;
    std::cout << "How many part time employees are there?: ";
    std::cin >> employeeCount;
    std::string* names = new std::string[employeeCount];
    int* IDs = new int[employeeCount];
    int tempID;
    int* max_hours = new int[employeeCount];
    int length = sizeof(IDs) / sizeof(*IDs);
    for(int i = 0; i < employeeCount; i++){
        std::cout << "Please enter employee number " << i + 1 << "'s first name: ";
        std::cin >> names[i];
        std::cout << "Please enter " << names[i] << "'s numerical ID: ";
        std::cin >> tempID;
        while(std::find(IDs,(IDs+length), tempID) != IDs + length){
                std::cout << "Invalid ID: Already in use \n";
                std::cout << "Please enter an unused ID: ";
                std::cin >> tempID;
        }
        IDs[i] = tempID;
        std::cout << "How many hours a week can " << names[i] << " work?: ";
        std::cin >> max_hours[i];
    }
    int ft_employeeCount;
    std::cout << "How many full time employees are there?: ";
    std::cin >> ft_employeeCount;
    std::string* ft_names = new std::string[employeeCount];
    int* ft_IDs = new int[employeeCount];
    length = sizeof(ft_IDs) / sizeof(*ft_IDs);
    for(int i = 0; i < ft_employeeCount; i++){
        std::cout << "Please enter employee number " << i + 1 << "'s first name: ";
        std::cin >> ft_names[i];
        std::cout << "Please enter " << names[i] << "'s numerical ID: ";
        std::cin >> tempID;
        while(std::find(IDs,(IDs+length), tempID) != IDs + length || (ft_IDs,(ft_IDs+length), tempID) != ft_IDs + length){
                std::cout << "Invalid ID: Already in use \n";
                std::cout << "Please enter an unused ID: ";
                std::cin >> tempID;
        }
        IDs[i] = tempID;
    }
    
    partTimeEmployee* employees = new partTimeEmployee[employeeCount];
    for(int i = 0; i < employeeCount; i++){
        employees[i].setData(names[i], 38, IDs[i]);
    }
    fullTimeEmployee* fullTimeEmployees = new fullTimeEmployee[ft_employeeCount];
    //t = partTimeEmployee(names[1], 38, IDs[1]);

    for(int i = 0; i < ft_employeeCount; i++){
        fullTimeEmployees[i].setData(names[i], IDs[i]);
    }
    employees[0].call_of(1, 2);
    std::cout << employees[0].id;

    delete[] employees;
    delete[] fullTimeEmployees;
}