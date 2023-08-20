#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	string name;
	char input;
	int inputuser;
	int score;
	cout<<"Enter Your Name ";
    getline(cin,name);

cout<<endl;
	do{
        //?
		int variable=rand()%5+1;  
		cout<<"enter any number in between range 1 to 5 "<<endl;
        cin>>inputuser;
		cout<<endl;
		if(inputuser==variable)
		{
			cout<<"Congratulation ! you guessed correect number"<<endl;
			score++;
		}
		else{
			cout<<"sorry try again!"<<endl;
		}
		cout<<"would you like to try again yes or no : "<<endl;
		cin>>input;
	}
	while(input!='N');
	cout<<"your score is: "<<score<<endl;
	cout<<"Game End"<<endl;
}