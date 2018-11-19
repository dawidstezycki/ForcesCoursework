//
//  Force.hpp
//  Coursework
//
//  Created by Dawid on 19/11/2018.
//  Copyright © 2018 Dawid. All rights reserved.
//

#ifndef Force_h
#define Force_h

class Force{
    double mXCoord;
    double mYCoord;
    
public:
    Force(char type = 'c', double value1 = 0, double value2 = 0);
    ~Force(){}
    
    void setMag(double magnitude);
    void setAngle(double angle);
    void setX(double value){mXCoord = value;}
    void setY(double value){mYCoord = value;}
    
    double getAngle() const;
    double getMag() const;
    double getX() const {return mXCoord;};
    double getY() const {return mYCoord;};
    
    void print(char type = 'c') const;
    
    Force operator+(Force& rv);
    Force operator-(Force& rv);
    Force operator-();
};

#endif /* Force_h */
