#pragma once
#include <iostream>

template <typename T>
class Singleton
{
public:
	static T& GetInstance() 				{ static T sInstance; return sInstance; }
	Singleton(const Singleton&) 			= delete;
	Singleton(Singleton&&) 					= delete;
	Singleton& operator=(const Singleton&) 	= delete;
	Singleton& operator=(Singleton&&) 		= delete;

protected:
	Singleton() { std::cout << "Singleton" << std::endl; }
	~Singleton() { std::cout << "Singleton 소멸자\n"; }
};
