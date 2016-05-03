#pragma once
#ifndef __NILYANG_TEXTBOX__
#include<string>
class TextBox
{
    std::string text;
public:
    TextBox(const std::string &txt) :text(txt){}
    const std::string& GetValue() const
    {
        return text;
    }

    int GetNumber() const
    {
        return std::stoi(text);
    }

    void SetText(const std::string & txt)
    {
        text = txt;
    }
};




#endif // !__NILYANG_TEXTBOX__