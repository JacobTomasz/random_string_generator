/*
 * AUTHOR: Jacob Tomaszewski
 * PURPOSE: Generate a string randomly of given 'length'
 */

#include <iostream>
#include <string>     //required
#include <algorithm>  //required
#include <cstdlib>
#include <ctime>
using namespace std;

//prototype
string rand_str(size_t length);

int main() {
    srand(time(nullptr));
    cout << rand_str(12) << endl;
    return 0;
}

//definition
string rand_str(size_t length) {
    auto rand_ch = []()-> char {
        const char ch_set[] = "0123456789"
                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "abcdefghijklmnopqrstuvwxyz";
        const size_t max = (sizeof(ch_set)-1);
        return ch_set[rand()%max];
    };
    string str(length, 0);
    generate_n(str.begin(), length, rand_ch);
    return str;
}