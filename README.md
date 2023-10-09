# Data Structures and Algorithm with Design and Analysis

![Hacktoberfest](https://img.shields.io/badge/Hacktoberfest-2023-brightgreen)

Welcome to the Hacktoberfest 2023 Data Structures and Algorithms project! This repository is open for contributions as part of the Hacktoberfest celebration. If you're passionate about algorithms, data structures, and programming in C++ or Python, this is the right place for you.

## Getting Started

1. Fork this repository.
2. Clone your forked repository to your local machine:
   ```bash
   https://github.com/Einsteinia11/Data-Structures-and-Algorithm-with-Design-and-Analysis
   <p style = "font-size = 15px;">In this repository as you can guess from the title itself it will contain all the Data structure Algorithms and their Design and Analysis. So if you can contribute❤ it would be great!🤩 </p>
   ```

<h3>What is Time Complexity?</h3>
It is just a mathematical way of analysing how long an algorithm with a given number of inputs (n) will take to complete it's task. It's usually defined using Big-O-notation. Now Big-O-Notation is a way of converting the overall steps of an algorithm term, then excluding lower order constants and coefficients that don't have that big impact on the orverall complexity of the problem.Below are some common time complexities with simple definitions. Feel free to check out Wikipedia, though, for more in-depth definitions. <br><br>
<ul>
<li>O(1) — Constant Time: Given an input of size n, it only takes a single step for the algorithm to accomplish the task. It only takes a single step for the algorithm to accomplish the task.</li>
<li>O(log n) — Logarithmic time: given an input of size n, the number of steps it takes to accomplish the task are decreased by some factor with each step. The number of steps it takes to accomplish a task are decreased by some factor with each step.</li>
<li>O(n) — Linear Time: Given an input of size n, the number of of steps required is directly related (1 to 1)</li>
<li>O(n²) — Quadratic Time: Given an input of size n, the number of steps it takes to accomplish a task is square of n.</li>
<li>O(C^n) — Exponential Time: Given an input of size n, the number of steps it takes to accomplish a task is a constant to the n power (pretty large number).</li>
</ul>

<h3>The idea behind big O notation</h3>
<p>Big O notation is the language we use for talking about how long an algorithm takes to run. It's how we compare the efficiency of different approaches to a problem.

It's like math except it's an awesome, not-boring kind of math where you get to wave your hands through the details and just focus on what's basically happening.

With big O notation we express the runtime in terms of—brace yourself—how quickly it grows relative to the input, as the input gets arbitrarily large.

Let's break that down:</p>

<ul>
<li><b> how quickly the runtime grows</b>—It's hard to pin down the exact runtime of an algorithm. It depends on the speed of the processor, what else the computer is running, etc. So instead of talking about the runtime directly, we use big O notation to talk about how quickly the runtime grows.</li>
<li><b>relative to the input</b>—If we were measuring our runtime directly, we could express our speed in seconds. Since we're measuring how quickly our runtime grows, we need to express our speed in terms of...something else. With Big O notation, we use the size of the input, which we call "n". So we can say things like the runtime grows "on the order of the size of the input" O(n) or "on the order of the square of the size of the input" or O(n²)</li>
<li><b>as the input gets arbitrarily large</b>—Our algorithm may have steps that seem expensive when n is small but are eclipsed eventually by other steps as n gets huge. For big O analysis, we care most about the stuff that grows fastest as the input grows, because everything else is quickly eclipsed as n gets very large. (If you know what an asymptote is, you might see why "big O analysis" is sometimes called "asymptotic analysis.")</li>
</ul>

And here are some helpful resources to learn more:

<a href = "https://en.wikipedia.org/wiki/Time_complexity">Wikipedia</a><br>
The <a href = "https://www.bigocheatsheet.com/">Big O Cheat Sheet</a> is a great resource with common algorithmic time complexities and a graphical representation. Check it out!

# Data Structures

Data structures play a fundamental role in computer science and software development. They are essential for organizing, processing, retrieving, and storing data efficiently. This README.md provides an overview of different types of data structures.

## Classification of Data Structures

- [Linear Data Structures](#linear-data-structures)
- [Static Data Structures](#static-data-structures)
- [Dynamic Data Structures](#dynamic-data-structures)
- [Non-linear Data Structures](#non-linear-data-structures)

## Linear Data Structures

Linear data structures are arrangements of data elements in a sequential or linear manner. Each element is linked to its previous and next adjacent elements. Common examples of linear data structures include:

- **Array**: A fixed-size collection of elements.
- **Stack**: A last-in, first-out (LIFO) data structure.
- **Queue**: A first-in, first-out (FIFO) data structure.
- **Linked List**: A collection of nodes where each node points to the next node.

## Static Data Structures

Static data structures have a fixed memory size. They are easy to access, but their size cannot change during runtime. An example of a static data structure is an array.

## Dynamic Data Structures

Dynamic data structures do not have a fixed size. They can be resized or updated during runtime, which can be efficient in terms of memory (space) complexity. Examples of dynamic data structures include queues and stacks.

## Non-linear Data Structures

Non-linear data structures do not organize data elements sequentially or linearly. In these structures, traversing all elements may require multiple runs. Common examples of non-linear data structures include:

- **Trees**: Hierarchical structures with a root node and child nodes.
- **Graphs**: Networks of nodes and edges that connect them.

## Applications of Data Structures in Real Life

Data structures find practical applications in numerous real-life scenarios:

<ul>
<li><b>Databases:</b> Data structures like B-trees are used in databases to store and retrieve data efficiently.</li>
<li><b>GPS Navigation:</b> Graph data structures are employed to find the shortest route between two locations.</li>
<li><b>Social Networks:</b> Graphs are used to represent social connections and recommend friends.</li>
<li><b>E-commerce:</b>Stacks and queues are used to manage shopping carts and process orders.</li>
<li><b>Compiler Design:</b> Data structures like symbol tables are crucial for parsing and compiling code.</li>
<li><b>Image Processing:</b>Arrays and matrices are used to represent and manipulate images.</li>
</ul>

And here are some helpful resources to learn more about Data Structures:
<a href = "https://en.wikipedia.org/wiki/Data_structure">Wikipedia</a><br>
