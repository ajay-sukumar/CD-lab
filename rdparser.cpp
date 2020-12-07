#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX_SIZE 100


char str[MAX_SIZE];
int length = 0;
int lookup = 0;
int error = 0;

void E();
void T();
void F();
void E_();
void T_();


int match(char ch)
{
	while (str[lookup] == ' ' || str[lookup] == '\n')
		lookup++;

	if (lookup < length && str[lookup] == ch)
	{
		lookup++;
		return 1;
	}
	return 0;
}


void E()
{
	T();
	E_();
}

void T()
{
	F();
	T_();
}

void F()
{
	if (match('('))
	{
		E();
		if (match(')') == 0)
			error = 1;
	}
	else
	{
		if (match('i') == 0)
			error = 1;
	}
}

void E_()
{
	if (match('+'))
	{
		T();
		E_();
	}
}

void T_()
{
	if (match('*'))
	{
		F();
		T_();
	}
}


int main()
{
	cout<<"GRAMMAR\n";
	cout<<"E->E+T|T\nT->T*F|F\nF->(E)|i\n";
	cout<<"\nAFTER ELIMINATING LEFT RECURSION\n";
	cout<<"E->TE'\nE'->+TE'|ε\nT->FT'\nT'->*FT'|ε\nF->(E)|i\n";

	cout<<"Enter string: ";
	// scanf("%[^\t]%*c",string);
	// scanf("%s", string);
	fgets(str, MAX_SIZE, stdin);
	length = strlen(str);

	E();

	cout<<"Lookup pos: "<<lookup<<"\nError: "<<error<<endl;

	if (lookup == length && error == 0)
	{
		cout<<"String Accepted\n";
	}
	else
	{
		cout<<"String not Accepted\n";
	}
	return 0;
}