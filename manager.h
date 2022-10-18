//Include libraries and header files
#include <iostream>
#include "employee.h"
#include "fullTimeEmployee.h"

//Defensive programming
#ifndef MANAGER_H
#define MANAGER_H
class manager : public fullTimeEmployee {
 //Third level of inheritence, inherits from fullTimeEmployee as manager is a fullTimeEmployee with added responsibilities/access
 public:
  int ID; //Numerical ID
  //manager(std::string name); //Initialiser with name
  manager(); //Initialiser without name
  void setNamePassword(std::string name, std::string password);
  std::string getName();
  std::string getPassword();
  std::string get_password(); //Returns password

 private:
  std::string password; //Password for access to app
};
#endif
