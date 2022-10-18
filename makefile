scheduler: schedule.h employee.h partTimeEmployee.h partTimeEmployee.h schedule.cpp employee.cpp partTimeEmployee.cpp partTimeEmployee.cpp main.cpp
	@g++ schedule.h employee.h partTimeEmployee.h partTimeEmployee.h schedule.cpp employee.cpp partTimeEmployee.cpp partTimeEmployee.cpp main.cpp -Wall -o scheduler
	@./scheduler
