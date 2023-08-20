#include<iostream>
using namespace std;
void calculator(double num1,double num2,char op)
{

		switch( op ){
		
			case '+':
			cout<<num1<<" + "<<num2<<" = "<< ( num1 + num2 ) ;
		    return ;
		    
		    case '-':
			cout<<num1<<" - "<<num2<<" = "<< ( num1 - num2 ) ;
		    return ;
		    
		    case '*':
			cout<<num1<<" * "<<num2<<" = "<< ( num1 * num2 ) ;
		    return;
		    
		    case '/':
		    	if(num2!=0.0)
		    	{
		    	cout<<num1<<" / "<<num2<<" = "<< ( num1 / num2 ) ;
				}
				else{
					cout<<"since denominator is zero=> division not possible:"<<endl;	
				}
				return;
				
			default:
				cout<<op<<" is an invalid operator "<<endl;
				return ;
	}
	


}
int main()
{
	char op;
	double num1, num2;
	cout<<"EITHER enter the operator:( + , - , * , / ) OR (!) to close the calculator :"<<endl;
	cin>>op;
	
	while(op!='!')
	{
	
	
	cout<<"enter two numbers one by one: "<<endl;
	cin>>num1>>num2;
	
	calculator(num1,num2,op);
	cout<<endl;
	cout<<"EITHER enter the operator:( + , - , * , / ) OR (!) to close the calculator :"<<endl;
	cin>>op;
	
	}
	return 0;
	
}