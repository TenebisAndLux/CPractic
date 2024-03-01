#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

static const string ranFackName[10] = {
		"Microelectronics",
		"LabaevArms",
		"RadioEngineering",
		"Avto",
		"RedFlag",
		"Automobile",
		"Millitary",
		"Metell",
		"Litie",
		"RanNaMe"
};

static const string ranDetailName[10] = {
	"Microelectronic",
	"Plata",
	"Software",
	"Toyota",
	"Barrel",
	"Gun",
	"RanDetAIl",
	"Transistor",
	"Antenna",
	"Refrezeraitor"
};

static const string ranName[65] = {
	"Kaisha",
	"Alexandria",
	"Hania",
	"Heidi",
	"Arthur",
	"Shanae",
	"Haydn",
	"Amara",
	"Aleah",
	"Emilie",
	"Arissa",
	"Ryker",
	"Mathild",
	"Ocean",
	"Jacqueline",
	"Heather",
	"Rafferty",
	"Umar",
	"Nansi",
	"Ethel",
	"Kiaan",
	"Chyna",
	"Drake",
	"Loretta",
	"Aarron",
	"Henri",
	"Jillian",
	"Dani",
	"Shereen",
	"Shayaan",
	"Daisy",
	"Piers",
	"Firat",
	"Summer",
	"Maxime",
	"Letitia",
	"Kiki",
	"Henrietta",
	"Cheryl",
	"Ayyan",
	"Ishmael",
	"Shreya",
	"Danish",
	"Uwais",
	"Storm",
	"Ewan",
	"Poppy",
	"Lani",
	"Roseanne",
	"Will",
	"Saul",
	"Bibi",
	"Alishba",
	"Viaan",
	"Matias",
	"Dominick",
	"Amber",
	"Christopher",
	"Osama",
	"Arjan",
	"Rhonda",
	"Ziggy",
	"Savannah",
	"Judith",
	"James",
};

static const string ranSurname[65] = {
	"Sierra",
	"Ramos",
	"Edge",
	"Pratt",
	"Read",
	"Calderon",
	"Crane",
	"Waters",
	"Rawlings",
	"Shepherd",
	"Russell",
	"Felix",
	"Ball",
	"Golden",
	"Fields",
	"Bird",
	"Hoover",
	"Vinson",
	"Tillman",
	"Nicholson",
	"Sparks",
	"Petty",
	"Truong",
	"Kenny",
	"Singleton",
	"Kramer",
	"Little",
	"Buckley",
	"Wicks",
	"York",
	"Neale",
	"Lin",
	"Jefferson",
	"Hough",
	"Bradford",
	"Alexander",
	"Bryan",
	"Hulme",
	"Wolf",
	"Coffey",
	"Ratcliffe",
	"Dawe",
	"Vang",
	"Arnold",
	"Glenn",
	"Figueroa",
	"Crouch",
	"Davies",
	"Simon",
	"Choi",
	"Chung",
	"Leigh",
	"AliZhba",
	"Taylor",
	"Mohammed",
	"Mcknight",
	"Todd",
	"Mills",
	"Orr",
	"Nash",
	"Mora",
	"Cannon",
	"Corona",
	"Summers",
	"Lake",
};

class Randomization
{
public:
	
	static int getRanAge() {
		int age = 18 + (rand() * 10) % (75 - 18 + 1);

		return age;
	}
	
	static float getRanSalary() {
		float Salary = 22000 + (rand() * 5512) % (220000 - 22000 + 1);

		return Salary;
	}

	static string getFackName() {
		int i = (rand() * 5) % (10 - 0);
		string fackName = ranFackName[i];

		return fackName;
	}

	static string getRanFIO() {
		int i = (rand() * 10) % (64 - 0);
		string name = ranName[i];
		string surname = ranSurname[i];
		string FIO = name + " " + surname;

		return FIO;
	} 

	static float getRanK1() {
		float Koeff = 40 + (rand() * 10) % (150 - 40 + 1);

		return Koeff;
	}

	static float getRanK2() {
		float Koeff = 40 + (rand() * 15) % (150 - 40 + 1);

		return Koeff;
	}

	static string getDetailName() {
		int i = rand() % (10);
		string detailName = ranDetailName[i];

		return detailName;
	}

};

