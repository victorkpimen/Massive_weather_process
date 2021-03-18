#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<math.h>
#include<cmath>
#include<map>
#include"Date.h" //Includes Date class
#include"Vector.h" //Includes Vector template class
#include"Time.h" //Includes Time class
#include"BST.h"
#include"Collect.h"

/*
 * Author: Victor Kavassaki Pimentel (33613433)
 * Date: 28/04/2020 Started
 * Due: 05/05/2020
 * Title: ICT283 Assignment 1
 * Purpose: Reads in from a file which contains weather information and
 * pass the data using data structure. Perform several operations depending on the user's options.
 */

using namespace std;

typedef struct {
    Date d;
    Time t;
    float speed;
    float sr;
    float temp;
} WeatherLogType; //A struct which holds Date, Time, wind speed, solar radiation, and temperature

typedef struct {
    Date date;
} mapKey; // A struct which will hold the key of the map

void startDisplay() // Display once files are read
{
    cout<<"ICT283 Assignment2"<<'\n';
    cout<<"Name: Victor Kavassaki Pimentel (33613433)"<<'\n';
    cout<<"Due: 12/06/2020 11:55pm"<<'\n';
    cout<<"Lab time: Friday 12:30pm"<<'\n';
}

ostream& operator<<(ostream& osObject, const WeatherLogType obj) // << overloading
{
    osObject<<obj.d.GetDay()<<"/"<<obj.d.GetMonth()<<"/"<<obj.d.GetYear()<<" "<<obj.t.GetHour()<<":"<<obj.t.GetMinute()<<obj.speed<<'\n';

    return osObject;
}

bool operator==(const WeatherLogType obj1, const WeatherLogType obj2) // == overloading
{
    bool same = false;

        if(obj1.d.GetYear()==obj2.d.GetYear()&&obj1.d.GetMonth()==obj2.d.GetMonth()&&obj1.d.GetDay()==obj2.d.GetDay()&&obj1.t.GetHour()==obj2.t.GetHour()&&obj1.t.GetMinute()==obj2.t.GetMinute()){
            same = true;
        }
    return same;
}

bool operator==(const mapKey date1, const mapKey date2) // == overloading
{
    bool same = false;

        if(date1.date.GetDay()==date2.date.GetDay()&&date1.date.GetMonth()==date2.date.GetMonth()&&date1.date.GetYear()==date2.date.GetYear()){
            same = true;
        }
    return same;
}


bool operator>(const WeatherLogType obj1, const WeatherLogType obj2) // > overloading
{
    bool large = false;

    /*USED WHEN INSERTING (SORTING) ITEMS THE TREE*/
        if(obj1.d.GetYear()>obj2.d.GetYear()){ // Items will be sorted according to name length
            large = true;
        }
        else if(obj1.d.GetYear()==obj2.d.GetYear()&&obj1.d.GetMonth()>obj2.d.GetMonth()){
            large = true;
        }
        else if(obj1.d.GetYear()==obj2.d.GetYear()&&obj1.d.GetMonth()==obj2.d.GetMonth()&&obj1.d.GetDay()>obj2.d.GetDay()){
            large = true;
        }
        else if(obj1.d.GetYear()==obj2.d.GetYear()&&obj1.d.GetMonth()==obj2.d.GetMonth()&&obj1.d.GetDay()==obj2.d.GetDay()&&obj1.t.GetHour()>obj2.t.GetHour()){
            large = true;
        }
        else if(obj1.d.GetYear()==obj2.d.GetYear()&&obj1.d.GetMonth()==obj2.d.GetMonth()&&obj1.d.GetDay()==obj2.d.GetDay()&&obj1.t.GetHour()==obj2.t.GetHour()&&obj1.t.GetMinute()>obj2.t.GetMinute()){
            large = true;
        }
    return large;
}

