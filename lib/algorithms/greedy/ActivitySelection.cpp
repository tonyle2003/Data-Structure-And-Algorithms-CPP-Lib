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
        template<typename Y>
        friend istream& operator >> (istream&, Activity<Y>&);
        template<typename Y>
        friend ostream& operator << (ostream&, const Activity<Y>&);
        bool operator < (const Activity<X>&) const;
        Activity();
        Activity(X, X, X);
        X getIndex() const;
        X getStartTime() const;
        X getFinishTime() const;
        void setIndex(X);
        void setStartTime(X);
        void setFinishTime(X);
};

template<typename Y>
istream& operator >> (istream& input, Activity<Y>& activity) {

    static_assert(
        is_integral<Y>::value
        && !is_same<Y, char>::value
        && !is_same<Y, bool>::value,
        "Error data type."
    );

    input >> activity.index >> activity.start_time >> activity.finish_time;
    return input;
}

template<typename Y>
ostream& operator << (ostream& output, const Activity<Y>& activity) {

    static_assert(
        is_integral<Y>::value
        && !is_same<Y, char>::value
        && !is_same<Y, bool>::value,
        "Error data type."
    );

    output << activity.index << " " << activity.start_time << " " << activity.finish_time << endl;
    return output;
}

template<typename X>
bool Activity<X>::operator < (const Activity<X>& activity) const {
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
X Activity<X>::getIndex() const {
    return this->index;
}

template<typename X>
X Activity<X>::getStartTime() const {
    return this->start_time;
}

template<typename X>
X Activity<X>::getFinishTime() const {
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

template<typename T>
class ActivitySelection {

    static_assert(
        is_integral<T>::value
        && !is_same<T, char>::value
        && !is_same<T, bool>::value,
        "Error data type."
    );

    public:
        static void selectedActivities(Activity<T>*, T);
        static T getMaxActivities(Activity<T>*, T);
};

template<typename T>
void ActivitySelection<T>::selectedActivities(Activity<T>* activity, T size) {
    sort(activity, activity + size);
    T i, j;
    i = 0;
    cout << activity[i].getIndex() << " ";
    for (j = 1; j < size; j++) {
        if (activity[j].getStartTime() >= activity[i].getFinishTime()) {
            cout << activity[j].getIndex() << " ";
            i = j;
        }
    }
    cout << endl;
}

template<typename T>
T ActivitySelection<T>::getMaxActivities(Activity<T>* activity, T size) {
    sort(activity, activity + size);
    T i, j;
    i = 0;
    T count = 1;
    for (j = 1; j < size; j++) {
        if (activity[j].getStartTime() >= activity[i].getFinishTime()) {
            count++;
            i = j;
        }
    }
    return count;
}