#include <type_traits>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename X>
class Activity {

    static_assert(
        is_integral<X>::value
        && !is_same<X, char>::value
        && !is_same<X, bool>::value,
        "Error data type."
    );

    private:
        X index;
        X start_time;
        X finish_time;

    public:
        friend istream& operator >> (istream&, Activity<X>&);
        friend ostream& operator << (ostream&, Activity<X>);
        bool operator < (Activity<X>);
        Activity();
        Activity(X, X, X);
        X getIndex();
        X getStartTime();
        X getFinishTime();
        void setIndex(X);
        void setStartTime(X);
        void setFinishTime(X);
};

template<typename X>
istream& operator >> (istream& input, Activity<X>& activity) {

    static_assert(
        is_integral<X>::value
        && !is_same<X, char>::value
        && !is_same<X, bool>::value,
        "Error data type."
    );

    input >> activity.index >> activity.start_time >> activity.finish_time;
    return input;
}

template<typename X>
ostream& operator << (ostream& output, Activity<X> activity) {

    static_assert(
        is_integral<X>::value
        && !is_same<X, char>::value
        && !is_same<X, bool>::value,
        "Error data type."
    );

    output << activity.index << " " << activity.start_time << " " << activity.finish_time << endl;
    return output;
}

template<typename X>
bool Activity<X>::operator < (Activity<X> activity) {
    return this->finish_time < activity.finish_time;
}

template<typename X>
Activity<X>::Activity() {
    this->index = -1;
    this->start_time = -1;
    this->finish_time = -1;
}

template<typename X>
Activity<X>::Activity(X index, X start_time, X finish_time) {
    this->index = index;
    this->start_time = start_time;
    this->finish_time = finish_time;
}

template<typename X>
X Activity<X>::getIndex() {
    return this->index;
}

template<typename X>
X Activity<X>::getStartTime() {
    return this->start_time;
}

template<typename X>
X Activity<X>::getFinishTime() {
    return this->finish_time;
}

template<typename X>
void Activity<X>::setIndex(X index) {
    this->index = index;
}

template<typename X>
void Activity<X>::setStartTime(X start_time) {
    this->start_time = start_time;
}

template<typename X>
void Activity<X>::setFinishTime(X finish_time) {
    this->finish_time = finish_time;
}