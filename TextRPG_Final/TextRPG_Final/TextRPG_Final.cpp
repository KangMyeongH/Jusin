// TextRPG_Final.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include <array>

#include "Object.h"
#include <iostream>

#include "Component.h"
#include "GameObject.h"
#include "Player.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	GameObject* test = new GameObject;
	test->AddComponent<Player>();
	return 0;
}
