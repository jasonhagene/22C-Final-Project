#include <string>

class Contact {
	private:
		//Location location;
		std::string name;
		int contactNum;
	public:
		std::string getName() { return name; }
		int getContactNum() { return contactNum; }
		//location getLocation(){ return location; }
};