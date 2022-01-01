//
// Created by tommi on 01/01/2022.
//

#ifndef SPREADSHEETES2_OPERATION_H
#define SPREADSHEETES2_OPERATION_H

#include "Values.h"
#include "Cell.h"

class Operation : public Observer {
public:
    Operation(Values *subj) : subject(subj) {
        subject->subscribe(this);
        update();
    }

    void update() override;

    virtual void compute() = 0;

    const std::vector<Cell> &getOpValues() const;

    Values *getSubject() const;

protected:
    std::vector<Cell> opValues;

private:
    Values *subject;
};


#endif //SPREADSHEETES2_OPERATION_H
