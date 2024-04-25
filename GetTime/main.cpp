#include <iostream>
#include "Time.h"
#include "ErrorList.h"
#include "GetTimeExceptionBase.h"

int main()
{  
   try
   {
      Time time;

      std::cout << time.getDayMonthYrHrMinSecMs() << std::endl;
      std::cout << time.getHrMinSecMs() << std::endl;
      std::cout << time.getHrMinSecs() << std::endl;
      std::cout << time.getHrMins() << std::endl;
      std::cout << time.getDay() << std::endl;
      std::cout << time.getMonth() << std::endl;
      std::cout << time.getYear() << std::endl;
      std::cout << time.getHrs() << std::endl;
      std::cout << time.getMins() << std::endl;
      std::cout << time.getSecs() << std::endl;
      std::cout << time.getMills() << std::endl;
   }
   catch (const GetFTimeException& exceptionsTypes)
   {
      ErrorList errorList{};
      errorList.printErrorMessage(exceptionsTypes.what(),
         exceptionsTypes.getTimeException());

      return exceptionsTypes.getTimeException();
   }
   catch (const GetLocalTimeException& exceptionsTypes)
   {

      ErrorList errorList{};
      errorList.printErrorMessage(exceptionsTypes.what(),
         exceptionsTypes.getTimeException());

      return exceptionsTypes.getTimeException();
   }

    

}