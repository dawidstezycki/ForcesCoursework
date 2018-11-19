//
//  main.cpp
//  Coursework
//
//  Created by Dawid on 19/11/2018.
//  Copyright © 2018 Dawid. All rights reserved.
//

#include "Force.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    char type;
    double value1;
    double value2;
    vector<Force> forces;
    Force fSum;
    Force ResultingForce;
    ifstream in("ForceList.txt");
    
    while (in >> type){
        in >> value1;
        in >> value2;
        Force f1(type,value1,value2);
        forces.push_back(f1);
    }
    
    for (int i = 0; i < forces.size(); i++){
        fSum = fSum + forces[i];
        forces[i].print('p');
        forces[i].print('c');
        cout << "\n";
    }
    
    cout << "** SUM OF THE FORCES ** \n \n";
    fSum.print('p');
    fSum.print('c');
    cout << "\n";
    
    ResultingForce = -(forces[0]-forces[1]+forces[2]);
    cout << "** RESULTING FORCE = -(F1-F2+F3) ** \n\n";
    ResultingForce.print('p');
    ResultingForce.print('c');
    
    in.close();
    return 0;
}
