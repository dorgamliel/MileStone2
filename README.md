Search Algorithms - Implementation, comparison and assimilation
=======

Second milestone
-----------
_Contributors_: Alonsho, dorgamliel.  
[link](https://github.com/Alonsho/MileStone1) to our GitHub repository.

**Milestone description:** In this milestone, the main focus is solving a search problem with search algorithims.
The issue is mainly choosing the best search algorithm to solve a certain problem, and eventyally giving a statistic evaluation of each algorithm, so that the comparison between their profitability will be clearer.

**Compilation instructions:**
The program receives multiple of client simultaniously, which means it handles multiple problems at the same time.
compile using 'make compile' and run using 'make run', and then send the server the appropriate problem. In this case, the problem is a matrix with cost on each vertex. This cost resembles the cost of passing through the vertex.
The input should be line by line, and includes all rows of the matrix, and after it; starting index, goal index, and eventually "end", which signifies the end of input.
The output will be the best path from Starting point to goal point, which includes the exact path, step by step, and its cumulative cost (in each step).

In addition, there is a PDF attached, with an analasys of all of the following algorithms: DFS, BFS, Best First Search and A*.

_note_: SafeQueue and ThreadPool classes were taken from the web.

**An important remark:** As written above, this project is in the making.  For now, only the first and second parts of the whole project are complete. All of the description above relates to the current milestone.
