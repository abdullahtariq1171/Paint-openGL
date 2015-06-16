#include "Color_RGB.h"

Color_RGB::Color_RGB() :R(0), G(0), B(0){}
Color_RGB::Color_RGB(const double & r,const  double & g,const double & b):R(r), G(g), B(b){}
void Color_RGB::SetColor(const Color_RGB & _S)
{
	this->R = _S.GetR_value();
	this->G = _S.GetG_value();
	this->B = _S.GetB_value();
}
double Color_RGB::GetR_value()const {return this->R;}
double Color_RGB::GetG_value()const {return this->G;}
double Color_RGB::GetB_value()const {return this->B;}
Color_RGB Color_RGB::GetColor()const{return (*this);}
void Color_RGB::SetColor(const double & _r,const double & _g,const double & _b) 
{
	R = _r;
	G = _g;
	B = _b;
}
Color_RGB::~Color_RGB(){}
