#include "Force.h"
#include <iostream>
#include <math.h>
using namespace std;

Force::Force(char type, double value1, double value2){
    if (type == 'p'){
        mXCoord = value1 * cos(value2);
        mXCoord = value1 * sin(value2);
    }
    else if (type == 'c'){
        mXCoord = value1;
        mYCoord = value2;
    }
    
    else {
        cout << "Wrong type";
    }
}

inline void Force::setMag(double magnitude){
    double angle = atan(mXCoord/mYCoord);
    mXCoord = magnitude * cos(angle);
    mYCoord = magnitude * sin(angle);
}

inline void Force::setAngle(double angle){
    double magnitude = sqrt(mXCoord * mXCoord + mYCoord * mYCoord);
    mXCoord = magnitude * cos(angle);
    mYCoord = magnitude * sin(angle);
}

double Force::getMag() const{
    return sqrt(mXCoord * mXCoord + mYCoord * mYCoord);
}

double Force::getAngle() const{
    return atan(mXCoord/mYCoord);
}

void Force::print(char type) const{
    if (type == 'p'){
        double magnitude = sqrt(mXCoord * mXCoord + mYCoord * mYCoord);
        double angle = atan(mXCoord/mYCoord);
        
        cout << "POLAR COORDINATES\n";
        cout << "Magnitude: " << magnitude << "\n";
        cout << "Angle (in radians): " << angle << "\n";
    }
    else if (type == 'c'){
        cout << "CARTESIAN COORDINATES\n";
        cout << "x coordinate: " << mXCoord << "\n";
        cout << "y coordinate: " << mYCoord << "\n";
    }
    else {
        cout << "Wrong type";
    }
}

Force Force::operator+(Force& rv) {
    return Force('c', mXCoord + rv.mXCoord, mYCoord + rv.mYCoord);
}

Force Force::operator-(Force& rv) {
    return Force('c', mXCoord - rv.mXCoord, mYCoord - rv.mYCoord);
}

Force Force::operator-(){
    mXCoord = (-mXCoord);
    mYCoord = (-mYCoord);
    
    return *this;
}
