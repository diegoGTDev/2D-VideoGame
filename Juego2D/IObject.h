#ifndef IOBJECT_H
#define IOBJECT_H
class IObject
{
public:
	virtual void Render() = 0;
	virtual void Update(double dt) = 0;
	virtual void Release() = 0;
};

#endif
