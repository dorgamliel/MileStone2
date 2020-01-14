//
// Created by dorgamliel on 11/01/2020.
//

#ifndef TEMPFORSERVER_SOLVER_H
#define TEMPFORSERVER_SOLVER_H
template <typename P, typename S>
class Solver {
protected:
    P problem;
    S solution;
public:
    virtual S solveProblem() = 0;
    virtual void setProblem(P) = 0;
};


#endif //TEMPFORSERVER_SOLVER_H
