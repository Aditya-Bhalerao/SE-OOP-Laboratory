/*
Experiment No 7: Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and returns the population of the state.
*/

#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main()
{
	typedef map<string, int> mapType;
	mapType populationMap;

	populationMap.insert(make_pair("Andaman and Nicobar Islands UT", 0.3));
	populationMap.insert(make_pair("Andhra Pradesh", 49));
	populationMap.insert(make_pair("Arunachal Pradesh", 1.3));
	populationMap.insert(make_pair("Assam", 31));
	populationMap.insert(make_pair("Bihar", 104));
	populationMap.insert(make_pair("Chandigarh UT", 1));
	populationMap.insert(make_pair("Chhattisgarh", 25));
	populationMap.insert(make_pair("Dadra and Nagar Haveli and Daman and Diu UT", 0.5));
	populationMap.insert(make_pair("Delhi ", 16));
	populationMap.insert(make_pair("Goa", 1));
	populationMap.insert(make_pair("Gujarat", 60));
	populationMap.insert(make_pair("Haryana", 25));
	populationMap.insert(make_pair("Himachal Pradesh", 6));
	populationMap.insert(make_pair("Jammu and Kashmir", 12));
	populationMap.insert(make_pair("Jharkhand", 32));
	populationMap.insert(make_pair("Karnataka", 61));
	populationMap.insert(make_pair("Kerala", 33));
	populationMap.insert(make_pair("Ladakh UT", 0.2));
	populationMap.insert(make_pair("Lakshadweep UT", 0.06));
	populationMap.insert(make_pair("Madhya Pradesh", 72));
	populationMap.insert(make_pair("Maharashtra", 112));
	populationMap.insert(make_pair("Manipur", 2.5));
	populationMap.insert(make_pair("Meghalaya", 3));
	populationMap.insert(make_pair("Mizoram", 1));
	populationMap.insert(make_pair("Nagaland", 1));
	populationMap.insert(make_pair("Odisha", 42));
	populationMap.insert(make_pair("Puducherry UT", 1));
	populationMap.insert(make_pair("Punjab", 27));
	populationMap.insert(make_pair("Rajasthan", 68));
	populationMap.insert(make_pair("Sikkim", 0.6));
	populationMap.insert(make_pair("Tamil Nadu", 72));
	populationMap.insert(make_pair("Telangana", 35));
	populationMap.insert(make_pair("Tripura", 3));
	populationMap.insert(make_pair("Uttar Pradesh", 199));
	populationMap.insert(make_pair("Uttarakhand", 10));
	populationMap.insert(make_pair("West Bengal", 91));

	mapType::iterator iter = --populationMap.end();

	char c;
	do
	{
		string state;
		cout << "\nEnter state name: ";
		cin >> state;
		iter = populationMap.find(state);
		if (iter != populationMap.end())
		{
			cout << state << " State population: " << iter->second << " million (approximately)\n";
		}
		else
		{
			cout << "State is not present in population Map." << endl;
		}
		cout << "\nDo you want to continue?(y/n): ";
		cin >> c;
	} while (c == 'y' || c == 'Y');

	populationMap.clear();

	return 0;
}