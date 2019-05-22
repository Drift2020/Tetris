#include "Field.h"
#include <stdio.h>

#pragma region  system
//Класс для хранения поля
Field::Field()
{
	cF_start = COORD() = {0,0};
	cF_end = COORD() = { 19,22 };
	Reset_symbol();
	

	//P
	 cP_start = COORD() = { 16,0 };
	 cP_end = COORD() = { 11,22 };
	 Reset_preview();
	 
	 //S




	cS_start = COORD() = { 0,21 };
	cS_end = COORD() = { 27,5 };
	Reset_scorre();
	
}

Field::~Field()
{
	for (int y = 0; y < cF_end.Y; y++)
	{
	
		for (int x = 0; x < cF_end.X; x++)
		{
			
			delete[] _field[y];
		}
	}
	delete[] _field;




	for (int y = 0; y < cP_end.Y; y++)
	{
		
		for (int x = 0; x < cP_end.X; x++)
		{
			
			delete[]	_preview[y];
		}
	}
	delete[] _preview;


	for (int y = 0; y < cS_end.Y; y++)
	{
		
		for (int x = 0; x < cS_end.X; x++)
		{
		
			delete[] _scorre[y];
		}
	}
	delete[]_scorre;
}

void Field::Reset_symbol()
{
	_field = new char*[cF_end.Y];

	for (int y = 0; y < cF_end.Y; y++)
	{
		_field[y] = new char [cF_end.X];

		for (int x = 0; x < cF_end.X; x++)
		{
			if (y == 0 || y == cF_end.Y - 1|| x == 0 || x == cF_end.X - 1)
				_field[y][x] = '#';
			else
				_field[y][x] = '.'; 


		}
	

	}
}
void Field::Reset_scorre()
{
	_scorre = new char*[cS_end.Y];
	for (int y = 0; y < cS_end.Y; y++)
	{
		_scorre[y] = new char[cS_end.X];
		for (int x = 0; x < cS_end.X; x++)
		{
			if (y == 0 || y == cS_end.Y - 1|| x == 0 || x == cS_end.X - 1)
				_scorre[y][x] = '#';
			else
				_scorre[y][x] = ' ';
		}
	

	}
}
void Field::Reset_preview()
{
	_preview = new char*[cP_end.Y];
	for (int y = 0; y < cP_end.Y; y++)
	{
		_preview[y] = new char[cP_end.X];
		for (int x = 0; x < cP_end.X; x++)
		{
			if (y == 0 || y == cP_end.Y - 1|| x == 0 || x == cP_end.X - 1)
				_preview[y][x] = '#';
			else
				_preview[y][x] = ' ';
		}
	}
}
#pragma endregion


#pragma region  set

void Field::Set_symbol(const COORD i, const char s)
{
	_field[i.Y][i.X] = s;
}
void Field::Set_scorre(const int i)
{
	char temp[100];
	sprintf(temp, "> Scorre: %d\0", i);
	int size = strlen(temp);
	for (int i = 3,i1=0; i < size; i++,i1++)
	{
		_scorre[3][i] = temp[i1];
	}

	
}
void Field::Set_preview(my_enums::Block b) {
	Reset_preview();
	switch (b)
	{
	case my_enums::T1:

		
		_preview[3][4]='▣';
		_preview[4][4] = '▣';
		_preview[5][4] = '▣';
		_preview[5][5] = '▣';
			

		break;
	case my_enums::T2:
		break;
	case my_enums::T3:
		break;
	case my_enums::T4:
		break;
	case my_enums::T5:
		break;
	case my_enums::T6:
		break;
	case my_enums::T7:
		break;
	default:
		Reset_preview();
		break;
	}
}
//F

void Field::Set_cF_start(const COORD i) {
	this->cF_start = i;
}
void Field::Set_cF_end(const COORD i) {
	this->cF_end = i;
}

//P
void Field::Set_cP_start(const COORD i) {
	this->cP_start = i;
}
void Field::Set_cP_end(const COORD i) {
	this->cF_end = i;
}

//S
void Field::Set_cS_start(const  COORD i) {
	this->cS_start = i;
}
void Field::Set_cS_end(const  COORD i) {
	this->cS_end = i;
}


#pragma endregion


#pragma region  get
char  Field::Get_symbol(const  COORD i) {

	return this->_field[i.Y][i.X];

}

char  Field::Get_scorre(const  COORD i) {

	return this->_scorre[i.Y][i.X];

}

char  Field::Get_preview(const  COORD i) {

	return this->_preview[i.Y][i.X];

}

//F
COORD  Field::Get_cF_start() {
	return this->cF_start;
}
COORD  Field::Get_cF_end()
{
	return this->cF_end;
}

//P
COORD  Field::Get_cP_start() {
	return this->cP_start;
}
COORD  Field::Get_cP_end() {
	return this->cP_end;
}

//S
COORD  Field::Get_cS_start() {
	return this->cS_start;
}
COORD  Field::Get_cS_end() {
	return this->cS_end;
}
#pragma endregion

