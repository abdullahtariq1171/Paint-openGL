#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "Shape.h"
class Text
{
protected:
	std::string Text_String;
public:
	Text::Text();
	Text::Text(const std::string & _sample);
	virtual void Text::Draw();

	~Text();
};

#endif