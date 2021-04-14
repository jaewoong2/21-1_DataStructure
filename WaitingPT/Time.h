//
// Created by 82109 on 2021-03-17.
//

#ifndef WAITINGPT_TIME_H
#define WAITINGPT_TIME_H

class Time {
public:
    void readTime(bool & errorFlag);
    int subtractTimes(Time t);

private:
    int minutes;
};


#endif //WAITINGPT_TIME_H
