// ErrorCodeDetector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>;
string ConvertDecimalToRadix(int decimal, int radix) {
    string radixString = "";
    int i = decimal;
    int mod;
    if (decimal != 0) {
        while (i > 0) {
            mod = i % radix;
            i = i / radix;
            radixString = to_string(mod) + radixString;
        }
    }
    else {
        radixString = "0";
    }
    if (radixString.length() < 8) {
        while (radixString.length() < 8) {
            radixString = "0" + radixString;
        }
    }
    return radixString;
}

int CheckForParity(string binaryInput) {
    int i = 0;
    int numberOfOnes = 0;
    while (i < binaryInput.length() - 1) {
        if (binaryInput[i] == '1') {
            numberOfOnes++;
        }
        i++;
    }
    cout << "\nOnes Count: " << numberOfOnes;
    if ((binaryInput[binaryInput.length() - 1] == '1') && (numberOfOnes % 2 == 0)) {
        return 1;
    }
    else if ((binaryInput[binaryInput.length() - 1] == '0') && (numberOfOnes % 2 != 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    /// <summary>
    ///   
    /// 
    /// </summary>
    /// <returns>
    /// returns an integer base number
    /// </returns>
    /// 
    int decimalNumber;
    int radixBase;
    string radixString;

    cout << "Please input a Decimal Number: ";
    cin >> decimalNumber;

    radixBase = 2;

    radixString = ConvertDecimalToRadix(decimalNumber, radixBase);

       
    cout << "Radix String is equal to: " << radixString;
    CheckForParity(radixString) == 1 ? cout << "\nPassed Parity Check! \n" : cout << "\nError Parity Check! ";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
