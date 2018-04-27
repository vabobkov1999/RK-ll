#include "Queue.hpp"
#include <sstream>
#include <fstream>

using namespace std;

int main()  
{
    Queue<int> q1;
    Queue<int> q2 = {1, 2, 3, 4};
    Queue<int> q3{q2};
    cout << q2 << endl;
    cout << q3 << endl;
    q1.swap(q3);
    cout << q1 << endl;
    cout << boolalpha << q3.empty() << endl;
    cout << q1.size() << endl;
    cout << q2.size() << endl;
    q3.push(5);
    
   cout << boolalpha << q2.empty() << endl;
    cout << q3 << endl;
    ofstream output{ "queue.bin" };
    output << q3;
    output.close();
    Queue<int> q4;
    ifstream input{ "queue.bin" };
    input >> q4;
    input.close();
    cout << (q4 == q3) << endl;
    try {
        q4.front();
    }
    catch (logic_error e) { cout << "empty" << endl; }
    //cout << q5.back() << endl;
    q4.pop();
    cout << q4 << endl;
    try {
        q4.front() = 6;
    }
    catch (logic_error e) { cout << e.what() << endl; }
    exit(0);
}
