#pragma once
using namespace std;

class Object
{
private:
	static int totalObj;
	static int activeObj;
	int* operations = nullptr;
	int operationsCount = 0;
	
public:
	
	int GetTObj() const {
		return totalObj;
			}
			
	int GetAObj() const {
		return activeObj;
			}
	
	int GetCOp() const {
		return operationsCount;
			}		
	
	enum Operations{
		SUM,
		SUB,
		MULT,
		DIV,
		COMP
	};
	
	Object();
	Object(const Object& otherFraction);
	Object& operator=(const Object& otherFraction);
	virtual ~Object();

	static void PrintTotalInfo();

	void AddOp(int Operations);
	void ClearOp();
	void PrintOp(const char** Present) const;
};
