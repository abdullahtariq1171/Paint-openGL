#ifndef POINT_H
#define POINT_H
class Point
{
	double x,y;
public:
	//CONSTRUCTORS
	Point::Point(void);
	Point::Point(const double _x,const double _y);
	Point::Point(const Point &);
	void Point::Draw();
	//GETTERS

	double Point::GetX(void) const;
	double Point::GetY(void)const ;
	Point Point::GetPoint(void)const;

	//SETTERS
	void Point::SetX(const double &) ;
	void Point::SetY(const double &);
	

	double Point::CalculateDistance(const Point &)const ;

	void Point::SetPoint(const Point &);
	void Point::SetPoint(const double & _x , const double &_y);

	Point Point::operator=(const Point &);


	//DESTRUCTOR
	~Point(void);
};

#endif