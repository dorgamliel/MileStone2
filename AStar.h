//
// Created by dorgamliel on 21/01/2020.
//

#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H
#include <map>
#include <queue>
#include "Searcher.h"

template <typename T>
struct CompareTotalCost {
    bool operator()(State<T>* const& state1, State<T>* const& state2)
    {
        return (state1->getCost() + state1->getHeuristicCost()) > (state2->getCost() + state2->getHeuristicCost());
    }
};
template <typename T>
class AStar : public Searcher<T> {
public:
    vector<State<T>*> search(Searchable<T>* searchable) {
        vector<State<T>*> vecForPQ;
        map<T, double> visited;
        priority_queue <State<T>*, vector<State<T>*>, CompareTotalCost<T>> openPq;
        vector<State<T>*> closed;
        //first state
        State<T>* state = searchable->getInitialState();
        //update state's heuristic cost.
        state->setHeuristicCost(searchable->getDistancefromEnd(state->getState()));
        openPq.push(state);
        while(!openPq.empty()){
            //each state is the minimum available  (by total cost).
            state = openPq.top();
            openPq.pop();
            closed.push_back(state);
            vector<State<T>*> neighbours = searchable->getNeighbours(state);
            //iterate current state's neighbours and push to priority queue if not visited already.
            for(State<T>* s : neighbours){
                s->setCameFrom(state);
                if (searchable->isGoalState(s)) {
                    return Searcher<T>::createPath(s);
                }
                //if successor is in closed, ignore it.
                if (find(closed.begin(),closed.end(), s) != closed.end()) {
                    continue;
                }
                //if successor is not in open
                if(!isInPQ(openPq, s) && find(closed.begin(), closed.end(), s) == closed.end()) {
                    //update state's cost.
                    s->setCost(state->getCost() + searchable->getCost(state, s));
                    //update state's heuristic cost.
                    s->setHeuristicCost(searchable->getDistancefromEnd(s->getState()));
                    openPq.push(s);
                    //if successor is in open already
                } else {
                    State<T>* oldS = getFromPQ(openPq, s);
                    //if total cost of same state (different paths to it) is different, act accordingly.
                    if (oldS->getHeuristicCost() + oldS->getCost() > s->getHeuristicCost() + s->getCost()) {
                        //empty queue until reaching relevant state.
                        while(openPq.top()->getState() != s->getState()) {
                            auto top = openPq.top();
                            vecForPQ.push_back(openPq.top());
                            openPq.pop();
                        }
                        vecForPQ.push_back(openPq.top());
                        openPq.pop();
                        //put back all stated into pq.
                        while(!vecForPQ.empty()){
                            openPq.push(vecForPQ.back());
                            vecForPQ.pop_back();
                        }
                    }
                }
            }
            closed.push_back(state);
        }

    }

    bool isInPQ(priority_queue <State<T>*, vector<State<T>*>, CompareTotalCost<T>> pq, State<T>* s){
        while (!pq.empty()){
            if (pq.top()->getState() == s->getState()){
                return true;
            }
            pq.pop();
        }
        return false;
    }
    State<T>* getFromPQ(priority_queue <State<T>*, vector<State<T>*>, CompareTotalCost<T>> pq, State<T>* newS) {
        while (!pq.empty()) {
            State<T>* state = pq.top();
            if (state->getState() == newS->getState()) {
                return state;
            }
            pq.pop();
        }
        return nullptr;
    }
};


#endif //MILESTONE2_ASTAR_H
