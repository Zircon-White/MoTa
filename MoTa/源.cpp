#include <stdio.h>
#include<conio.h>
#include <string>  
#include <iostream> 
#include <vector>  
#include <windows.h>
#include<unordered_map>

class PlayerOut {//玩家（战斗外）
public:
	std::string name;//名字
	float hp=100;//生命值
	float atk=20;//攻击力
	int mana=20;//法力
	float def=5;//防御力
	int cookie=30;//饼干
	int lev=1;//等级
	int exp=0;//经验值
	int boss = 0;//挑战的boss数(世界等级

	int redBottle = 3;//血瓶
	int blueBottle = 2;//蓝瓶
	int energyBottle = 0;//力量瓶
	int spyWater = 0;//辣椒水
	int chaWater = 0;//蓄力水
	int magicWater = 0;//神奇药水

	bool smallgift = false;
	bool HasSeenMovie = false;

	PlayerOut(const std::string name):name(name){}

	void PlayerOutInfo() const {//战斗外状态
		std::cout << "名称："<<name<<std::endl;
		std::cout << "生命值：" << hp << std::endl;
		std::cout << "攻击力：" << atk << std::endl;
		std::cout << "魔力值：" << mana << std::endl;
		std::cout << "防御力：" << def << std::endl;
		std::cout << "饼干数：" << cookie << std::endl;
		std::cout << "等级：" << lev << std::endl;
		std::cout << "经验值：" << exp << std::endl;
		std::cout << std::endl;
		std::cout << "道具:" << std::endl;
		std::cout << "健康药水：" <<redBottle<< "瓶" << std::endl;
		std::cout << "魔力药水：" << blueBottle << "瓶" << std::endl;
		std::cout << "力量药水：" << energyBottle << "瓶" << std::endl;
		if (boss > 0) {
			std::cout << "辣椒水：" << spyWater << "瓶" << std::endl;
		}
		if (boss > 2) {
			std::cout << "蓄力水：" << chaWater << "瓶" << std::endl;
		}
		if (boss > 3) {
			std::cout<< "神奇药水：" << magicWater << "瓶" << std::endl;
		}
		if (smallgift) {
			std::cout<<"已经收到礼物了" << std::endl;
		}
		std::cout << std::endl;
	}
};
//玩家（战斗外）

class PlayerFight {
public:
	int hot;//被辣到
	int poison;//中毒
	int strong;//强壮
	int charge;//蓄力

	PlayerFight(const int hot, int poison, int strong,int charge)
		:hot(hot),poison(poison),strong(strong),charge(charge){}

	void PlayerFightInfo() const {//战斗内状态
		std::cout << "现在的状态是:" << std::endl;
		if(hot != 0)std::cout << "被辣到动不了了" << std::endl;
		if (poison != 0)std::cout << "因为黑暗料理中毒了" << std::endl;
		if (strong != 0)std::cout << "感觉身上充满力量" << std::endl;
		if (charge != 0)std::cout << "正在蓄力" << std::endl;
	}
};
//玩家（战斗内）

class Monster {
public:
	std::string name;//名字
	float hp;//生命值倍率
	float atk;//攻击力倍率
	float def;//防御力倍率
	int cookie;//饼干倍率
	int exp;//经验值倍率
	bool hasMeet = false;//是否遇到过

	Monster(){}
	Monster(const std::string name, float hp, float atk, float def, int cookie, int exp)
		:name(name),hp(hp),atk(atk),def(def),cookie(cookie),exp(exp){}

	void monsterInfo() const {
		std::cout << "名称：" <<name<< std::endl;
		std::cout << "生命值倍率：" <<hp<< std::endl;
		std::cout << "攻击力倍率：" <<atk<< std::endl;
		std::cout << "防御力倍率：" <<def<< std::endl;
		std::cout << "饼干倍率：" <<cookie<< std::endl;
		std::cout << "经验值倍率：" <<exp<< std::endl;
		std::cout <<std::endl;
	}
};
//怪物

