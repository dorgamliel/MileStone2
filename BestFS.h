//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_BESTFS_H
#define MILESTONE2_BESTFS_H

#include <map>
#include "Searcher.h"
#include <queue>
#include <algorithm>
template<typename T>
struct CompareCost {
    bool operator()(State<T>* const& state1, State<T>* const& state2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return state1->getCost()>state2->getCost();
    }
};
template<typename T>

class BestFS : public Searcher<T> {
    vector<State<T> *> search(Searchable<T> *searchable) {
        vector<State<T>*> vecForPQ;
        map<T, double> visited;
        State<T> *currentState = searchable->getInitialState();
        //priority_queue<State<T>*> pq;
        //priority_queue <State<T>*, vector<State<T>*>, greater<State<T>*> > pq;
        priority_queue <State<T>*, vector<State<T>*>, CompareCost<T>> pq;
        vector<State<T> *> closed;
        pq.push(currentState);
        while (!pq.empty()) {
            //current state is the state we pop from priority queue.
            currentState = pq.top();
            pq.pop();
            closed.push_back(currentState);
            if (searchable->isGoalState(currentState)) {
                return createPath(currentState);
            }
            vector<State<T>*> neighbours = searchable->getNeighbours(currentState);
            //iterate current state's neighbours and push to priority queue if not visited already.
            for(auto s : neighbours){
                T vertex = s->getState();
                //if neighbour wasn't iterated (visited\operated on) before,
                // mark it as "visited" and push to priority queue.
                if (visited.find(vertex) == visited.end() && find(closed.begin(), closed.end(), s) == closed.end()){
                    s->setCost(currentState->getCost() + searchable->getCost(currentState, s));
                    visited[s->getState()] = s->getCost();
                    s->setCameFrom(currentState);
                    pq.push(s);
                } else {
                    int x = visited[s->getState()];
                    int y = currentState->getCost() + searchable->getCost(currentState, s);
                    //if current neighbour cost is bigger than currently checked cost, update new cost.
                    if (visited[s->getState()] > currentState->getCost() + searchable->getCost(currentState, s)){
                        //if neighbour is not in priority queue, add it to it.
                        if (!isInPQ(pq, s)){
                            visited[s->getState()] = s->getCost();
                            s->setCameFrom(currentState);
                            pq.push(s);
                        } else { // adjust priority in queue.
                            while(pq.top()->getState() != s->getState()) {
                                auto top = pq.top();
                                vecForPQ.push_back(pq.top());
                                pq.pop();
                            }
                            vecForPQ.push_back(pq.top());
                            pq.pop();
                            while(!vecForPQ.empty()){
                                pq.push(vecForPQ.back());
                                vecForPQ.pop_back();
                            }
                        }
                    }
                }
            }
        }
    }

    bool isInPQ(priority_queue <State<T>*, vector<State<T>*>, CompareCost<T>> pq, State<T>* s){
        while (!pq.empty()){
            if (pq.top()->getState() == s->getState()){
                return true;
            }
            pq.pop();
        }
    }
};


#endif //MILESTONE2_BESTFS_H