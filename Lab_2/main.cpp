#include <iostream>
#include <time.h>
#include "complex.h"
#include "extrafunctions.h"
#include "func.h"
#include "func.cpp"
using namespace std;

const char *MSGS_TYPE[] = {"Which type of function do you need?",
                           "0. Quit",
                           "1. Make an integer function",
                           "2. Make a float function",
                           "3. Make a complex function",
                          };
const int MSGS_TYPE_SIZE = sizeof(MSGS_TYPE) / sizeof(MSGS_TYPE[0]);

const char *MSGS[] = {"What do you want to do?",
                      "0. Quit",
                      "1. To previous step",
                      "2. Generate n-pieces function",
                      "3. Generate the function on an interval",
                      "4. Define on an interval (keyboard input)",
                      "5. Monotony check",
                      "6. Continuity check",
                      "7. Find value at point",
                    };
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        cout << error << endl;
        error = "Incorrect input. Please, enter one positive integer number.\n";
        for (int i = 0; i < n; ++i) {
            cout << msgs[i] << endl;
        }
        cout << "Make your choice: ";
        choice = getchar() - '0';
        char c = getchar();
        while (c != '\n') {
            if (0 <= (int)c - '0' && (int)c - '0' <= 9)
                choice = choice * 10 + (c - '0');
            c = getchar();
        }
    } while (choice < 0 || choice >= n);
    return choice;
}

