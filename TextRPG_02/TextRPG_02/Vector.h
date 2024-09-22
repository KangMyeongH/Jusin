#pragma once

template<typename T>
class Vector
{
public:
	// constructor
	Vector();
	~Vector();
	Vector(const Vector& rhs) = delete;
	Vector(Vector&& rhs) noexcept = delete;

	// operator
	Vector& 	operator=(const Vector& rhs);
	Vector& 	operator=(Vector&& rhs) noexcept;
	T& 			operator[](int position);

	// inner class
	class Iterator
	{
	public:
		friend class Vector;

		// constructor
		Iterator() : mVector(nullptr), mCursor(nullptr), mIndex(0) {}
		Iterator(Vector* vector, T* value, const size_t index) : mVector(vector), mCursor(value), mIndex(index) {}
		~Iterator() = default;
		Iterator(const Iterator& rhs) = default;
		Iterator(Iterator&& rhs) noexcept = default;

		// operator
		Iterator& 	operator=(const Iterator& rhs) = default;
		Iterator& 	operator=(Iterator&& rhs) = default;
		bool 		operator==(const Iterator rhs)
		{
			return mVector == rhs.mVector && mCursor == rhs.mCursor;
		}
		bool 		operator!=(const Iterator rhs)
		{
			return !(*this == rhs);
		}
		Iterator& 	operator++()
		{
			if (mVector)
			{
				if (mVector->mSize <= mIndex + 1)
				{
					*this = mVector->End();
					return *this;
				}

				++mCursor;
				++mIndex;
			}

			return *this;
		}
		Iterator& 	operator--()
		{
			if (mVector)
			{
				if (mIndex == 0) return *this;
				if (!mCursor)
				{
					mCursor = &mVector->mArray[mVector->mSize - 1];
					mIndex = mVector->mSize - 1;
					return *this;
				}
				--mCursor;
				--mIndex;
			}

			return *this;
		}
		Iterator 	operator++(int)
		{
			Iterator copy(*this);
			++(*this);

			return copy;
		}
		Iterator 	operator--(int)
		{
			Iterator copy(*this);
			--(*this);

			return copy;
		}
		T& 			operator*()
		{
			return *mCursor;
		}
		Iterator& 	operator+(const int index)
		{
			if(mVector)
			{
				if (mVector->mSize <= mIndex + index)
				{
					mCursor = nullptr;
					mIndex = mVector->mSize;
					return *this;
				}

				for(int i = 0; i < index; i++)
				{
					++mCursor;
				}
				mIndex += index;
				return *this;
			}

			return *this;
		}
		Iterator&	operator-(const int index)
		{
			if (mVector)
			{
				if(mIndex <= index)
				{
					*this = mVector->Begin();
					return *this;
				}

				for(int i = 0; i < index; i++)
				{
					--mCursor;
				}
				mIndex -= index;
				return *this;
			}

			return *this;
		}

	private:
		Vector* 	mVector;
		T* 			mCursor;
		size_t		mIndex;
	};

	// method
	T& 			Back();
	Iterator& 	Begin();
	size_t 		Capacity() const;
	void 		Clear();
	bool 		Empty() const;
	Iterator& 	End();
	Iterator 	Erase(Iterator cursor);
	T& 			Front();
	Iterator 	Insert(Iterator cursor, const T& value);
	void 		PopBack();
	void 		PushBack(const T& value);
	size_t 		Size() const;
	void 		Swap(Vector& rhs);

private:
	T* 			mArray;
	size_t 		mSize;
	size_t		mCapacity;
};

template <typename T>
Vector<T>::Vector() : mArray(nullptr), mSize(0), mCapacity(0) {}

template <typename T>
Vector<T>::~Vector()
{
	if (mArray) delete[] mArray;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (this != &rhs)
	{
		delete[] mArray;
		mArray = new T[rhs.mCapacity];
		memcpy_s(mArray, rhs.mArray, sizeof(T) * rhs.mSize);
		mSize = rhs.mSize;
		mCapacity = rhs.mCapacity;
	}

	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& rhs) noexcept
{
	mArray = new T[rhs.mCapacity];
	memcpy_s(mArray, rhs.mArray, sizeof(T) * rhs.mSize);
	mSize = rhs.mSize;
	mCapacity = rhs.mCapacity;
	delete[] rhs.mArray;
	rhs.mArray = nullptr;
	rhs.mSize = 0;
	rhs.mCapacity = 0;

	return *this;
}

template <typename T>
T& Vector<T>::operator[](const int position)
{
	Iterator iter = Begin();
	iter = iter + position;
	return *iter;
}

template <typename T>
T& Vector<T>::Back()
{
	return mArray[mSize - 1];
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Begin()
{
	Iterator iter;
	if(mSize)
	{
		iter.mVector = this;
		iter.mCursor = &mArray[0];
	}
	else
	{
		iter.mVector = nullptr;
		iter.mCursor = nullptr;
	}
	return iter;
}

template <typename T>
size_t Vector<T>::Capacity() const
{
	return mCapacity;
}

template <typename T>
void Vector<T>::Clear()
{
	delete[] mArray;
	mSize = 0;
	mArray = new T[mCapacity]();
}

template <typename T>
bool Vector<T>::Empty() const
{
	return !mSize;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::End()
{
	Iterator iter(this, nullptr, mSize);
	return iter;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Erase(Iterator cursor)
{
	if (!cursor.mCursor) return cursor;

	T* newArray = new T[mCapacity]();
	for(size_t i = 0; i < cursor.mIndex; ++i)
	{
		newArray[i] = mArray[i];
	}

	for(size_t i = cursor.mIndex; i < mSize - 1; ++i)
	{
		newArray[i] = mArray[i + 1];
	}
	delete[] mArray;
	mArray = newArray;
	--mSize;

	return cursor;
}

template <typename T>
T& Vector<T>::Front()
{
	return *Begin();
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Insert(Iterator cursor, const T& value)
{
	if (cursor == End())
	{
		PushBack(value);
		return cursor;
	}

	mCapacity = (mSize == mCapacity) ? mCapacity + mCapacity / 2 : mCapacity;

	T* newArray = new T[mCapacity]();

	for(size_t i = 0; i < cursor.mIndex; ++i)
	{
		newArray[i] = mArray[i];
	}

	newArray[cursor.mIndex] = value;

	for(size_t i = cursor.mIndex; i < mSize; ++i)
	{
		newArray[i + 1] = mArray[i];
	}

	++mSize;
	T* temp = mArray;
	delete[] mArray;
	mArray = newArray;
	return cursor;
}

template <typename T>
void Vector<T>::PopBack()
{
	if (!mSize) return;
	--mSize;
}

template <typename T>
void Vector<T>::PushBack(const T& value)
{
	if(mSize == mCapacity)
	{
		mCapacity = mCapacity / 2 ? mCapacity + mCapacity / 2 : mCapacity + 1;
		T* newArray = new T[mCapacity]();
		memcpy(newArray, mArray, sizeof(T) * mSize);
		T* deleteTemp = mArray;
		delete[] mArray;
		mArray = newArray;
	}
	mArray[mSize] = value;
	++mSize;
}

template <typename T>
size_t Vector<T>::Size() const
{
	return mSize;
}

template <typename T>
void Vector<T>::Swap(Vector& rhs)
{
	T* tempArray = mArray;
	size_t tempSize = mSize;
	size_t tempCapacity = mCapacity;
	mArray = rhs.mArray;
	mSize = rhs.mSize;
	mCapacity = rhs.mCapacity;
	rhs.mArray = tempArray;
	rhs.mSize = tempSize;
	rhs.mCapacity = tempCapacity;
}