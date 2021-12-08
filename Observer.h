//
// Created by tommi on 08/12/2021.
//

#ifndef SPREADSHEETES2_OBSERVER_H
#define SPREADSHEETES2_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {}

    virtual void update() = 0;
};

#endif //SPREADSHEETES2_OBSERVER_H

