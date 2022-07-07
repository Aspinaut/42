#pragma once
#include <iostream>
#include <string>
using namespace std;

class Warlock
{
	public:
		Warlock(const string &name, const string &title);
		~Warlock();
	
		void introduce() const;

		const string &getName() const;
		void setTitle(const string &title);
		const string &getTitle() const;

	private:
		const string _name;
		string _title;

		Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
};
