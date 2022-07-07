#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "ATarget.hpp"

class ATarget;

class BrickWall : public ATarget
{
	public:
		BrickWall();
		~BrickWall();

        virtual ATarget *clone() const;

};