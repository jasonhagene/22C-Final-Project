#include <string>

class Contact {
	private:
		//Location location;
		std::string name;
		std::string address;
		int contactNum;
	public:
		std::string getName() { return name; }
		std::string getAdress() { return address;}
		int getContactNum() { return contactNum; }
		//location getLocation(){ return location; }
};
