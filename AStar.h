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
        map<T, double> cVisited;
        map<T, double> hVisited;
        State<T>* state = searchable->getInitialState();
        state->setCost(searchable->getCost(NULL, state));
        priority_queue <State<T>*, vector<State<T>*>, CompareTotalCost<T>> pq;
        vector<State<T>*> closed;
        //update state's heuristic cost.
        state->setHeuristicCost(searchable->getDistancefromEnd(state->getState()));
        pq.push(state);
        while(!pq.empty()){
            //each state is the minimum available  (by total cost).
            state = pq.top();
            pq.pop();
            closed.push_back(state);
            if (searchable->isGoalState(state)) {
                return Searcher<T>::createPath(state);
            }
            vector<State<T>*> neighbours = searchable->getNeighbours(state);
            //iterate current state's neighbours and push to priority queue if not visited already.
            for(State<T>* s : neighbours){
                T vertex = s->getState();
                /*//if successor is in closed, ignore it.
                if (find(closed.begin(),closed.end(), s) != closed.end()) {
                    continue;
                }*/
                //if neighbour wasn't iterated (visited\operated on) before,
                // mark it as "visited" and push to priority queue.
                if(cVisited.find(vertex) == cVisited.end() && find(closed.begin(), closed.end(), s) == closed.end()) {
                    //update state's cost.
                    s->setCost(state->getCost() + searchable->getCost(state, s));
                    cVisited[s->getState()] = s->getCost();
                    s->setCameFrom(state);
                    //update state's heuristic cost.
                    s->setHeuristicCost(searchable->getDistancefromEnd(s->getState()));
                    hVisited[s->getState()] = s->getHeuristicCost();
                    pq.push(s);
                    //if successor is in open already
                } else {
                    //if current neighbour total is bigger than currently checked total cost, update new cost.
                    if (cVisited[s->getState()] > state->getCost() + searchable->getCost(state, s)){
                        //if neighbour is not in priority queue, add it to it.
                        if (!isInPQ(pq, s)){
                            s->setCost(state->getCost() + searchable->getCost(state, s));
                            cVisited[s->getState()] = s->getCost();
                            s->setCameFrom(state);
                            s->setHeuristicCost(searchable->getDistancefromEnd(s->getState()));
                            hVisited[s->getState()] = s->getHeuristicCost();
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
    Searcher<T>* clone() {
        return new AStar<T>();
    }
};


#endif //MILESTONE2_ASTAR_H
