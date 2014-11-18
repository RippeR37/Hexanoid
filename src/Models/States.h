#ifndef MODEL_STATES_H_INCLUDED
#define MODEL_STATES_H_INCLUDED

#include "../Controllers/State.h"

namespace Model {

    class States {
        public:
            static States& get();

            void initialize();

            Controller::State::Initialization* initialization;
            Controller::State::Gameplay* gameplay;
            Controller::State::Shutdown* shutdown;

            Controller::State::GameplayEnd* gameplayEnd;

        private:
            States();
            ~States();

    };

}

#endif