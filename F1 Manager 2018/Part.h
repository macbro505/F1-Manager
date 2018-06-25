#ifndef _PART_H_
#define _PART_H_
#include <string>
class Part {
public:
	friend std::ostream& operator<<(std::ostream & os, const Part & part);
	unsigned int quality;
	float price;
	std::string part_name;
	/////////////////////////////////////////////////////////////////////
	void setname(std::string set_name);
	Part(float price,unsigned int quality, std::string name);
	Part();
	~Part();
};
#endif