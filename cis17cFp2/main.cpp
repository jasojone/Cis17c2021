/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 2nd, 2021, 8:11 AM
 * Problem 2 - Stacks
Take my hyperbolic sin/cos recursive function 
place the angle on a sine or cosine stack that 
represents a call to the sine or cosine.
When the program returns, examine the stack
for how many times the hyp sine was called and
how many times hyp sine/cosine was called vs. the
value you were trying to find.  Put the results
in a table.  Range of values from -1 to 1 in 
.1 radian increments.
Does the number of function calls agree with
what you predict it should be?
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;

float h(float);
float g(float);
stack<float> sinStack, cosStack;

int main(int argc, char** argv) {
    double angle = -1.0;
    while (angle <= 1.0) {

        while (!sinStack.empty()) {
            sinStack.pop();
        }
        while (!cosStack.empty()) {
            cosStack.pop();
        }

        cout << fixed << setprecision(2) << angle << " radians\n" << "sinh = " << h(angle) << "   "
                << "sinh calls: " << sinStack.size() << "   "
                << "cosh calls: " << cosStack.size() << "\n";

        while (!sinStack.empty()) {
            sinStack.pop();
        }

        while (!cosStack.empty()) {
            cosStack.pop();
        }

        cout << fixed << setprecision(2) << "cosh = " << g(angle) << "   "
                << "sinh calls: " << sinStack.size() << "   "
                << "cosh calls: " << cosStack.size() << "\n\n";

        angle += 0.1;
    }

    return 0;
}

float h(float angR) {
    //push angR onto the sinStack
    sinStack.push(angR);
    float tol = 1e-6;
    if (angR>-tol && angR < tol)
        return angR + angR * angR * angR / 6;

    return 2 * h(angR / 2) * g(angR / 2);
}

float g(float angR) {
    //push angl onto the cosStack
    cosStack.push(angR);
    float tol = 1e-6;
    if (angR>-tol && angR < tol)
        return 1 + angR * angR / 2;
    float b = h(angR / 2);

    return 1 + 2 * b*b;
}
