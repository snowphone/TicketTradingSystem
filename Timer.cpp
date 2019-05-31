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
	list.erase(it);
}

void Timer::update()
{
	//현재 시각을 기준으로 만료된 타이머를 찾고, 각 만료된 타이머마다 미리 설정된 행동을 수행한다.
	auto end = std::partition(list.begin(), list.end(), [](Timer* t) { return t->isExpired(); });
	for (auto it = list.begin(); it != end; ++it) {
		if ((*it)->callback) {
			(*it)->callback();
		}
	}
	list.erase(list.begin(), end);
}

std::string Timer::makeTime(time_t t) {
	// Epoch time을 출력 형식에 맞게 바꾸는 보조함수이다.
	char buf[128];
	strftime(buf, sizeof(buf), "%Y:%m:%d:%H:%M", localtime(&t));
	return std::string(buf);
}

time_t Timer::parseTime(const std::string & str) {
	// 문자열 형식으로 표현된 시각을 연산에 편리한 epoch time으로 변환하는 역할을 수행하는 보조함수이다.
	auto t = tm();
	sscanf(str.c_str(), "%d:%d:%d:%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min);
	t.tm_year -= 1900;
	t.tm_mon -= 1;
	return mktime(&t);
}
