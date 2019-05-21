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

	void Reset_symbol();
	void Reset_scorre();
	void Reset_preview();
	

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
	

	

	
	char Get_symbol(const  COORD i);
	char Get_scorre(const  COORD i);
	char Get_preview(const  COORD i);

	//F
	COORD Get_cF_start();
	COORD Get_cF_end();
	
	//P
	COORD Get_cP_start();
	COORD Get_cP_end();
	
	//S
	COORD Get_cS_start();
	COORD Get_cS_end();
	

};

