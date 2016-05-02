#pragma once
#ifndef __NILYANG_TEXTBOX__
#include<string>
class TextBox
{
    std::string text;
public:
    const std::string& GetText() const
    {
        return text;
    }

    void SetText(const std::string & txt)
    {
        text = txt;
    }
};




#endif // !__NILYANG_TEXTBOX__