#include <iostream>
#include <string>

using namespace std;

class Player{
	
	private:
		int health;
		int xp;
		string name;
	public:
		string get_name(void){return name;}
		int get_health(void){return health;}
		int get_xp(void){return xp;}
	
		Player(string name_val="None",int health_val=100,int xp_val=0);
			
		~Player(){cout<<"Destructor called for: " + name <<endl;}
	
		//copy constructor
		Player(const Player &source);
		

		
	
};

void display_player(Player p);


void display_player(Player p){
	
	cout<<"Name: "<<p.get_name()<<endl;
	cout<<"Health: "<<p.get_health()<<endl;
	cout<<"Xp: "<<p.get_xp()<<endl;	
	
}

Player::Player(string name_val,int health_val,int xp_val)
	:name{name_val},health{health_val},xp{xp_val}{
		cout<<"Three-args constructor with default parameters: "<<endl;
	}
	
Player::Player(const Player &source)
	: Player(source.name,source.health,source.xp){
	
	cout<<"Copy constructor - made copy of: "<<source.name<<endl;
	
}


int main(void){
	
	Player player1("alper",100,94);
	
	display_player(player1); //this copy of player1 lives within the range of copy constructor.
	
	cout<<"Goodbye"<<endl;
	
	return 0;
}