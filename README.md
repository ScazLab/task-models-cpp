# Task models for human-robot collaboration [![Build Status](https://travis-ci.org/ScazLab/task-models-cpp.svg?branch=master)](https://travis-ci.org/ScazLab/task-models-cpp)

C++ port of the [task-models](https://github.com/ScazLab/task-models) Python library. It provides tools to manipulate and use task models for human robot collaboration.

If you are using this software and or one of its components, we warmly recommend you to cite the following paper:

  > [Roncone2017] Roncone Alessandro, Mangin Olivier, Scassellati Brian **Transparent Role Assignment and Task Allocation in Human Robot Collaboration** *IEEE International Conference on Robotics and Automation (ICRA 2017)*, Singapore. [[PDF]](http://alecive.github.io/papers/[Roncone%20et%20al.%202017]%20Transparent%20Role%20Assignment%20and%20Task%20Allocation%20in%20Human%20Robot%20Collaboration.pdf) [[BIB]](http://alecive.github.io/papers/[Roncone%20et%20al.%202017]%20Transparent%20Role%20Assignment%20and%20Task%20Allocation%20in%20Human%20Robot%20Collaboration.bib)

## Dependencies

### Eigen3

`Eigen3` can be installed in `Ubuntu 14.04` through the follwing command:

```
sudo apt-get install libeigen3-dev
```

### C++14

A compiler with C++14 support is required. This is supported by default in both `g++-4.9` and `clang-3.6`. In the following, some instructions on how to install `g++-4.9` on `Ubuntu 14.04`:

```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-4.9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 50
sudo apt-get install g++-4.9
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9 50
```

## Compilation

```
mkdir build
cd build
cmake ../
make -j3
```
