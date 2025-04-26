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

struct TimeFrameInput{
    string dateInput;
    string timeInput;
};

struct InputType{
    OilChange oilChangeInput;
    TimeFrameInput timeFrameInput;
    int inputType;
};

Date filterDate(string dateInput);
Time filterTime(string timeInput);
void printOilInfo(OilChange oilChange);
InputType takeInput(Date date, int infoType);