bool operator<(const mapKey date1, const mapKey date2) // > overloading
{
    bool large = false;

    /*USED WHEN INSERTING (SORTING) ITEMS THE TREE*/
        if(date1.date.GetYear()<date2.date.GetYear()){ // Items will be sorted according to name length
            large = true;
        }
        else if(date1.date.GetYear()==date2.date.GetYear()&&date1.date.GetMonth()<date2.date.GetMonth()){
            large = true;
        }
        else if(date1.date.GetYear()==date2.date.GetYear()&&date1.date.GetMonth()==date2.date.GetMonth()&&date1.date.GetDay()<date2.date.GetDay()){
            large = true;
        }

    return large;
}



unsigned ConvertInt(string fix) //Converts a string value into an unsigned value
{
    unsigned num;
    istringstream convert(fix);
    convert>>num;
    return num; // returns an unsigned number
}

float ConvertFloat(string fix) //Converts a string value into a float value
{
    float num;
    istringstream convert(fix);
    convert>>num;
    return num; // returns a float number
}

string ConvertString(float num) //Converts a float number value into string
{
    ostringstream ss;
    ss<<num;
    string s(ss.str());

    return s;
}

string ConvertMonthToString(int num){ //Converts a numeric month value into string

    string MonthString;

    switch(num){ //Switch case which takes a numeric value from 1-12 and converts into string

    case 1: MonthString = "January"; // 1 is January
        break;
    case 2: MonthString = "February"; // 2 is February
        break;
    case 3: MonthString = "March"; // 3 is March
        break;
    case 4: MonthString = "April"; // 4 is April
        break;
    case 5:MonthString = "May"; // 5 is May
        break;
    case 6: MonthString = "June"; // 6 is June
        break;
    case 7: MonthString = "July"; // 7 is July
        break;
    case 8: MonthString = "August"; // 8 is August
        break;
    case 9: MonthString = "September"; // 9 is September
        break;
    case 10: MonthString = "October"; // 10 is October
        break;
    case 11: MonthString = "November"; // 11 is November
        break;
    default:MonthString = "December"; // 12 is December
        break;
    }
    return MonthString; // returns the month value as string
}


void printMenu(){ //Displays the menu functions from 1-5

    cout<<"Menu options: "<<'\n';
    cout<<"1. The average wind speed and sample standard deviation for this speed for selected month and year"<<'\n';
    cout<<"2. The average ambient air temperature and sample standard deviation for each month of selected year"<<'\n';
    cout<<"3. Total solar radiation in kWh/m2 for each month of selected year"<<'\n';
    cout<<"4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of selected year (standar deviation next to average)"<<'\n';
    cout<<"5. The time of the highest solar radiation of a given day."<<'\n';
    cout<<"6. Press 'q' to quit"<<'\n';
}

float Round(float num){ //Round a float number to one decimal point

    num = (int)(num*10+0.5); //Formula to round off
    return (float)num/10; //returns a float number rounded to one decimal point
}

float CalculateAverage(const Vector<float> &array){ //Calculates the average of the elements in the array passed as parameter

    float sum = 0;

    for(int i=0;i<array.GetLength();i++){
        sum = sum + array[i]; //Add up all the elements in the array
    }

    sum =  sum/array.GetLength(); //Divide the sum by the length of the array
    sum = Round(sum); //Rounds its result using Round() function
    return sum; //returns the average
}

float CalculateSD(const Vector<float> &array, float mean){ //Calculate the standard deviation of the elements of the array passed as parameter with its mean
    float sum = 0;

    for(int i=0;i<array.GetLength();i++){
        sum = sum + (array[i]-mean)*(array[i]-mean); //Add what go in the square brackets of the standard deviation formula
    }

    if(array.GetLength()<2){
        sum = 0;
    }
    else{
    sum = sqrt(sum/array.GetLength()); //Puts in a square brackets
    }
    sum = Round(sum); //Rounds its result using Round() function
    return sum; //returns the standard deviation
}

