// include headers and libraries
#include "manager.h"

#include <fstream>
#include <iostream>

#include "employee.h"
#include "fullTimeEmployee.h"
#include "roster.h"

/*manager::manager(std::string name) {
  // Initialiser with set name

  salary = 70000;                  // Manager's salary
  this->firstName = name;          // For that personal touch
  this->max_hours = 45;            // Available for all 15 shifts
  this->id = 1;                    // Manager's ID
  this->password = "ArchieRocks";  // Used to gain access to program (My IRL
                                   // password (Not really!))
}*/
manager::manager() {
  // Initialiser with default name
  salary = 70000;                  // Manager's salary
  this->firstName =  getName();       // My bosses name as a default name
  this->max_hours = 45;            // Available for all 15 shifts
  this->id = 1;                    // Manger's ID
  this->password =  getPassword();  // Used to gain access to program

}
std::string manager::get_password() {
  return password;  // As password is private, has to be retrieved through a
                    // public function
}

void manager::setNamePassword(std::string name, std::string password) {
  // open a temp file for editing
  std::ofstream managerInfo("managerInfo.txt");

  // check for errors
  if (managerInfo.is_open()) {
    // as file is wiped clean, input the new name first then throw in the old
    // password
    managerInfo << name << " " << password;
  } else {
    // error msg if file doesnt open
    std::cout << "Error Writing to File Try Again";
  }

  // After you are done with the file close it
  managerInfo.close();
}

std::string manager::getName() {
  std::ifstream input("managerInfo.txt");
  std::string name, password;
  while (input >> name >> password) {
  }
  return name;
}

std::string manager::getPassword() {
  std::ifstream input("managerInfo.txt");
  std::string name, password;
  while (input >> name >> password) {
  }
  return password;
}