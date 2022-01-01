//
// Created by tommi on 08/12/2021.
//

#ifndef SPREADSHEETES2_VALUES_H
#define SPREADSHEETES2_VALUES_H


#include "Subject.h"
#include "Cell.h"
#include "Observer.h"
#include <vector>
#include <list>


class Values : public Subject {
public:

    Values() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 11; j++) {
                if (i == 0)
                    values.emplace_back("a", j, 0);
                else if (i == 1)
                    values.emplace_back("b", j, 0);
                else if (i == 2)
                    values.emplace_back("c", j, 0);
                else
                    values.emplace_back("d", j, 0);
            }
        }
    };

    virtual ~Values() {};

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    virtual void notify() override;

    const std::vector<Cell> getValues() const;

    void addValue(std::string x, int y, int val);

    void removeValue(std::string x, int y);

    void replaceValue(std::string x, int y, int val);

    void printValues();

    std::list<Observer *> getObserver() const;

private:
    std::vector<Cell> values;
    std::list<Observer *> observers;


};


#endif //SPREADSHEETES2_VALUES_H
