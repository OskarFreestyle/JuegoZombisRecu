#pragma once
#include "Button.h"

// Indica al GameManager que se acaba la partida al dar al exit
class ExitOnPlay : public Button
{
public:
    ExitOnPlay() {};
    ~ExitOnPlay();

    bool init(const std::map<std::string, std::string>& mapa);

protected:
    virtual void onClick();
};

