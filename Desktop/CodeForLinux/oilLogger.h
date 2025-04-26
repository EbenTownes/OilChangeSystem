#include <string>
#include <chrono>
using namespace std;

enum interval {AM, PM, ERROR};

struct Time{
    string hour;
    string minute;
    string second;
    interval tod;
};

struct Date{
    string month;
    string day;
    string year;
    Time time;
};

struct OilChange{
    Date changeDates;
    string brand;
    string viscosity; 
    int oilAmount;
};

Date filterDate(string dateInput);
Time filterTime(string timeInput);
void printOilInfo(OilChange oilChange);