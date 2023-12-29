#pragma once
#include <list>

class CharList {
	public:
		CharList (const char* str);
		~ CharList ();
		bool CheckPalindrome();
		std::list<char> GetAll();
	private:
		std::list<char> mystring_;
};
