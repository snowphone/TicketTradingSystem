#include "Timer.h"
#include <ctime>



std::vector<Timer*> Timer::list;

void Timer::setTimer(std::string time, void(*callback)())
{
	deadline = time;
	this->callback = callback;
	this->list.push_back(this);
}

std::string Timer::currentTime;
Timer::Timer()
{
}
void Timer::setCurrentTime(const std::string & time)
{
	currentTime = time;
	update();
}

std::string Timer::getCurrentTime()
{
	return currentTime;
}

bool Timer::isExpired() const
{
	return currentTime > deadline;
}

std::string Timer::getDeadline() const
{
	return deadline;
}


Timer::~Timer()
{
}

void Timer::update()
{
	for(auto it = list.begin(); it != list.end(); ++it){
		if ((*it)->isExpired()) {
			if((*it)->callback)
				(*it)->callback();
			list.erase(it);
		}
	}
}

std::string makeTime(time_t t) {
	char buf[128];
	strftime(buf, sizeof(buf), "%Y:%m:%d:%H:%M", localtime(&t));
	return std::string(buf);
}

time_t parseTime(const std::string & str)
{	auto t = tm();
		sscanf(str.c_str(), "%d:%d:%d:%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min);
		t.tm_year -= 1900;
		t.tm_mon -= 1;
		return mktime(&t);
}
