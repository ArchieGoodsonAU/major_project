//defensive programming
#ifndef SCHEDULE_H
#define SCHEDULE_H
class schedule{
    public:
    int mySchedule[5][3]; //2D array of all shifts across all days
    schedule(); //initialiser
    void update_schedule(int day, int shift, int updated_avail); //to update shift information
    void print_schedule(); //display shift roster
};
#endif
