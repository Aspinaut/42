#pragma once
#include <iostream>
#include <string>
using namespace std;

class Warlock
{
	public:
		Warlock(const string name, const string title);
		Warlock(const Warlock &rhs);
		~Warlock();
	
		void introduce() const;

		void setName(string name);
		string getName() const;
		void setTitle(string title);
		string getTitle() const;

	private:
		string _name;
		string _title;

};
