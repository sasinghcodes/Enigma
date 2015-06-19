#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std ;
int q=0,w=0,e=0;
int Pos[3];							//GLOBAL VARIABLE FOR POSITION OF ROTORS
char R[3][27],
		   //ABCDEFGHIJKLMNOPQRSTUVWXYZ
AR[5][27]={	"EKMFLGDQVZNTOWYHXUSPAIBRCJ",//R1
			"AJDKSIRUXBLHWTMCQGZNPYFVOE",//R2
			"BDFHJLCPRTXVZNYEIWGAKMUSQO",//R3
			"ESOVPZJAYQUIRHXLNFTGKDCMWB",//R4
			"VZBRGITYUPSDNHLXAWMJQOFECK"},//R5
Ref[27]=	"EJMZALYXVBWFCRQUONTSPIKHGD",//REFLECTOR
pb[27]=		"ZYXWVUTSRQKLMNOPJIHGFEDCBA";//PLUGBOARD
		   //ABCDEFGHIJKLMNOPQRSTUVWXYZ
 char rotor(char a)
{
	int i=-1,j;
	if(a>96)a-=32;
	a=pb[a-65];//FIRST PASS IN PLUG BOARD
	while(++i<3)	
		a=R[i][(a-65+Pos[i])%26];//PASSING THROUGH EACH ROTOR 1ST TIME TOP TO BOTTOM
	a=Ref[a-65];				  //REFLECTOR CHANGE THE VALUE
	while(j=26,i--)					//PASSING THROUGH ROTORS 2ND TIME FROM BOTTOM TO TOP
	{
		while(--j*(R[i][j]-a));		//FINDING INDEX OF CHARACTER a FROM 25 TO 0(RIGHT TO LEFT)
		a=65+((j-Pos[i]+26)%26);	
	}
	if(!(Pos[0]=++Pos[0]%26))//ROATATING ROTOR 1
		//IF ROTOR 1 HAS VALUE 26 THN IT WILL ROTATE 2ND ROTOR ND VALUE OF 1ST ROTOR WILL BE 0
		if(!(Pos[1]=++Pos[1]%26))//ROTATING ROTOR 2 IF ROTOR 1 IS ZERO
			//IF ROTOR 2 HAS VALUE 26 THN IT WILL ROTATE 3RD ROTOR WILL BE 0
			Pos[2]=++Pos[2]%26;//ROTATING ROTOR 3 IF ROTOR 1 AND ROTOR 2 ARE ZERO
	a=pb[a-65];//SECOND PASS THROUGH PLUG BOARD 
	return a;
}
int main()
{
	char str[20];
	int x=1,i;
	cout<<setw(45)<<"||__Enigma__||";
	while(x==1)
	{
		cout<<"\n\nEnter Order Of Rotors( |5| |4| |3| |2| |1| ) ";
		cin>>q>>w>>e;
		for(int k=0;k<26;k++)
		{
			R[0][k]=AR[q-1][k];
			R[1][k]=AR[w-1][k];
			R[2][k]=AR[e-1][k];
		}
		
	//x:	try
		//{
		cout<<"\n\nEnter the Rotor Positions :";
/*	cin>>Pos[2]>>Pos[1]>>Pos[0];
	Pos[0]--;
	Pos[1]--;
	Pos[2]--;
*/
		for(i=3;i--;Pos[i]--)		//ENTERING INITIAL POSITIONS OF ROTORS
			cin>>Pos[i];
		/*if(Pos[i]>27||Pos[i]<=0)
			throw(5);
		
		}
		catch(int i)
		{
			cout<<"\nConfigure Rotor with value less than 26 ";
			goto x;
		}*/
		cout<<"\nEnter the string : ";	//ENTERING STRING
		flushall();
		cin.getline(str,20);
		cout<<"Coded string is : ";		//OUTPUT STRING
		for(int i=0;str[i]!='\0';cout<<rotor(str[i++]));
		cout<<"\nDo you Want To Continue(0/1) ";
		cin>>x;
		}
	getch();
	return 0;
}
