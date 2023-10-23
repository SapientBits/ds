//
//  main.cpp
//  ClassesReview
//
//  Created by Sapient Bits on 22/10/2023.
//
#include <iostream>
#include "SbVector.h"
using namespace std;

int main(int argc, const char * argv[])
{
    const SbVector v1 {1,0,4,2,3,4};
    cout << "V1:" << v1 << endl;
    cout<< v1[2] << endl;
    
    SbVector v2;
    v2.insert(1);
    v2.insert(5);
    v2.insert(4);
    v2.insert(3);
    v2.insert(1);
    v2.insert(7);
    v2.insert(2);
    v2.insert(0);
    v2.insert(1);
    v2.insert(9);
    v2.insert(23);
    cout << "V2:" << v2 << endl;
    v2.remove(23);
    v2.remove(3);
    cout << "V2:" << v2 << endl;
    v2[2] = 17;
    cout << "V2:" << v2 << endl;

    SbVector v3=v2;
    v3.remove(7);
    cout << "V2:" << v2 << endl;
    cout << "V3:" << v3 << endl;
    
    v3=v1;
    cout << "V3:" << v3 << endl;
    
    return 0;
}
