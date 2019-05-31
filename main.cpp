#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include "SignUpMembershipUI.h"
#include "WithdrawUI.h"
#include "SignInUI.h"
#include "SignOutUI.h"
#include "RegisterTicketUI.h"
#include "SearchRegisteredTicketUI.h"
#include "SearchReservableTicketUI.h"
#include "SearchTicketsInAuctionUI.h"
#include "BookedTicketManagerUI.h"

#include "Timer.h"
#include "UserCollection.h"

using namespace std;


int main(int argc, char* argv[]) {
#ifdef  _MSC_VER
	system("chcp 65001");	//utf-8로 콘솔에 출력을 강제함
#endif
	ifstream in("input.txt");
#ifndef _DEBUG
	freopen("output.txt", "w", stdout);	//cout -> output.txt로 리디렉션
#endif
	vector<const Info*> sessions;
	vector<const Info*>::iterator currentUser = sessions.end();
	while (in) {
		int first, second;
		string input;
		in >> first >> second;
		switch (first)
		{
		case 1:
			if (second == 1) { //회원가입
				string id, pw, name, ssn, userType;
				in >> id >> pw >> name >> ssn >> userType;
				SignUpMembershipUI::get().requestSignUP(Info(id, pw, name, ssn, userType));
			}
			else {
				//회원탈퇴
				WithdrawUI::get().requestWithdraw(**currentUser);
			}
			break;
		case 2:
			if (second == 1) {
				//로그인
				string id, pw;
				in >> id >> pw;
				const Info* ret = SignInUI::get().requestSignIn(id, pw);
				if (ret) { //로그인 성공
					sessions.push_back(ret);
					currentUser = sessions.end() - 1;
				}
				else	// 로그인 실패
					currentUser = sessions.end();
			}
			else {
				//로그아웃
				SignOutUI::get().requestSignOut(**currentUser);
				sessions.erase(currentUser);
				currentUser = sessions.end();
			}
			break;
		case 3:
			if (currentUser == sessions.end())
				break;	//guest session은 진입 불가
			else if (second == 1) {
				//판매 티켓 등록
				string time, home, away, position;
				bool lta;
				int price;
				in >> price >> time >> home >> away >> position >> lta;
				RegisterTicketUI::get().createNewTicket(*currentUser, price, time, home, away, position, lta);
			}
			else {
				//등록 티켓 조회
				SearchRegisteredTicketUI::get().search(**currentUser);
			}
			break;
		case 4:
			if (currentUser == sessions.end())
				break;	//guest session은 진입 불가
			if (second == 1) {
				//티켓 검색
				string home;
				in >> home;
				SearchReservableTicketUI::get().search(home);

			}
			else if(second == 2) {
				//티켓 예약
				string time, away, position;
				in >> time >> away >> position;
				SearchReservableTicketUI::get().reserve(**currentUser, time, away, position);
			}
			else if (second == 3) {
				//경매중 티켓 검색
				string home;
				in >> home;
				SearchTicketsInAuctionUI::get().search(home);
			}
			else if (second == 4) {
				//경매 참여
				string time, away, position;
				int price;
				in >> time >> away >> position >> price;
				SearchTicketsInAuctionUI::get().bid(**currentUser, time, away, position, price);
			}
			else {
				//예약 정보 조회
				BookedTicketManagerUI::get().search(**currentUser);
			}
			break;
		case 5:
		{
			cout << "5.1. 현재시간 설정" << endl;
			string time;
			in >> time;
			cout << "> " << time << std::endl;
			Timer::setCurrentTime(time);
			break;
		}
		case 6:
			if (second == 1) {
				cout << "6.1. session 변경" << endl;
				string id;
				in >> id;
				cout << "> " << id << endl;
				currentUser = find_if(sessions.begin(), sessions.end(), [&id](const Info* i) {return i->getID() == id; });
			}
			else {
				cout << "6.2. guest session으로 변경" << endl;
				currentUser = sessions.end();
			}
			break;
		case 7:
			cout << "7.1. 종료" << endl;
			return 0;
		default:
			break;
		}
		std::cout << std::endl;
	}
}
