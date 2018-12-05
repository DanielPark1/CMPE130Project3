//
// Created by Photo on 12/3/2018.
//

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <vector>
#include "BigInteger.h"

#ifndef CMPE130PROJECT3_KEYPAIR_H
#define CMPE130PROJECT3_KEYPAIR_H

using namespace std;

class keypair {

public:
    BigInteger p;
    BigInteger q;
    BigInteger n;
    BigInteger z;
    BigInteger e;
    BigInteger d;


    keypair();
    keypair(string p1, string q1, string e1, string d1);
    void encrypt(string info[], string temp[], int length);
    void decrypt(string info[], string temp[], int length);
};


#endif //CMPE130PROJECT3_KEYPAIR_H