int main() {
    srand(time(NULL));
    int cmd = 0;
    int cmd_action = 0;

    int mode;
    int n;
    int start, end;
    int point;

    Function<int> *funcInt = new Function<int>;
    Sequence<int> *cInt = new ArraySequence<int>;
    int itemInt;
    int valueInt;

    Function<float> *funcFloat = new Function<float>;
    Sequence<float> *cFloat = new ArraySequence<float>;
    float itemFloat;
    float valueFloat;

    Function<Complex> *funcComplex = new Function<Complex>;
    Sequence<Complex> *cComplex = new ArraySequence<Complex>;
    Complex itemComplex;
    Complex valueComplex;

    cout << "Hello! I've made a little program for working with piecewise functions (form: c + bx + ax^2). You are welcome :)\n";
    do {
        cmd = dialog(MSGS_TYPE, MSGS_TYPE_SIZE);
        switch(cmd) {
        case 0:
            cout << "Goodbye! :)";
            break;
        case 1:
            cout << "\nOption 1 - Integer function\n";
            cmd_action = 0;
            do {
                cmd_action = dialog(MSGS, MSGS_SIZE);
                switch (cmd_action) {
                case 0:
                    printf("Goodbye! :)");
                    cmd = 0;
                    cmd_action = 0;
                    break;
                case 1:
                    funcInt->Clear();
                    cmd_action = 0;
                    break;
                case 2:
                    cout << "\nOption 2 - Generate n-pieces function\n";

                    cout << "Input number of pieces: ";
                    mode = readInt(&n);
                    if (mode != 0) {
                        break;
                    }
                    if (n <= 0) {
                        cout << "The number must be positive.\n";
                        break;
                    }
                    funcInt->Generate(n, randomInt);
                    cout << "Generated:\n" << *funcInt;
                    break;
                case 3:
                    cout << "\nOption 3 - Generate the function on an interval\n";

                    cout << "Input start of the interval: ";
                    mode = readInt(&start);
                    if (mode != 0) {
                        break;
                    }
                    cout << "Input end of the interval: ";
                    mode = readInt(&end);
                    if (mode != 0) {
                        break;
                    }
                    if (end < start) {
                        swap(end, start);
                    }
                    funcInt->Generate(start, end, randomInt);
                    cout << "Generated:\n" << *funcInt;
                    break;
                case 4:
                    cout << "\nOption 4 - Define on an interval\n";

                    cout << "Input start of the interval: ";
                    mode = readInt(&start);
                    if (mode != 0) {
                        break;
                    }
                    cout << "Input end of the interval: ";
                    mode = readInt(&end);
                    if (mode != 0) {
                        break;
                    }
                    if (end < start) {
                        swap(end, start);
                    }
                    cout << "Form of function: c + b * x + a * x^2.\n\tInput c: ";
                    mode = readInt(&itemInt);
                    if (mode != 0) {
                        break;
                    }
                    cInt->Append(itemInt);

                    cout << "\tInput b: ";
                    mode = readInt(&itemInt);
                    if (mode != 0) {
                        break;
                    }
                    cInt->Append(itemInt);

                    cout << "\tInput a: ";
                    mode = readInt(&itemInt);
                    if (mode != 0) {
                        break;
                    }
                    cInt->Append(itemInt);
                    funcInt->Set(cInt, start, end);
                    cInt->DelByIndex(0);
                    cInt->DelByIndex(0);
                    cInt->DelByIndex(0);
                    cout << "Success!\n" << *funcInt;
                    break;
                case 5:
                    cout << "\nOption 5 - Monotony check\n";

                    if (!funcInt->GetLength()) {
                        cout << "The function isn't defined. Please, define it by generation or keyboard input.\n";
                        break;
                    }
                    cout << "The function " << (funcInt->IsMonotone() ? "is" : "isn't") << " monotone.\n";
                    break;
                case 6:
                    cout << "\nOption 6 - Continuity check\n";

                    if (!funcInt->GetLength()) {
                        cout << "The function isn't defined. Please, define it by generation or keyboard input.\n";
                        break;
                    }
                    cout << "The function " << (funcInt->IsContinuous() ? "is" : "isn't") << " continuous.\n";
                    break;
                case 7:
                    cout << "\nOption 7 - Value at point\n";

                    cout << "Input the coordinate where you want to find value: ";
                    mode = readInt(&point);
                    if (mode != 0) {
                        break;
                    }
                    valueInt = funcInt->Value(point, INT_INF);
                    if (valueInt == INT_INF) break;
                    cout << "The function at " << point << " is " << valueInt;
                    break;
                }
            } while(cmd_action != 0);
            break;
        case 2:
            cout << "\nOption 2 - Float function\n";
            cmd_action = 0;
            do {
                cmd_action = dialog(MSGS, MSGS_SIZE);
                switch (cmd_action) {
                case 0:
                    printf("Goodbye! :)");
                    cmd = 0;
                    cmd_action = 0;
                    break;
                case 1:
                    funcFloat->Clear();
                    cmd_action = 0;
                    break;
                case 2:
                    cout << "\nOption 2 - Generate n-pieces function\n";

                    cout << "Input number of pieces: ";
                    mode = readInt(&n);
                    if (mode != 0) {
                        break;
                    }
                    if (n <= 0) {
                        cout << "The number must be positive.\n";
                        break;
                    }
                    funcFloat->Generate(n, randomFloat);
                    cout << "Generated:\n" << *funcFloat;
                    break;
                case 3:
                    cout << "\nOption 3 - Generate the function on an interval\n";

                    cout << "Input start of the interval: ";
                    mode = readInt(&start);
                    if (mode != 0) {
                        break;
                    }
                    cout << "Input end of the interval: ";
                    mode = readInt(&end);
                    if (mode != 0) {
                        break;
                    }
                    if (end < start) {
                        swap(end, start);
                    }
                    funcFloat->Generate(start, end, randomFloat);
                    cout << "Generated:\n" << *funcFloat;
                    break;
                case 4:
                    cout << "\nOption 4 - Define on an interval\n";

                    cout << "Input start of the interval: ";
                    mode = readInt(&start);
                    if (mode != 0) {
                        break;
                    }
                    cout << "Input end of the interval: ";
                    mode = readInt(&end);
                    if (mode != 0) {
                        break;
                    }
                    if (end < start) {
                        swap(end, start);
                    }
                    cout << "Form of function: c + b * x + a * x^2.\n\tInput c: ";
                    mode = readFloat(&itemFloat);
                    if (mode != 0) {
                        break;
                    }
                    cFloat->Append(itemFloat);

                    cout << "\tInput b: ";
                    mode = readFloat(&itemFloat);
                    if (mode != 0) {
                        break;
                    }
                    cFloat->Append(itemFloat);

                    cout << "\tInput a: ";
                    mode = readFloat(&itemFloat);
                    if (mode != 0) {
                        break;
                    }
                    cFloat->Append(itemFloat);
                    funcFloat->Set(cFloat, start, end);
                    cFloat->DelByIndex(0);
                    cFloat->DelByIndex(0);
                    cFloat->DelByIndex(0);
                    cout << "Success!\n" << *funcFloat;
                    break;
                case 5:
                    cout << "\nOption 5 - Monotony check\n";

                    if (!funcFloat->GetLength()) {
                        cout << "The function isn't defined. Please, define it by generation or keyboard input.\n";
                        break;
                    }
                    cout << "The function " << (funcFloat->IsMonotone() ? "is" : "isn't") << " monotone.\n";
                    break;
                case 6:
                    cout << "\nOption 6 - Continuity check\n";

                    if (!funcFloat->GetLength()) {
                        cout << "The function isn't defined. Please, define it by generation or keyboard input.\n";
                        break;
                    }
                    cout << "The function " << (funcFloat->IsContinuous() ? "is" : "isn't") << " continuous.\n";
                    break;
                case 7:
                    cout << "\nOption 7 - Value at point\n";

                    cout << "Input the coordinate where you want to find value: ";
                    mode = readInt(&point);
                    if (mode != 0) {
                        break;
                    }
                    valueFloat = funcFloat->Value(point, FLOAT_INF);
                    if (valueFloat == FLOAT_INF) break;
                    cout << "The function at " << point << " is " << valueFloat;
                    break;
                }
            } while(cmd_action != 0);
            break;
        case 3:
            cout << "\nOption 3 - Complex function\n";
            cmd_action = 0;
            do {
                cmd_action = dialog(MSGS, MSGS_SIZE);
                switch (cmd_action) {
                case 0:
                    printf("Goodbye! :)");
                    cmd = 0;
                    cmd_action = 0;
                    break;
                case 1:
                    funcFloat->Clear();
                    cmd_action = 0;
                    break;
                case 2:
                    cout << "\nOption 2 - Generate n-pieces function\n";

                    cout << "Input number of pieces: ";
                    mode = readInt(&n);
                    if (mode != 0) {
                        break;
                    }
                    if (n <= 0) {
                        cout << "The number must be positive.\n";
                        break;
                    }
                    funcComplex->Generate(n, complexRandom);
                    cout << "Generated:\n" << *funcComplex;
                    break;
                case 3:
                    cout << "\nOption 3 - Generate the function on an interval\n";

                    cout << "Input start of the interval: ";
                    mode = readInt(&start);
                    if (mode != 0) {
                        break;
                    }
                    cout << "Input end of the interval: ";
                    mode = readInt(&end);
                    if (mode != 0) {
                        break;
                    }
                    if (end < start) {
                        swap(end, start);
                    }
                    funcComplex->Generate(start, end, complexRandom);
                    cout << "Generated:\n" << *funcComplex;
                    break;
                case 4:
                    cout << "\nOption 4 - Define on an interval\n";

                    cout << "Input start of the interval: ";
                    mode = readInt(&start);
                    if (mode != 0) {
                        break;
                    }
                    cout << "Input end of the interval: ";
                    mode = readInt(&end);
                    if (mode != 0) {
                        break;
                    }
                    if (end < start) {
                        swap(end, start);
                    }
                    cout << "Form of function: c + b * x + a * x^2.\n\tInput c: ";
                    mode = readComplex(&itemComplex);
                    if (mode != 0) {
                        break;
                    }
                    cComplex->Append(itemComplex);

                    cout << "\tInput b: ";
                    mode = readComplex(&itemComplex);
                    if (mode != 0) {
                        break;
                    }
                    cComplex->Append(itemComplex);

                    cout << "\tInput a: ";
                    mode = readComplex(&itemComplex);
                    if (mode != 0) {
                        break;
                    }
                    cComplex->Append(itemComplex);
                    funcComplex->Set(cComplex, start, end);
                    cComplex->DelByIndex(0);
                    cComplex->DelByIndex(0);
                    cComplex->DelByIndex(0);
                    cout << "Success!\n" << *funcComplex;
                    break;
                case 5:
                    cout << "\nOption 5 - Monotony check\n";

                    cout << "Complex function can't be monotone.\n";
                    break;
                case 6:
                    cout << "\nOption 6 - Continuity check\n";

                    cout << "Complex function can't be continuous.\n";
                    break;
                case 7:
                    cout << "\nOption 7 - Value at point\n";

                    cout << "Input the coordinate where you want to find value: ";
                    mode = readInt(&point);
                    if (mode != 0) {
                        break;
                    }
                    valueComplex = funcComplex->Value(point, COMPLEX_INF);
                    if (valueComplex == COMPLEX_INF) break;
                    cout << "The function at " << point << " is " << valueComplex;
                    break;
                }
            } while(cmd_action != 0);
            break;
        }
    } while (cmd != 0);

    return 0;
}
