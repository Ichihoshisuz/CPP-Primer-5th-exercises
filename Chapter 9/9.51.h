#include <iostream>
#include <vector>
#include <string>
class calendar {
public:
	friend std::ostream &out(std::ostream& os,const calendar &data);
public:
	calendar(std::string &s);
	calendar() = default;
private:
	unsigned int month=0;
	unsigned int day=0;
	unsigned int year=0;
	std::vector<std::string> vmonth{ "January","February","March","April","May",
		"June","July","August","September","October","November","December" };
	std::vector<std::string> vsmon{ "Jan","Feb","Mar","Apr","May","Jun",
		"Jul","Aug","Sep","Oct","Nov","Dec" };
	std::vector<std::string> svi{ "1","2","3","4","5","6","7","8","9","10","11","12" };
	std::string number = "1234567890";
};
calendar::calendar(std::string &s) {
	for (int i=11;i!=-1;--i){
		if (s.find(vsmon[i]) == 0){
			auto pos = s.find(vsmon[i]);
			month = std::stoi(svi[i]);
			if (s.find(vmonth[i])!=std::string::npos)
				pos += vmonth[i].size();
			else
				pos += vsmon[i].size();
				if ((pos=s.find_first_of(number, pos))!=std::string::npos){
					std::string sday;
					sday.push_back(s[pos]);
					++pos;
					if ('0'<=s[pos]&&s[pos]<='9')
					{
						sday.push_back(s[pos]);
						++pos;

					}
					day = stoi(sday);
						if ((pos=s.find_first_of(number, pos)) != std::string::npos){
							std::string syear = s.substr(pos,1);
							if(pos<s.size()){
								pos += 1;

								while ((pos=s.find_first_of(number, pos)) != std::string::npos&&pos <s.size()) {
									syear += s[pos];
									++pos;
								}
							}
							year = stoi(syear);
							break;
						}
				}
			
		}
		else if (s.find_first_of(number)==0)
		{
			auto pos = s.find(svi[i]);
			month = std::stoi(svi[i]);
			pos += svi[i].size()+1;
			if ((pos = s.find_first_of(number, pos)) != std::string::npos) {
				std::string sday;
				sday.push_back(s[pos]);
				++pos;
				if ('0' <= s[pos] && s[pos] <= '9')
				{
					sday.push_back(s[pos]);
					++pos;
				}
				day = stoi(sday);
				if ((pos = s.find_first_of(number, pos)) != std::string::npos) {
					std::string syear = s.substr(pos, 1);
					if (pos<s.size() - 1) {
						pos += 1;
						while ((pos = s.find_first_of(number, pos)) != std::string::npos&&pos <s.size()) {
							syear += s[pos];
							++pos;
						}
					}
					year = stoi(syear);
					break;
				}
			}
		}
	}
}
std::ostream &out(std::ostream &os, const calendar &data)
{
	os << data.month << "/" << data.day << "/" << data.year << std::endl;
	return os;
}