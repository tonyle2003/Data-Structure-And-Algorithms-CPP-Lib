#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <iostream>

using namespace std;

// class for WeightedActivity
class WeightedActivity {
    private:
        string name;
        int start_time;
        int finish_time;
        int profit;
        int accProf;
    public:
        bool operator < (WeightedActivity);
        friend istream& operator>>(istream&, WeightedActivity&);
        WeightedActivity();
        WeightedActivity(string, int, int, int);
        string getName();
        int getStartTime();
        int getFinishTime();
        int getProfit();
        int getAccProf();
        void setName(string);
        void setStartTime(int);
        void setFinishTime(int);
        void setProfit(int);
        void setAccProf(int);
};

// operator overloading of WeightedActivity class
bool WeightedActivity::operator<(WeightedActivity another) {
    return this->finish_time < another.finish_time;
}

istream& operator>>(istream& input, WeightedActivity& WeightedActivity) {
    input >> WeightedActivity.name;
    input >> WeightedActivity.start_time;
    input >> WeightedActivity.finish_time;
    input >> WeightedActivity.profit;
    WeightedActivity.accProf = WeightedActivity.profit;
    return input;
}

// constructor of WeightedActivity class
WeightedActivity::WeightedActivity() {
    this->name = "NULL";
    this->start_time = this->finish_time = this->profit = this->accProf = INT_MIN;
}

WeightedActivity::WeightedActivity(string name, int start_time, int finish_time, int profit) {
    this->name = name;
    this->start_time = start_time;
    this->finish_time = finish_time;
    this->profit = profit;
    this->accProf = profit;
}

// getter of WeightedActivity class
string WeightedActivity::getName() {
    return this->name;
}

int WeightedActivity::getStartTime() {
    return this->start_time;
}

int WeightedActivity::getFinishTime() {
    return this->finish_time;
}

int WeightedActivity::getProfit() {
    return this->profit;
}

int WeightedActivity::getAccProf() {
    return this->accProf;
}

// setter of WeightedActivity class
void WeightedActivity::setName(string name) {
    this->name = name;
}

void WeightedActivity::setStartTime(int start_time) {
    this->start_time = start_time;
}

void WeightedActivity::setFinishTime(int finish_time) {
    this->finish_time = finish_time;
}

void WeightedActivity::setProfit(int profit) {
    this->profit = profit;
}

void WeightedActivity::setAccProf(int profit) {
    this->accProf = profit;
}

// class to solve the problem Weighted WeightedActivity Selection
class WeightedWeightedActivitySelection {
    public:
        static int getMaxProfit(WeightedActivity*, int);
};

int WeightedWeightedActivitySelection::getMaxProfit(WeightedActivity* job, int size) {
    sort(job, job + size);
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (job[j].getFinishTime() <= job[i].getStartTime()) {
                if (job[j].getAccProf() + job[i].getProfit() > job[i].getAccProf()) {
                    job[i].setAccProf(job[j].getAccProf() + job[i].getProfit());
                }
            }
        }
    }
    int maxProfit = 0;
    for (int i = 0; i < size; i++) {
        if (maxProfit < job[i].getAccProf()) {
            maxProfit = job[i].getAccProf();
        }
    }
    return maxProfit;
}