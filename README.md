# yama1223xxx
主にAOJ、TopCoder,AtCoderの問題をといていこうかなぁと思ってます。

## Runtime Analysis
One of the most important aspects of an algorithm is how fast it is. It is often easy to come up with an algorithm to solve a problem, but if the algorithm is too slow, it’s back to the drawing board. Since the exact speed of an algorithm depends on where the algorithm is run, as well as the exact details of its implementation, computer scientists typically talk about the runtime relative to the size of the input. For example, if the input consists of N integers, an algorithm might have a runtime proportional to N2, represented as O(N2). This means that if you were to run an implementation of the algorithm on your computer with an input of size N, it would take C*N2 seconds, where C is some constant that doesn’t change with the size of the input. 

However, the execution time of many complex algorithms can vary due to factors other than the size of the input. For example, a sorting algorithm may run much faster when given a set of integers that are already sorted than it would when given the same set of integers in a random order. As a result, you often hear people talk about the worst-case runtime, or the average-case runtime. The worst-case runtime is how long it would take for the algorithm to run if it were given the most insidious of all possible inputs. The average-case runtime is the average of how long it would take the algorithm to run if it were given all possible inputs. Of the two, the worst-case is often easier to reason about, and therefore is more frequently used as a benchmark for a given algorithm. The process of determining the worst-case and average-case runtimes for a given algorithm can be tricky, since it is usually impossible to run an algorithm on all possible inputs. There are many good online resources that can help you in estimating these values.

Approximate completion time for algorithms, N = 100

O(Log(N))	10-7 seconds
O(N)	10-6 seconds
O(N*Log(N))	10-5 seconds
O(N2)	10-4 seconds
O(N6)	3 minutes
O(2N)	1014 years.
O(N!)	10142 years.
