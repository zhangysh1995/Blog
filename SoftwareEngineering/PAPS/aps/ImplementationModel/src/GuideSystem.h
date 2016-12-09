#include <string>
#include <map>
class GuideSystem{
public:
	GuideSystem();
	std::string showGuidance(int i);
private:
	std::map<int,std::string>guidance;
};
