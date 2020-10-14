#include <iostream>
#include <fstream>
#include <locale.h>
#include "Queue/Queue.h"
using namespace std;
using namespace mathTools;

void resh(string fileName, int A, int B) {
    fstream inOut;
    Queue<int> a;
    Queue<int> b;
    Queue<int> c;
    inOut.open(fileName, ios::in);
    int mem = NULL;
    while (!inOut.eof()) {
        inOut >> mem;
        if (mem < A) {
            a.EnQueue(mem);
        }
        else if (mem > B) {
            c.EnQueue(mem);
        }
        else {
            b.EnQueue(mem);
        }
    }
    while (!a.isEmpty()) 
        cout << a.DeQueue() << " ";
    cout << endl;
    while (!b.isEmpty())
        cout << b.DeQueue() << " ";
    cout << endl;
    while (!c.isEmpty())
        cout << c.DeQueue() << " ";
    
    inOut.close();
}

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    int A, B;
    cout << "Введите A:";
    cin >> A;
    cout << "Введите Б:";
    cin >> B;
    resh("text.txt", A, B);
}