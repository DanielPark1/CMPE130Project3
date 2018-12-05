#include <iostream>
#include <string.h>
#include "keypair.h"
#include <fstream>

void word_string_to_int(string const& s, int arr[], int length);
void int_to_number_string(int arr[], string s[] , int length);

int main() {

    string p1, q1, e1, d1;
    string p2, q2, e2, d2;

    std::cout << "Enter prime number 'p1'" << std::endl;
    std::cin >> p1;
    std::cout << "Enter prime number 'q1'" << std::endl;
    std::cin >> q1;
    std::cout << "Enter prime number 'e1'" << std::endl;
    std::cin >> e1;
    std::cout << "Enter prime number 'd1'" << std::endl;
    std::cin >> d1;

    std::cout << "Enter prime number 'p2'" << std::endl;
    std::cin >> p2;
    std::cout << "Enter prime number 'q2'" << std::endl;
    std::cin >> q2;
    std::cout << "Enter prime number 'e2'" << std::endl;
    std::cin >> e2;
    std::cout << "Enter prime number 'd2'" << std::endl;
    std::cin >> d2;

    keypair h("23", "29", "19", "227");
    keypair i("1223", "971", "223", "898307");




    //string test[2] = {"104", "105"};
    //string hold[2];
    string message;
    int path;

    std::cout << "Console: \n Press 1. Type message for encryption. \n Press 2. Select text file for encryption." << std::endl;
    std::cin >> path;

    if(path == 1){
        std::cin.ignore();
        std::cout << "Enter message for encryption." << std::endl;
        std::getline(std::cin, message);
    }else if (path == 2){
        std::cin.ignore();

        fstream file_;
        file_.open("test.txt");
        while (getline(file_, message))
        {
            // use line
            cout << message << "\n";
        }
        file_.close();

    }else{
        std::cout << "Please choose from the valid options." << std::endl;
        exit(1);
    }





    int length = message.length();
    int msg[length];
    string numbers[length];
    string hold_numbers[length];

    int sign[length];
    string numbers2[length];
    string hold_numbers2[length];


    cout << "\nTHE ORIGINAL MESSAGE IS\n";
    for(int i = 0; i < length; i++){
        cout << message[i];
    }
    cout << endl;

    word_string_to_int(message, msg, length);
    int_to_number_string(msg, numbers, length);

    for(int i = 0; i < length; i++){
        numbers2[i] = numbers[i];
    }


    h.encrypt(numbers, hold_numbers, length);
    h.decrypt(numbers, hold_numbers, length);

    i.encrypt(numbers2, hold_numbers, length); //key 2 signature
    h.encrypt(numbers2, hold_numbers2, length); //encrypt key 2
    h.decrypt(numbers2, hold_numbers2, length);
    i.decrypt(numbers2, hold_numbers, length);

    for(int i = 0; i < length; i++){
        if(numbers[i] != numbers2[i]){
            cout << "THE DIGITAL SIGNATURES DO NOT MATCH!" << endl;
            break;
        }
        if(i == length - 1){
            cout << "THE DIGITAL SIGNATURES MATCH!" << endl;
        }
    }


    return 0;
}

void word_string_to_int(string const& s, int arr[],int length){
    for(int i = 0; i < length; i++){
        arr[i] = s[i];
    }
}

void int_to_number_string(int arr[], string s[], int length){
    for(int i = 0; i < length; i++){
        s[i] = std::to_string(arr[i]);
    }
}