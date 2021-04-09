#pragma once

class Base
{
public:
	void memfcn(Base& b) { b = *this; }
};

class Pub_Derv :public Base
{
public:
	void memfcn(Base& b) { b = *this; }
};

class Pro_Derv :protected Base
{
public:
	void memfcn(Base& b) { b = *this; }
};

class Pri_Derv :private Base
{
public:
	void memfcn(Base& b) { b = *this; }
};

class Derived_from_Public :public Pub_Derv
{
public:
	void memfcn(Base& b) { b = *this; }
};

class Derived_from_protected :protected Pro_Derv
{
public:
	void memfcn(Base& b) { b = *this; }
};

class Derived_from_private :private Pri_Derv
{
public:
	// error
	// void memfcn(Base& b) { b = *this; }
};

