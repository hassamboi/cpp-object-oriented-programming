#include<iostream>
using namespace std;

class parent
{
private:
	float real1;
	float ima1;
public:
	parent() :real1(0.0), ima1(0.0) {}
	~parent() {}

	void set_complex(float r, float i)
	{
		real1 = r;
		ima1 = i;
	}

	float get_real()
	{
		return real1;
	}

	float get_imaginary()
	{
		return ima1;
	}
};

class child : public parent
{
private:
	float real2;
	float ima2;
	float r, i;
public:
	child() : real2(0.0), ima2(0.0) {}
	child(float x, float y) :real2(x), ima2(y) {}
	~child() {}

	void add_complex()
	{
		cout << "Before Addition: (" << get_real() << '+' << get_imaginary() << "i) + (" << real2 << '+' << ima2 << "i)";
		r = real2 + get_real();
		i = ima2 + get_imaginary();
		cout << "\nAfter addition: " << r << '+' << i << 'i' << endl;
	}

	friend class third;
};

class third
{
private:
	float real_diff;
	float ima_diff;

public:
	void difference(child& c)
	{
		real_diff = c.real2 - c.get_real();
		ima_diff = c.ima2 - c.get_imaginary();
		cout << "Real part diff: " << real_diff << endl;
		cout << "Imaginary part diff: " << ima_diff << endl;
	}
};

int main()
{
	child c(2.5, 3.1);
	c.set_complex(1.5, 0.1);
	c.add_complex();

	third t;
	t.difference(c);


	system("pause");
	return 0;
}