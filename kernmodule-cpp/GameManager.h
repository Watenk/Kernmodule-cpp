#pragma once

#include <list>
#include "BaseClass.h"

using std::list;

class GameManager {
public:
	GameManager();
	void update();
	void ups();
	void addBaseClass(BaseClass* newBaseClass);
	void removeBaseClass();

private:
	void updateUps();

	list<BaseClass*> baseClassObjects;
};