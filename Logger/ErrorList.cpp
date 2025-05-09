#include "ErrorList.h"


#if (DEBUG_ERROR)
ErrorList::ErrorList()
{
   for (auto iter{ errorMessageList.begin() };
      iter != errorMessageList.end();
      ++iter)
   {
      std::cout << '\t' << iter->first << '\t' << iter->second << '\n';
   }
}
#endif // DEBUG

constexpr int ErrorList::getErrorNumber() const
{
   return errorNumber;
}

std::string ErrorList::getErrorMessage(const int errNum) const
{

   if (errorMessageList.contains(errNum))
   {
      errorMessage = errorMessageList.at(errNum);
   }
   else
   {
      errorMessage = "Unknown Error";
   }
   
   return errorMessage;
}

std::wstring ErrorList::getErrorMessage_w(const int errNum) const
{
   if (errorMessageList.contains(errNum))
   {
      errorMessage_w = errorMessageList_w.at(errNum);
   }
   else
   {
      errorMessage_w = L"Unknown Error";
   }

   return errorMessage_w;
}

void ErrorList::printErrorMessage(const std::string& errTypeMsg, const int errNum) const
{
   std::fstream outErrorFile{};
   outErrorFile.open(errorLogFileName, std::ios::app);

   std::cerr << errTypeMsg <<  errNum << " - " << getErrorMessage(errNum) << std::endl;
   outErrorFile << errTypeMsg << errNum << " - " << getErrorMessage(errNum) << std::endl;
   outErrorFile.close();

     // Open the file for the user to see the contents of the file.
     ShellExecute(nullptr, L"open", getErrorLogPathName.c_str(), nullptr, nullptr, SW_SHOW);

}

void ErrorList::printErrorMessage_w(const std::wstring& errTypeMsg, const int errNum) const
{
   std::wofstream outErrorFile{};
   outErrorFile.open(errorLogFileName, std::ios::app);

   std::wcerr << errTypeMsg << errNum << " - " << getErrorMessage_w(errNum) << std::endl;
   outErrorFile << errTypeMsg << errNum << " - " << getErrorMessage_w(errNum) << std::endl;

     // Open the file for the user to see the contents of the file.
     ShellExecute(nullptr, L"open", getErrorLogPathName.c_str(), nullptr, nullptr, SW_SHOW);
}

void ErrorList::printErrorMessage(const int errNum) const
{
   std::fstream outErrorFile{};
   outErrorFile.open(errorLogFileName, std::ios::app);

   std::cerr << errNum << " - " << getErrorMessage(errNum) << std::endl;
   outErrorFile << errNum << " - " << getErrorMessage(errNum) << std::endl;
   outErrorFile.close();

   // Open the file for the user to see the contents of the file.
   ShellExecute(nullptr, L"open", getErrorLogPathName.c_str(), nullptr, nullptr, SW_SHOW);
}
