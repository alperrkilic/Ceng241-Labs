#include <iostream>
#include <string>

using namespace std;

class Player{
	
	private:	
		string name;
		int xp;
		int health;
		
	public:	
		
		Player()
		{
			cout<<"No args constructor called"<<endl;
			name="Default name";
			xp=999;
			health=100;
		}
		Player(string name)
		{
			cout<<"One-args constructor called"<<endl;
			this->name=name;
			this->xp=999;
			this->health=100;
		}
		Player(string name,int xp,int health)
		{
			cout<<"Three-args constructor called."<<endl;
			this->name=name;
			this->xp=xp;
			this->health=health;
		}
		~Player()
		{
			cout<<"Destructor for: "<<name<<endl;
		}
		
		void setName(string name){
			this->name=name;
		}
		
		string getName(void){
			return this->name;
		}
		
		void setXp(int xp){
			this->xp=xp;
		}
		
		int getXp(void){
			return this->xp;
		}
		
		void setHealth(int health){
			this->health=health;
		}
		
		int getHealth(void){
			return this->health;
		}
		
};

int main(void){
	
	Player p1;
	{
		Player p2;
		cout<<"Inside the block p2"<<endl;	
	}
	
	Player p2("Alper");
	Player p3("Utku",100,100);
	
	return 0;
}