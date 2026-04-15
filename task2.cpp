#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BallsFaced;

class Runs {
private:
    int totalRuns;
    string batsmanName;
public:
    Runs(string name, int r) {
        batsmanName = name;
        totalRuns = r;
    }
    
    void displayRuns() const {
        cout << "Batsman: " << batsmanName << " | Runs: " << totalRuns << endl;
    }

    friend void calculateStrikeRate(Runs r, BallsFaced b);
};

class BallsFaced {
private:
    int deliveryCount;
public:
    BallsFaced(int b) {
        deliveryCount = b;
    }

    void displayBalls() const {
        cout << "Balls Faced: " << deliveryCount << endl;
    }

    friend void calculateStrikeRate(Runs r, BallsFaced b);
};

void calculateStrikeRate(Runs r, BallsFaced b) {
    if (b.deliveryCount <= 0) {
        cout << "Error: Strike Rate cannot be calculated for zero balls faced." << endl;
    } else {
        double strikeRate = (static_cast<double>(r.totalRuns) / b.deliveryCount) * 100.0;
        cout << "\n--- ICC Match Statistics Analysis ---" << endl;
        cout << "Player Name: " << r.batsmanName << endl;
        cout << "Total Runs Scored: " << r.totalRuns << endl;
        cout << "Total Balls Faced: " << b.deliveryCount << endl;
        cout << "Formula: (Runs / Balls) * 100" << endl;
        cout << "Calculated Strike Rate: " << fixed << setprecision(2) << strikeRate << endl;
        cout << "------------------------------------" << endl;
    }
}

int main() {
    Runs matchRuns("Star Batsman", 85);
    BallsFaced matchBalls(60);

    matchRuns.displayRuns();
    matchBalls.displayBalls();
    calculateStrikeRate(matchRuns, matchBalls);

    return 0;
}
