#pragma once

#include <list>
#include "BaseClass.h"

using std::list;

class GameManager {
public:
	GameManager();
	void addBaseClass();
	void removeBaseClass();

private:
	list<BaseClass*> baseClassObjects;
};