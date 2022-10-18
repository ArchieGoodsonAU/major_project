#include headers and libraries 
#include "manager.h"
#include "employee.h"
#include "roster.h"
#include "fullTimeEmployee.h"
#include <iostream>


manager::manager(std::string name){ 
    //Initialiser with set name
    
    salary = 70000; //Manager's salary
    this->firstName = name; //For that personal touch
    this->max_hours = 45; //Available for all 15 shifts
    this->id = 1; //Manager's ID
    this->password = "ArchieRocks"; //Used to gain access to program (My IRL password (Not really!)) 
}
manager::manager(){
    //Initialiser with default name
    salary = 70000; //Manager's salary
    this->firstName = "Marco"; //My bosses name as a default name
    this->max_hours = 45; //Available for all 15 shifts
    this->id = 1; //Manger's ID
    this->password = "ArchieRocks"; //Used to gain access to program
}
std::string manager::get_password(){
    return password; //As password is private, has to be retrieved through a public function
}
