#include <iostream>

using namespace std;
#include "Distance.h"


Distance::Distance()
{
    /* Constructs a default Distance of 0 (0 feet and 0.0 inches)
   */
    feet = 0;
    inches = 0.0;
}



Distance::Distance(unsigned ft, double in)
{
    /* Constructs a distance of ft feet and in inches,
     unless in >= 12, in which case the values of feet and inches
     are adjusted accordingly. A Distance will always be positive.
     Just convert negative inches to positive. Don't subtract from feet.
*/
    feet = ft;
    inches = in;
    init();
}


Distance::Distance(double in)
{
    /* Constructs a distance of 0 ft and in inches,
     unless in >= 12, in which case the values of feet and inches
     are adjusted accordingly. A Distance will always be positive.
     Just convert negative inches to positive. Don't subtract from feet.
*/
    feet = 0;
    inches = in;
    init();
}


unsigned Distance::getFeet() const
{
    /* Returns just the feet portion of the Distance
*/
    return feet;
}


double Distance::getInches() const
{
    /* Returns just the inches portion of the Distance
*/
    return inches;
}

double Distance::distanceInInches() const
{
    /* Returns the entire distance as the equivalent amount of inches.
     (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
    double totalInches;
    double feetToInches;
    feetToInches = feet * 12;
    totalInches = inches + feetToInches;
    return totalInches;
}


double Distance::distanceInFeet() const
{
    /* Returns the entire distance as the equivalent amount of feet.
     (e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
    double totalFeet;
    double inchesToFeet;
    inchesToFeet = inches / 12;
    totalFeet = feet + inchesToFeet;
    return totalFeet;
    
}


double Distance::distanceInMeters() const
{
    /* Returns the entire distance as the equivalent amount of meters.
     1 inch equals 0.0254 meters.
     (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
    double feetToInches;
    double totalInches;
    double inchesToMeter;
    feetToInches = feet * 12;
    totalInches = inches + feetToInches;
    inchesToMeter = totalInches * 0.0254;
    return inchesToMeter;
}


Distance Distance::operator+(const Distance& rhs) const
{
    /* Returns the sum of 2 Distances.
*/
    Distance totalDistance;
    totalDistance.feet = feet + rhs.feet;
    totalDistance.inches = inches + rhs.inches;
    while (totalDistance.inches >= 12)
    {
        totalDistance.inches -= 12;
        totalDistance.feet += 1;
    }
    return totalDistance;
}


Distance Distance::operator-(const Distance& rhs) const
{
    /* Returns the difference between 2 Distances.
*/
    Distance feetToInches;
    Distance feetToInchesrhs;
    Distance difference;
    feetToInches.inches = inches + (feet * 12);
    feetToInchesrhs.inches = rhs.inches + (rhs.feet * 12);
    difference.inches = feetToInches.inches - feetToInchesrhs.inches;
    if (difference.inches < 0)
    {
        difference.inches = difference.inches * -1;
    }
    while (difference.inches >= 12)
    {
        difference.feet += 1;
        difference.inches -= 12;
    }
    return difference;
}
ostream& operator<<(ostream& out, const Distance& rhs)
{
    /* Outputs to the stream out the Distance in the format:
     feet' inches'' (i.e. 3' 3.41'')
*/
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init()
{
    /* Used by the 2 parameterized constructors to convert any negative values to positive and
     inches >= 12 to the appropriate number of feet and inches.
*/
    if (feet < 0)
    {
        feet = feet * -1;
    }
    if (inches < 0)
    {
        inches = inches * -1;
    }
    while (inches >= 12)
    {
        feet = feet + 1;
        inches = inches - 12;
    }
}
