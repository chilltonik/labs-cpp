#pragma once
#include <map>
#include "Game.h"
#include "Fixed.h"
#include "Mobile.h"
#include "Planet.h"
#include "Star.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "Rocket.h"

class ObjectFactory //класс который создает нужный нам объект
{
private:
	map<string, Game*>	OBJECTS;//список, который хранит 2 значения(название класса и указатель на объект класса)
	void Add_object_type(Game* obj)//заполняет список объектами
	{
		OBJECTS.try_emplace(obj->get_Type(), obj);//push_back для map
	}
public:
	ObjectFactory()//Добавляем все объекты в map
	{
		Add_object_type(new Star());
		Add_object_type(new Planet());
		Add_object_type(new Asteroid());
		Add_object_type(new Spaceship());
		Add_object_type(new Rocket());
	}
	~ObjectFactory()
	{
		for (map<string, Game*>::iterator it = OBJECTS.begin(); it != OBJECTS.end(); ++it)
		{
			delete it->second;
		}
		OBJECTS.clear();//очищаем map
	}

	Game* create(const char* typeName)//ищем нужный нам объект класса
	{
		map<string, Game*>::iterator it = OBJECTS.find(typeName);//итератор, который ищет объект с таким названием
		if (it == OBJECTS.end())//если не нашел
		{
			return nullptr;
		}
		return it->second->Clone();//возвращаем скопированный нужный нам объект
	}
};