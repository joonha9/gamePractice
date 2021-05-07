#include <iostream>
#include <Windows.h>
using namespace std;

const int n = 7;
char map[n][n + 1] = {
    "#######",
    "#   ^ #",
    "# #  a#",
    "### M #",
    "#    ##",
    "#    Y#",
    "#######",
};

//주인공 좌표
int dy = 1;
int dx = 1;

//HP
int hp = 100;

void print()
{
    system("cls");

    //2중for 맵을 출력 소스코드 작성
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            if (y == dy && x == dx) {
                cout << "@";
            }
            else {
                cout << map[y][x];
            }
        }
        cout << "\n";
    }
    cout << "HP : " << hp << "\n";
    Sleep(100);
}

int main()
{

    //위, 아래, 왼쪽, 오른쪽 출력
    while (1) {
        
        print();

        if (GetAsyncKeyState(VK_UP) & 0x8001) {
            if (map[dy - 1][dx] != '#') dy--;
            if (map[dy][dx] == '^') hp -= 10;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
            if (map[dy + 1][dx] != '#') dy++;
            if (map[dy][dx] == '^') hp -= 10;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8001) {
            if (map[dy][dx - 1] != '#') dx--;
            if (map[dy][dx] == '^') hp -= 10;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
            if (map[dy][dx + 1] != '#') dx++;
            if (map[dy][dx] == '^') hp -= 10;
        }

        if (map[dy][dx] == 'a') {
            map[dy][dx] = ' ';
            hp = 100;
        }

        if (map[dy][dx] == 'M' || hp == 0) {
            print();
            Sleep(700);
            system("cls");
            cout << "\n\n\n      GAME OVER\n\n\n";
            Sleep(3000);
            break;
        }

        if (map[dy][dx] == 'Y') {
            print();
            Sleep(700);
            system("cls");
            cout << "\n\n\n      WIN (" << hp << ")\n\n\n";
            Sleep(3000);
            break;
        }

        Sleep(10);
    };

    return 0;
}