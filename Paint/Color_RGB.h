#ifndef Color_RGB_H
#define Color_RGB_H

class Color_RGB
{
protected:
	double R, G, B;
public:
	Color_RGB::Color_RGB();
	Color_RGB::Color_RGB(const double & r,const  double & g,const double & b);

	double Color_RGB::GetR_value()const;
	double Color_RGB::GetG_value()const;
	double Color_RGB::GetB_value()const;

	void Color_RGB::SetColor(const double &,const  double &,const double &);
	void Color_RGB::SetColor(const Color_RGB &);


	Color_RGB Color_RGB::GetColor()const;

	~Color_RGB();
};

#endif