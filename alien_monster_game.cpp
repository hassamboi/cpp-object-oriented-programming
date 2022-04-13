#include<iostream>
using namespace std;

class Enemy
{
public:
	Enemy() {}
	~Enemy() {}
	virtual void Attack() = 0;
	void Capture()
	{
		cout << "Capturing defenders' outpost" << endl;
	}
	virtual void Destroy() = 0;
};

class Alien :public Enemy
{
public:
	Alien() {}
	~Alien() {}
	void Attack()
	{
		cout << "Alien used Laser Beam" << endl;
	}

	void Destroy()
	{
		cout << "Alien was destroyed" << endl;
	}
};


class Monster :public Enemy
{
public:
	Monster() {}
	~Monster() {}
	void Attack()
	{
		cout << "Monster used its thorns" << endl;
	}

	void Destroy()
	{
		cout << "Monster was destroyed" << endl;
	}
};





class Defenders
{
public:
	Defenders() {}
	~Defenders() {}
	virtual bool Attack() = 0;
	void Capture()
	{
		cout << "Capturing Enemies' outpost" << endl;
	}
	virtual void Destroy() = 0;
	virtual bool SpecialAttack() = 0;
};




class GroundArmy :public Defenders
{
public:
	GroundArmy() {}
	~GroundArmy() {}
	bool Attack()
	{
		int attProb = rand() % 4;
		if (attProb <= 2)
		{
			cout << "Headshot on a Monster" << endl;
			return true;
		}
		else
		{
			cout << "Body Shot on a Monster" << endl;
			return false;
		}
	}

	void Destroy()
	{
		cout << "Ground Defender was destroyed" << endl;	
	}

	bool SpecialAttack()
	{
		int x = rand() % 10;
		cout << "Ground Army has used a Tactical Nuke" << endl;
		if (x > 8)
			return true;
		else
			return false;
	}
};




class AirborneArmy :public Defenders
{
public:
	AirborneArmy() {}
	~AirborneArmy() {}
	bool Attack()
	{
		int attProb = rand() % 4;
		if (attProb <= 2)
		{
			cout << "Headshot on an Alien" << endl;
			return true;
		}
		else
		{
			cout << "Body Shot on an Alien" << endl;
			return false;
		}
	}

	void Destroy()
	{
		cout << "Airborne Defender was destroyed" << endl;
	
	}

	bool SpecialAttack()
	{
		int x = rand() % 10;
		cout << "Airborne Army has used a Surgical strike" << endl;
		if (x > 8)
			return true;
		else
			return false;
	}
};


string choiceAtt()
{
	string x = "TAN";
	return "Author[name=" + x;
}

void choiceDef()
{
	cout << "Defenders' turn" << endl;
	cout << "Press 1 to use Special Attack" << endl;
	cout << "Press anything else to attack" << endl;
}

class Game
{
	Enemy* aliens;
	Enemy* monsters;
	Defenders* ground;
	Defenders* air;
	int* Talien;
	int* Tmonst;
	int* Tground;
	int* TAir;
public:
	
	Game()
	{
		aliens = new Alien[3];
		air = new AirborneArmy[5];
		monsters = new Monster[1];
		ground = new GroundArmy[5];
		(*Talien) = 0;
		(*Tmonst) = 0;
		(*Tground) = 0;
		(*TAir) = 0;
	}
	Game(int TAlien, int TMonst, int TGround, int Tair)
	{
		Talien = new int(TAlien);
		Tmonst = new int(TMonst);
		Tground = new int(TGround);
		TAir = new int(Tair);

		aliens = new Alien[*Talien];
		air = new AirborneArmy[*TAir];
		monsters = new Monster[*Tmonst];
		ground = new GroundArmy[*Tground];
	}

	~Game()
	{
		if (aliens != nullptr) 
			delete[] aliens;
		if(monsters!=nullptr)
			delete[] monsters;
		if(ground!=nullptr)
			delete[] ground;
		if(air!=nullptr)
			delete[] air;
		if(Talien!=nullptr)
			delete Talien;
		if(Tmonst!=nullptr)
			delete Tmonst;
		if(Tground!=nullptr)
			delete Tground;
		if(TAir!=nullptr)
			delete TAir;
	}



	void play()
	{
		int option;
		int* hitCount = new int(0);

		int* alienDeadCount = new int(0);
		int* monstDeadCount = new int(0);
		int* defDeadCount = new int(0);

		bool x;

		while (true)
		{
			choiceAtt();
			cin >> option;
			if (option == 1)
			{
				aliens->Capture();
				if (rand() % 2 == 1)
				{
					(*alienDeadCount)--;
					cout << "A defender turned into an Alien" << endl;
					(*defDeadCount)++;
				}
				else
					cout << "Capturing was stopped" << endl;
			}
			else
			{
				if ((*alienDeadCount != (*Talien))) 
				{
					aliens->Attack();
					air->Destroy();
					(*defDeadCount)++;
				}
				if ((*monstDeadCount != (*Tmonst))) {
					monsters->Attack();
					ground->Destroy();
					(*defDeadCount)++;
				}
			}

			if ((*defDeadCount) >= ((*TAir) + (*Tground)))
			{
				cout << "THE MONSTERS HAVE WON" << endl;
				delete this;
				break;
			}

			cout << "-----------------------------------------------------------------------" << endl;

			choiceDef();
			cin >> option;
			
			if (option == 1)
			{
				cout << "Press 1 to use Ground army's special attack" << endl;
				cout << "Press anything else to use Air army's special attack" << endl;
				cin >> option;

				if (option == 1)
				{
					x = ground->SpecialAttack();
					if (x == true && (*monstDeadCount) != (*Tmonst))
					{
						cout << "A monster was destroyed" << endl;
						(*monstDeadCount)++;
					}
					else
						cout << "The Special attack missed. No monsters were destroyed" << endl;
				}
				else
				{
					x = air->SpecialAttack();
					if (x == true && (*alienDeadCount) != (*Talien))
					{
						cout << "An alien was destroyed" << endl;
						(*alienDeadCount)++;
					}
					else
						cout << "The Special attack missed. No aliens were destroyed" << endl;
				}
			}

			else
			{
				x = ground->Attack();
				if (x == true && (*monstDeadCount) != (*Tmonst))
				{
					(*hitCount)++;
					if ((*hitCount) == 5)
					{
						monsters->Destroy();
						hitCount = 0;
						(*monstDeadCount)++;
					}
				}

				x = air->Attack();
				if (x == true && (*alienDeadCount) != (*Talien))
				{
					aliens->Destroy();
					(*alienDeadCount)++;
				}
			}

			cout << "-----------------------------------------------------------------------" << endl;

			if ((*alienDeadCount) >= (*Talien) && (*monstDeadCount) >= (*Tmonst))
			{
				cout << "THE DEFENDERS HAVE WON" << endl;
				delete this;
				break;
			}
		}
	}
};


int main()
{

	Game G;
	G.getA();
	return 0;
}