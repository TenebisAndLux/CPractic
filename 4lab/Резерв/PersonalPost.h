#pragma once
namespace PersonalPost
{
	enum PersonalPost
	{
		DEFAULT = 0,
		WORKER,
		ENGINEER,
		FOREMAN,
		MANAGER
	};

	inline const string ToString(PersonalPost type)
	{
		switch (type)
		{
		case WORKER:
			return "Worker";
		case ENGINEER:
			return "Engineer";
		case FOREMAN:
			return "Foreman";
		case MANAGER:
			return "Manager";
		default:
			return "Default";
		}
	}
}