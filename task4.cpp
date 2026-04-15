#include <iostream>
#include <string>

using namespace std;

class TrafficSystem {
private:
    int vehicleCount;
    string roadName;
public:
    TrafficSystem() {
        vehicleCount = 0;
        roadName = "General Road";
    }
    
    TrafficSystem(int count, string name) {
        vehicleCount = count;
        roadName = name;
    }

    TrafficSystem operator+(const TrafficSystem& other) const {
        return TrafficSystem(this->vehicleCount + other.vehicleCount, "Merged Junction");
    }

    TrafficSystem operator-(const TrafficSystem& other) const {
        int result = this->vehicleCount - other.vehicleCount;
        if (result < 0) result = 0;
        return TrafficSystem(result, this->roadName);
    }

    TrafficSystem operator*(int multiplier) const {
        return TrafficSystem(this->vehicleCount * multiplier, this->roadName);
    }

    bool operator==(const TrafficSystem& other) const {
        return this->vehicleCount == other.vehicleCount;
    }

    void showStatus() const {
        cout << "Traffic Report for [" << roadName << "]" << endl;
        cout << "Total Vehicles Detected: " << vehicleCount << endl;
        if (vehicleCount >= 100) cout << "Status: GRIDLOCK DETECTED!" << endl;
        else if (vehicleCount >= 50) cout << "Status: Heavy Congestion." << endl;
        else cout << "Status: Traffic flowing smoothly." << endl;
        cout << "------------------------------------" << endl;
    }
};

int main() {
    TrafficSystem mainRoad(50, "Main Avenue");
    TrafficSystem sideRoad(20, "Side Street");

    cout << "Initial Traffic Conditions:" << endl;
    mainRoad.showStatus();

    cout << "Merging Side Street into Main Avenue (+ operator):" << endl;
    TrafficSystem junction = mainRoad + sideRoad;
    junction.showStatus();

    cout << "Clearing 15 vehicles via exit ramp (- operator):" << endl;
    TrafficSystem exitRamp(15, "Exit");
    TrafficSystem currentTraffic = junction - exitRamp;
    currentTraffic.showStatus();

    cout << "Signal Failure! Traffic units doubling (* operator):" << endl;
    TrafficSystem failure = TrafficSystem(5, "Delay Point");
    TrafficSystem doubled = failure * 2;
    doubled.showStatus();

    cout << "Checking for identical congestion (== operator):" << endl;
    TrafficSystem roadA(100, "Road A"), roadB(100, "Road B");
    if (roadA == roadB) {
        cout << "Alert: Road A and Road B are equally jammed at 100 cars!" << endl;
    }

    return 0;
}
