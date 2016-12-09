#include "GuideSystem.h"
#include <utility>

GuideSystem::GuideSystem(){
	guidance.insert(std::make_pair(1,"Wrong position! Need move!\n"));
	guidance.insert(std::make_pair(2,"Vehicle is not empty!\n"));
}

std::string GuideSystem::showGuidance(int i){
	return guidance[i];
}
