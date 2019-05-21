#include "Field.h"


#pragma region  system
Field::Field()
{
	cF_start = COORD() = {0,0};
	 cF_end = COORD() = { 18,22 };
	_field = new char*[cF_end.Y];

	for (int y = 0; y < cF_end.Y; y++)
	{
		_field[y] = new char[cF_end.X];
		for (int x = 0; x < cF_end.X; x++)
		{
			if(x==0||y==0||x== cF_end.X-1|| y == cF_end.Y-1)
				_field[y][x] = '#';
			else
			_field[y][x] ='●';
		}
	}
	

	//P
	 cP_start = COORD() = { 16,0 };
	 cP_end = COORD() = { 9,22 };


	 for (int y = 0; y < cP_end.Y; y++)
	 {
		 _preview[y] = new char[cP_end.X];
		 for (int x = 0; x < cP_end.X; x++)
		 {
			 if (x == 0 || y == 0 || x == cP_end.X - 1 || y == cP_end.Y - 1)
				 _preview[y][x] = '#';
			 else
			 _preview[y][x] = ' ';
		 }
	 }
	 //S
	
	


	cS_start = COORD() = { 0,22 };
	cS_end = COORD() = { 25,5 };


	for (int y = 0; y < cS_end.Y; y++)
	{
		_scorre[y] = new char[cS_end.X];
		for (int x = 0; x < cS_end.X; x++)
		{
			if (x == 0 || y == 0 || x == cS_end.X - 1 || y == cS_end.Y - 1)
				_scorre[y][x] = '#';
			else
			_scorre[y][x] = ' ';
		}
	}
	
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

#pragma endregion


#pragma region  set

void Field::Set_symbol(const COORD i, const char s)
{
	_field[i.Y][i.X] = s;
}
void Field::Set_scorre(const int i)
{

}
void Field::Set_preview(my_enums::Block b);
//F
void Field::Set_cF_start(const COORD i);
void Field::Set_cF_end(const COORD i);

//P
void Field::Set_cP_start(const COORD i);
void Field::Set_cP_end(const COORD i);

//S
void Field::Set_cS_start(const  COORD i);
void Field::Set_cS_end(const  COORD i);

//G
void Field::Set_cG_start(const COORD i);
void Field::Set_cG_end(const COORD i);


#pragma endregion


#pragma region  get
char Get_symbol(const int x, const int y);

//F
int Get_xF();
int Get_yF();

//P
int Get_xP();
int Get_yP();

//S
int Get_xS();
int Get_yS();
#pragma endregion

