#include "graphics.h"
#include "winbgi.h"
#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Type in size: ";
    int size = 0;
    cin >> size;
    TQueue<int> A(size);

    cout << "Type push [number], pop, peek or exit" << endl;

    int start = 90, end = 90;

    initwindow(400, 400);
    setcolor(12);
    setlinestyle(0, 0, 5);

    int temp = 0;
    string command = "";

    while (1 == 1)
    {
        cin >> command;
        if (command == "push")
            if (A.IsFull())
                cout << "Can't push, it's full!" << endl;
            else
            {
                cin >> temp;
                A.push(temp);
                end = start + (360.0 / size) * A.GetCount();
                cleardevice();
            }
        else if (command == "pop")
            if (A.IsEmpty())
                cout << "Can't pop, it's empty!" << endl;
            else
            {
                A.pop();
                start += (360.0 / size);
                cleardevice();
            }
        else if (command == "peek")
            cout << A << endl;
        else if (command == "exit")
            return 0;

        if (start != end)
            arc(200, 200, start, end, 100);
    }

    return 0;
}