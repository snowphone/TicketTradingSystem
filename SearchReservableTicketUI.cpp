// Class: SearchReservableTicketUI
// Description: 예약 가능한 티켓을 조회 및 예약하는 boundary class이다.
// Author: 유새람
#include "SearchReservableTicketUI.h"
#include "SearchReservableTicketManager.h"


// Function: SearchReservableTicketUI()
// Description: private 생성자 (singleton)
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: singleton패턴을 위한 private 생성자
SearchReservableTicketUI::SearchReservableTicketUI()
{
}


SearchReservableTicketUI* SearchReservableTicketUI::var = nullptr;

// Function: static SearchReservableTicketUI& get()
// Description: singleton패턴에서 instance를 불러오는 메소드
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: 한번만 constructor 호출하도록 함
SearchReservableTicketUI& SearchReservableTicketUI::get()
{
	if (!var)
		var = new SearchReservableTicketUI();
	return *var;
}

// Function: void search(std::string home)
// Description: 선택한 홈팀에 해당하는 예약 가능한 Ticket을 조회하는 함수
// Parameters:	string home - 검색할 홈팀
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: 클래스 SearchReservableTicketManager의 함수 호출
void SearchReservableTicketUI::search(std::string home)
{
	SearchReservableTicketManager::get().show(home);
}

// Function: void reserve(const Info& buyerInfo, std::string time, std::string away, std::string position)
// Description: 선택한 Ticket을 예약하는 함수
// Parameters:	const Info& buyerInfo- 예약을 진행할 Buyer
//				string time, away, position - 예약할 Ticket의 경기 시간, 어웨이팀, 좌석 위치
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
//				What: 클래스 SearchReservableTicketManager의 함수 호출
void SearchReservableTicketUI::reserve(const Info& buyerInfo, std::string time, std::string away, std::string position)
{
	SearchReservableTicketManager::get().reserve(buyerInfo, time, away, position);
}

// Function: ~SearchReservableTicketUI()
// Description: 소멸자
// Author: 유새람
// Revisions:
//		1. When & Who: 2019/06/04 by 유새람
SearchReservableTicketUI::~SearchReservableTicketUI()
{
}

