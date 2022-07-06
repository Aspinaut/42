#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();

        virtual ATarget *clone() const;

};