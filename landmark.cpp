#include <iostream>
#include <string>
using namespace std;

class Landmark
{
public:
	Landmark(string a)
	{
		m_name = a;
	}
	virtual string color() const { return "yellow"; }
	virtual string icon() const = 0;
	virtual string lmType() const = 0;
	string name() const { return m_name; }
private:
	string m_name;
};

class Hotel : public Landmark
{
public:
	Hotel(string a) : Landmark(a) {}
	string icon() const { return "bed"; }
	virtual string lmType() const { return "hotel"; }
};

class Restaurant : public Landmark
{
public:
	Restaurant(string a, int b) : Landmark(a)
	{
		cap = b;
	}
	string icon() const
	{ 
		if (cap < 40)
			return "small knife/fork";
		else
			return "large knife/fork";
	}
	virtual string lmType() const { return "restaurant"; }
private:
	int cap;
};

class Hospital : public Landmark
{
public:
	Hospital(string a) : Landmark(a) {}
	virtual string color() const {return "blue";}
	string icon() const { return "H"; }
	virtual string lmType() const { return "hospital"; }
};

void display(const Landmark* lm)
{
	cout << "Display a " << lm->color() << " " << lm->icon() << " icon for "
		<< lm->name() << "." << endl;
}

int main()
{
	Landmark* landmarks[4];
	landmarks[0] = new Hotel("Westwood Rest Good");
	landmarks[1] = new Restaurant("Bruin Bite", 30);
	landmarks[2] = new Restaurant("La Morsure de l'Ours", 100);
	landmarks[3] = new Hospital("UCLA Medical Center");

	cout << "Here are the landmarks." << endl;
	for (int k = 0; k < 4; k++)
		display(landmarks[k]);

	cout << "Cleaning up." << endl;
	for (int k = 0; k < 4; k++)
	{ 
		cout << "Destroying the " << landmarks[k]->lmType() << " " << landmarks[k]->name() << "." << endl;
		delete landmarks[k];
	}
		
}


