// p1.cpp
// F1403022班  5140309508  张福明 

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int answer[3], guess[3];	// answer[3]:三个随机数，guess[3]: 猜测的数字 
	int i, j, correctA, correctB, games=0, win=0;	// correctA, correctB: A,B的数，games:游戏局数， win:赢的局数  
	char choose;	// choose: 输入的Y/N 
	
	srand(time(NULL));		// 随机数种子初始化 
	
	cout << "需要玩游戏吗（Y/N）？ ";
	cin >> choose;
	if (choose=='Y'){
		do {
			answer[0]=rand()*10/(RAND_MAX+1);		// 生成随机数1 
			answer[1]=rand()*10/(RAND_MAX+1);		// 生成随机数2 
			while (answer[1]==answer[0]){
				answer[1]=rand()*10/(RAND_MAX+1);	// 检验随机数2和随机数1是否相同 
			}
			answer[2]=rand()*10/(RAND_MAX+1);		// 生成随机数3 
			while (answer[2]==answer[1] || answer[2]==answer[0]){
				answer[2]=rand()*10/(RAND_MAX+1);	// 检验随机数3和随机数1、2是否相同 
			}
			games+=1;						// 记录游戏局数 
			for (i=0; i<7; ++i){
				cout << "请输入你猜测的数字:" << endl;
				for (j=0; j<3; ++j){
					cin >> guess[j];		// 输入猜测的数字 
				}
				correctA=0;
				correctB=0;
				for (j=0; j<3; ++j){		// 计算位置正确数字也正确(A)的数目 
					if (answer[j] == guess[j]) correctA+=1;		
				}
				for (j=0; j<3; ++j){		// 计算数字正确但位置不正确(B)的数目
					if (answer[j]==guess[(j+1)%3] || answer[j]==guess[(j+2)%3])	correctB+=1;	
				}
				if (correctA==3){
					win+=1;					// 记录赢的局数 
					cout << "恭喜，你猜对了";
					break; 
				}
				else cout << correctA << 'A' << correctB << 'B' << endl;	// 输出A、B 
			}
			if (correctA!=3) {
				cout << "很遗憾，你没有在规定次数内猜对。答案是 ";
				for (j=0; j<3; ++j){		// 输出正确答案 
					cout << answer[j];
				}
			}
			cout << endl << "需要玩游戏吗（Y/N）？ ";		// 询问玩家是否继续游戏 
			cin >> choose; 
		} while (choose=='Y');
	}
	cout << "你一共玩了" << games << "局，赢了" << win << "局，输了" << games-win << "局\n";	// 统计输出 
	
	return 0;
}
