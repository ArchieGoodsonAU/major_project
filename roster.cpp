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
    Manager = manager("Marco");
    int inputted_ID;
    std::string inputted_password;
    int remaining_attempts = 4;
    char user_response;
    std::cout << "Please enter Manager ID: ";
    std::cin >> inputted_ID;
    while(inputted_ID != 1){
        std::cout << "Invalid Manager ID, please enter Manager ID: ";
        std::cin >> inputted_ID;
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
    std::cout << "Would you like to add employee rosters? (Y/N): ";
    std::cin >> user_response;
    while(user_response != 'Y' && user_response != 'N'){
        std::cout << "Please enter Y (yes) or N (no): ";
        std::cin >> user_response;
    }
    if(user_response == 'Y'){
        roster_employees();
    }
    std::cout << "Thank you for using our not patented and not very good rostering system! Have a nice day :) \n";
}
void roster::roster_employees(){
    int employeeIndex;
    int inputted_id;
    bool employee_found = false;
    employee* targetedEmployee;
    std::cout << "Please enter employee ID: ";
    std::cin >> inputted_id;
    if(inputted_id == Manager.id){
        targetedEmployee = &Manager;
    }
    else{
    for(employeeIndex = 0; employeeIndex < employeeCount; employeeIndex++){
        if(part_time_employees[employeeIndex].id == inputted_id){
            employee_found = true;
            targetedEmployee = &part_time_employees[employeeIndex];

            break;
        }
    }}
    if(employee_found == false){
        for(employeeIndex = 0; employeeIndex < ft_employeeCount; employeeIndex++){
            if(full_time_employees[employeeIndex].id == inputted_id){
                employee_found = true;
                targetedEmployee = &full_time_employees[employeeIndex];
                break;
            }
        }
    }
    std::cout << "Making " << targetedEmployee->firstName << "'s roster \n";
    
    char user_response;
    char user_response_2;
    for(int day = 0; day < 5; day++){
        std::cout << "Would you like " << targetedEmployee->firstName << " to work on day " << day + 1 << "?(Y/N): ";
        std::cin >> user_response;
        while(user_response != 'Y' && user_response != 'N'){
            std::cout << "Please enter Y (yes) or N (no): ";
            std::cin >> user_response;
        };
        if(user_response == 'Y'){
            for(int shift = 0; shift < 3; shift++){
                std::cout << "Would you like " << targetedEmployee->firstName << " to work during shift " << shift + 1 << "?(Y/N): ";
                std::cin >> user_response_2;
                while(user_response_2 != 'Y' && user_response_2 != 'N'){
                    std::cout << "Please enter Y (yes) or N (no): ";
                    std::cin >> user_response_2;
                }
                if(user_response_2 == 'Y'){
                    targetedEmployee->mySchedule.update_schedule(day, shift, 0); //Roster on
                    std::cout << targetedEmployee->firstName << " Has been rostered on, make sure to notify them! \n";
                }
        
            }
        }
    }
    std::cout << targetedEmployee->firstName << "'s Roster is printed below, 1 means they are rostered off, 0 means they are rostered on! \n";
    targetedEmployee->mySchedule.print_schedule();
    std::cout << "Now checking " << targetedEmployee->firstName << "'s roster against their hour and shift requirements \n";
    targetedEmployee->checkSchedule();
    std::cout << "Would you like to change any other employee's roster?(Y/N): ";
    std::cin >> user_response;
    while(user_response != 'Y' && user_response != 'N'){
        //std::cout << "Please enter Y (yes) or N (no): ";
        std::cin >> user_response;
    }
    if(user_response == 'Y'){
        roster_employees();
    }
    return;


}
void roster::input_employees(){
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
    
    part_time_employees = new partTimeEmployee[employeeCount];
    for(int i = 0; i < employeeCount; i++){
        part_time_employees[i].setData(names[i], max_hours[i], IDs[i]);

    }
    full_time_employees = new fullTimeEmployee[ft_employeeCount];

    for(int i = 0; i < ft_employeeCount; i++){
        full_time_employees[i].setData(ft_names[i], IDs[i]);
    }
    
    //schedule randomSchedule;
    //part_time_employees[0].checkSchedule(randomSchedule);
    delete[] names;
    delete[] ft_names;
    delete[] IDs;
    delete[] ft_IDs;
    delete[] max_hours;
}