float TotalSR(const Vector<float> &array){ //Calculates the total solar radiation in kWh/m2

    float sum = 0;

    for(int i=0;i<array.GetLength();i++){
        sum = sum + array[i]; //Add up all the elements in the array passed as parameter
    }

    sum = (sum/6)/1000; //Converts into kWh/m2 from W/m2
    sum = Round(sum); //Rounds the result using Round() function
    return sum; //returns the total solar radiation in kWh/m2
}

void readFile(map<mapKey,BST<WeatherLogType>>& mapWeather, char* fileName){ //Read in from a file and put the data into the array passed as parameter

    BST<WeatherLogType> weatherlog; //BST which will hold the data read from file (will be reused for each day)

    ifstream infile;
    infile.open(fileName); //Opens the file
    if(!infile){
        cout<<"Error with file"; //Displays an error message and exit from the program in case file is not found
        exit(-1);
    }else{ //Does the following when file exists
        infile.ignore(100,'\n'); //Ignore all the strings in the first line

        int i = 0;
        int sum;

        while(!infile.eof()){ //Loop the process of reading from file till end of the file
            unsigned day; //Day
            unsigned month; //Month
            unsigned year; //Year
            string line; //A string which used to replace the numeric values temporarily
            unsigned hour; //Hour
            unsigned minute; //Minute
            float speed; //Wind speed (S)
            float sr; //Solar radiation (SR)
            float temp; //Temperature (T)

            /* DAY */
            getline(infile,line,'/');
            day = ConvertInt(line);
            /* MONTH */
            getline(infile,line,'/');
            month = ConvertInt(line);
            /* YEAR */
            getline(infile,line,' ');
            year = ConvertInt(line);
            /* HOUR */
            getline(infile,line,':');
            hour = ConvertInt(line);
            /* MINUTE */
            getline(infile,line,',');
            minute = ConvertInt(line);

            for(int k=0;k<9;k++){ //Ignores non neceessary data between minute and wind speed
                infile.ignore(9,',');
            }
            /* S */
            getline(infile,line,',');
            speed = ConvertInt(line);
            for(int i=0;i<line.length();i++){
                if(isdigit(line[i])==false){ //Sets speed as NAN if not a digit
                    speed = NAN;
                }
            }
            /* SR */
            getline(infile,line,',');
            sr = ConvertInt(line);
            for(int i=0;i<line.length();i++){
                if(isdigit(line[i])==false){ //Sets solar radiation as NAN if not a digit
                    sr = NAN;
                }
            }

            for(int i=0;i<5;i++){ //Ignores non necessary data between solar radiation and temperature
            getline(infile,line,',');
            }
            /* T */
            getline(infile,line,'\n');
            temp = ConvertFloat(line);
                if(isdigit(line[0])==false){ //Sets temperature as NAN if not a digit
                    temp = NAN;
                }

            if(infile.eof()){ //Breaks the loop when end of the file is reached
                break;
            }

            WeatherLogType record; //An object that holds the data for each loop
            record.speed = speed;//Assign the speed data read from the file to the object
            record.sr = sr; //Assign the solar radiation data read from the file to the object
            record.temp = temp; //Assign the temperature data read from the file to the object
            record.t = Time(hour,minute); //Puts the time data into Time constructor
            record.d = Date(day,month,year); //Puts the date time into Date constructor

            mapKey key; //Key object of type myKey
            key.date = Date(day,month,year); //Assign the values read from the file to the key object

           if(mapWeather.find(key)==mapWeather.end()){ //If key (date) is not found in the map, create a temporary tree and insert the WeatherLogType object
                BST<WeatherLogType> bin;
                weatherlog = bin;
                weatherlog.insertNode(record);
                mapWeather.insert(pair<mapKey,BST<WeatherLogType>>(key,weatherlog));
           }
            else{
                mapWeather[key].insertNode(record); //If dsame date, keep inserting in the same tree
           }

        }//End of while loop

    infile.close(); //Closes the file
    cout<<"file read"<<'\n';
    }
}

