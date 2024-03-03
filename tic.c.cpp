#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
char t[9]={'1','2','3','4','5','6','7','8','9'};
int n;
/*Not completed*/
void display_board();
void xo_read();
bool checkwiner();
void ia_player();
bool checkdraw();
int main()
{
	bool b,c;
	cout << "tic_tac_toe by engineer aboud\n";
		display_board();
	do{ 
		xo_read();
		ia_player();
        	display_board();
		b=checkdraw();
		c=checkwiner();
	}while(b==false && c==false);
}

void display_board()
{
	cout << " " << t[0] << " | " << t[1] << " | " << t[2] << " " << endl;
	cout << "-----------" << endl;
	cout << " " << t[3] << " | " << t[4] << " | " << t[5] << " " << endl;
	cout << "-----------" << endl;
	cout << " " << t[6] << " | " << t[7] << " | " << t[8] << " " << endl;
}
void xo_read()
{
	do {
		cout << "enter number 1~9 : ";
		cin >> n;
	} while (t[n-1] == 'x' && t[n-1] == 'o');
		t[n-1] = 'x';
}
void ia_player() {
    int ii=1;
	do {
		srand(time(NULL));
		n = rand() % 9;
		if(t[n] == 'x' && t[n] == 'x'){
			ii=1;
		}
	} while (ii==0);
	t[n - 1] = 'o';
}
/*checkwinner function and checkdraw are not completed*/
bool checkwiner(){
	int i;
	for (i=0;i<9;i+=3)
	{
	if(t[i] == t[i+1] == t[i+2])
		return true;
	}
	for (i=0;i<3;i+=3)
	{
	if(t[i] == t[i+3] == t[i+6])
		return true;
	}
	i=0;
	if(t[i]==t[i+4]==t[i+8])
		return true;
	if(t[i+2]==t[i+4]==t[i+6])
		return true;

	return false;
}
bool checkdraw(){
	int i;
		for(i=0;i<9;i++){
		if(t[i] != 'x' || t[i] != 'o' )
		return false;
		}
		return true;
}
