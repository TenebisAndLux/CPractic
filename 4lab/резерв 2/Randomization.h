#pragma once
#include<iostream>
#include<stdlib.h>
#pragma warning(disable : 4996)


using namespace std;

static const char* ranFackName[10] = {
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

static const char* ranDetailName[10] = {
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

static const char* ranName[65] = {
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

static const char* ranSurname[65] = {
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

	static const char* getFackName() {
		int i = (rand() * 5) % (10 - 0);
		const char* fackName = ranFackName[i];

		return fackName;
	}

	static const char* getRanFIO() {
		int i = (rand() * 10) % (64 - 0);
		const char* name = ranName[i];
		const char* surname = ranSurname[i];
		const char* space =" ";
		char* FIO = new char{};
		strcat(FIO, name);
		strcat(FIO, space);
		strcat(FIO, surname);

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

	static const char* getDetailName() {
		int i = rand() % (10);
		const char* detailName = ranDetailName[i];

		return detailName;
	}

};

