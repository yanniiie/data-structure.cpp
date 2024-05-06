#include <bits/stdc++.h>
using namespace std;

struct Date {
    int day, month, year;

    Date(int d, int m, int y):day(d), month(m), year(y) {}

    bool isValidDate(){
        if (year < 0)
            return false;
        if (month < 1 || month > 12) // Months should be between 1 and 12
            return false;
        if (day < 1 || day > daysInMonth(month, year))
            return false;
        return true;
    }

    void newDate(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }

    string printDate() const {
        static const string months[] = {
            "", "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"
        };
        stringstream ss;
        ss << day << " " << months[month] << " " << year;
        return ss.str();
    }

    bool operator<(const Date& other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }

    int daysInMonth(int m, int y) const {
        switch (m) {
            case 1:  // January
            case 3:  // March
            case 5:  // May
            case 7:  // July
            case 8:  // August
            case 10: // October
            case 12: // December
                return 31;
            case 4:  // April
            case 6:  // June
            case 9:  // September
            case 11: // November
                return 30;
            case 2:
                return (isLeapYear(y)) ? 29 : 28;
            default:
                throw std::logic_error("Invalid month");
        }
    }

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

int getDayOfWeek() const {
    int d = day, m = month, y = year;

    // Adjust month for Zeller's Congruence (March = 3, April = 4, ..., January = 13, February = 14 of the previous year)
    if (m < 3) {
        m += 12;
        y--;
    }

    int k = y % 100;   // year within century
    int j = y / 100;   // century
    int h = (d + ((m + 1) * 26) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;

    // Convert Zeller's Congruence result to day of week (0 = Saturday, 1 = Sunday, ..., 6 = Friday)
    int dayOfWeek = (h + 5) % 7 + 1; // Adjusted so Monday = 1, ..., Sunday = 7
    return dayOfWeek;
}



    int calculateDifference(const Date& other) const {
        int days1 = day + 31 * (month - 1) + 365 * year;
        for (int i = 0; i < year; i++) {
            if (isLeapYear(i))
                days1++;
        }

        int days2 = other.day + 31 * (other.month - 1) + 365 * other.year;
        for (int i = 0; i < other.year; i++) {
            if (other.isLeapYear(i))
                days2++;
        }

        return abs(days2 - days1);
    }
};

int main() {
    string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    Date d1(25, 3, 2001);
    Date d2(6, 7, 2004);
    Date d3(25, 11, 2009);
    Date d4(27, 8, 2015);

    d2.newDate(10, 7, 2024);

    cout << d1.printDate() << " is " << daysOfWeek[d2.getDayOfWeek()] << endl;
    cout << "The difference between " << d1.printDate() << " and " << d2.printDate() << " is " << d1.calculateDifference(d2) << " days " << endl;

    vector<Date> dates = {d1, d2, d3, d4};

    sort(dates.begin(), dates.end());

    cout << "Sorted dates:" << endl;
    for (auto date : dates) {
        cout << date.printDate() << endl;
    }
    return 0;
}
