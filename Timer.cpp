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
#include "RegisterTicketManager.h"
#include "SearchTicketsInAuction.h"
#include <ctime>

// Function: void Timer::setTimer(std::string time, void(*callback)())
// Description: Timer를 설정하는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters: std::string time(설정할 시간대), void(*callback)()(call back 될 함수)
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/02 by 김상엽
// 				What: test callback part


void Timer::setTimer(std::string time)
{
	//데드라인 설정 
	deadline = time;
}

// Function: Timer::Timer()
// Description: Timer 클래스의 생성자이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: Timer 클래스의 인스턴스

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

std::string Timer::currentTime;
Timer::Timer()
{
}

// Function: void Timer::setCurrentTime(const std::string & time)
// Description: 현재 시간으로 시간을 설정하는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters: const std::string & time(설정할 시간대)
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: test update

void Timer::setCurrentTime(const std::string & time)
{
	currentTime = time;
	update();
}

// Function: std::string Timer::getCurrentTime()
// Description: 현재 시간을 가져오는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: std::string currentTime(string 형식의 현재 시간)

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

std::string Timer::getCurrentTime()
{
	return currentTime;
}

// Function: bool Timer::isExpired() const
// Description: 타이머가 만료되었는지 확인하는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: boolean 타입의 만료 여부

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

bool Timer::isExpired() const
{
	// 타이머가 만료되었는지 확인한다.
	return currentTime > deadline;
}

// Function: std::string Timer::getDeadline() const
// Description: 만료 기한을 가져오는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value: std::string deadline(만료 기한)

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

std::string Timer::getDeadline() const
{
	return deadline;
}

// Function: Timer::~Timer()
// Description: Timer 클래스의 소멸자이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: modify detail logic

Timer::~Timer()
{
}

// Function: void Timer::update()
// Description: Timer list를 갱신하는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters:
// Return Value:

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: modify condition of for loop

void Timer::update()
{
	//LTA 티켓을 처리한다.
	RegisterTicketManager::switchToLTA();
	//경매가 끝난 티켓들을 처리한다.
	SearchTicketsInAuction::finishBidding();
	//등록한지 1년이 지난 티켓들을 삭제한다.
	RegisterTicketManager::deleteHistory();
}

// Function: std::string Timer::makeTime(time_t t)
// Description: time_t 형식의 변수를 string 형식으로 바꾸어주는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters: time_t t(형식을 맞출 시간)
// Return Value: string 형식의 시간

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function

std::string Timer::makeTime(time_t t) {
	// Epoch time -> YYYY:MM:DD:hh:dd
	char buf[128];
	strftime(buf, sizeof(buf), "%Y:%m:%d:%H:%M", localtime(&t));
	return std::string(buf);
}

// Function: time_t Timer::parseTime(const std::string & str)
// Description: string 형식의 변수를 time_t 형식으로 바꾸어주는 함수이다.
// Author: 김상엽
// Created: 2019/06/03
// Parameters: const std::string & str(형식을 맞출 string 형태의 변수)
// Return Value: time_t 형식의 시간

// Revisions:
// 		1.	When & Who: 2019/06/03 by 김상엽
// 				What: create function
// 		2.	When & Who: 2019/06/03 by 김상엽
// 				What: modify miss on var name

time_t Timer::parseTime(const std::string & str) {
	// YYYY:MM:DD:hh:dd -> epoch time
	auto t = tm();
	sscanf(str.c_str(), "%d:%d:%d:%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min);
	t.tm_year -= 1900;
	t.tm_mon -= 1;
	return mktime(&t);
}
