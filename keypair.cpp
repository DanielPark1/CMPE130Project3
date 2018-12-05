//
// Created by Photo on 12/3/2018.
//

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#include "keypair.h"
#include "BigInteger.h"
#include <sstream>

keypair::keypair(){
    BigInteger zero("0");
    p = zero;
    q = zero;
    n = zero;
    z = zero;
    e = zero;
    d = zero;
}

keypair::keypair(string p1, string q1, string e1, string d1){
    BigInteger one("1");
    BigInteger pp1(p1);
    BigInteger qq1(q1);
    BigInteger nn1;
    BigInteger zz1;

    p = pp1;
    q = qq1;

    nn1 = pp1 * qq1;
    n = nn1;

    zz1 = (pp1 - one) * (qq1 - one);
    z = zz1;

    BigInteger ee1(e1);
    BigInteger dd1(d1);

    e = ee1;
    d = dd1;


}

void keypair::encrypt(string info[], string temp[], int length){

    BigInteger zero("0");
    BigInteger ns("30");
    BigInteger key;
    BigInteger pt;
    BigInteger ct;

    key = e;

    for(int i = 0; i < length; i++){
        pt.setNumber(info[i]);
        pt = pt - ns;
        BigInteger k("1");
        BigInteger j("0");
        for(j = zero; j < key; j++){
            k = k * pt;
            k = k % n;
        }
        temp[i] = k.getNumber();
        ct = k + ns;
        info[i] = ct.getNumber();

    }



    /*
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    for (int i = 0; i < length; i++){
        cout << info[i] << " ";
    }
    cout << endl;
    */

    int x;
    char y;
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    for(int i = 0; i < length; i++){
        x = stoi(info[i]);
        y = (char) x;
        cout << y;
    }
    cout << endl;

    /*
    cout << "\nTHE TEMP ARRAY IS\n";
    for (int i = 0; i < length; i++){
        cout << temp[i] << " ";
    }
    cout << endl;
     */

}

void keypair::decrypt(string info[], string temp[], int length){

    BigInteger zero("0");
    BigInteger ns("30");
    BigInteger key;
    BigInteger pt;
    BigInteger ct;

    key = d;

    for(int i = 0; i < length; i++){
        ct.setNumber(temp[i]);
        BigInteger k("1");
        BigInteger j("0");
        for(j = zero; j < key; j++){
            k = k * ct;
            k = k % n;
        }
        pt = k + ns;
        info[i] = pt.getNumber();

    }

    /*
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (int i = 0; i < length; i++){
        cout << info[i] << " ";
    }
    cout << endl;
    */

    int x;
    char y;
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for(int i = 0; i < length; i++){
        x = stoi(info[i]);
        y = (char) x;
        cout << y;
    }
    cout << endl;
}