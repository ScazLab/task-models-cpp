# Task models for human-robot collaboration

C++ port of the [task-models](https://github.com/ScazLab/task-models) Python library. It provides tools to manipulate and use task models for human robot collaboration.

If you are using this software and or one of its components, we warmly recommend you to cite the following paper:

  > [Roncone2017] Roncone Alessandro, Mangin Olivier, Scassellati Brian **Transparent Role Assignment and Task Allocation in Human Robot Collaboration** *IEEE International Conference on Robotics and Automation (ICRA 2017)*, Singapore. [[PDF]](http://alecive.github.io/papers/[Roncone%20et%20al.%202017]%20Transparent%20Role%20Assignment%20and%20Task%20Allocation%20in%20Human%20Robot%20Collaboration.pdf) [[BIB]](http://alecive.github.io/papers/[Roncone%20et%20al.%202017]%20Transparent%20Role%20Assignment%20and%20Task%20Allocation%20in%20Human%20Robot%20Collaboration.bib)

## Prerequisites

This package requires a binary from Anthony Cassandra's POMDP solver. Please visit [pomdp.org](http://www.pomdp.org) for any matter related to the POMDP solver.

Here are some instructions on how to compile and install the solver properly (assuming that :code:`~/src` is the directory in which you usually place your code):

```
   cd ~/src
   wget www.pomdp.org/code/pomdp-solve-5.4.tar.gz
   tar -xvzf pomdp-solve-5.4.tar.gz
   cd pomdp-solve-5.4/
   mkdir build
   cd build/
   ../configure --prefix=$HOME/.local
   make
   make install
```

Now you should have `pomdp-solve` installed in your local path, and it should be available for the python package to be used.
