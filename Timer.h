#pragma once
#include <string>
#include <vector>
#include <algorithm>
class Timer
{
	static std::string currentTime;
	static std::vector<Timer*> list;
	std::string deadline;
	void(*callback)() = nullptr;
public:
	static std::string makeTime(time_t t);
	static time_t parseTime(const std::string& str);
	Timer();
	void setTimer(std::string time, void(*callback)());
	static void setCurrentTime(const std::string& time);
	static std::string getCurrentTime();
	bool isExpired() const;
	std::string getDeadline() const;
	~Timer();

private:
	static void update();
};

