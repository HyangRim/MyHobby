#define _CRT_NONSTDC_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
char key1, key2;
double accurate[1001] = { -1, };
int main(void) {
	int turn = 1;
	cout << "Hello. This is Stream Test Practice" << "\n";
	cout << "You Should checking two key for checking." << "\n";
	cout << "First Key : ";
	key1 = getch();
	cout << key1 <<"\n";
	cout << "Second Key : ";
	key2 = getch();
	cout << key2 << "\n";
	while (turn) {
		clock_t time1=0, time2=0, start=0, endtime=0;
		int count = 0, FirstKey = 1, accurateKey = 0;
		double Accaverage = 0;
		cout << "Input Key press Num.(20~1000) : ";
		cin >> count;
		for (int I = 0; I < count; I++) {
			accurate[I] = -1;
		}
		int KeyPressNum = count;
		cout << "\n" << "Okey. Setting is ready. if you press key, Timer is start." << "\n";
		while (count) {
			char c = getch();
			if ((c == key1 || c == key2) && FirstKey == 0) {
				time2 = clock();
				accurate[accurateKey] = time2 - time1;
				time1 = time2;
				count--;
				continue;
			}
			else if ((c == key1 || c == key2) && FirstKey == 1) {
				time1 = clock();
				start = time1;
				count--;
				FirstKey--;
				continue;
			}
		}
		endtime = clock();
		clock_t result = endtime - start;
		double SpendClock = (double)result / (double)CLOCKS_PER_SEC;
		double SecondPress = KeyPressNum / SpendClock;
		for (int I = 0; I < KeyPressNum; I++) {
			Accaverage += accurate[I];
		}
		Accaverage = Accaverage / KeyPressNum;
		cout << "\n\n";
		cout << "You spend " << SpendClock << " second" << "\n";
		cout << "You press " << SecondPress << " times a second and You can stream beat " << SecondPress*15 <<" bpm!\n";
		cout << "Your Press AverageAcc is " << Accaverage << ". (Zero is best)\n";
		cout << "Do you want repeat?" << "\n";
		
		cout << "Yes = 1, No = 0 " << "\n";
		cin >> turn;
	}
	return 0;
}