#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>
#include "GameObject.h"

class Character : public GameObject
{
	public:
		Character(Properties* props) : GameObject(props) {}
		virtual void Render() = 0;
		virtual void Release() = 0;
		virtual void Update(double dt) = 0;
	protected:
		std::string _name;
};

#endif