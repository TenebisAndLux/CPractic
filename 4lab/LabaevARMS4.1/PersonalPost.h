#pragma once
namespace PersonalPost
{
	enum class PersonalPost
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
		case PersonalPost::WORKER:
			return "Worker";
		case PersonalPost::ENGINEER:
			return "Engineer";
		case PersonalPost::FOREMAN:
			return "Foreman";
		case PersonalPost::MANAGER:
			return "Manager";
		default:
			return "Default";
		}
	}
}