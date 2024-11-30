#pragma once

#pragma region Singleton
#define NO_COPY(ClassName)							\
ClassName(const ClassName&) = delete; 				\
ClassName(ClassName&&) = delete;					\
ClassName& operator=(const ClassName&) = delete; 	\
ClassName& operator=(ClassName&&) = delete; 		

#define DECLARE_SINGLETON(ClassName)				\
		NO_COPY(ClassName)							\
public:												\
	static ClassName& GetInstance();


#define IMPLEMENT_SINGLETON(ClassName)				\
ClassName& ClassName::GetInstance()					\
{													\
	static ClassName sClass;						\
	return sClass;									\
}
#pragma endregion Singleton

enum CHANNELID
{
	SOUND_EFFECT,
	SOUND_BGM,
	MAXCHANNEL
};

struct CUSTOMVERTEX
{
	float x, y, z;
	DWORD color;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)