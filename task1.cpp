#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Time;

class Speed {
private:
    double kmph;
    string unit;
public:
    Speed() {
        kmph = 0.0;
        unit = "km/h";
    }
    
    Speed(double s) {
        kmph = s;
        unit = "km/h";
    }

    void setSpeed(double s) {
        kmph = s;
    }

    double getSpeed() const {
        return kmph;
    }

    friend void calculateDistance(Speed s, Time t);
};

class Time {
private:
    double hours;
    double minutes;
public:
    Time() {
        hours = 0.0;
        minutes = 0.0;
    }
    
    Time(double h) {
        hours = h;
        minutes = h * 60.0;
    }

    void setTime(double h) {
        hours = h;
        minutes = h * 60.0;
    }

    double getHours() const {
        return hours;
    }

    friend void calculateDistance(Speed s, Time t);
};

void calculateDistance(Speed s, Time t) {
    double totalDistance = s.kmph * t.hours;
    cout << "--- Journey Details ---" << endl;
    cout << "Vehicle Speed: " << s.kmph << " " << s.unit << endl;
    cout << "Travel Duration: " << t.hours << " hours (" << t.minutes << " mins)" << endl;
    cout << "Formula Applied: Distance = Speed * Time" << endl;
    cout << "Calculation: " << s.kmph << " * " << t.hours << endl;
    cout << "Total Distance Traveled: " << fixed << setprecision(2) << totalDistance << " km" << endl;
    cout << "-----------------------" << endl;
}

int main() {
    Speed travelSpeed(60.0);
    Time travelTime(2.0);

    calculateDistance(travelSpeed, travelTime);

    return 0;
}
