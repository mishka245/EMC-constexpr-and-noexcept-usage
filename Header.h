#pragma once
#include<string>
using namespace std;
#define Pi 3.141592653589793



//გრადუსების რადიანებში გადაყვანა
constexpr
double degreeToRadian(double deg) noexcept
{
	return (deg*Pi) / 180.0;
}

//დაბალი რეგისტრის სიმბოლოების მთვლელი
constexpr int countlower(const string & s, int n = 0, int c = 0) noexcept
{
	return n == s.size() ? c :
		'a' <= s[n] && s[n] <= 'z' ? countlower(s, n + 1, c + 1) :
		countlower(s, n + 1, c);
}

//მაღალი რეგისტრის სიმბოლოების მთვლელი
constexpr int countupper(const string & s, int n = 0, int c = 0) noexcept
{
	return n == s.size() ? c :
		'A' <= s[n] && s[n] <= 'Z' ? countupper(s, n + 1, c + 1) :
		countupper(s, n + 1, c);
}

//კომპლექცური რიცხვის წარმოდგენა
struct complex
{
	//a constant expression constructor
	constexpr complex(double r, double i) : re(r), im(i) { }  //empty body
	//constant expression functions
	constexpr double real() { return re; }
	constexpr double imag() { return im; }
private:
	double re;
	double im;
};

//ხარისხის დათვლის ფუნქცია არამთელებისთვის
constexpr float exp(double x, int n) noexcept
{
	return n == 0 ? 1 : n % 2 == 0 ? exp(x * x, n / 2) : exp(x * x, (n - 1) / 2) * x;
};

//ხარისხის დათვლის ფუნქცია მთელებისთვის
constexpr float exp(int x, int n) noexcept
{
	return n == 0 ? 1 : n % 2 == 0 ? exp(x * x, n / 2) : exp(x * x, (n - 1) / 2) * x;
};

//მასივის სიგრძის დადგენა
template<typename T, int N>
constexpr int length(const T(&arr)[N]) noexcept
{
	return N;
}

