#include <iostream>

using namespace std;

template<typename T>

class Vector3
{
public:
	T x , y, z;

	Vector3() {
		x = 0;
		y = 0;
		z = 0;
	};

	Vector3(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};

	Vector3(Vector3 * vector) {
		this->x = vector->x;
		this->y = vector->y;
		this->z = vector->z;
	};

	Vector3<T> operator+(const Vector3<T> &v) {
		Vector3 vec;
		vec.x = this->x + v.x;
		vec.y = this->y + v.y;
		vec.z = this->z + v.z;
		return vec;
	}

	Vector3<T> operator-(const Vector3<T> &v) {
		Vector3 vec;
		vec.x = this->x - v.x;
		vec.y = this->y - v.y;
		vec.z = this->z - v.z;
		return vec;
	}

	Vector3<T> operator+=(const Vector3<T> &v) {
		this->x = this->x + v.x;
		this->y = this->y + v.y;
		this->z = this->z + v.z;
		return *this;
	}

	Vector3<T> operator-=(const Vector3<T> &v) {
		this->x = this->x - v.x;
		this->y = this->y - v.y;
		this->z = this->z - v.z;
		return *this;
	}

	Vector3<T> operator=(const Vector3<T> &v) {
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		return *this;
	}

	const bool operator==(const Vector3<T> &v) {
		return (this->x == v.x) && (this->y == v.y) && (this->z == v.z);
	}

	void normalize() {
		const T length = sqrt((x * x) + (y * y) + (z * z));
		this->x = this->x / length;
		this->y = this->y / length;
		this->z = this->z / length;
	}

	void zero() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	const bool is_zero() {
		return (this->x == 0) && (this->y == 0) && (this->z == 0);
	}

	const T distance_to(const Vector3<T> &vec) {
		const T distance = sqrt(pow((this->x - vec.x), 2) + pow((this->y - vec.y), 2) + pow((this->z - vec.z), 2));
		return distance;
	}
};

int main() {

	Vector3<float> *vec1 = new Vector3<float>();
	cout << "Vector 1:" << std::endl;
	cout << vec1->x << std::endl;
	cout << vec1->y << std::endl;
	cout << vec1->z << std::endl;


	Vector3<float> *vec2 = new Vector3<float>(1,1,1);
	cout << "Vector 2:" << std::endl;
	cout << vec2->x << std::endl;
	cout << vec2->y << std::endl;
	cout << vec2->z << std::endl;


	Vector3<float> *aux = new Vector3<float>(2, 2, 2);
	Vector3<float> *vec3 = new Vector3<float>(aux);
	cout << "Vector 3:" << std::endl;
	cout << vec3->x << std::endl;
	cout << vec3->y << std::endl;
	cout << vec3->z << std::endl;

	*vec1 = *vec1 + *vec2;

	cout << "Vector 1 + Vector 2:" << std::endl;
	cout << vec1->x << std::endl;
	cout << vec1->y << std::endl;
	cout << vec1->z << std::endl;

	*vec1 = *vec1 - *vec2;

	cout << "Vector 1 - Vector 2:" << std::endl;
	cout << vec1->x << std::endl;
	cout << vec1->y << std::endl;
	cout << vec1->z << std::endl;
	
	*vec1 += *vec2;

	cout << "Vector 1 += Vector 2:" << std::endl;
	cout << vec1->x << std::endl;
	cout << vec1->y << std::endl;
	cout << vec1->z << std::endl;

	*vec1 -= *vec2;

	cout << "Vector 1 -= Vector 2:" << std::endl;
	cout << vec1->x << std::endl;
	cout << vec1->y << std::endl;
	cout << vec1->z << std::endl;

	*vec1 = *vec3;

	cout << "Vector 1 = Vector 3:" << std::endl;
	cout << vec1->x << std::endl;
	cout << vec1->y << std::endl;
	cout << vec1->z << std::endl;

	cout << "Vector 1 == Vector 2?" << std::endl;
	cout << (*vec1==*vec2) << std::endl;

	cout << "Vector 1 == Vector 3?" << std::endl;
	cout << (*vec1 == *vec3) << std::endl;

	vec1->normalize();

	cout << "Vector 1 Normalize:" << std::endl;
	cout << vec1->x << std::endl;
	cout << vec1->y << std::endl;
	cout << vec1->z << std::endl;

	vec1->zero();

	cout << "Vector 1 Zero:" << std::endl;
	cout << vec1->x << std::endl;
	cout << vec1->y << std::endl;
	cout << vec1->z << std::endl;
	
	cout << "Vector 1 is Zero?" << std::endl;
	cout << vec1->is_zero() << std::endl;

	cout << "Vector 1 Distance to Vector 2:" << std::endl;
	cout << vec1->distance_to(vec2) << std::endl;

	system("pause");

}