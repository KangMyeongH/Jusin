#pragma once
#include "Component.h"
class MonoBehavior : public Component
{
public:
	MonoBehavior();

	Component* Clone() const override = 0;
protected:
	virtual void 		start() = 0;
	virtual void 		update() = 0;
	virtual void 		render() = 0;
	virtual void 		end() = 0;

	friend class Core;
};