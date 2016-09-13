<img src="logo.png" alt="phyx logo" width=150px/> 

**phyx** performs phylogenetics analyses on trees and sequences. See installation instructions for Linux and Mac including any dependencies on the wiki [here](https://github.com/FePhyFoFum/phyx/wiki/Installation) or below. A list of the current programs with examples can be found [here](https://github.com/FePhyFoFum/phyx/wiki/Program-list).

Authors: Joseph W. Brown, Joseph F. Walker, and Stephen A. Smith

License: GPL https://www.gnu.org/licenses/gpl-3.0.html

# Installation instructions (also on the wiki [here](https://github.com/FePhyFoFum/phyx/wiki/Installation)). 
phyx requires a few dependencies. Since installation of these dependencies differs on Linux vs. mac, we've separated the instructions below.

## Linux install

1. Install general dependencies:

        sudo apt-get install git
        sudo apt-get install autotools-dev
        sudo apt-get install autoconf
        sudo apt-get install automake
        sudo apt-get install cmake
        sudo apt-get install libtool
        sudo apt-get install liblapack-dev
        sudo apt-get install libatlas-cpp-0.6-dev
2. Clone the phyx repo (if you haven't already):

        git clone git@github.com:FePhyFoFum/phyx.git
3. Install nlopt dependency (default is C, we need C++; not available from apt-get):

        cd phyx/deps
        tar -xvzf nlopt-2.4.2.tar.gz
        cd nlopt-2.4.2
        ./configure --with-cxx --without-octave --without-matlab
        make
        sudo make install
4. Install armadillo dependency  
**Note**: it is possible to get from apt-get, but need version >= 5.2:

        sudo apt-get install libarmadillo-dev
On debian it was necessary to use backports:

        sudo apt-get -t jessie-backports install libarmadillo-dev
If that is not possible, compile the provided code:

        cd phyx/deps
        tar -xvzf armadillo-7.400.2.tgz
        cd armadillo-7.400.2
        ./configure
        make
        sudo make install
5. Finally, install phyx:

        cd phyx/src
        autoreconf -fi
        ./configure
        make
If you want to install it so it is available anywhere in your system, do:

        sudo make install

## Mac install
Mac has become increasingly difficult to support at the command line with changes every version on location and standards for compilation tools. in particular, Mac now defaults to clang, and clang does not support OpenMP and doesn't link to gfortran (both used by phyx).  For 10.9, we have found that it is good to install gcc from [here] (http://hpc.sourceforge.net/) or [homebrew] (http://brew.sh/). Instructions for both are below.

### Install with Homebrew
The instructions below assume homebrew, which is convenient for dealing with dependencies.

1. Install the homebrew package manager:

        /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
Get access to science packages with:

        brew tap homebrew/science
2. Install gcc (can take a while, but enables use of openmp and fortran):

        brew install --without-multilib gcc
3. Install dependencies from homebrew:

        brew install git
        brew install --use-gcc automake
        brew install --use-gcc autoconf
        brew install --use-gcc libtool
        brew install --use-gcc cmake
        brew install --use-gcc --c++11 nlopt
        brew install --use-gcc --c++11 armadillo
4. On to phyx. first, clone the repository (if you haven't already):

        git clone git@github.com:FePhyFoFum/phyx.git
        cd phyx/src
        autoreconf -fi
        ./configure CXX=/usr/local/bin/g++-6
        make
If you want to install it so it is available anywhere in your system, do:

        sudo make install

### HPC GCC Install
1. Install gcc and gfortran. Download gcc-6.2-bin.tar.gz or more recent from http://hpc.sourceforge.net/. Install with:
        
        sudo tar -xvf gcc-6.2-bin.tar -C /

2. Install autoconf from http://ftp.gnu.org/gnu/autoconf/. Get autoconf-latest.tar.gz, then:

        tar -xzf autoconf-latest.tar.gz
        cd autoconf-2.69
        ./configure --prefix=/usr/local/autoconf-2.69
        make
        sudo make install
        ln -s autoconf-2.69 /usr/local/autoconf

3. Install cmake and install Armadillo. Get cmake from https://cmake.org/download/. I got https://cmake.org/files/v3.6/cmake-3.6.2-Darwin-x86_64.tar.gz. Get armadillo from the `deps` directory or http://arma.sourceforge.net/download.html, get the stable one. Untar it. Double click the Cmake.app. Click "Browse source..." and choose the armadillo folder that was created after untaring. Click "Browse build..." and choose the same folder as browse source. Click "Configure" and then click "Generate". Go to the terminal and browse to that armadillo folder and type:

        make
        sudo make install

4. Install nlopt. Get armadillo from the `deps` directory or go to http://ab-initio.mit.edu/wiki/index.php/NLopt#Download_and_installation and download the latest (probably nlopt-2.4.2.tar.gz). Untar and browse in the terminal to that directory:

        ./configure --with-cxx --without-octave --without-matlab
        make
        sudo make install

5. Compile phyx. Now you can go to the src directory of phyx and type:

        ./configure
        make

and all the programs should compile without issue. 