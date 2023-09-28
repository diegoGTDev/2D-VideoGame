#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include"IObject.h"
#include"Transform.h"
#include<string>
#include<SDL_render.h>
class Texture;
class Animation;

struct Properties
{
public:
	Properties(std::string texturePath, int width = 0, int height = 0, float x = 0, float y = 0, SDL_RendererFlip flip = SDL_FLIP_NONE)
	{
		this->texturePath = texturePath;
		this->Flip = flip;
		this->Width = width;
		this->Height = height;
		this->X = x;
		this->Y = y;
	}
	float X, Y;
	int Width, Height;
	std::string texturePath;
	SDL_RendererFlip Flip;
};
class GameObject : public IObject
{
	public:
		GameObject(Properties* props) : m_TexturePath(props->texturePath), m_width(props->Width), m_height(props->Height), m_flip(props->Flip) {
			m_transform = new Transform(props->X, props->Y);
		}
		virtual void Render() = 0;
		virtual void Release() = 0;
		virtual void Update(double dt) = 0;
protected:
	Transform* m_transform;
	int m_width, m_height;
	std::string m_TexturePath;
	Texture* m_texture;
	SDL_RendererFlip m_flip;
};

#endif
