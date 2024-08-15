#include <iostream>
#include <thread>
#include <chrono>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <Windows.h>

// Global variables.
constexpr auto numberOfSeconds{ 1 };
constexpr auto keyToPress{ VK_SPACE };

// Function declaration.
uint32_t swapFirstAndLastBytes(const uint32_t originalValue);

int main()
{

   const auto dc{ GetDC(nullptr) };
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

         POINT _cursor{};
         GetCursorPos(&_cursor);
         const auto color{ swapFirstAndLastBytes(static_cast<uint32_t>(GetPixel(dc, _cursor.x, _cursor.y))) };
         const auto red = GetRValue(color);
         const auto green = GetGValue(color);
         const auto blue = GetBValue(color);

         std::wstringstream stringstream_w{};
         stringstream_w << L"Cursor Loc X: " << _cursor.x << L" Y: " << _cursor.y
            << L" Color: " << L"0x" << std::setfill(L'0') << std::setw(6) << std::right
            << std::hex << std::uppercase << color << std::dec << L" RGB: {" << red << L", "
            << green << L", " << blue << L"}" << std::flush;

         std::wcout << stringstream_w.str() << std::endl;

         std::this_thread::sleep_for(std::chrono::seconds(numberOfSeconds));

         // Clear the buffer.
         stringstream_w.str(L"");
         stringstream_w.clear();
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
   const std::uint8_t firstByteToSwap{ (originalValue >> 0) & 0xFF };
   const std::uint8_t lastByteToSwap{ (originalValue >> 16) & 0xFF };
   newValue &= 0x00FF00;
   newValue |= (lastByteToSwap << 0) | (firstByteToSwap << 16);

   return newValue;
}
