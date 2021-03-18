# Massive_weather_process

Description:

This program was designed to read in a massive amount of weather data, store, and process them.
The data structure design plays a crucial role here since it makes difficult to read in tons of data
with a bad design. This program has ten sample files, each of them contains data such as Date, Wind speed,
Temperature, Solar radiation, and etc. of every ten minutes of a whole year (they are massive).

Files included in this project:

BST.H, Collect.H, Date.H, Date.CPP, Time.H, Time.CPP, Vector.H, main.CPP,

Data files (folder:data) - 
MetData_Jan01-2007-Dec31-2007-ALL.csv
MetData_Jan01-2008-Dec31-2008-ALL.csv
MetData_Jan01-2009-Dec31-2009-ALL.csv
MetData_Jan01-2010-Jan01-2011-ALL.csv
MetData_Jan01-2011-Jan01-2012-ALL.csv
MetData_Jan01-2012-Jan01-2013-ALL.csv
MetData_Jan01-2013-Jan01-2014-ALL.csv
MetData_Jan01-2016-Dec31-2016-ALL.csv
MetData_Mar01-2014-Mar01-2015-ALL.csv
MetData_Mar01-2015-Mar01-2016-ALL.csv



How to run "Massive_weather_process":

Once you create a project with all the .H and .CPP files, you can run it through the main.cpp program (please do not forget to include
the data file in the same directory as the source codes).



Design and implementation:

In this program, I have 10 sample data files, each containing weather data of a whole year of every ten minutes.
The structure used here is, map<Date,BST<WheatherLogType>> and Vector. That is, a BST contains stores data of one day and the map
gives a key, which is Date, to each BST. Once, all the data is read, they are stored into a Vector, which makes it easier to
access the data later on (also because I already had this Vector.h from a different project). This design manages duplicates and 
invalid data such as NULL and NaN.



What the program does:

-It reads in the data from the files at the beginning of the program.
-Display a menu for the user:
    1. The average wind speed and sample standard deviation for this speed for selected month and year
    2. The average ambient air temperature and sample standard deviation for each month of selected year
    3. Total solar radiation in kWh/m2 for each month of selected year
    4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of selected year (standar deviation next to average)
    5. The time of the highest solar radiation of a given day
    6. Press 'q' to quit

-User enters the option, the month or year as required.
-Grab the data needed for the given month/year and do the calculation
-Display the results
