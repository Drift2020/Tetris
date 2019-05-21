#pragma once
#include "Enums.h"
#include <Windows.h>


class Field
{
	char ** _field;
	COORD cF_start;
	COORD cF_end;

	char ** _preview;
	COORD cP_start;
	COORD cP_end;


	char ** _scorre;
	COORD cS_start;
	COORD cS_end;


	COORD cG_start;
	COORD cG_end;
	

public:
	Field();
	~Field();

	

	void Set_symbol(const COORD i, const char s);
	void Set_scorre(const int i);
	void Set_preview(my_enums::Block b);
	//F
	void Set_cF_start(const COORD i);
	void Set_cF_end(const COORD i);
	
	//P
	void Set_cP_start(const COORD i);
	void Set_cP_end(const COORD i);
	
	//S
	void Set_cS_start(const  COORD i);
	void Set_cS_end(const  COORD i);
	
	//G
	void Set_cG_start(const COORD i);
	void Set_cG_end(const COORD i);
	
	

	
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
	

};

