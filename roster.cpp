//include headers and libraries
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
    //On roster initialisation, user input is gathered to instantiate and aggregate employee objects
    Manager = manager(); //Create manager
    int inputted_ID; //ID entered by user
    std::string inputted_password; //Password entered by user
    int remaining_attempts = 4; //Remaining attempts to enter correct password
    char user_response; //'Y' or 'N' as requested from the user multiple times
    std::cout << "Please enter Manager ID: "; //Ask for manager's ID
    std::cin >> inputted_ID; //Read inputted ID from user
    while(inputted_ID != 1){ //If not the correct manager's ID
        std::cout << "Invalid Manager ID, please enter Manager ID: "; //request another attempt
        std::cin >> inputted_ID; //Read next attempt
    }
    std::cout << "Please enter Manager password: "; //Request user to input password
    std::cin >> inputted_password; //Read password from console
    while(inputted_password != Manager.get_password()){ //If input is not the correct password
        remaining_attempts--; //Reduce remaining password guesses
        if(remaining_attempts == 0){ //If out of guesses
            std::cout << "Too many incorrect guesses, closing app \n"; //Inform the user the app will be closed
            return; //Close app to prevent unauthorised access
        }
        std::cout << "Incorrect Password! " << remaining_attempts << " attempts remaining. \n"; //Inform user password entered was incorrect
        std::cout << "Please enter Manager password: "; //Ask for next attempt
        std::cin >> inputted_password; //read next attempt from console
        
        
    }
    std::cout << "Would you like to add employees? (Y/N): "; //Would the manager like to list employees?
    std::cin >> user_response; //Read user response from console
    while(user_response != 'Y' && user_response != 'N'){ //if invalid response
        std::cout << "Please enter Y (yes) or N (no): "; //request valid response
        std::cin >> user_response; //read next response from user
    }
    if(user_response == 'Y'){ //If user says yes
        input_employees(); //read in employee rosters
    }
    std::cout << "Would you like to add employee rosters? (Y/N): "; //Offer user to add employee rosters
    std::cin >> user_response; //read user response from console
    while(user_response != 'Y' && user_response != 'N'){ //if invalid response (this should be a seperate function but it created errors with cin)
        std::cout << "Please enter Y (yes) or N (no): "; //Ask for valid input
        std::cin >> user_response; //Read next attempt
    }
    if(user_response == 'Y'){ //If they indicate yes
        roster_employees(); //Roster employees
    }
    std::cout<<"Would you like like to change your name or password? Y/N: ";
    std::cin>>user_response;
    while(user_response != 'Y' && user_response != 'N'){ //if invalid response (this should be a seperate function but it created errors with cin)
        std::cout << "Please enter Y (yes) or N (no): "; //Ask for valid input
        std::cin >> user_response; //Read next attempt
    }
    if(user_response == 'Y'){ //If they indicate yes
    std::string newName;
    std::string newPassword;
    std::cout<<"What is your new name? ";
    std::cin>>newName;
    std::cout<<"What is your new password? ";
    std::cin>>newPassword;
    Manager.setNamePassword(newName, newPassword); //change name and passowrd
    }
    std::cout << "Thank you for using our not patented and not very good rostering system! Have a nice day :) \n"; //Goodbye message
}
void roster::roster_employees(){
    //this function allows the manager to make/update an employee's roster
    int employeeIndex; //index of employee addressed
    int inputted_id; //ID to be entered by manager
    bool employee_found = false; //Has the requested employee been located?
    employee* targetedEmployee; //Pointer to employee who's roster is being changed (example of upcasting)
    std::cout << "Please enter employee ID: "; //Ask user for target employee's numerical ID
    std::cin >> inputted_id; //read numerical ID from console
    if(inputted_id == Manager.id){ //if it is the manager
        targetedEmployee = &Manager; //Assign pointer to the manager
    }
    else{ //if it is not the manager
    for(employeeIndex = 0; employeeIndex < employeeCount; employeeIndex++){ //loop through all part time employee objects
        if(part_time_employees[employeeIndex].id == inputted_id){ //if correct ID
            employee_found = true; //employee has been found
            targetedEmployee = &part_time_employees[employeeIndex]; //Assign pointer to requested employee

            break; //exit loop to save computational time
        } 
    }}
    if(employee_found == false){ //if not one of the part time employees
        for(employeeIndex = 0; employeeIndex < ft_employeeCount; employeeIndex++){ //loop through all full time employees
            if(full_time_employees[employeeIndex].id == inputted_id){ //if object targeted is correct employee
                employee_found = true; //update bool to true
                targetedEmployee = &full_time_employees[employeeIndex]; //assign pointer to correct employee object
                break; //save computational time by exiting loop
            }
        }
    }
    if(employee_found == false){ //if the employee's ID is not listed
        std::cout << "Invalid ID, employee not found, please try again \n"; //ask manager to try again
        roster_employees(); //restart function
        return; //end function
    }
    std::cout << "Making " << targetedEmployee->firstName << "'s roster \n"; //Inform the manager who's roster they are changing
    
    char user_response; //for user response to input
    char user_response_2; //for user response to input
    for(int day = 0; day < 5; day++){ //loop through every day
        std::cout << "Would you like " << targetedEmployee->firstName << " to work on day " << day + 1 << "?(Y/N): "; //ask manager if employee is working that day
        std::cin >> user_response; //read user input from console
        while(user_response != 'Y' && user_response != 'N'){ //if not a valid response
            std::cout << "Please enter Y (yes) or N (no): "; //request valid response
            std::cin >> user_response; //read in next response
        };
        if(user_response == 'Y'){ //if yes
            for(int shift = 0; shift < 3; shift++){ //loop through every shift
                std::cout << "Would you like " << targetedEmployee->firstName << " to work during shift " << shift + 1 << "?(Y/N): "; //ask if employee should work this shift
                std::cin >> user_response_2; //read in user response and store it in user_response_2
                while(user_response_2 != 'Y' && user_response_2 != 'N'){ //if invalid input
                    std::cout << "Please enter Y (yes) or N (no): "; //request valid input
                    std::cin >> user_response_2; //read in next input
                }
                if(user_response_2 == 'Y'){ //if employee should work this shift
                    targetedEmployee->mySchedule.update_schedule(day, shift, 0); //Assign scheduled time to 0 (working)
                    std::cout << targetedEmployee->firstName << " Has been rostered on, make sure to notify them! \n"; //inform manager
                }
        
            }
        }
    }
    std::cout << targetedEmployee->firstName << "'s Roster is printed below, 1 means they are rostered off, 0 means they are rostered on! \n"; //explain the roster chart
    targetedEmployee->mySchedule.print_schedule(); //display the schedule
    std::cout << "Now checking " << targetedEmployee->firstName << "'s roster against their hour and shift requirements \n"; //check to see if shifts are allowable
    targetedEmployee->checkSchedule(); //check shifts against max hours and against unavailability
    std::cout << "Would you like to change any other employee's roster?(Y/N): "; //would they like to do more?
    std::cin >> user_response; //read user response
    while(user_response != 'Y' && user_response != 'N'){ //if invalid response
        //std::cout << "Please enter Y (yes) or N (no): "; //request valid response
        std::cin >> user_response; //read in next response
    }
    if(user_response == 'Y'){ //if they do want to roster another employee
        roster_employees(); //run function again
    }
    return; 


}
void roster::input_employees(){ 
    //this allows for the manager to input employee details via a text interface
    std::cout << "How many part time employees are there?: "; //used for size of dynamic array
    std::cin >> employeeCount; //read in employeeCount from console
    while(employeeCount < 0 || employeeCount > 3000){ //if too many or negative employeees, inform user (can't be assigning arbitrarily large arrays)
        if(employeeCount < 0){ //if negative employee count
            std::cout << "Please enter a number greater than or equal to 0: "; //request positive or 0 employee count
            std::cin >> employeeCount; //read in new input
        }else{ //this code will run only if employeeCount > 3000
            std::cout << "Too many employees, please consider a different software \n"; //politely tell user to get lost
            return; //end function
        }
    }

    std::string* names = new std::string[employeeCount]; //For storing employee names prior to assignment
    int* IDs = new int[employeeCount]; //for storing employee IDs prior to assignment
    int tempID; //for storing ID briefly
    int* max_hours = new int[employeeCount]; //for storing maximum hours
    int length = sizeof(IDs) / sizeof(*IDs); //length of IDs array 
    for(int i = 0; i < employeeCount; i++){ //for as many employees as requested
        std::cout << "Please enter employee number " << i + 1 << "'s first name: "; //request employee's name
        std::cin >> names[i]; //read in employee's name
        std::cout << "Please enter " << names[i] << "'s numerical ID: "; //request employee's ID number
        std::cin >> tempID; //read employee's ID number
        while(std::find(IDs,(IDs+length), tempID) != IDs + length){ //will continue until a unique ID is entered
                std::cout << "Invalid ID: Already in use \n"; //inform user ID is already used
                std::cout << "Please enter an unused ID: "; //request a unique ID
                std::cin >> tempID; //read in next attempt
        }
        IDs[i] = tempID; //assign tempID to IDs array
        std::cout << "How many hours a week can " << names[i] << " work?: "; //request max weekly hours of employee
        std::cin >> max_hours[i];
    }
    
    std::cout << "How many full time employees are there?: "; //ask for number of full time employees
    std::cin >> ft_employeeCount; //store entered number of employees in ft_employeeCount
    while(ft_employeeCount < 0 || ft_employeeCount > 3000){ //if too many or too few
        if(ft_employeeCount < 0){ //if negative employee count
            std::cout << "Please enter a number greater than or equal to 0: "; //request positive employee count
            std::cin >> ft_employeeCount; //read in next attempt
        }else{ //this code will only run if ft_employeeCount > 3000
            std::cout << "Too many employees, please consider a different software \n"; //politely tell user to get lost
            return;
        }
    }
    
    std::string* ft_names = new std::string[ft_employeeCount]; //array for full time employee's names
    int* ft_IDs = new int[ft_employeeCount]; //array for full time employee's ID numbers
    int ft_length = sizeof(ft_IDs) / sizeof(*ft_IDs); //length of ID array for use in verifying ID is unique
    for(int i = 0; i < ft_employeeCount; i++){ //loop for all requested employees
        std::cout << "Please enter employee number " << i + 1 << "'s first name: "; //request employee's name
        std::cin >> ft_names[i]; //read in employee's name
        std::cout << "Please enter " << ft_names[i] << "'s numerical ID: "; //request ID number
        std::cin >> tempID; //read in ID number
        while(std::find(IDs,(IDs+length), tempID) != IDs + length || std::find(ft_IDs,(ft_IDs+length), tempID) != ft_IDs + ft_length){ //if ID is already in use, keep looping until a unique one is entered
                std::cout << "Invalid ID: Already in use \n"; //inform user ID is in use
                std::cout << "Please enter an unused ID: "; //request a unique ID
                std::cin >> tempID; //read in next attempt
        }
        IDs[i] = tempID; //assign ID only once valid
    }
    
    part_time_employees = new partTimeEmployee[employeeCount]; //aggregate part time employees
    for(int i = 0; i < employeeCount; i++){ //for each part time employee
        part_time_employees[i].setData(names[i], max_hours[i], IDs[i]); //assign data gathered about employees

    }
    full_time_employees = new fullTimeEmployee[ft_employeeCount]; //dynamically allocate array of full time employees

    for(int i = 0; i < ft_employeeCount; i++){ //for each full time employee
        full_time_employees[i].setData(ft_names[i], IDs[i]); //assign identifying data
    }
    
    //good practice to free memory
    delete[] names;
    delete[] ft_names;
    delete[] IDs;
    delete[] ft_IDs;
    delete[] max_hours;
}
