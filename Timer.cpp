//Class: Timer
//Description: 시간과 관련된 기능을 담당하는 클래스이다.
//Author: 김상엽
// Created: 2019/06/03
// Mail: natsuko0012@gmail.com

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create file
//
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: modify ambiguous var name and add comment
//
// 		3.	When & Who: 2019/06/03 by 김상엽
// 				What: temp modification
//
// 		4.	When & Who: 2019/06/03 by 김상엽
// 				What: complete


#include "Timer.h"
#include <ctime>



std::vector<Timer*> Timer::list;

void Timer::setTimer(std::string time, void(*callback)())
{
	//데드라인 설정 및 데드라인시 수행할 콜백함수 설정
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
	// 타이머가 만료되었는지 확인한다.
	return currentTime > deadline;
}

std::string Timer::getDeadline() const
{
	return deadline;
}


Timer::~Timer()
{
	auto it = std::find(list.begin(), list.end(), this);
	if(it != list.end())
		list.erase(it);
}

void Timer::update()
{
	// 현재 시각을 기준으로 만료된 타이머를 찾는다.
	auto end = std::partition(list.begin(), list.end(), [](Timer* t) { return t->isExpired(); });
	for (auto it = list.begin(); it != end; ++it) {
		/* 미리 설정한 callback을 호출한다. */
		if ((*it)->callback) {
			(*it)->callback();
		}
	}
	list.erase(list.begin(), end);
}

std::string Timer::makeTime(time_t t) {
	// Epoch time -> YYYY:MM:DD:hh:dd
	char buf[128];
	strftime(buf, sizeof(buf), "%Y:%m:%d:%H:%M", localtime(&t));
	return std::string(buf);
}

time_t Timer::parseTime(const std::string & str) {
	// YYYY:MM:DD:hh:dd -> epoch time
	auto t = tm();
	sscanf(str.c_str(), "%d:%d:%d:%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min);
	t.tm_year -= 1900;
	t.tm_mon -= 1;
	return mktime(&t);
}
