#pragma 



class Block
{
	int _x;
	int _y;
	char _symbol;
public:
	Block();
	Block(int x, int y, char & _symbol);
	~Block();


	char Get_symbol();
	int Get_X();
	int Get_Y();

	void Set_symbol(char & symbol);
	void Set_X(int x);
	void Set_Y(int y);

	void Move_on(int x, int y);
	void Move_to(int x, int y);
//	void Rotate(my_enums::Rotate r);

};

