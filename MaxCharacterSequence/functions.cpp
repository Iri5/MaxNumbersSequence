
#include <iostream>
#include <string>
int MaxNumSequense(std::string text) {
    int counter = 0;
    int curCounter = 0;
    for (int i = 0; i < text.length(); i++) {
        int newMsg = static_cast<int>(text[i]);

        if ((newMsg >= 48) && (newMsg <= 57)) {
            curCounter++;
            if (curCounter > counter) {
                counter = curCounter;
            }
        }
        else {
            curCounter = 0;
        }
    }
    return counter;
}