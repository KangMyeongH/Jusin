#include "pch.h"
#include "MonoBehavior.h"

MonoBehavior::MonoBehavior()
{
	Core::GetInstance().AddMonoBehavior(this);
}