static void object(PlayerOut& playerout) {
	std::cout << std::endl;
	std::cout << "背包:" << std::endl;
	std::cout << "1.健康药水：" << playerout.redBottle <<"瓶"<< std::endl;
	std::cout << "2.魔力药水：" << playerout.blueBottle << "瓶" << std::endl;
	std::cout << "3.力量药水：" << playerout.energyBottle << "瓶" << std::endl;
	if (playerout.boss > 0) {
		std::cout << "4.辣椒水：" << playerout.spyWater << "瓶" << std::endl;
	}
	if (playerout.boss > 2) {
		std::cout << "5.蓄力水：" << playerout.chaWater << "瓶" << std::endl;
	}
	if (playerout.boss > 3) {
		std::cout << "6.神奇药水：" << playerout.magicWater << "瓶" << std::endl;
	}
	std::cout << "同一药水在时效内服用只会刷新时间" << std::endl;
};
//道具列表

static int fight(PlayerOut& playerout, Monster& monster) {
	char useless;
	system("cls");//清屏

	int ahot=0;//被辣到
	int apoison=0;//中毒
	int astrong=0;//强壮
	int acharge=0;//蓄力
	int aTen = 0;//减伤

	int bhot = 0;
	int bpoison = 0;

	int abHurt, baHurt;     //勇士每回合攻击怪物的伤害、怪物反击的伤害
	int turn = 0;

	float aAtk = playerout.atk;//引用
	float aDef = playerout.def;
	float aHp = playerout.hp;
	float bAtk = monster.atk*(playerout.boss+1);
	float bDef = monster.def *(playerout.boss + 1);
	float bHp = monster.hp *(playerout.boss + 1);
	int aMana = playerout.mana;

	std::cout << monster.name << "出现了！" << std::endl;
	if (!monster.hasMeet) {
		std::cout << monster.name << "是第一次遇到" << std::endl;
		monster.hasMeet = true;
	}

	while (aHp > 0 && bHp > 0){
		turn++;
		std::cout << std::endl;
		std::cout << "第" << turn << "回合" << std::endl;

		if (astrong > 0) {
			std::cout << playerout.name << "感觉充满了力量" << std::endl;
		}
		//力量

		if (aTen > 0) {
			std::cout << playerout.name << "感觉自己刀枪不入" << std::endl;
		}
		//减伤

		std::cout << "请做出选择：" << std::endl;
		std::cout << "1.攻击 2.防御 3.逃跑 4.道具" << std::endl;

		int choice = 0;
		std::cin >> choice;

		if (choice == 3) {
			std::cout << playerout.name << "逃跑了" << std::endl;
			playerout.hp = aHp;
			useless=_getch();
			return 0;
		}
		//逃跑
		else if (choice == 1) {
			std::cout << "请选择攻击方式：" << std::endl;
			std::cout << "1.普通攻击" << std::endl;
			std::cout << "2.蓄力攻击(在蓄力攻击后发动普通攻击可增加伤害)"<< std::endl;
			std::cout << "3.黑暗料理攻击" << std::endl;
			std::cout << std::endl;
			int x = 0;
			std::cin >> x;

			if (x == 1) {
				aAtk = aAtk * (acharge+1);
				abHurt = (aAtk > bDef) ? (aAtk - bDef) : 0;
				std::cout << playerout.name << "向" << monster.name << "发起了攻击，造成了" << abHurt << "点伤害" << std::endl;
				bHp -= abHurt;
				std::cout << monster.name << "现在有" << bHp << "点生命值" << std::endl;
			}
			//普攻
			else if (x == 2) {
				std::cout << playerout.name << "开始蓄力" << std::endl;
				acharge++;
				std::cout << "现在已经蓄力了" << acharge << "个回合"<<std::endl;
			}
			//蓄力
			else if (x == 3) {
				std::cout << "请选择给出的料理：" << std::endl;
				std::cout << "1.仰望星空派(伤害减少，但所造成的攻击无视对方防御力)，法力消耗：10" << std::endl;
				std::cout << "2.超辣火鸡面(造成持续伤害，持续三回合)，法力消耗：15" << std::endl;
				std::cout << std::endl;
				int y=0;
				std::cin >> y;

				if (y == 1&&aMana>=10) {
					abHurt = aAtk*0.7;
					std::cout << monster.name << "被仰望星空派攻击了，造成了" << abHurt << "点伤害" << std::endl;
					bHp -= abHurt;
					aMana -= 10;
				}
				//仰望星空派
				else if (y == 2&&aMana>=15) {
					std::cout << monster.name << "被超辣火鸡面攻击了"<< std::endl;
					bhot = 3;
					aMana -= 15;
				}
				//超辣火鸡面
				else {
					std::cout << playerout.name << "在发呆" << std::endl;
				}
				//发呆（魔力不足或输入错误
			}
			//魔法
		}
		//攻击
		else if (choice == 2) {
			aDef = aDef * 2;
		}
		//防御
		else if (choice == 4) {
			object(playerout); 
			int y = 0;
			std::cin >> y;
			if (y == 1&&playerout.redBottle>0) {
				std::cout << playerout.name << "使用了健康药水，感觉自己充满了决心" << std::endl;
				aHp += 50 * (playerout.boss+1);
				std::cout << "现在有" << aHp << "点生命值" << std::endl;
				playerout.redBottle--;
			}
			//健康药水
			else if (y == 2 && playerout.blueBottle > 0) {
				std::cout << playerout.name << "使用了魔力药水，魔力恢复了" << std::endl;
				aMana = (aMana+20*(playerout.boss+1)<playerout.mana) ? (aMana + 20 * (playerout.boss+1)) : playerout.mana;
				std::cout << "现在有" << aMana << "点魔力" << std::endl;
				playerout.blueBottle--;
			}
			//魔力药水
			else if (y == 3 && playerout.blueBottle > 0) {
				std::cout << playerout.name << "使用了力量药水，基础伤害增加了" << std::endl;
				astrong=3;
				std::cout << playerout.name << "感觉充满了力量" << std::endl;
				aAtk = aAtk * 1.6;
			}
			//力量
			else if (y == 4 && playerout.spyWater > 0) {
				std::cout << playerout.name << "使用了辣椒水" << std::endl;
				std::cout << monster.name << "被辣椒水辣到睁不开眼睛" << std::endl;
				bhot = 3;
				playerout.spyWater --;
			}
			//辣椒水
			else if (y == 5 && playerout.chaWater > 0) {
				std::cout << playerout.name << "使用了蓄力水" << std::endl;
				std::cout << playerout.name << "跳过了蓄力过程" << std::endl;
				acharge+=2;
				std::cout << "现在已经蓄力了" << acharge << "个回合" << std::endl;
				playerout.chaWater--;
			}
			//蓄力水
			else if (y == 6 && playerout.magicWater > 0) {
				std::cout << playerout.name << "使用了神奇药水" << std::endl;
				std::cout << playerout.name << "感觉自己现在强的可怕" << std::endl;
				aTen = 3;
				aDef = aDef * 10;
				playerout.magicWater--;
			}
			else {
				std::cout << playerout.name << "在发呆" << std::endl;
			}
		}
		//道具
		else {
			std::cout << playerout.name << "听不懂，不知道该做什么" << std::endl;
		}
		//无所事事


		if (bHp <= 0)break;//打败怪物
		else {
			baHurt = (bAtk > aDef) ? (bAtk - aDef) : 0;
			std::cout << monster.name << "向" << playerout.name << "发起了攻击，造成了" << baHurt << "点伤害" << std::endl;
			aHp -= baHurt;
			std::cout <<playerout.name <<"剩余" << aHp << "点生命值" << std::endl;
		}
		//怪物攻击
		if (playerout.smallgift) {
			aHp += 20 * (playerout.boss + 1);
			std::cout << "老板娘的菜谱在闪闪发光" << std::endl;
			std::cout << playerout.name << "恢复了" << 20 * (playerout.boss + 1) << "点生命值" << std::endl;
		}
		//小礼物

		if (choice == 2) {
			aDef = aDef / 2;
		}
		//防御

		if (bhot > 0) {
			abHurt = aAtk*0.45;
			std::cout << monster.name << "被辣到了，造成了" << abHurt << "点伤害" << std::endl;
			bHp -= abHurt;
			std::cout << monster.name << "现在有" << bHp << "点生命值" << std::endl;
		}
		//辣到了

		if (astrong >0) {
			astrong--;
			if (astrong == 0) {
				std::cout << "力量效果消失了" << std::endl;
				aAtk = playerout.atk;
			}
		}
		//力量效果
	
		if (aTen > 0) {
			aTen--;
			if (aTen == 0) {
				std::cout << "减伤效果消失了" << std::endl;
				aDef = playerout.def;
			}
		}	
		//减伤效果
		
		if (bHp <= 0)break;//打败怪物
	}

	if (aHp > 0) {
		playerout.cookie += monster.cookie * (playerout.boss + 1);
		playerout.exp += monster.exp * (playerout.boss + 1);
		playerout.hp = aHp;

		std::cout << std::endl;
		std::cout << playerout.name << "战胜了" << monster.name << std::endl;
		std::cout << "获得" << monster.cookie * (playerout.boss + 1) << "块饼干," << monster.exp * (playerout.boss + 1) << "点经验,";
		std::cout << "剩余生命值" << playerout.hp << "点,";
		std::cout << "饼干" << playerout.cookie << "块" << std::endl;

		while (playerout.exp >= playerout.lev*1000) {
			playerout.exp -= playerout.lev * 1000;

			playerout.lev++;
			playerout.hp +=100;
			playerout.atk +=5;
			playerout.def +=2;
			playerout.mana +=5;
			
			std::cout << "升级了！" << playerout.name << "现在是" << playerout.lev << "级"<<std::endl;
			std::cout<<playerout.name<<"的生命值增加了" << std::endl;
			std::cout << playerout.name << "的攻击力增加了" << std::endl;
			std::cout << playerout.name << "的防御力增加了" << std::endl;
			std::cout << playerout.name << "的魔力上限增加了" << std::endl;
		}
		useless=_getch();
		return 1;
	}
	else {
		std::cout << "战斗失败，" << playerout.name << "被路过的好心人送到了旅馆" << std::endl;
		playerout.hp = 50;
		useless = _getch();
		return 0;
	}
};
//战斗函数