unsigned EnterYear(){ //Gets the year input from the user

    unsigned num;
    cout<<"Enter the year in number (e.g. 2020)"<<'\n';
    cin>>num;

    return num; //returns the year
}

unsigned EnterMonth(){ //Gets the month input from the user

    unsigned num;
    cout<<"Enter the month in number (e.g. 3 for March)"<<'\n';
    cin>>num;

    return num; //returns the month
}

unsigned EnterDay(){ //Gets the day input from the user

    unsigned num;
    cout<<"Enter the day in number (e.g. 14, 25)"<<'\n';
    cin>>num;

    return num; //returns the day
}


void MenuOpe(map<mapKey, BST<WeatherLogType>> weatherMap, int option){ //Performs the operations of menu from 1-4

    switch(option){ //Switch case of a given option

    case 1:
        {
        CollectU<WeatherLogType> data1;
        map<mapKey,BST<WeatherLogType>>::iterator itr;
        BST<WeatherLogType> dataTree;
        Vector<float> spdata; //Array which will hold the wind speed data of given year and month
        string month; //month in string
        unsigned year = EnterYear(); //Gets year input from the user
        unsigned NumMonth = EnterMonth(); //Gets the month input from the user

        month = ConvertMonthToString(NumMonth); //Converts the month input from user into string

        while(NumMonth<1||NumMonth>12){ //Displays an error message when month input is not valid and let the user input again
            cout<<"Invalid number for month... try again:"<<'\n';
            cin>>NumMonth;
        }

        mapKey key;
        mapKey tempKey;
        key.date.SetYear(year);
        key.date.SetMonth(NumMonth);

        for(itr=weatherMap.begin();itr!=weatherMap.end();itr++){ //Loops throughout the length of weatherlog
                tempKey = itr->first;
                if(tempKey.date.GetYear()==year&&tempKey.date.GetMonth()==NumMonth){ //If the key matches with the Year and Month of the BST, collect data from that BST
                    dataTree = weatherMap.at(tempKey);
                    dataTree.inorderTraversal(CollectU<WeatherLogType>::vecCollect);
            }
        }
        for(int i=0;i<data1.size();i++){
            if(!isnan(data1[i].speed)){ //If speed is not NAN
            spdata.pushIn(data1[i].speed*3.6); //If they match, insert data in the end of the array
            }
        }

        cout<<month<<" "<<year<<":"<<'\n'; //Display year and month

        if(spdata.GetLength()<5){
            cout<<"No Data"<<'\n';
        }
        else{
        if(CalculateAverage(spdata)==0){
            cout<<"No Data"<<'\n'; //If there is no data in the array, display "No data"
        }
        else{

        float speedAve = CalculateAverage(spdata); //Calculates the wind speed average of the given year and month
        float speedSD = CalculateSD(spdata, speedAve); //Calculates the standard deviation of the windspeed of the given year and month

        cout<<"Average speed: "<<speedAve<<"km/h"<<'\n'; //Displays wind speed average
        cout<<"Sample stdev: "<<speedSD<<'\n'; //Displays the standard deviation of the windspeed
        }
        }
        data1.deleteData(); //Clears the items in the collector vector which is static for reuse
        break;
        }

    case 2:
    {
        CollectU<WeatherLogType> data2;
        map<mapKey,BST<WeatherLogType>>::iterator itr;
        BST<WeatherLogType> dataTree;
        Vector<WeatherLogType> yeardata; //An array which will hold the data of a given year

        unsigned year = EnterYear(); //Gets the year input from user

        mapKey key;
        mapKey tempKey;
        key.date.SetYear(year);

        for(itr=weatherMap.begin();itr!=weatherMap.end();itr++){ //Loops throughout the length of weatherlog
                tempKey = itr->first;
                if(tempKey.date.GetYear()==year){ //If key matches with the Year of a BST, collect data from that BST
                    dataTree = weatherMap.at(tempKey);
                    dataTree.inorderTraversal(CollectU<WeatherLogType>::vecCollect);
            }
        }
        for(int i=0;i<data2.size();i++){
            if(!isnan(data2[i].temp)){ //If temperature value is not NAN
            yeardata.pushIn(data2[i]); //Insert the data of the whole year in a vector
            }
        }


        cout<<year<<'\n'; //Display the year
        if(yeardata.GetLength()<5){
            cout<<"No Data"<<'\n';
        }
        else{
        for(int i=1;i<=12;i++){ //Loop through each month
            Vector<float> tempdata; //Array which will hold the data for each month
            string tempMonth = ConvertMonthToString(i); //Converts the month number into string

            for(int j=0;j<yeardata.GetLength();j++){
                if(yeardata[j].d.GetMonth()==i){
                    tempdata.pushIn(yeardata[j].temp); //If the month data matches the one being looped, insert the temperature data into the end of the array
                }
            }

            if(tempdata.GetLength()<5){
                cout<<tempMonth<<": No Data"<<'\n';
            }
            else{
            if(CalculateAverage(tempdata)==0){
                cout<<tempMonth<<": No Data"<<'\n'; //Display "No Data" when there is no data for a specific month
            }
            else{
            float tempave = CalculateAverage(tempdata); //Calculates the average of the temperature of each month
            float tempSD = CalculateSD(tempdata, tempave); //Calculates the standard deviation of the temperature of each month

            cout<<tempMonth<<": Average: "<<tempave<<" degree C, "<<"Stdev: "<<tempSD<<'\n'; //Display the results
            }
            }
        }
        }
            data2.deleteData(); //Clears collector vector which is static for reuse
            break;
    }

    case 3:
    {
        CollectU<WeatherLogType> data3;
        map<mapKey,BST<WeatherLogType>>::iterator itr;
        BST<WeatherLogType> dataTree;
        Vector<WeatherLogType> yeardata; //An array which will hold the data of a given year

        unsigned year = EnterYear(); //Gets the year input from user

        mapKey key;
        mapKey tempKey;
        key.date.SetYear(year);

        for(itr=weatherMap.begin();itr!=weatherMap.end();itr++){ //Loops throughout the length of weatherlog
                tempKey = itr->first;
                if(tempKey.date.GetYear()==year){ //If key matches with the Year of a BST, collect data from that BST
                    dataTree = weatherMap.at(tempKey);
                    dataTree.inorderTraversal(CollectU<WeatherLogType>::vecCollect);
            }
        }
        for(int i=0;i<data3.size();i++){
            yeardata.pushIn(data3[i]); //Insert the data of the whole year in a vector
        }
        cout<<year<<'\n'; //Display the year

        float srTotal;
        if(yeardata.GetLength()<5){
            cout<<"No Data"<<'\n';
        }
        else{
        for(int i=1;i<=12;i++){
            Vector<float> srdata; //Array which will hold solar radiation data of each month being looped

            for(int j=0;j<yeardata.GetLength();j++){
                if(yeardata[j].d.GetMonth()==i&&yeardata[j].sr>=100){ //If month value matches and solar radiation is bigger than 100
                    if(!isnan(yeardata[j].sr)){ //If solar radiation is not NAN
                    srdata.pushIn(yeardata[j].sr); //If the month matches the one being looped and solar radiation is larger than 100, insert into the end of the array
                    }
                }
            }
            string srMonth = ConvertMonthToString(i); //Convert month number into string

            if(TotalSR(srdata)==0){
                cout<<srMonth<<": "<<"No Data"<<'\n'; //Display "No Data" if there is no that for specific month
            }
            else{
            srTotal = TotalSR(srdata); //Calculate the total solar radiation of each month in kWh/m2
            cout<<srMonth<<": "<<srTotal<<" kWh/m2"<<'\n'; //Display the results
            }
        }
        }
        data3.deleteData(); //Clears collector vector which is static for reuse
        break;
    }

    case 4:
    {
        CollectU<WeatherLogType> data4;
        map<mapKey,BST<WeatherLogType>>::iterator itr;
        BST<WeatherLogType> dataTree;
        Vector<WeatherLogType> yeardata; //An array which will hold the data of a given year

        unsigned year = EnterYear(); //Gets the year input from user

        mapKey key;
        mapKey tempKey;
        key.date.SetYear(year);

        for(itr=weatherMap.begin();itr!=weatherMap.end();itr++){ //Loops throughout the length of weatherlog
                tempKey = itr->first;
                if(tempKey.date.GetYear()==year){ //If key matches with the Year of a BST, collect data from that BST
                    dataTree = weatherMap.at(tempKey);
                    dataTree.inorderTraversal(CollectU<WeatherLogType>::vecCollect);
            }
        }
        for(int i=0;i<data4.size();i++){
            yeardata.pushIn(data4[i]); //Insert the data of the whole year in a vector
        }

        ofstream ofile("WindTempSolar.csv"); //csv file which data will be put in
        cout<<year<<'\n';
        ofile<<year<<'\n';

        if(yeardata.GetLength()<5){
            cout<<"No Data"<<'\n'; //Displays "No Data" if the given year contains no data
            ofile<<"No Data"<<'\n';
        }
        else{
            for(int i=1;i<=12;i++){ //Loops through each month
                Vector<WeatherLogType> monthdata; //Array which will hold data of the month being looped
                Vector<float> speeddata; //Array which will hold wind speed data of the month being looped
                Vector<float> srdata; //Array which will hold solar radiation data of the month being looped
                Vector<float> tempdata; //Array which will hold temperature data of the month being looped
                string tempMonth = ConvertMonthToString(i); //Converts month number into string

                for(int k=0;k<yeardata.GetLength();k++){ //Loops throught out the year array
                    if(yeardata[k].d.GetMonth()==i){
                        monthdata.pushIn(yeardata[k]); //If the month in the year array matches with the one being looped, insert month data in the array
                    }
                }
                if(monthdata.GetLength()<5){
                    cout<<""; //Does not display anything when the month contains no data
                    ofile<<"";
                }
                else{
                for(int j=0;j<monthdata.GetLength();j++){
                    if(!isnan(monthdata[j].speed)){ //If speed data is not NAN
                    speeddata.pushIn(monthdata[j].speed*3.6); //Inserts the wind speed data of the month being looped in the array
                    }
                    if(monthdata[j].sr>=100&&!isnan(monthdata[j].sr)){//If solar radiation data is bigger than 100 and is not NAN
                        srdata.pushIn(monthdata[j].sr); //Inserts the solar radiation data of the month being looped in the array
                    }
                    if(!isnan(monthdata[j].temp)){ //If temperature data is not NAN
                    tempdata.pushIn(monthdata[j].temp); //Inserts the temperature data of the month being looped in the array
                    }
                }

                cout<<tempMonth<<",";
                ofile<<tempMonth<<",";

                float spave = CalculateAverage(speeddata); //Calculates the average wind speed
                float spsd = CalculateSD(speeddata, spave); //Calculates the standard deviation of the wind speed
                if(spave==0){
                    cout<<","; //Prints a comma when wind speed does not contain data
                    ofile<<",";
                }
                else{
                    cout<<spave<<"("<<spsd<<"),";
                    ofile<<spave<<"("<<spsd<<")"<<",";
                }
                float tempave = CalculateAverage(tempdata); //Calculates the average temperature
                float tempsd = CalculateSD(tempdata, tempave); //Calculates the standard deviation of the temperature
                if(tempave==0){
                    cout<<","; //Prints a comma when temperature does not contain data
                    ofile<<",";
                }
                else{
                    cout<<tempave<<"("<<tempsd<<"),";
                    ofile<<tempave<<"("<<tempsd<<")"<<",";
                }
                float totalsr = TotalSR(srdata); //Calculates the total solar radiation
                if(totalsr==0){
                    cout<<""<<'\n'; //Prints a comma when solar radiation does not contain data
                    ofile<<""<<'\n';
                }
                else{
                    cout<<totalsr<<'\n';
                    ofile<<totalsr<<'\n';
                }
                }
            }
        }
        data4.deleteData(); //Clears the collector vector which is static for reuse
        ofile.close();
    break;
    }

    case 5:
        {
        CollectU<WeatherLogType> data5;
        map<mapKey,BST<WeatherLogType>>::iterator itr;
        BST<WeatherLogType> dataTree;
        Vector<WeatherLogType> daydata; //An array which will hold the data of a given year

        unsigned year = EnterYear(); //Gets the year input from user
        unsigned month = EnterMonth(); //Gets the month input from user
        unsigned day = EnterDay(); //Gets the day input from user

        mapKey key;
        mapKey tempKey;
        key.date = Date(day,month,year);

        for(itr=weatherMap.begin();itr!=weatherMap.end();itr++){ //Loops throughout the length of weatherlog
                tempKey = itr->first;
                if(tempKey.date.GetYear()==year&&tempKey.date.GetMonth()==month&&tempKey.date.GetDay()==day){ //If the Date matches with a BST, collect data from that BST
                    dataTree = weatherMap.at(tempKey);
                    dataTree.inorderTraversal(CollectU<WeatherLogType>::vecCollect);
            }
        }
        if(data5.size()<5){
                cout<<"No data"<<'\n';
        }
        else{
        for(int i=0;i<data5.size();i++){
            if(data5[i].sr>=100&&!isnan(data5[i].sr)){ //If solar radiation is bigger than 100 and is not NAN
            daydata.pushIn(data5[i]); //Insert the data of the whole year in a vector
            }
        }
            float largest = 0; //Temporary value to hold the largest solar radiation value

            for(int i=0;i<daydata.GetLength();i++){
                if(daydata[i].sr>largest){ //If it is bigger than temporary largest value, assign that to largest
                    largest = daydata[i].sr;
                }
            }

            cout<<"Date: "<<day<<"/"<<month<<"/"<<year<<'\n';
            cout<<"Highest solar radiation of the day: "<<largest<<"W/m2"<<'\n';
            cout<<"Time: "<<'\n';

            for(int i=0;i<daydata.GetLength();i++){
                if(daydata[i].sr==largest){ //If there are more than one value, prints out all of them
                    cout<<daydata[i].t.GetHour()<<":"<<daydata[i].t.GetMinute()<<'\n';
                }
            }
        }
        break;
        }
    default:
        exit(0);
    }
}



int main(){ //Main function

    map<mapKey ,BST<WeatherLogType>> mapWeather;; //key: year, value: BST BST<Vector<WeatherLogType>>

    ifstream indexFile;
    indexFile.open("data/met_index.txt");

    if(!indexFile){
        cout<<"Error opening the file"<<'\n';
        exit(1);
    }
    else{
    while(!indexFile.eof()){

        string fileName;
        getline(indexFile,fileName,'\n'); //Reads in file name from index file
        char d[50] = "data/";
        char file[50];

        for(int i=0;i<fileName.length();i++){
            file[i] = fileName[i];
        }

        strcat(d, file);
        cout<<file<<'\n';

        readFile(mapWeather, d); //Read in from file
    }

        startDisplay();

        unsigned option;

        do{
        //* Display menu options */
            printMenu(); //Displays the menu options

            cin>>option; //Gets the menu option input from the user
            while(option<1||option>6){
            cout<<"Invalid option number... try again"<<'\n'; //Displays an error message when option number is not valid
            cin>>option; //Lets the user enter the option again
            }
        MenuOpe(mapWeather, option); //Does the operation according to the user's option
        }while(option!=6); //Loop the process until user chooses 6 which means quit the program
    }

   return 0;
}










