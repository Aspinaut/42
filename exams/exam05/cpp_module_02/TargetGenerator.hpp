#pragma once

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();
	
		void learnTargetType(ATarget*);
		void forgetTargetType(string const &);
		ATarget* createTarget(string const &);

	private:
		TargetGenerator(TargetGenerator const &ref);
		TargetGenerator &operator=(TargetGenerator const &ref);

};