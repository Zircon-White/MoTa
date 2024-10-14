#include <stdio.h>
#include<conio.h>
#include <string>  
#include <iostream> 
#include <vector>  
#include <windows.h>
#include<unordered_map>

class PlayerOut {//��ң�ս���⣩
public:
	std::string name;//����
	float hp=100;//����ֵ
	float atk=20;//������
	int mana=20;//����
	float def=5;//������
	int cookie=30;//����
	int lev=1;//�ȼ�
	int exp=0;//����ֵ
	int boss = 0;//��ս��boss��(����ȼ�

	int redBottle = 3;//Ѫƿ
	int blueBottle = 2;//��ƿ
	int energyBottle = 0;//����ƿ
	int spyWater = 0;//����ˮ
	int chaWater = 0;//����ˮ
	int magicWater = 0;//����ҩˮ

	bool smallgift = false;
	bool HasSeenMovie = false;

	PlayerOut(const std::string name):name(name){}

	void PlayerOutInfo() const {//ս����״̬
		std::cout << "���ƣ�"<<name<<std::endl;
		std::cout << "����ֵ��" << hp << std::endl;
		std::cout << "��������" << atk << std::endl;
		std::cout << "ħ��ֵ��" << mana << std::endl;
		std::cout << "��������" << def << std::endl;
		std::cout << "��������" << cookie << std::endl;
		std::cout << "�ȼ���" << lev << std::endl;
		std::cout << "����ֵ��" << exp << std::endl;
		std::cout << std::endl;
		std::cout << "����:" << std::endl;
		std::cout << "����ҩˮ��" <<redBottle<< "ƿ" << std::endl;
		std::cout << "ħ��ҩˮ��" << blueBottle << "ƿ" << std::endl;
		std::cout << "����ҩˮ��" << energyBottle << "ƿ" << std::endl;
		if (boss > 0) {
			std::cout << "����ˮ��" << spyWater << "ƿ" << std::endl;
		}
		if (boss > 2) {
			std::cout << "����ˮ��" << chaWater << "ƿ" << std::endl;
		}
		if (boss > 3) {
			std::cout<< "����ҩˮ��" << magicWater << "ƿ" << std::endl;
		}
		if (smallgift) {
			std::cout<<"�Ѿ��յ�������" << std::endl;
		}
		std::cout << std::endl;
	}
};
//��ң�ս���⣩

class PlayerFight {
public:
	int hot;//������
	int poison;//�ж�
	int strong;//ǿ׳
	int charge;//����

	PlayerFight(const int hot, int poison, int strong,int charge)
		:hot(hot),poison(poison),strong(strong),charge(charge){}

	void PlayerFightInfo() const {//ս����״̬
		std::cout << "���ڵ�״̬��:" << std::endl;
		if(hot != 0)std::cout << "��������������" << std::endl;
		if (poison != 0)std::cout << "��Ϊ�ڰ������ж���" << std::endl;
		if (strong != 0)std::cout << "�о����ϳ�������" << std::endl;
		if (charge != 0)std::cout << "��������" << std::endl;
	}
};
//��ң�ս���ڣ�

class Monster {
public:
	std::string name;//����
	float hp;//����ֵ����
	float atk;//����������
	float def;//����������
	int cookie;//���ɱ���
	int exp;//����ֵ����
	bool hasMeet = false;//�Ƿ�������

	Monster(){}
	Monster(const std::string name, float hp, float atk, float def, int cookie, int exp)
		:name(name),hp(hp),atk(atk),def(def),cookie(cookie),exp(exp){}

	void monsterInfo() const {
		std::cout << "���ƣ�" <<name<< std::endl;
		std::cout << "����ֵ���ʣ�" <<hp<< std::endl;
		std::cout << "���������ʣ�" <<atk<< std::endl;
		std::cout << "���������ʣ�" <<def<< std::endl;
		std::cout << "���ɱ��ʣ�" <<cookie<< std::endl;
		std::cout << "����ֵ���ʣ�" <<exp<< std::endl;
		std::cout <<std::endl;
	}
};
//����

static void object(PlayerOut& playerout) {
	std::cout << std::endl;
	std::cout << "����:" << std::endl;
	std::cout << "1.����ҩˮ��" << playerout.redBottle <<"ƿ"<< std::endl;
	std::cout << "2.ħ��ҩˮ��" << playerout.blueBottle << "ƿ" << std::endl;
	std::cout << "3.����ҩˮ��" << playerout.energyBottle << "ƿ" << std::endl;
	if (playerout.boss > 0) {
		std::cout << "4.����ˮ��" << playerout.spyWater << "ƿ" << std::endl;
	}
	if (playerout.boss > 2) {
		std::cout << "5.����ˮ��" << playerout.chaWater << "ƿ" << std::endl;
	}
	if (playerout.boss > 3) {
		std::cout << "6.����ҩˮ��" << playerout.magicWater << "ƿ" << std::endl;
	}
	std::cout << "ͬһҩˮ��ʱЧ�ڷ���ֻ��ˢ��ʱ��" << std::endl;
};
//�����б�

static int fight(PlayerOut& playerout, Monster& monster) {
	char useless;
	system("cls");//����

	int ahot=0;//������
	int apoison=0;//�ж�
	int astrong=0;//ǿ׳
	int acharge=0;//����
	int aTen = 0;//����

	int bhot = 0;
	int bpoison = 0;

	int abHurt, baHurt;     //��ʿÿ�غϹ���������˺������ﷴ�����˺�
	int turn = 0;

	float aAtk = playerout.atk;//����
	float aDef = playerout.def;
	float aHp = playerout.hp;
	float bAtk = monster.atk*(playerout.boss+1);
	float bDef = monster.def *(playerout.boss + 1);
	float bHp = monster.hp *(playerout.boss + 1);
	int aMana = playerout.mana;

	std::cout << monster.name << "�����ˣ�" << std::endl;
	if (!monster.hasMeet) {
		std::cout << monster.name << "�ǵ�һ������" << std::endl;
		monster.hasMeet = true;
	}

	while (aHp > 0 && bHp > 0){
		turn++;
		std::cout << std::endl;
		std::cout << "��" << turn << "�غ�" << std::endl;

		if (astrong > 0) {
			std::cout << playerout.name << "�о�����������" << std::endl;
		}
		//����

		if (aTen > 0) {
			std::cout << playerout.name << "�о��Լ���ǹ����" << std::endl;
		}
		//����

		std::cout << "������ѡ��" << std::endl;
		std::cout << "1.���� 2.���� 3.���� 4.����" << std::endl;

		int choice = 0;
		std::cin >> choice;

		if (choice == 3) {
			std::cout << playerout.name << "������" << std::endl;
			playerout.hp = aHp;
			useless=_getch();
			return 0;
		}
		//����
		else if (choice == 1) {
			std::cout << "��ѡ�񹥻���ʽ��" << std::endl;
			std::cout << "1.��ͨ����" << std::endl;
			std::cout << "2.��������(�����������󷢶���ͨ�����������˺�)"<< std::endl;
			std::cout << "3.�ڰ�������" << std::endl;
			std::cout << std::endl;
			int x = 0;
			std::cin >> x;

			if (x == 1) {
				aAtk = aAtk * (acharge+1);
				abHurt = (aAtk > bDef) ? (aAtk - bDef) : 0;
				std::cout << playerout.name << "��" << monster.name << "�����˹����������" << abHurt << "���˺�" << std::endl;
				bHp -= abHurt;
				std::cout << monster.name << "������" << bHp << "������ֵ" << std::endl;
			}
			//�չ�
			else if (x == 2) {
				std::cout << playerout.name << "��ʼ����" << std::endl;
				acharge++;
				std::cout << "�����Ѿ�������" << acharge << "���غ�"<<std::endl;
			}
			//����
			else if (x == 3) {
				std::cout << "��ѡ�����������" << std::endl;
				std::cout << "1.�����ǿ���(�˺����٣�������ɵĹ������ӶԷ�������)���������ģ�10" << std::endl;
				std::cout << "2.��������(��ɳ����˺����������غ�)���������ģ�15" << std::endl;
				std::cout << std::endl;
				int y=0;
				std::cin >> y;

				if (y == 1&&aMana>=10) {
					abHurt = aAtk*0.7;
					std::cout << monster.name << "�������ǿ��ɹ����ˣ������" << abHurt << "���˺�" << std::endl;
					bHp -= abHurt;
					aMana -= 10;
				}
				//�����ǿ���
				else if (y == 2&&aMana>=15) {
					std::cout << monster.name << "���������湥����"<< std::endl;
					bhot = 3;
					aMana -= 15;
				}
				//��������
				else {
					std::cout << playerout.name << "�ڷ���" << std::endl;
				}
				//������ħ��������������
			}
			//ħ��
		}
		//����
		else if (choice == 2) {
			aDef = aDef * 2;
		}
		//����
		else if (choice == 4) {
			object(playerout); 
			int y = 0;
			std::cin >> y;
			if (y == 1&&playerout.redBottle>0) {
				std::cout << playerout.name << "ʹ���˽���ҩˮ���о��Լ������˾���" << std::endl;
				aHp += 50 * (playerout.boss+1);
				std::cout << "������" << aHp << "������ֵ" << std::endl;
				playerout.redBottle--;
			}
			//����ҩˮ
			else if (y == 2 && playerout.blueBottle > 0) {
				std::cout << playerout.name << "ʹ����ħ��ҩˮ��ħ���ָ���" << std::endl;
				aMana = (aMana+20*(playerout.boss+1)<playerout.mana) ? (aMana + 20 * (playerout.boss+1)) : playerout.mana;
				std::cout << "������" << aMana << "��ħ��" << std::endl;
				playerout.blueBottle--;
			}
			//ħ��ҩˮ
			else if (y == 3 && playerout.blueBottle > 0) {
				std::cout << playerout.name << "ʹ��������ҩˮ�������˺�������" << std::endl;
				astrong=3;
				std::cout << playerout.name << "�о�����������" << std::endl;
				aAtk = aAtk * 1.6;
			}
			//����
			else if (y == 4 && playerout.spyWater > 0) {
				std::cout << playerout.name << "ʹ��������ˮ" << std::endl;
				std::cout << monster.name << "������ˮ�����������۾�" << std::endl;
				bhot = 3;
				playerout.spyWater --;
			}
			//����ˮ
			else if (y == 5 && playerout.chaWater > 0) {
				std::cout << playerout.name << "ʹ��������ˮ" << std::endl;
				std::cout << playerout.name << "��������������" << std::endl;
				acharge+=2;
				std::cout << "�����Ѿ�������" << acharge << "���غ�" << std::endl;
				playerout.chaWater--;
			}
			//����ˮ
			else if (y == 6 && playerout.magicWater > 0) {
				std::cout << playerout.name << "ʹ��������ҩˮ" << std::endl;
				std::cout << playerout.name << "�о��Լ�����ǿ�Ŀ���" << std::endl;
				aTen = 3;
				aDef = aDef * 10;
				playerout.magicWater--;
			}
			else {
				std::cout << playerout.name << "�ڷ���" << std::endl;
			}
		}
		//����
		else {
			std::cout << playerout.name << "����������֪������ʲô" << std::endl;
		}
		//��������


		if (bHp <= 0)break;//��ܹ���
		else {
			baHurt = (bAtk > aDef) ? (bAtk - aDef) : 0;
			std::cout << monster.name << "��" << playerout.name << "�����˹����������" << baHurt << "���˺�" << std::endl;
			aHp -= baHurt;
			std::cout <<playerout.name <<"ʣ��" << aHp << "������ֵ" << std::endl;
		}
		//���﹥��
		if (playerout.smallgift) {
			aHp += 20 * (playerout.boss + 1);
			std::cout << "�ϰ���Ĳ�������������" << std::endl;
			std::cout << playerout.name << "�ָ���" << 20 * (playerout.boss + 1) << "������ֵ" << std::endl;
		}
		//С����

		if (choice == 2) {
			aDef = aDef / 2;
		}
		//����

		if (bhot > 0) {
			abHurt = aAtk*0.45;
			std::cout << monster.name << "�������ˣ������" << abHurt << "���˺�" << std::endl;
			bHp -= abHurt;
			std::cout << monster.name << "������" << bHp << "������ֵ" << std::endl;
		}
		//������

		if (astrong >0) {
			astrong--;
			if (astrong == 0) {
				std::cout << "����Ч����ʧ��" << std::endl;
				aAtk = playerout.atk;
			}
		}
		//����Ч��
	
		if (aTen > 0) {
			aTen--;
			if (aTen == 0) {
				std::cout << "����Ч����ʧ��" << std::endl;
				aDef = playerout.def;
			}
		}	
		//����Ч��
		
		if (bHp <= 0)break;//��ܹ���
	}

	if (aHp > 0) {
		playerout.cookie += monster.cookie * (playerout.boss + 1);
		playerout.exp += monster.exp * (playerout.boss + 1);
		playerout.hp = aHp;

		std::cout << std::endl;
		std::cout << playerout.name << "սʤ��" << monster.name << std::endl;
		std::cout << "���" << monster.cookie * (playerout.boss + 1) << "�����," << monster.exp * (playerout.boss + 1) << "�㾭��,";
		std::cout << "ʣ������ֵ" << playerout.hp << "��,";
		std::cout << "����" << playerout.cookie << "��" << std::endl;

		while (playerout.exp >= playerout.lev*1000) {
			playerout.exp -= playerout.lev * 1000;

			playerout.lev++;
			playerout.hp +=100;
			playerout.atk +=5;
			playerout.def +=2;
			playerout.mana +=5;
			
			std::cout << "�����ˣ�" << playerout.name << "������" << playerout.lev << "��"<<std::endl;
			std::cout<<playerout.name<<"������ֵ������" << std::endl;
			std::cout << playerout.name << "�Ĺ�����������" << std::endl;
			std::cout << playerout.name << "�ķ�����������" << std::endl;
			std::cout << playerout.name << "��ħ������������" << std::endl;
		}
		useless=_getch();
		return 1;
	}
	else {
		std::cout << "ս��ʧ�ܣ�" << playerout.name << "��·���ĺ������͵����ù�" << std::endl;
		playerout.hp = 50;
		useless = _getch();
		return 0;
	}
};
//ս������

static void shop(PlayerOut& player) {
	system("cls");//����
	std::cout << "��ӭ����ף��ħ�̵꣬������ʲô��Ҫ�ģ�" << std::endl;
	std::cout << "������" << player.cookie << "�����" << std::endl;
	std::cout << "��Ʒ1��5�㹥�������ۼ�100�����" << std::endl;
	std::cout << "��Ʒ2��5�����ֵ���ۼ�100�����" << std::endl;
	std::cout << "��Ʒ3��1ƿ����ҩˮ���ָܻ�" << 50 * (player.boss + 1) << "������ֵ���ۼ�" << 80 * (player.boss + 1) << "�����" << std::endl;
	std::cout << "��Ʒ4��1ƿħ��ҩˮ���ָܻ�" << 20 * (player.boss + 1) << "��ħ�����ۼ�" << 80 * (player.boss + 1) << "�����" << std::endl;
	std::cout << "��Ʒ5��1ƿ����ҩˮ���������غ������������˺����ۼ�"<<150 * (player.boss + 1) <<"�����" << std::endl;
	if (player.boss > 0) {
		std::cout << "������Ʒ��" << std::endl;
		std::cout << "��Ʒ6��1ƿ����ˮ������������鼱ʱ�����һ�����ۼ�"<<100 * (player.boss + 1) <<"�����" << std::endl;
	}
	if (player.boss > 2) {
		std::cout << "��Ʒ7��1ƿ����ҩˮ�����¿������̻����������Ч�����ۼ�1000�����" << std::endl;
	}
	if (player.boss > 3) {
		std::cout << "��Ʒ8��1ƿ����ҩˮ�����¿����ڽ������������غ����������ܵ����˺����ۼ�2000�����" << std::endl;
	}
	if (player.boss > 4) {
		std::cout << "��Ʒ9�����������ߵ�СС���������ñ���Ŷ" << std::endl;
	}
	std::cout << "����0�˳��̵�" << std::endl;

	int x = 1;
	while (x!=0) {
		std::cin >> x;
		int num = 0;
		switch (x) {
		case 1:
			std::cout << "���빺�򼸷��أ�" << std::endl;

			std::cin >> num;
			if (player.cookie >= 100*num) {
				player.cookie -= 100*num;
				player.atk += 5*num;
				std::cout << "����ɹ���������������" << std::endl;
				std::cout << "������" << player.cookie << "�����" << std::endl;
			}
			else {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 2:
			std::cout << "���빺�򼸷��أ�" << std::endl;
			std::cin >> num;
			if (player.cookie >= 100 * num) {
				player.cookie -= 100 * num;
				player.def += 5 * num;
				std::cout << "����ɹ���������������" << std::endl;
				std::cout << "������" << player.cookie << "�����" << std::endl;
			}
			else {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 3:
			if (player.cookie >= 80 * (player.boss + 1)) {
				player.cookie -= 80 * (player.boss + 1);
				player.redBottle ++;
				std::cout << "����ɹ���������" << player.redBottle << "ƿ����ҩˮ" << std::endl;
			}
			else {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 4:
			if (player.cookie >= 80 * (player.boss + 1)) {
				player.cookie -= 80 * (player.boss + 1);
				player.blueBottle++;
				std::cout << "����ɹ���������" << player.blueBottle << "ƿħ��ҩˮ" << std::endl;
			}
			else {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 5:
			if (player.cookie >= 150 * (player.boss + 1)) {
				player.cookie -= 150 * (player.boss + 1);
				player.energyBottle++;
				std::cout << "����ɹ���������" << player.energyBottle << "ƿ����ҩˮ" << std::endl;
			}
			else {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 6:
			if (player.cookie >= 100 * (player.boss + 1)&& player.boss > 0) {
				player.cookie -= 100 * (player.boss + 1);
				player.spyWater++;
				std::cout << "����ɹ���������" << player.spyWater << "ƿ����ˮ" << std::endl;
			}
			else if(player.cookie < 100 * (player.boss + 1)){
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 7:
			if (player.cookie >= 1000 && player.boss > 2) {
				player.cookie -= 1000;
				player.chaWater++;
				std::cout << "����ɹ���������" << player.chaWater << "ƿ����ˮ" << std::endl;
			}
			else if(player.cookie < 1000) {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 8:
			if (player.cookie >= 2000 && player.boss > 3) {
				player.cookie -= 2000;
				player.magicWater++;
				std::cout << "����ɹ���������" << player.magicWater << "ƿ����ҩˮ" << std::endl;
			}
			else if (player.cookie < 2000) {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 9:
			if (player.boss > 4&&!player.smallgift) {
				player.smallgift=true;
				std::cout << "�������յ��ҵ�С�����ˣ�Ҫ���쿪��ѽ" << std::endl;
				std::cout << "���յ����ϰ���Ĳ���" << std::endl;
				std::cout << "�Ӵ��Ժ�ÿ�غϽ�������ָ���������ֵ" << std::endl;
			}
			break;
		}
	}
};
//�̵꺯��

static void hotel(PlayerOut& player) {
	system("cls");//����
	std::cout << "��ӭ�����ùݣ���סʲô���ķ��䣿" << std::endl;
	std::cout << "������" << player.cookie << "�����" << std::endl;
	std::cout << "1.���ؼ䣺�ָ�100������ֵ���ۼ�30�����" << std::endl;
	std::cout << "2.��ͨ���˼䣺�ָ�500������ֵ���ۼ�100�����" << std::endl;
	std::cout << "3.�����󴲷����ָ�4000������ֵ���ۼ�500�����" << std::endl;
	std::cout << "���뿪�ùݵĻ�������0" << std::endl;

	int x = 1;
	while (x != 0) {
		std::cin >> x;

		switch (x) {
		case 1:
			if (player.cookie >= 30) {
				player.cookie -= 30;
				player.hp += 100;
				std::cout << "�ڴ��ؼ���Ϣ��һ�ᣬ����ֵ������100�㡣" << std::endl;
				std::cout << "������" << player.cookie << "�����" << std::endl;
			}
			else {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 2:
			if (player.cookie >= 100) {
				player.cookie -= 100;
				player.hp += 500;
				std::cout << "����ͨ���˼���Ϣ��һ�ᣬ����ֵ������500�㡣" << std::endl;
				std::cout << "������" << player.cookie << "�����" << std::endl;
			}
			else {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		case 3:
			if (player.cookie >= 500) {
				player.cookie -= 500;
				player.hp += 4000;
				std::cout << "�ں����󴲷���Ϣ��һ�ᣬ����ֵ������2000�㡣" << std::endl;
				std::cout << "������" << player.cookie << "�����" << std::endl;
			}
			else {
				std::cout << "���ɲ�����" << std::endl;
			}
			break;
		}
	}
};
//�ùݺ���

static void story() {
	char useless;
	system("cls");//����
	printf("����һ���ܹ��ϵĹ���\n");Sleep(150);
	printf("�ںܾúܾ���ǰ����ңԶ�Ļ������\n");Sleep(150);
	printf("����������������ڴ����\n");Sleep(150);
	printf("��ͻȻ��һ�죬������һ�����ص�������\n");Sleep(150);
	printf("��·��������żȻ�����������\n");Sleep(150);
	printf("���������������������ʳ��\n");Sleep(150);
	printf("��û�������Ǹ��ˣ�\n");	Sleep(150);
	printf("���Ƿ��������ﻹ�����������ꤵĹ��\n");Sleep(150);
	printf("ֻ�н���Щ����һһ���ܣ�\n");	Sleep(150);
	printf("���ܿ������ϵĵ�·��\n");	Sleep(150);
	printf("����\n");	Sleep(150);
	printf("��·�ľ�ͷ���н⿪�����������ܵ�Կ�ס�\n");	Sleep(150);
	printf("�����ڣ�\n");	Sleep(150);
	printf("��һλ��;����������˵ء�\n");	Sleep(150);
	printf("Ta���Ϊ�ҿ������������\n");	Sleep(150);
	useless=_getch();
};
//��������

static void Help() {
	char useless;
	system("cls");//����
	std::cout << "��ӭ������Zircon��д������" << std::endl;Sleep(150);
	std::cout << "����ģ��������Ϸ��ħ������д��С��Ϸ" << std::endl;Sleep(150);
	std::cout << "�������Ϸ������Դ���һλ��;������" << std::endl;Sleep(150);
	std::cout << "���ϴ����;�Ĺ�������Լ���ʵ��" << std::endl;Sleep(150);
	std::cout << "���սҿ����������ܣ��ٴ������Ϊʲô��ɵľ�������" << std::endl;Sleep(150);
	std::cout << std::endl;
	std::cout << "д�����Ϸ����һʱ�����ѧ��д�Ľ��" << std::endl;Sleep(150);
	std::cout << "���зǳ��������û���޸ģ��������" << std::endl;Sleep(150);
	std::cout << "����뽻���Ļ���ӭ΢������" << std::endl;Sleep(150);
	std::cout << "�һ�ͦ�е�" << std::endl;Sleep(150);
	std::cout << "�ٴθ�л" << std::endl;Sleep(150);
	useless=_getch();
};
//����

static void EndMovie() {
	char useless;
	system("cls");//����
	std::cout << "�ϰ�����Ȼ��������" << std::endl;useless=_getch();
	std::cout << "�ϰ����Ȼ�ܲ����ģ��������ʱ���Ѿ���������Щ��������׬�˺ܶ�Ǯ��" << std::endl;useless = _getch();
	std::cout << "�ϰ��������Ҫȥ���ݳ�����" << std::endl;useless = _getch();
	std::cout << "�ϰ�������Ժ󻹻���Ǯ����������������һ���Ҫʱ��ʱ���������" << std::endl;useless = _getch();
	std::cout << "�ϰ�������������ҵĵ�" << std::endl;useless = _getch();
	std::cout << "�ϰ��ֻ����Ϊ���������븺ծΣ�������̲�ס��Ǯ�ѵ꿪��Խ��Խ��ͱ��������" << std::endl;useless = _getch();
	std::cout << "�ϰ����֮����ӭ�ٴι��٣�������Ե�ټ�" << std::endl;useless = _getch();
	std::cout << "�����ĳ���������ǰ������" << std::endl;useless = _getch();
	std::cout << "�ⳡ������ó����ջ��ǵ������յ�" << std::endl;useless = _getch();
	std::cout << "��л����" << std::endl;
	std::cout <<std::endl;useless = _getch();
}
//��������Boss�ĶԻ�

static void menu() {
	system("cls");//����
	std::cout << std::endl;
	std::cout << "����������������......"<<std::endl;
	std::cout << "������Ҫ��ʲô��" << std::endl;
	std::cout << "A:ȥҰ�����߰�" << std::endl;
	std::cout << "S:ȥ��㶫����" << std::endl;
	std::cout << "H:ȥ�ù���Ϣһ���" << std::endl;
	std::cout << "W:ȥ��սǿ�а�" << std::endl;
	std::cout << "T:���������������Ĵ�˵" << std::endl;
	std::cout << "I:�����ڵ�״̬��ô���ˣ�" << std::endl;
	std::cout << "B:��������ʼǰ�" << std::endl;
	std::cout << "J:�ؿ�һ������ֽ����" << std::endl;
	std::cout << "End:�˳�" << std::endl;
	std::cout << std::endl;
};
//�˵�

int main() {
	char useless;
	std::unordered_map<int, Monster>monsterbook;

	system("color 9F");

	monsterbook[1] = Monster("Ĩ��ʷ��ķ", 40.0, 10.0, 5.0, 10, 80);
	monsterbook[2] = Monster("����ʷ��ķ", 40.0, 13.0, 5.0, 12, 100);
	monsterbook[3] = Monster("����ʷ��ķ", 50.0, 10.0, 5.0, 12, 100);
	monsterbook[4] = Monster("�ɿ���ʷ��ķ", 60.0, 10.0, 10.0, 12, 150);
	monsterbook[5] = Monster("��ʷ��ķ", 40.0, 0.0, 0.0, 990, 9900);
	monsterbook[6] = Monster("С����������", 30.0, 13.0, 3.0, 10, 80);
	monsterbook[7] = Monster("�����������", 35.0, 15.0, 3.0, 12, 100);
	monsterbook[8] = Monster("�Ǻ�«����", 40.0, 20.0, 5.0, 18, 200);

	monsterbook[101] = Monster("͵�Ե�����", 100.0, 30.0, 10.0, 100, 1000);
	monsterbook[102] = Monster("��·�Ļ�ë����", 200.0, 60.0, 20.0, 200, 2000);
	monsterbook[103] = Monster("�޴����ڵ�ǿ׳����Ͱ", 300.0, 100.0, 30.0, 300, 3000);
	monsterbook[104] = Monster("��ҧ�˵�������", 400.0, 200.0, 40.0, 400, 4000);
	monsterbook[110] = Monster("ֻ����۾Ƶ��ϰ���", 800.0, 300.0, 50.0, 500, 5000);

	std::cout << "��ӭ��������" << std::endl;
	std::cout << "��Ϊ�ʵǵ����������" << std::endl;
	std::string PlayerName;
	std::cin >> PlayerName;
	std::cout << PlayerName << "�������Ǹ�������"<<std::endl<<"���ڣ���ʼ���ð�հ�" << std::endl;
	useless=_getch();

	PlayerOut playerout(PlayerName);

	while (true) {	
		menu();
		useless = _getch();

		if(GetAsyncKeyState(65)|| GetAsyncKeyState(97)) {
			int choice = 1;
			while (choice != 2) {
				int randomIndex = std::rand() % 7;// ����һ��������  
				if (fight(playerout, monsterbook[randomIndex+1]) == 1) {
					std::cout << std::endl;
					std::cout << "��Ҫ���������" << std::endl;
					std::cout << "1.���� 2.��ȥ��" << std::endl;
					std::cin >> choice;
				}
				else {
					choice = 2;
				}
			}
		}
		//Ұ��
		if (GetAsyncKeyState(83) || GetAsyncKeyState(115)) {
			shop(playerout);
		}
		//�̵�
		if (GetAsyncKeyState(72) || GetAsyncKeyState(104)) {
			hotel(playerout);
		}
		//�ù�
		if (GetAsyncKeyState(87) || GetAsyncKeyState(119)) {
			std::cout << playerout.name << "ʰ�����ϣ��ܿ�������һ����ǰ" << std::endl;
			std::cout << playerout.name << "�����о����������������ǰ�Ķ��֣�Ұ��Ĺ���Ҳ���ɱ���ǿ" << std::endl;
			std::cout << playerout.name << "��Ȼ����ǿ�Ķ���Ҳ��ζ�Ÿ����Ľ����������̵�Ҳ�Ὺ���µ���Ʒ" << std::endl;
			
			if (playerout.boss < 4) {
                std::cout << "�µ����罫����ǰչ��" << std::endl;
				if (fight(playerout, monsterbook[playerout.boss + 101])) {
					playerout.boss++;
				}
			}
			else{
				std::cout << "���������ܾ�����ǰ�������е����߱�������ֱǰ" << std::endl;
				if (fight(playerout, monsterbook[110])) {
					if (playerout.HasSeenMovie == false) {
						EndMovie();
						playerout.HasSeenMovie = true;					
						playerout.boss++;
					}
				}
			}
		}
		//��ս
		if (GetAsyncKeyState(98) || GetAsyncKeyState(66)) {
			std::cout << "������Ұ�������Ĺ����У�" << std::endl;
			for (int i = 1;i <= 8;i++) {
				if (monsterbook[i].hasMeet) {
					monsterbook[i].monsterInfo();
				}
			}
			useless = _getch();
			std::cout << "����������ǿ���У�" << std::endl;
			for (int i = 101;i <= 104;i++) {
				if (monsterbook[i].hasMeet) {
					monsterbook[i].monsterInfo();
				}
				if (monsterbook[110].hasMeet) {
					monsterbook[110].monsterInfo();
				}
			}
			useless = _getch();
		}
		//����ʼ�
		if (GetAsyncKeyState(84) || GetAsyncKeyState(116)) {
			story();
		}
		//����
		if (GetAsyncKeyState(73) || GetAsyncKeyState(105)) {
			std::cout << "����"<<playerout.name<<"����ϢΪ:" << std::endl;
			playerout.PlayerOutInfo();
			useless = _getch();
		}
		//��Ϣ
		if (GetAsyncKeyState(74) || GetAsyncKeyState(106)) {
			Help();
		}
		//����
		if (GetAsyncKeyState(VK_END)&0x23) {
			std::cout << "End" << std::endl;
			break;
		}
		//�˳�
	}
	return 0;
};