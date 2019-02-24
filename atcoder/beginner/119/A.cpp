#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;

	getline(cin, s, '/');
	int year = stoi(s);

	getline(cin, s, '/');
	int month = stoi(s);

	getline(cin, s);
	int day = stoi(s);

	if(year > 2019) cout << "TBD\n";
	else if(year < 2019) cout << "Heisei\n";
	else
	{
		if(month > 4) cout << "TBD\n";
		else if(month < 4) cout << "Heisei\n";
		else
		{
			if(day > 30) cout << "TBD\n";
			else cout << "Heisei\n";
		}
	}
}