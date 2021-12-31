//
// Created by tommi on 08/12/2021.
//

#ifndef SPREADSHEETES2_VALUES_H
#define SPREADSHEETES2_VALUES_H


#include "Subject.h"
#include "Cell.h"
#include <vector>
#include <list>


class Values : public Subject {
public:

    Values() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 11; j++) {
                if (i == 0)
                    values.push_back(Cell("a", j, 0));
                else if (i == 1)
                    values.push_back(Cell("b", j, 0));
                else if (i == 2)
                    values.push_back(Cell("c", j, 0));
                else
                    values.push_back(Cell("d", j, 0));
            }
        }
    };

    virtual ~Values() {};

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    virtual void notify() override;

    const std::list<Cell> getValues() const;

    //void addValue(std::string x, int y, int value);

    //void removeValue(std::string x, int y);

    void printValues();

    Observer *getObserver() const;

private:
    std::list<Cell> values;
    Observer *observer;


};


#endif //SPREADSHEETES2_VALUES_H