static void shop(PlayerOut& player) {
	system("cls");//清屏
	std::cout << "欢迎来到祝尼魔商店，看看有什么想要的？" << std::endl;
	std::cout << "现在有" << player.cookie << "块饼干" << std::endl;
	std::cout << "商品1：5点攻击力，售价100块饼干" << std::endl;
	std::cout << "商品2：5点防御值，售价100块饼干" << std::endl;
	std::cout << "商品3：1瓶健康药水，能恢复" << 50 * (player.boss + 1) << "点生命值，售价" << 80 * (player.boss + 1) << "块饼干" << std::endl;
	std::cout << "商品4：1瓶魔力药水，能恢复" << 20 * (player.boss + 1) << "点魔力，售价" << 80 * (player.boss + 1) << "块饼干" << std::endl;
	std::cout << "商品5：1瓶力量药水，能在三回合内提升基础伤害，售价"<<150 * (player.boss + 1) <<"块饼干" << std::endl;
	if (player.boss > 0) {
		std::cout << "更新商品：" << std::endl;
		std::cout << "商品6：1瓶辣椒水，或许可以在情急时喷对面一脸，售价"<<100 * (player.boss + 1) <<"块饼干" << std::endl;
	}
	if (player.boss > 2) {
		std::cout << "商品7：1瓶蓄力药水，喝下可以立刻获得两层蓄力效果，售价1000块饼干" << std::endl;
	}
	if (player.boss > 3) {
		std::cout << "商品8：1瓶神奇药水，喝下可以在接下来的三个回合里大幅减少受到的伤害，售价2000块饼干" << std::endl;
	}
	if (player.boss > 4) {
		std::cout << "商品9：给传奇勇者的小小奖励，不用饼干哦" << std::endl;
	}
	std::cout << "输入0退出商店" << std::endl;

	int x = 1;
	while (x!=0) {
		std::cin >> x;
		int num = 0;
		switch (x) {
		case 1:
			std::cout << "您想购买几份呢？" << std::endl;

			std::cin >> num;
			if (player.cookie >= 100*num) {
				player.cookie -= 100*num;
				player.atk += 5*num;
				std::cout << "购买成功！攻击力增加了" << std::endl;
				std::cout << "现在有" << player.cookie << "块饼干" << std::endl;
			}
			else {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 2:
			std::cout << "您想购买几份呢？" << std::endl;
			std::cin >> num;
			if (player.cookie >= 100 * num) {
				player.cookie -= 100 * num;
				player.def += 5 * num;
				std::cout << "购买成功！防御力增加了" << std::endl;
				std::cout << "现在有" << player.cookie << "块饼干" << std::endl;
			}
			else {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 3:
			if (player.cookie >= 80 * (player.boss + 1)) {
				player.cookie -= 80 * (player.boss + 1);
				player.redBottle ++;
				std::cout << "购买成功！现在有" << player.redBottle << "瓶健康药水" << std::endl;
			}
			else {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 4:
			if (player.cookie >= 80 * (player.boss + 1)) {
				player.cookie -= 80 * (player.boss + 1);
				player.blueBottle++;
				std::cout << "购买成功！现在有" << player.blueBottle << "瓶魔法药水" << std::endl;
			}
			else {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 5:
			if (player.cookie >= 150 * (player.boss + 1)) {
				player.cookie -= 150 * (player.boss + 1);
				player.energyBottle++;
				std::cout << "购买成功！现在有" << player.energyBottle << "瓶力量药水" << std::endl;
			}
			else {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 6:
			if (player.cookie >= 100 * (player.boss + 1)&& player.boss > 0) {
				player.cookie -= 100 * (player.boss + 1);
				player.spyWater++;
				std::cout << "购买成功！现在有" << player.spyWater << "瓶辣椒水" << std::endl;
			}
			else if(player.cookie < 100 * (player.boss + 1)){
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 7:
			if (player.cookie >= 1000 && player.boss > 2) {
				player.cookie -= 1000;
				player.chaWater++;
				std::cout << "购买成功！现在有" << player.chaWater << "瓶蓄力水" << std::endl;
			}
			else if(player.cookie < 1000) {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 8:
			if (player.cookie >= 2000 && player.boss > 3) {
				player.cookie -= 2000;
				player.magicWater++;
				std::cout << "购买成功！现在有" << player.magicWater << "瓶神奇药水" << std::endl;
			}
			else if (player.cookie < 2000) {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 9:
			if (player.boss > 4&&!player.smallgift) {
				player.smallgift=true;
				std::cout << "看来你收到我的小礼物了，要天天开心呀" << std::endl;
				std::cout << "你收到了老板娘的菜谱" << std::endl;
				std::cout << "从此以后，每回合结束都会恢复少量生命值" << std::endl;
			}
			break;
		}
	}
};
//商店函数

static void hotel(PlayerOut& player) {
	system("cls");//清屏
	std::cout << "欢迎来到旅馆，想住什么样的房间？" << std::endl;
	std::cout << "现在有" << player.cookie << "块饼干" << std::endl;
	std::cout << "1.储藏间：恢复100点生命值，售价30块饼干" << std::endl;
	std::cout << "2.普通单人间：恢复500点生命值，售价100块饼干" << std::endl;
	std::cout << "3.豪华大床房：恢复4000点生命值，售价500块饼干" << std::endl;
	std::cout << "想离开旅馆的话就输入0" << std::endl;

	int x = 1;
	while (x != 0) {
		std::cin >> x;

		switch (x) {
		case 1:
			if (player.cookie >= 30) {
				player.cookie -= 30;
				player.hp += 100;
				std::cout << "在储藏间休息了一会，生命值增加了100点。" << std::endl;
				std::cout << "现在有" << player.cookie << "块饼干" << std::endl;
			}
			else {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 2:
			if (player.cookie >= 100) {
				player.cookie -= 100;
				player.hp += 500;
				std::cout << "在普通单人间休息了一会，生命值增加了500点。" << std::endl;
				std::cout << "现在有" << player.cookie << "块饼干" << std::endl;
			}
			else {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		case 3:
			if (player.cookie >= 500) {
				player.cookie -= 500;
				player.hp += 4000;
				std::cout << "在豪华大床房休息了一会，生命值增加了2000点。" << std::endl;
				std::cout << "现在有" << player.cookie << "块饼干" << std::endl;
			}
			else {
				std::cout << "饼干不够了" << std::endl;
			}
			break;
		}
	}
};
//旅馆函数

static void story() {
	char useless;
	system("cls");//清屏
	printf("这是一个很古老的故事\n");Sleep(150);
	printf("在很久很久以前，在遥远的幻想乡里，\n");Sleep(150);
	printf("无数神奇的生灵们在此生活。\n");Sleep(150);
	printf("但突然有一天，出现了一座神秘的馍塔。\n");Sleep(150);
	printf("迷路的旅人在偶然间进入馍塔，\n");Sleep(150);
	printf("发现里面充满了无数的美食。\n");Sleep(150);
	printf("可没等旅人们高兴，\n");	Sleep(150);
	printf("他们发现馍塔里还有无数饥肠辘辘的怪物，\n");Sleep(150);
	printf("只有将那些怪物一一击败，\n");	Sleep(150);
	printf("才能开启向上的道路，\n");	Sleep(150);
	printf("或许，\n");	Sleep(150);
	printf("道路的尽头会有解开这座馍塔秘密的钥匙。\n");	Sleep(150);
	printf("而现在，\n");	Sleep(150);
	printf("又一位迷途的灵魂来到此地。\n");	Sleep(150);
	printf("Ta会成为揭开谜题的勇者吗？\n");	Sleep(150);
	useless=_getch();
};
//背景故事

static void Help() {
	char useless;
	system("cls");//清屏
	std::cout << "欢迎来到由Zircon编写的馍塔" << std::endl;Sleep(150);
	std::cout << "这是模仿著名游戏“魔塔”所写的小游戏" << std::endl;Sleep(150);
	std::cout << "在这个游戏中你可以创造一位迷途的旅人" << std::endl;Sleep(150);
	std::cout << "不断打败沿途的怪物，提升自己的实力" << std::endl;Sleep(150);
	std::cout << "最终揭开塔顶的秘密，再次理解鸟为什么会飞的经典问题" << std::endl;Sleep(150);
	std::cout << std::endl;
	std::cout << "写这个游戏本是一时兴起边学边写的结果" << std::endl;Sleep(150);
	std::cout << "还有非常多的问题没有修改，还请见谅" << std::endl;Sleep(150);
	std::cout << "如果想交流的话欢迎微信找我" << std::endl;Sleep(150);
	std::cout << "我还挺闲的" << std::endl;Sleep(150);
	std::cout << "再次感谢" << std::endl;Sleep(150);
	useless=_getch();
};
//帮助

static void EndMovie() {
	char useless;
	system("cls");//清屏
	std::cout << "老板娘：你居然击败了我" << std::endl;useless=_getch();
	std::cout << "老板娘：虽然很不甘心，但我这段时间已经在你们这些旅人身上赚了很多钱了" << std::endl;useless = _getch();
	std::cout << "老板娘：现在我要去办演唱会了" << std::endl;useless = _getch();
	std::cout << "老板娘：或许以后还会有钱不够的情况，所以我还是要时不时过来开店的" << std::endl;useless = _getch();
	std::cout << "老板娘：这座塔就是我的店" << std::endl;useless = _getch();
	std::cout << "老板娘：只是因为反反覆陷入负债危机还会忍不住借钱把店开得越来越大就变成这样了" << std::endl;useless = _getch();
	std::cout << "老板娘：总之，欢迎再次光临，我们有缘再见" << std::endl;useless = _getch();
	std::cout << "馍塔的出口在你面前缓缓打开" << std::endl;useless = _getch();
	std::cout << "这场奇妙的旅程最终还是到达了终点" << std::endl;useless = _getch();
	std::cout << "感谢游玩" << std::endl;
	std::cout <<std::endl;useless = _getch();
}
//击败最终Boss的对话

static void menu() {
	system("cls");//清屏
	std::cout << std::endl;
	std::cout << "噔噔噔噔噔噔噔噔......"<<std::endl;
	std::cout << "接下来要做什么？" << std::endl;
	std::cout << "A:去野外走走吧" << std::endl;
	std::cout << "S:去买点东西吧" << std::endl;
	std::cout << "H:去旅馆休息一会吧" << std::endl;
	std::cout << "W:去挑战强敌吧" << std::endl;
	std::cout << "T:还想再听听馍塔的传说" << std::endl;
	std::cout << "I:我现在的状态怎么样了？" << std::endl;
	std::cout << "B:翻翻怪物笔记吧" << std::endl;
	std::cout << "J:回看一下神秘纸条吧" << std::endl;
	std::cout << "End:退出" << std::endl;
	std::cout << std::endl;
};
//菜单

int main() {
	char useless;
	std::unordered_map<int, Monster>monsterbook;

	system("color 9F");

	monsterbook[1] = Monster("抹茶史莱姆", 40.0, 10.0, 5.0, 10, 80);
	monsterbook[2] = Monster("辣椒史莱姆", 40.0, 13.0, 5.0, 12, 100);
	monsterbook[3] = Monster("可乐史莱姆", 50.0, 10.0, 5.0, 12, 100);
	monsterbook[4] = Monster("巧克力史莱姆", 60.0, 10.0, 10.0, 12, 150);
	monsterbook[5] = Monster("金箔史莱姆", 40.0, 0.0, 0.0, 990, 9900);
	monsterbook[6] = Monster("小拐杖糖蝙蝠", 30.0, 13.0, 3.0, 10, 80);
	monsterbook[7] = Monster("大拐杖糖蝙蝠", 35.0, 15.0, 3.0, 12, 100);
	monsterbook[8] = Monster("糖葫芦蝙蝠", 40.0, 20.0, 5.0, 18, 200);

	monsterbook[101] = Monster("偷吃的扑满", 100.0, 30.0, 10.0, 100, 1000);
	monsterbook[102] = Monster("迷路的黄毛耗子", 200.0, 60.0, 20.0, 200, 2000);
	monsterbook[103] = Monster("无处不在的强壮垃圾桶", 300.0, 100.0, 30.0, 300, 3000);
	monsterbook[104] = Monster("嗷嗷咬人的依蝙蝠", 400.0, 200.0, 40.0, 400, 4000);
	monsterbook[110] = Monster("只卖天价酒的老板娘", 800.0, 300.0, 50.0, 500, 5000);

	std::cout << "欢迎来到馍塔" << std::endl;
	std::cout << "请为攀登的灵魂命名：" << std::endl;
	std::string PlayerName;
	std::cin >> PlayerName;
	std::cout << PlayerName << "啊，真是个好名字"<<std::endl<<"现在，开始你的冒险吧" << std::endl;
	useless=_getch();

	PlayerOut playerout(PlayerName);

	while (true) {	
		menu();
		useless = _getch();

		if(GetAsyncKeyState(65)|| GetAsyncKeyState(97)) {
			int choice = 1;
			while (choice != 2) {
				int randomIndex = std::rand() % 7;// 生成一个随机编号  
				if (fight(playerout, monsterbook[randomIndex+1]) == 1) {
					std::cout << std::endl;
					std::cout << "还要继续逛逛吗？" << std::endl;
					std::cout << "1.继续 2.回去吧" << std::endl;
					std::cin >> choice;
				}
				else {
					choice = 2;
				}
			}
		}
		//野外
		if (GetAsyncKeyState(83) || GetAsyncKeyState(115)) {
			shop(playerout);
		}
		//商店
		if (GetAsyncKeyState(72) || GetAsyncKeyState(104)) {
			hotel(playerout);
		}
		//旅馆
		if (GetAsyncKeyState(87) || GetAsyncKeyState(119)) {
			std::cout << playerout.name << "拾级而上，很快来到了一座门前" << std::endl;
			std::cout << playerout.name << "隐隐感觉到，如果击败了眼前的对手，野外的怪物也将成倍变强" << std::endl;
			std::cout << playerout.name << "当然，更强的对手也意味着更丰厚的奖励，或许商店也会开放新的商品" << std::endl;
			
			if (playerout.boss < 4) {
                std::cout << "新的世界将在眼前展开" << std::endl;
				if (fight(playerout, monsterbook[playerout.boss + 101])) {
					playerout.boss++;
				}
			}
			else{
				std::cout << "馍塔的秘密就在眼前，命运中的勇者必须勇往直前" << std::endl;
				if (fight(playerout, monsterbook[110])) {
					if (playerout.HasSeenMovie == false) {
						EndMovie();
						playerout.HasSeenMovie = true;					
						playerout.boss++;
					}
				}
			}
		}
		//挑战
		if (GetAsyncKeyState(98) || GetAsyncKeyState(66)) {
			std::cout << "现在在野外遇到的怪物有：" << std::endl;
			for (int i = 1;i <= 8;i++) {
				if (monsterbook[i].hasMeet) {
					monsterbook[i].monsterInfo();
				}
			}
			useless = _getch();
			std::cout << "现在遇到的强敌有：" << std::endl;
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
		//怪物笔记
		if (GetAsyncKeyState(84) || GetAsyncKeyState(116)) {
			story();
		}
		//故事
		if (GetAsyncKeyState(73) || GetAsyncKeyState(105)) {
			std::cout << "现在"<<playerout.name<<"的信息为:" << std::endl;
			playerout.PlayerOutInfo();
			useless = _getch();
		}
		//信息
		if (GetAsyncKeyState(74) || GetAsyncKeyState(106)) {
			Help();
		}
		//帮助
		if (GetAsyncKeyState(VK_END)&0x23) {
			std::cout << "End" << std::endl;
			break;
		}
		//退出
	}
	return 0;
};