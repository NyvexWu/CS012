#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char* argv[])
{
	string filename;
	string repeat = "Yes";
	vector<double> flightPathAngle;
	vector<double> coefficientOfLift;
	
	if(argc < 2)
	{
		cout << "usage " << argv[0] << " filename" << endl;
		return 1;
	}
	filename = argv[1];
	readData(filename, flightPathAngle, coefficientOfLift);
	if (isOrdered(flightPathAngle) == false)
	{
		reorder(flightPathAngle, coefficientOfLift);
	}
	while (repeat != "No" || repeat == "Yes")
	{
		double userAngle;
		cout << "Enter a flight-path Angle: ";
		cin >> userAngle;
		cout << endl;

		cout << interpolation(userAngle, flightPathAngle, coefficientOfLift) << endl;
		cout << "Do you want to enter another flight-path angle?" << endl;
		cin >> repeat;
	}
}

void readData(const string& filename,vector<double>& flightPathAngle, vector<double>& coefficientOfLift)
{
	ifstream inputFile;
	double hold;
	double temp;
	inputFile.open(filename);
	
	//fail to open
	if (!(inputFile.is_open()))
	{
		cout << "Error opening " << filename << endl;
		exit(EXIT_FAILURE);
	}
	//putting first column in one vector(flight-path angle) and second column in another(coefficient of lift)
	while (inputFile >> hold && inputFile >> temp)
	{	
		flightPathAngle.push_back(hold);	
		coefficientOfLift.push_back(temp);
		inputFile.ignore();
	}
		
	inputFile.close();
}

double interpolation(double b, const vector<double>& flightPathAngle, const vector<double>& coefficientOflift)
{
	double c;
	double cCoefficient;
	double a;
	double aCoefficient;
	double bCoefficient;
	double upper = flightPathAngle.at(flightPathAngle.size()-1);
	double lower = flightPathAngle.at(0);
	if (b <= upper && b >= lower)
	{
		for (unsigned int i = 0; i < flightPathAngle.size(); i++)
		{
			if (b == flightPathAngle.at(i))
				return coefficientOflift.at(i);
			else if(b < flightPathAngle.at(i))
			{
				if (flightPathAngle.at(i) > b)
				{
					//get c and f(c)
					c = flightPathAngle.at(i);
					cCoefficient = coefficientOflift.at(i);
					a = flightPathAngle.at(i - 1);
					aCoefficient = coefficientOflift.at(i - 1);
				}
				bCoefficient = aCoefficient + ((b - a) / (c - a)) * (cCoefficient - aCoefficient);
				return bCoefficient;
			}	
		}
	}
	return 1;
}

bool isOrdered(const vector<double>& flightPathAngle)
{
	for (unsigned int i = 1; i < flightPathAngle.size(); ++i)
	{
		//if at(i) > at(i+1) returns false and exit;
		if (flightPathAngle.at(i-1) > flightPathAngle.at(i))
		{
			return false;
		}
	}
	//if the vector is in order
	return true;
}

void reorder(vector<double>& flightPathAngle, vector<double>& coeffiencientOfLift)
{
	int smallIndex;
	double temp;
	double hold;
	for (unsigned int i = 0; i < flightPathAngle.size(); ++i)
	{
		smallIndex = i;
		for (unsigned int j = i + 1; j < flightPathAngle.size(); ++j)
		{
			if (flightPathAngle.at(j) < flightPathAngle.at(i))
			{
				smallIndex = j;
			}
		}
		//putting flight-path angle in order
		temp = flightPathAngle.at(i);
		flightPathAngle.at(i) = flightPathAngle.at(smallIndex);
		flightPathAngle.at(smallIndex) = temp;
		//matching coefficient of lift with original flight-path angle with the angle is moved
		hold = coeffiencientOfLift.at(i);
		coeffiencientOfLift.at(i) = coeffiencientOfLift.at(smallIndex);
		coeffiencientOfLift.at(smallIndex) = hold;
	}
}