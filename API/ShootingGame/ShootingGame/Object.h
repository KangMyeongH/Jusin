#pragma once
#include <string>

class Object
{
public:
	// constructor
	Object() : mActive(false) {}
	explicit Object(const char* name) : mName(name), mActive(true) {}
	virtual ~Object() = default;
	Object(const Object& rhs) = default;
	Object(Object&& rhs) noexcept = default;

	// operator
	Object& operator=(const Object& rhs) = default;
	Object& operator=(Object&& rhs) noexcept = default;
	virtual explicit operator bool() const;
	virtual bool operator==(const Object& rhs);
	virtual bool operator!=(const Object& rhs);

	// static method
	static void 	Destroy(const Object* object);

	// method
	std::string 	ToString() const;

protected:
	std::string 	mName;
	bool 			mActive;
};