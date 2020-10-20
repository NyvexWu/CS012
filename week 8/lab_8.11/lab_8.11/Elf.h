#include <string>
#include "Character.h"
using namespace std;

#ifndef __ELF_H__
#define __ELF_H__
class Elf : public Character
{
	private:
		string family;
	public:
		Elf(
			const string&,
			const double&,
			const double&,
			string);
		void damage(double d);
		void attack(Character& opponent) override;
};
#endif
