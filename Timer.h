//Class: Timer
//Description: 시간과 관련된 기능을 담당하는 클래스이다.
//Author: 문준오
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
	//Description: epoch time을 출력 양식인 YYYY:MM:DD:hh:mm 에 맞춰주는 보조함수이다.
	static std::string makeTime(time_t t);
	//Description: YYYY:MM:DD:hh:mm양식을 epoch time으로 바꾸는 보조함수이다.
	static time_t parseTime(const std::string& str);
	//Description: 생성자이다.
	Timer();
	//Description: 타이머가 만료될 시각 및 이때 수행될 콜백함수를 설정하는 setter이다.
	void setTimer(std::string time, void(*callback)());
	//Description: 현재 시각을 재설정하는 함수이다.
	static void setCurrentTime(const std::string& time);
	//Description: 현재 시각을 반환하는 함수이다.
	static std::string getCurrentTime();
	//Description: 타이머가 만료되었는지를 반환하는 함수이다.
	bool isExpired() const;
	//Description: 타이머에 설정된 만료시각을 반환하는 getter이다.
	std::string getDeadline() const;
	//Description: 소멸자이다.
	~Timer();

private:
	//Description: 현재시각이 재설정되었을 때, 이에 따른 타이머의 만료 여부를 업데이트하는 함수이다.
	static void update();
};

