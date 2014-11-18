#include "States.h"

namespace Model {

    States::States() {
        initialization = new Controller::State::Initialization;
        shutdown = new Controller::State::Shutdown;

        gameplay = nullptr;
        gameplayEnd = nullptr;
    }

    States::~States() {
        delete initialization;
        delete shutdown;
        
        delete gameplay;
        delete gameplayEnd;
    }

    States& States::get() {
        static States instance;
        return instance;
    }

    void States::initialize() {
        if(gameplay == nullptr) 
            gameplay = new Controller::State::Gameplay;

        if(gameplayEnd == nullptr)
            gameplayEnd = new Controller::State::GameplayEnd;
    }

}