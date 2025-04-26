#include <iostream>
#include "oilLogger.h"
using namespace std;

int main(){
    cout << "#-------------------------------------------#\n";
    cout << "|      DOCUMENT OIL CHANGE NOTES BELOW      |\n";
    cout << "#-------------------------------------------#\n";

    cout << "\nTIME RELATED NOTES:\n";
    cout << "-------------------\n";
    string dateInput, timeInput;
    cout << "Date [00/00/0000]: ";
    getline(cin, dateInput);
    cout << "Time [00:00:00 AM] ";
    getline(cin, timeInput);

    Date date = filterDate(dateInput);
    date.time = filterTime(timeInput);

    cout << "\nOIL RELATED NOTES:\n";
    cout << "------------------\n";
    OilChange oilChange;
    oilChange.changeDates = date;
    cout << "Brand of Oil: ";
    cin >> oilChange.brand;
    cout << "Oil Viscosity [0W-00]: ";
    cin >> oilChange.viscosity;
    cout << "Amount of Oil (quarts): ";
    cin >> oilChange.oilAmount;

    printOilInfo(oilChange);
}

Date filterDate(string dateInput){
    Date date;
    for(int i = 0; i < dateInput.length(); i++){
        if(i < 2){
            date.month += dateInput[i];
        }
        else if((2 < i)&&(i < 5)){
            date.day += dateInput[i];
        }
        else if((5 < i)&&(i < 10)){
            date.year += dateInput[i];
        }
    }
    return date;
}

Time filterTime(string timeInput){
    Time time;
    string timeInterval;
    for(int i = 0; i < timeInput.length(); i++){
        if(i < 2){
            time.hour += timeInput[i];
        }
        else if((2 < i)&&(i < 5)){
            time.minute += timeInput[i];
        }
        else if((5 < i)&&(i < 8)){
            time.second += timeInput[i];
        }
        else if((8 < i)&&(i < 11)){
            timeInterval += timeInput[i];
        }
    }
    if(timeInterval == "AM"){
        time.tod = AM;
    }
    else if(timeInterval == "PM"){
        time.tod = PM;
    }
    else{
        time.tod = ERROR;
    }
    return time;
}

void printOilInfo(OilChange oilChange){
    cout << "\n#-------------------------------------------#\n";
    cout << "|              Oil Info Summary             |\n";
    cout << "#-------------------------------------------#\n";
    cout << "Oil Brand: " << oilChange.brand << "\n";
    cout << "Oil Viscosity: " << oilChange.viscosity << "\n";
    cout << "Oil Amount: " << oilChange.oilAmount << "\n";

    cout << "\n#---------------------------------------------#\n";
    cout << "|               Date/Time Summary             |\n";
    cout << "#---------------------------------------------#\n";
    cout << "Month: " << oilChange.changeDates.month << "\n";
    cout << "Day: " << oilChange.changeDates.day << "\n";
    cout << "Year: " << oilChange.changeDates.year << "\n";
    cout << "Hour: " << oilChange.changeDates.time.hour << "\n";
    cout << "Minute: " << oilChange.changeDates.time.minute << "\n";
    cout << "Second: " << oilChange.changeDates.time.second << "\n";
    cout << "AM/PM: " << oilChange.changeDates.time.tod << "\n";
}