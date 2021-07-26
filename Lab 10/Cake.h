#pragma once
#include"BakedGood.h"

using namespace std;

class Cake : public BakedGood {
public:
	Cake();
protected:
	string cakeFlavor;
	string frostingFlavor;
};