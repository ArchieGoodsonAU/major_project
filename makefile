employee_test: schedule.h  employee.h partTimeEmployee.h fullTimeEmployee.h manager.h roster.h schedule.cpp employee.cpp partTimeEmployee.cpp fullTimeEmployee.cpp manager.cpp roster.cpp employee_tester.cpp
	@g++ -Wall schedule.h  employee.h partTimeEmployee.h fullTimeEmployee.h manager.h roster.h schedule.cpp employee.cpp partTimeEmployee.cpp fullTimeEmployee.cpp manager.cpp roster.cpp employee_tester.cpp -o tester.out
run_test: tester.out employee_testing.txt
	@./tester.out < employee_testing.txt
compile_main: schedule.h  employee.h partTimeEmployee.h fullTimeEmployee.h manager.h roster.h schedule.cpp employee.cpp partTimeEmployee.cpp fullTimeEmployee.cpp manager.cpp roster.cpp  main.cpp
	@g++ schedule.h  employee.h partTimeEmployee.h fullTimeEmployee.h manager.h roster.h schedule.cpp employee.cpp partTimeEmployee.cpp fullTimeEmployee.cpp manager.cpp roster.cpp  main.cpp -o yeet
run_main:
	@./yeet
more_test: schedule.h  employee.h partTimeEmployee.h fullTimeEmployee.h manager.h roster.h schedule.cpp employee.cpp partTimeEmployee.cpp fullTimeEmployee.cpp manager.cpp roster.cpp moreTesting.cpp
	@g++ -Wall schedule.h  employee.h partTimeEmployee.h fullTimeEmployee.h manager.h roster.h schedule.cpp employee.cpp partTimeEmployee.cpp fullTimeEmployee.cpp manager.cpp roster.cpp moreTesting.cpp -o testing.out
	@./testing.out