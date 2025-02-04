#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <cmath>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int A = getmaxx(), B = getmaxy();

    setcolor(GREEN);
    line(0, B / 2, A, B / 2);  // x-axis
    setcolor(RED);
    line(A / 2, 0, A / 2, B);  // y-axis
    A = A / 2;
    B = B / 2;

    // User input for the two points
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the first point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2, y2): ";
    cin >> x2 >> y2;

    // DDA Line Algorithm
    int dx = x2 - x1;
    int dy = y2 - y1;

    float m = (float)dy/(float)dx;
    cout << "Slope: " << m << "\n";

    if(abs(m) <= 1) {
        int x = x1, y = y1;
        while(x <= x2) {
            cout << "x: " << x << ", y: " << y << "\n";
            putpixel(round(x) + A, B - round(y), YELLOW);
            x++;
            y = y + m;
        }
    } else {
        int x = x1, y = y1;
        while(y <= y2) {
            cout << "x: " << x << ", y: " << y << "\n";
            putpixel(x + A, B - round(y), YELLOW);
            y++;
            x = round(x + 1 / m);
        }
    }

    getch();
    closegraph();
    return 0;
}
