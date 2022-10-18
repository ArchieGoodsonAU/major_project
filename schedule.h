#ifndef SCHEDULE_H
#define SCHEDULE_H
class schedule{
    public:
    int mySchedule[5][3];
    schedule();
    void update_schedule(int day, int shift, int updated_avail);
    void print_schedule();
};
#endif