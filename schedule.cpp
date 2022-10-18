#include <iostream>
#include "schedule.h"

schedule::schedule(){
    //default initialiser, initialise all shifts to unavailable/not working
    for(int day = 0; day < 5; day++){ //loop through each day
        for(int shift = 0; shift < 3; shift++){ //loop through each shift
            mySchedule[day][shift] = 1; //assign to 1 (not working)
        }
    }
}

void schedule::update_schedule(int day, int shift, int updatedAvail){
    mySchedule[day][shift] = updatedAvail; //updated required shift to desired value
}
void schedule::print_schedule(){
    //this function prints the schedule in a nice format to the console
    for(int day = 0; day < 5; day++){ //loop through each day
        std::cout << "Day " << day + 1 << ": "; //show day number
        for(int shift = 0; shift < 3; shift++){ // loop through each shift
            std::cout << mySchedule[day][shift] << " "; //display each shift
        }
        std::cout << std::endl; // new line
    }
}
