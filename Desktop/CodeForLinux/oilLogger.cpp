#include <iostream>
#include "oilLogger.h"
using namespace std;

int main(){
    cout << "#-------------------------------------------#\n";
    cout << "|      DOCUMENT OIL CHANGE NOTES BELOW      |\n";
    cout << "#-------------------------------------------#\n";
    InputType input;
    Date date;
    input.timeFrameInput = takeInput(date, 0).timeFrameInput;
    date = filterDate(input.timeFrameInput.dateInput);
    date.time = filterTime(input.timeFrameInput.timeInput);
    input.oilChangeInput = takeInput(date, 1).oilChangeInput;
    cout << "\n##  OIL NOTES SAVED. RETURNING TO MENU  ##";
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

InputType takeInput(Date date, int infoType){
    InputType input;
    if(infoType == 0){
        input.inputType = 0;
        TimeFrameInput timeframe;
        cout << "\nTIME RELATED NOTES:\n";
        cout << "-------------------\n";
        cout << "Date [00/00/0000]: ";
        getline(cin, timeframe.dateInput);
        cout << "Time [00:00:00 AM] ";
        getline(cin, timeframe.timeInput);
        input.timeFrameInput = timeframe;
    }
    else if(infoType == 1){
        input.inputType = 1;
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
        input.oilChangeInput = oilChange;
    }
    return input;
}