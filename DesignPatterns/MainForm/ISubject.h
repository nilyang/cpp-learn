#pragma once
#ifndef __NILYANG_ISUBJECT__

#include"IObserver.h"

#include<list>

class ISubject
{
public :
    virtual ~ISubject();

    virtual void Aattach(IObserver*);
    virtual void Detach(IObserver*);
    virtual void Notify();
protected:
    ISubject();
private:
    std::list<IObserver*> m_Container;

};


inline ISubject::ISubject()
{
}

inline
void ISubject::Aattach(IObserver* observer)
{
    m_Container.push_back(observer);
}

inline
void ISubject::Detach(IObserver* observer)
{
    //²éÕÒÔªËØ
    std::remove(m_Container.begin(), m_Container.end(), observer);
}

inline
void ISubject::Notify()
{
    std::for_each(m_Container.begin(), m_Container.end(), [](IObserver * observer) {
        observer->Update();
    });
}


#endif // !__NILYANG_ISUBJECT__