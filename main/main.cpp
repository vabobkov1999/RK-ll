#include "queue.hpp"
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    Queue<int> b1;
    Queue<int> b2 = {1, 2, 3, 4};
    Queue<int> b3{a2};
    cout << a2 << endl;
    cout << b3 << endl;
    b1.swap(b3);
    cout << b1 << endl;
    cout << boolalpha << b3.empty() << endl;
    cout << b1.size() << endl;
    cout << b2.size() << endl;
    a3.push(5);
   cout << boolalpha << b2.empty() << endl;
    cout << b3 << endl;
    ofstream output{ "queue.bin" };
    output << b3;
    output.close();
    Queue<int> b4;
    ifstream input{ "queue.bin" };
    input >> b4;
    input.close();
    cout << (b4 == b3) << endl;
    try {
        b4.front();
    }
    catch (logic_error e) { cout << "empty" << endl; 
    b4.pop();
    cout << b4 << endl;
    try {
        b4.front() = 6;
    }
    catch (logic_error e) { cout << e.what() << endl; }
    exit(0);
}
