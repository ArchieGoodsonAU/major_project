#include <iostream>
#include "fullTimeEmployee.h"
#include "partTimeEmployee.h"
#include "employee.h"
#include "schedule.h"
#include "roster.h"
#include "manager.h"
#include <vector>
#include <algorithm>

roster::roster(void){
    manager Manager("Mark");
    int inputted_ID;
    std::string inputted_password;
    int remaining_attempts = 4;
    std::cout << "Please enter Manager ID: ";
    std::cin >> inputted_ID;
    char user_response;
    while(inputted_ID != 1){
        std::cout << "Invalid Manager ID, please enter Manager ID: ";
    }
    std::cout << "Please enter Manager password: ";
    std::cin >> inputted_password;
    while(inputted_password != Manager.get_password()){
        remaining_attempts--;
        if(remaining_attempts == 0){
            std::cout << "Too many incorrect guesses, closing app \n";
            return;
        }
        std::cout << "Incorrect Password! " << remaining_attempts << " attempts remaining. \n";
        std::cout << "Please enter Manager password: ";
        std::cin >> inputted_password;
        
        
    }
    std::cout << "Would you like to add employees? (Y/N): ";
    std::cin >> user_response;
    while(user_response != 'Y' && user_response != 'N'){
        std::cout << "Please enter Y (yes) or N (no): ";
        std::cin >> user_response;
    }
    if(user_response == 'Y'){
        input_employees();
    }

}

void roster::input_employees(){
    int employeeCount;
    std::cout << "How many part time employees are there?: ";
    std::cin >> employeeCount;
    while(employeeCount < 0 || employeeCount > 3000){
        if(employeeCount < 0){
            std::cout << "Please enter a number greater than or equal to 0: ";
            std::cin >> employeeCount;
        }else{
            std::cout << "Too many employees, please consider a different software \n";
            return;
        }
    }

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
    while(ft_employeeCount < 0 || ft_employeeCount > 3000){
        if(ft_employeeCount < 0){
            std::cout << "Please enter a number greater than or equal to 0: ";
            std::cin >> ft_employeeCount;
        }else{
            std::cout << "Too many employees, please consider a different software \n";
            return;
        }
    }
    std::string* ft_names = new std::string[ft_employeeCount];
    int* ft_IDs = new int[ft_employeeCount];
    int ft_length = sizeof(ft_IDs) / sizeof(*ft_IDs);
    for(int i = 0; i < ft_employeeCount; i++){
        std::cout << "Please enter employee number " << i + 1 << "'s first name: ";
        std::cin >> ft_names[i];
        std::cout << "Please enter " << ft_names[i] << "'s numerical ID: ";
        std::cin >> tempID;
        while(std::find(IDs,(IDs+length), tempID) != IDs + length || std::find(ft_IDs,(ft_IDs+length), tempID) != ft_IDs + ft_length){
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
    delete[] names;
    delete[] ft_names;
    delete[] IDs;
    delete[] ft_IDs;
    delete[] max_hours;
    delete[] employees;
    delete[] fullTimeEmployees;
}