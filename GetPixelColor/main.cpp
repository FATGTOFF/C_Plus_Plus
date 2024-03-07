#include <iostream>
#include <thread>
#include <chrono>
#include <cstdint>
#include <Windows.h>

// Global variables.
constexpr auto numberOfSeconds{ 1 };
constexpr auto keyToPress{ VK_SPACE };

// Function declaration.
uint32_t swapFirstAndLastBytes(const uint32_t originalValue);

int main()
{

   const HDC dc{ GetDC(nullptr) };
   POINT _cursor;
   bool keepLooping{ true };

   while (keepLooping)
   {

      if (GetAsyncKeyState(keyToPress))
      {
         keepLooping = false;
      }
      else
      {
         std::cout << "Press the <SPACE> key to exit..." << std::endl;

         GetCursorPos(&_cursor);
         const auto color{ swapFirstAndLastBytes(static_cast<uint32_t>(GetPixel(dc, _cursor.x, _cursor.y))) };
         const auto red = GetRValue(color);
         const auto green = GetGValue(color);
         const auto blue = GetBValue(color);

         static_cast<void>(printf("Cursor Loc X: %ld Y: %ld Color: 0x%06X: RGB: { %d, %d, %d}\n", _cursor.x, _cursor.y, color, red, green, blue));

         std::this_thread::sleep_for(std::chrono::seconds(numberOfSeconds));
      }
   }

   const auto releaseDCValue{ ReleaseDC(nullptr, dc) };
   // If the DC was released, the return value is 1.
   // If the DC was not released, the return value is 0.
   if (1 != releaseDCValue)
   {
      std::cerr << "DC was not released. Return value is " << releaseDCValue << std::endl;
   }

}

uint32_t swapFirstAndLastBytes(const uint32_t originalValue)
{
   std::uint32_t newValue{ originalValue };
   std::uint8_t firstByteToSwap{ (originalValue >> 0) & 0xFF };
   std::uint8_t lastByteToSwap{ (originalValue >> 16) & 0xFF };
   newValue &= 0x00FF00;
   newValue |= (lastByteToSwap << 0) | (firstByteToSwap << 16);

   return newValue;
}
