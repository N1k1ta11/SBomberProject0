#include "FieldMemento.h"

FieldMemento::~FieldMemento()
{
    for (size_t i = 0; i < state->vecDynamicObj.size(); i++)
    {
        if (state->vecDynamicObj[i] != nullptr)
        {
            delete state->vecDynamicObj[i];
        }
    }

    for (size_t i = 0; i < state->vecStaticObj.size(); i++)
    {
        if (state->vecStaticObj[i] != nullptr)
        {
            delete state->vecStaticObj[i];
        }
    }
}

TState::~TState()
{
    for (size_t i = 0; i < this->vecDynamicObj.size(); i++)
    {
        if (this->vecDynamicObj[i] != nullptr)
        {
            delete this->vecDynamicObj[i];
        }
    }

    for (size_t i = 0; i < this->vecStaticObj.size(); i++)
    {
        if (this->vecStaticObj[i] != nullptr)
        {
            delete this->vecStaticObj[i];
        }
    }
}
