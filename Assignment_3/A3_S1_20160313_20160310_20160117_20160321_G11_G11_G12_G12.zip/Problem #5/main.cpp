#include <iostream>
#include "IntStack.h"

using std::cout;
using std::endl;

int main() {
    IntStack s;

    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    // 3 4 5 6
    cout << s.top() << '\n';
    s.pop();

    // 3 4 5
    cout << s.top() << '\n';
    s.pop();

    // 3 4
    cout << s.top() << '\n';
    s.pop();

    // 3
    cout << s.top() << endl;
    s.pop();

    return 0;
}
