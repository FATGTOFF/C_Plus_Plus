#include <iostream>
#include<thread>
#include<chrono>
#include <Windows.h>

int main() {

    HDC dc = GetDC(nullptr);
    POINT _cursor;

    while (true)
    {

        GetCursorPos(&_cursor);
        auto color = GetPixel(dc, _cursor.x, _cursor.y);
        auto red = GetRValue(color);
        auto green = GetGValue(color);
        auto blue = GetBValue(color);

        printf("X: %d Y: %d RGB: { %d, %d, %d}\n", _cursor.x, _cursor.y, red, green, blue);
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    ReleaseDC(nullptr, dc);

}
