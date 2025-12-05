#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void addPotion(int addCount, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion += addCount;
	*p_MPPotion += addCount;
}

int main() {
	//HP, MP 는 50 이상
   //공격력, 방여력은 0 이상
	int status[7] = { 0,0,0,0 ,0,0,0 }; //HP, MP, 공격력, 방어력 , 힘 , 민첩, 지능
	int level = 1;
	int hpPotion = 0, mpPotion = 0;
	int selectNum = 0;

	cout << "HP와 MP를 입력해 주세요 : ";

	while (1) {
		cin >> status[0] >> status[1];

		if (status[0] >= 50 && status[1] >= 50)
			break;

		cout << "HP와 MP 값이 너무 작습니다 다시 입력해 주세요 : ";
	}

	cout << "공격력과 방어력을 입력해주세요 : ";

	while (1) {
		cin >> status[2] >> status[3];

		if (status[2] >= 0 && status[3] >= 0)
			break;

		cout << "공격력과 방어력 값이 너무 작습니다. 다시 입력해 주세요 : ";
	}

	setPotion(5, &hpPotion, &mpPotion);
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";
	cout << "======================================\n";

	cout << "<스텟 관리 시스템>\n";
	cout << "1. HP UP\n";
	cout << "2. MP UP\n";
	cout << "3. 공격력 UP\n";
	cout << "4. 방어력 UP\n";
	cout << "5. 현재 능력치\n";
	cout << "6. Level UP\n";
	cout << "7. 힘 UP\n";
	cout << "8. 민첩 UP\n";
	cout << "9. 지능 UP\n";
	cout << "0. 나가기\n";

	while (1) {
		cout << "번호를 선택해주세요 : ";
		cin >> selectNum;

		if (selectNum == 0) break;

		switch (selectNum) {
		case 1:
			if (hpPotion > 0)
			{
				status[0] += 20;
				hpPotion--;
				cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
				cout << "현재 HP : " << status[0] << "\n";
				cout << "남은 Hp포션수 : " << hpPotion << "\n";
			}
			else {
				cout << "HP포션이 부족합니다...!\n";
			}
			continue;

		case 2:
			if (mpPotion > 0)
			{
				status[1] += 20;
				mpPotion--;
				cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
				cout << "현재 MP : " << status[1] << "\n";
				cout << "남은 Mp포션수 : " << mpPotion << "\n";
			}
			else
			{
				cout << "MP포션이 부족합니다...!\n";
			}
			continue;

		case 3:
			status[2] *= 2;
			cout << "*공격력이 2배로 증가되었습니다.\n";
			cout << "현재 공격력 : " << status[2] << "\n";
			continue;

		case 4:
			status[3] *= 2;
			cout << "* 방어력이 2배로 증가되었습니다.\n";
			cout << "현재 방어력 : " << status[3] << "\n";
			continue;

		case 5:
			cout << "현재 레벨 : " << level << "\n";
			cout << "HP : " << status[0] << ", MP : " << status[1] << ", 공격력 : " << status[2] << ", 방어력 : " << status[3] << "\n";
			cout << "힘 : " << status[4] << ", 민첩 : " << status[5] << ", 지능 : " << status[6] << "\n";
			cout << "남은 HP/MP 포션 수 : " << hpPotion << "/" << mpPotion << "\n";
			continue;

		case 6:
			level++;
			addPotion(1, &hpPotion, &mpPotion);
			cout << "* 레벨업! HP/MP 포션이 지급됩니다.\n";
			cout << "현재 레벨 : " << level << "\n";
			cout << "남은 HP / MP 포션 수 : " << hpPotion << "/" << mpPotion << "\n";
			continue;

		case 7:
			status[4]++;
			cout << "*힘이 1 상승했습니다..\n";
			cout << "현재 힘 : " << status[4] << "\n";
			continue;

		case 8:
			status[5]++;
			cout << "*민첩이 1 상승했습니다..\n";
			cout << "현재 힘 : " << status[5] << "\n";
			continue;

		case 9:
			status[6]++;
			cout << "*지능이 1 상승했습니다..\n";
			cout << "현재 힘 : " << status[6] << "\n";
			continue;

		default:
			cout << "잘못된 입력입니다.\n";
			continue;
		}
		return 0;
	}
}