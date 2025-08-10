#include <stdlib.h>
#include <windows.h>

using namespace std;

int main()
{
  ShowWindow(GetConsoleWindow(), SW_HIDE);
  system("taskkill /f /im \"explorer.exe\"");
  system("taskkill /f /im \"GlazeWM.exe\"");
  system("start explorer.exe");
  system("start C:\\Users\\Danial\\scoop\\apps\\glazewm\\current\\GlazeWM.exe");
  return 0;
}