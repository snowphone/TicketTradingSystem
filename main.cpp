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

using namespace std;


int main(int argc, char* argv[]) {
	ifstream in("input.txt");
#ifndef _DEBUG
	freopen("output.txt", "w", stdout);	//cout -> output.txt로 리디렉션
#endif
	const Info* currentUser = nullptr;
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
				WithdrawUI::get().requestWithdraw(*currentUser);
			}
			break;
		case 2:
			if (second == 1) {
				//로그인
				string id, pw;
				in >> id >> pw;
				currentUser = SignInUI::get().requestSignIn(id, pw);
			}
			else {
				//로그아웃
				SignOutUI::get().requestSignOut(*currentUser);
				currentUser = nullptr;
			}
			break;
		case 3:
			if (second == 1) {
				//판매 티켓 등록
				string time, home, away, position;
				bool lta;
				int price;
				in >> price >> time >> home >> away >> position >> lta;
				RegisterTicketUI::get().createNewTicket(currentUser, price, time, home, away, position, lta);
			}
			else {
				//등록 티켓 조회
				SearchRegisteredTicketUI::get().search(*currentUser);
			}
			break;
		case 4:
			if (second == 1) {
				//티켓 검색
			}
			else if(second == 2) {
				//티켓 예약
			}
			else if (second == 3) {
				//경매중 티켓 검색
			}
			else if (second == 4) {
				//경매 참여
			}
			else {
				//예약 정보 조회
			}
			break;
		case 5:
			//현재시간 설정
			break;
		case 6:
			if (second == 1) {
				//세션 변경
			}
			else {
				//guest session으로 변경
			}
			break;
		case 7:
			return 0;
		default:
			break;
		}
	}
}
