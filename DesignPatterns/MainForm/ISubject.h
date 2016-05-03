#pragma once
#ifndef __NILYANG_ISUBJECT__

#include"IObserver.h"

#include<list>
#include<memory>

class ISubject
{
public :
    virtual ~ISubject();

    virtual void Aattach(IObserver*);
    virtual void Detach(IObserver*);
    virtual void Notify();
protected:
    ISubject() 
    : m_Observers(new std::list<IObserver*>())
    {}
private:
    std::list<IObserver*> *m_Observers;
};

inline ISubject::~ISubject()
{
    //remove all
    std::for_each(m_Observers->begin(), m_Observers->end(),std::default_delete<IObserver>());
    delete m_Observers;
}


inline
void ISubject::Aattach(IObserver* observer)
{
    m_Observers->push_back(observer);
}

inline
void ISubject::Detach(IObserver* observer)
{
    //²éÕÒÔªËØ
    std::remove(m_Observers->begin(), m_Observers->end(), observer);
}

inline
void ISubject::Notify()
{
    std::for_each(m_Observers->begin(), m_Observers->end(), [](IObserver * observer) {
        observer->Update();
    });
}


#endif // !__NILYANG_ISUBJECT__