#include <iostream>
using namespace std;

void getBinarySInt(bool arrInt[]){
    short int binaryInt;
    cout << "Enter data of type short int:\n";
    while (!(cin >> binaryInt)) {
        cout << "error, expecting a num value\n";
        cin.clear();
        fflush(stdin);
    }
    int b = sizeof(binaryInt) * 8 - 1;
    int maskInt = 1 << b;
    for (int i = 0; i <= b; i++) {
        if (i == 1 || i % 8 == 0) {
            putchar(' ');
        }

        putchar(binaryInt & maskInt ? '1' : '0');
        if (binaryInt & maskInt){
            arrInt[i]=1;
        }
        else {
            arrInt[i]=0;

        }

        binaryInt = binaryInt << 1;
    }

}

void getBinaryFloat(bool arrFloat[]){

    cout << "\n";
    cout << "Enter data of type float: \n";
    union {
        float binaryFloat;
        int value;
    };
    unsigned order = sizeof(float) * 8;
    unsigned mask = 1 << order - 1;
    while (!(cin >> binaryFloat)) {
        cout << "error, expecting num value\n";
        cin.clear();
        fflush(stdin);
    }
    for (int i = 0; i <= order-1; ++i) {
        if (i == 1 || i == 9) {
            putchar(' ');
        }
        putchar(value & mask ? '1' : '0');


        if (value & mask){
            arrFloat[i]=1;
        }
        else {
            arrFloat[i]=0;
        }
        value <<= 1;

    }
}

void fromBinaryToSInt(bool array[]){
    short int newValue = 0;
    unsigned order = sizeof(short int) * 8,mask;
    for(int i = 0; i < order; i++){
        array[i] ? mask = 1 << order - 1 - i : mask = 0 << order - 1 - i;
        newValue |= mask;
    }
    cout << "\nNew Value = " << newValue << endl;
}

void fromBinaryToFloat(bool array[]){
    union {
        float newFloat;
        int value = 0;
    };
    unsigned order = sizeof(float) * 8, mask;

    for (int i = 0; i < order; i++){
        array[i] ? mask = 1 << order - 1 - i : mask = 0 << order - 1 - i;
        value |= mask;
    }
    cout << "\nNew Value = " << newFloat << endl;

}

void inversionBytes(bool array[], bool isFlag){
    int count,index;
    cout << "\nEnter the count of non-inversion value\n";
    cin >> count;
    if(isFlag) {
        for(int i = 0; i < 16;i++){
            if(array[i]){array[i] = 0;}
            else{array[i] = 1;}
        }
        cout << "\nEnter the indexes of non - inversion byte:\n";
        for (int i = 0; i < count; i++) {
            cin >> index;
            if(array[index]){array[index] = 0;}
            else{array[index] = 1;}
        }
    }
    else{
        for(int i = 0; i < 32;i++){
            if(array[i]){array[i] = 0;}
            else{array[i] = 1;}
        }
        cout << "\nEnter the indexes of non - inversion byte:\n";
        for (int i = 0; i < count; i++) {
            cin >> index;
            if(array[index]){array[index] = 0;}
            else{array[index] = 1;}
        }
    }
}

void printBytes(bool array[],bool isFlag){
    if (isFlag){
        for (int i = 0; i<16; i++){
        if(i==1 || i == 9){
            putchar(' ');
        }
        cout << array[i];
    }
    }
    else{
        for (int i = 0; i<32; i++){
            if(i==1 || i == 9){
                putchar(' ');
            }
            cout << array[i];
        }
    }
}


int main() {
    bool arrFloat[32];
    bool arrSInt[16];
    bool flagFloat = 0,flagSInt = 1;
    int cycleMain;
    while(true){
        cout << "\n--------------------------------------------------------------\n";
        cout <<"Choose the command:"
               "\n1 - Convert short int num from dec to binary form"
               "\n2 - Convert float num from dec to binary form"
               "\n3 - Transformation 9. Inverting bytes by user choice"
               "\n4 - Convert value from binary to dec form"
               "\n5 - Print current bytes of numbers"
               "\n0 - Exit the program";
        cout << "\n--------------------------------------------------------------\n";
        cin >> cycleMain;
        if(!cycleMain){
            return 0;
        }
        if(cycleMain == 1){
            system("cls");
            cout << "\n--------------------------------------------------------------\n";
            getBinarySInt(arrSInt);
            cout << "\n--------------------------------------------------------------\n";
        }
        if(cycleMain == 2){
            system("cls");
            cout << "\n--------------------------------------------------------------\n";
            getBinaryFloat(arrFloat);
            cout << "\n--------------------------------------------------------------\n";
        }
        if(cycleMain ==3){
            system("cls");
            int userChoice;
            cout << "\n--------------------------------------------------------------\n";
            cout << "Choose the type of value to invert:"
                    "\n1 - Float"
                    "\n2 - Short int";
            cout << "\n--------------------------------------------------------------\n";
            cin >> userChoice;
            if (userChoice==2){
                inversionBytes(arrSInt,flagSInt);
                cout << "\n--------------------------------------------------------------\n";
                printBytes(arrSInt,flagSInt);
            }
            if(userChoice == 1)
            {inversionBytes(arrFloat,flagFloat);
            cout << "\n--------------------------------------------------------------\n";
                printBytes(arrFloat,flagFloat);
            }
        }
        if(cycleMain == 4){
            system("cls");
            int userChoice;
            cout << "\n--------------------------------------------------------------\n";
            cout << "Choose the type of value to convert:"
                    "\n1 - Float"
                    "\n2 - Short int";
            cout << "\n--------------------------------------------------------------\n";
            cin >> userChoice;
            if (userChoice==2){
                fromBinaryToSInt(arrSInt);
                cout << "\n--------------------------------------------------------------\n";
            }
            if(userChoice == 1)
            {fromBinaryToFloat(arrFloat);
                cout << "\n--------------------------------------------------------------\n";
            }

        }
        if(cycleMain ==5){
            system("cls");
            int userChoice;
            cout << "\n--------------------------------------------------------------\n";
            cout << "Choose the type of value to print bytes:"
                    "\n1 - Float"
                    "\n2 - Short int";
            cout << "\n--------------------------------------------------------------\n";
            cin >> userChoice;
            if (userChoice == 2){
                cout << "\n--------------------------------------------------------------\n";
                printBytes(arrSInt,flagSInt);
            }
            if(userChoice == 1) {
                cout << "\n--------------------------------------------------------------\n";
                printBytes(arrFloat, flagFloat);
            }
        }
    }
}

